#include<cstdio>
#include<algorithm>
const int Q=155;
const int INF=(1<<30);
const int mod=998244353;
#define gc() getchar()
typedef long long ll;
#define rg register int
#define cint const register int
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){int res=0,f=1;char c;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
int prd[Q],inv[Q];
inline int inc(cint x,cint y){return x+y<mod?x+y:x+y-mod;}
inline int dec(cint x,cint y){return x>=y?x-y:x-y+mod;}
inline int mul(cint x,cint y){return 1ll*x*y%mod;}
inline int pow(rg x,rg y){rg res=1;for(;y;y>>=1,x=mul(x,x))if(y&1)res=mul(res,x);return res;}
inline int Inv(cint x){return pow(x,mod-2);}
inline int C(cint N,cint M){return mul(prd[N],mul(inv[N-M],inv[M]));}
int n,m,k,vl[Q];
namespace Brute{
	int c[Q],ans;
	inline void dfs(cint dep,cint cnt){
		if(dep==m+1&&cnt<n)return;
		if(cnt==n){
			ll S=0,ct=0,ml=1,num=1,tp=n;
			for(rg i=0;i<=m;++i)S+=mul(c[i],(1ll<<i)),ml=mul(ml,pow(vl[i],c[i]));
			for(rg i=30;i>=0;--i)if((S>>i)&1)++ct;if(ct>k)return;
			for(rg i=0;i<=m;++i)num=mul(num,C(tp,c[i])),tp-=c[i];
			ans=inc(ans,mul(ml,num));return;
		}for(rg i=0;i<=n-cnt;++i)c[dep]=i,dfs(dep+1,cnt+i);c[dep]=0;
	}
	inline void solve(){
		prd[0]=1;for(rg i=1;i<=n;++i)prd[i]=mul(prd[i-1],i);
		inv[0]=1;inv[n]=Inv(prd[n]);
		for(rg i=n-1;i>=1;--i)inv[i]=mul(inv[i+1],i+1);
		dfs(0,0);write(ans,'\n');
	}
}
namespace K1{
	int f[Q][Q],ans;
	inline void solve(){
		prd[0]=1;for(rg i=1;i<=n;++i)prd[i]=mul(prd[i-1],i);
		inv[0]=1;inv[n]=Inv(prd[n]);
		for(rg i=n-1;i>=1;--i)inv[i]=mul(inv[i+1],i+1);m+=5;
		f[0][1]=vl[0];for(rg i=1;i<=m;++i){
			f[i][1]=vl[i];
			for(rg j=2;j<=n;++j)for(rg k=1;k<j;++k){
				if(k>j-k)break;
				f[i][j]=inc(f[i][j],mul(1,mul(f[i-1][k],f[i-1][j-k])));
			}
		}
		for(rg i=0;i<=m;++i)ans=inc(ans,f[i][n]);
		write(ans,'\n');
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(rg i=0;i<=m;++i)read(vl[i]);
	if(n<=8&&m<=9){Brute::solve();return 0;}
	else if(k==1){K1::solve();return 0;}
	else{Brute::solve();return 0;}
	return 0;
}
