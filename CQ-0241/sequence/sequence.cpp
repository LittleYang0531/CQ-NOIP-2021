#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>

#define maxn 35
#define maxm 50005
#define rc() getchar()

using namespace std;

int a[maxn],pd[maxm],val[maxn],n,m,k;
const int mod=998244353;
long long ans;

inline long long read()
{
	register long long x=0,b=1;register char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

inline bool check(int ret)
{
	register int cnt=0;
	while(ret)
	{
		cnt+=ret&1;ret>>=1;
		if(cnt>k) return 0;
	}
	return 1;
}

void dfs(int x,long long sum,int ret)
{
	if(x==n+1)
	{
		if(pd[ret]) ans=(ans+sum)%mod;
		return;
	}
	for(register int i=0;i<=m;++i)
	{
		a[x]=i;dfs(x+1,sum*val[i]%mod,ret+(1<<i));
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(register int i=0;i<=m;++i) val[i]=read();
	for(register int i=n;i<=(1<<m)*n;++i) pd[i]=check(i);
	dfs(1,1,0);printf("%lld",ans);
	return 0;
}

