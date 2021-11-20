#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,k;
long long v[105];
int a[35];
long long ans;
void check()
{
	long long tot=1;
	int vis[155];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		vis[a[i]]++;
		tot*=v[a[i]];
		tot%=mod;
		for(int j=a[i];1;++j)
		{
			if(vis[j]>=2)
			{
				vis[j]-=2;
				vis[j+1]++;
			}
			else
			{
				break;
			}
		}
	}
	int bj=0;
	for(int i=0;i<=150;++i)
	{
		bj+=vis[i];
		if(bj>k)
		return;
	}
	ans+=tot;
	ans%=mod;
}
void dfs(int x)
{
	if(x>n)
	{
		check();
		return;
	}
	for(int i=0;i<=m;++i)
	{
		a[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i)
	cin>>v[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
