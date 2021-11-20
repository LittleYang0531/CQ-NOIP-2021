#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cmath>
#define int long long
const int Q=10005;
const int INF=(1<<30);
#define gc() getchar()
typedef long long ll;
#define rg register int
#define cint const register int
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){int res=0,f=1;char c;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
inline int sqr(cint x){return x*x;}
inline int rnd(cint N){return (1ll*rand()*rand()+rand())%N+1;}
int n,a[Q],S,s;
const double eps=1e-18;
const double Dlt=0.9992;
const int TT=114;
int ans;
inline void SA(){
	srand((unsigned)time(NULL));
	for(double Tmp=1919810;Tmp>eps;Tmp*=Dlt){
		rg pos=rnd(n);
		if(pos==1)++pos;if(pos==n)--pos;
		cint l=a[pos-1],t=a[pos],r=a[pos+1],nv=l+r-t;
		cint ts=s-t+nv,tS=S-sqr(t)+sqr(nv);
		cint nans=n*tS-ts*ts,dlt=ans-nans;
		if(nans<ans)ans=nans,a[pos]=nv,S=tS,s=ts;
		else if(-dlt*exp(Tmp)<RAND_MAX)a[pos]=nv,S=tS,s=ts;
	}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);for(rg i=1;i<=n;++i)read(a[i]);
	s=0;S=0;for(rg i=1;i<=n;++i)s+=a[i],S+=a[i]*a[i];ans=n*S-s*s;
	if(n==2){for(rg i=1;i<=n;++i)s+=a[i],S+=a[i]*a[i];write(n*S-s*s,'\n');return 0;}
	for(rg _=1;_<=TT;++_)SA();write(ans,'\n');
	return 0;
}
