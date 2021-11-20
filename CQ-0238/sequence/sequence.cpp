#include <iostream>
#include <cstdio>
#include <bitset>
#define mod 998244353
using namespace std;
int n,m,k,v[105],a[35],c[35][35],cnt;
bitset<205>s;
bool f[105];
long long ans;
void init()
{
	c[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
}
void change(int x)
{
	if(s[x]==1) s[x]=0,cnt--,change(x+1);
	else {s[x]=1; cnt++; return;}
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(cnt<=k)
		{
			long long sum=1;
			for(int i=1;i<=n;i++) sum=sum*v[a[i]]%mod;
			ans=(ans+sum)%mod;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		bitset<205>ss;
		int cntt=cnt;
		ss=s;
		change(i); dfs(x+1);
		s=ss; cnt=cntt;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
//	init();
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
