#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
bool ppp;
const int N=33;
const int p=998244353;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int sa[30],tp;
void write(int x){
	if(x<0){putchar('-'),x=-x;}
	if(!x){putchar('0');return;}
	while(x)sa[++tp]=x%10,x/=10;
	while(tp){putchar(sa[tp]+'0');tp--;}
	return;
}
int dp[110][N][N][2*N];//考虑到第i位，离散后当前选的为j，已经用了l个数，位数已经是k 
int n,m,K,ans,v[110];
int fac[110],ifac[110];
int pop[1000010];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void init(int n){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);
	Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(fac[n-1]*ifac[n-1]%p==1);
	rep(i,10000)pop[i]=pop[i>>1]+(i&1);
}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
bool pppp;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc sequence.out sequence2.ans");
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read();init(N-1);
	For(i,0,m)v[i]=read();
	dp[0][0][0][0]=1;
	For(i,0,m)For(j,0,31)For(l,0,n)For(k,0,60){
		int w=dp[i][j][l][k];if(!w)continue;
		For(cnt,0,n-l)if(k>=pop[j]&&k-pop[j]+pop[j+cnt]<=60){
			(dp[i+1][(j+cnt)/2][l+cnt][k-pop[j]+pop[j+cnt]]+=w*inv(v[i],cnt)%p*C(n-l,cnt)%p)%=p;
		}
	}
	For(j,0,31)For(k,0,K)ans=(ans+dp[m+1][j][n][k])%p;
	cout<<ans<<endl;
	return 0;
}

