#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#define maxn 102
#define inf (1<<30)
typedef long long ll;
using namespace std;
ll mod=998244353;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
ll ans;
ll v[maxn];
int bit[10000002];
int a[32];
int n,m,k;
void dfs(int x,int s,ll sum)
{
	if(x>n)
	{
		int qwe=0;
		while(s>10000000)
		{
			if(s&1) qwe++;
			s/=2;
		}
		qwe+=bit[s];
		if(qwe<=k) ans=(ans+sum)%mod;
		return ;
	}
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1,s+(1<<i),sum*v[i]%mod);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	bit[1]=1;
	for(int i=2;i<=10000000;i++)
	{
		bit[i]=bit[i/2]+i%2;
	}
	for(int i=0;i<=m;i++) v[i]=1ll*read();
	dfs(1,0,1ll);
	printf("%lld\n",ans);
	return 0;
}


