#include<iostream>
#include<cstdio>
#include<unordered_map>
const int N=333,M=333,mod=998244353;
using namespace std;
//char me1;
unordered_map<int,int>ans;
int v[M],fra[N],ifra[N];
int n,m,k;
inline char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *(S++);
}
#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
#define lb(x) ((x)&(-(x)))
inline int calc(int n)
{
	int cnt=0;
	while(n)
	{
		n-=lb(n);
		cnt++;
	}
	return cnt;
}
inline int qpow(int a,int b)
{
	int j=1;
	while(b)
	{
		if(b&1)j=1ll*j*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return j;
}
inline void init()
{
	fra[0]=ifra[0]=1;
	for(int i=1;i<N;i++)fra[i]=1ll*fra[i-1]*i%mod;
	ifra[N-1]=qpow(fra[N-1],mod-2);
	for(int i=N-2;i;i--)ifra[i]=1ll*ifra[i+1]*(i+1)%mod;
}
inline int C(int n,int m)
{
//	cout<<n<<' '<<m<<"::"<<(n<m?0:1ll*fra[n]*ifra[m]%mod*ifra[n-m]%mod)<<"!!!!\n";
	return n<m?0:1ll*fra[n]*ifra[m]%mod*ifra[n-m]%mod;
}
int dfs(int re,int x,int s)
{
	if(re==0)
	{
		return calc(s)<=k?1:0;
	}
	if(x==-1)return 0;
	int vv=s*(n+1)*(m+1)+x*(n+1)+re;
	if(ans.find(vv)!=ans.end())return ans[vv];
	int da=0;
	for(int i=0,t=1;i<=re;i++)
	
	{
		da=(da+1ll*C(re,i)*dfs(re-i,x-1,s+(1<<x)*i)%mod*t)%mod;
		t=1ll*t*v[x]%mod;
	}
	return ans[vv]=da;
}
//char me2;
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!!\n";
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init();
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)v[i]=read();
	cout<<dfs(n,m,0)<<"\n";
	return 0;
}
/*
5 1 1
2 1
*/
