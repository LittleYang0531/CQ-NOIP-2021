#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,k,ans;
ll v[101],a[31];
ll u[101];
bool check()
{
	memset(u,0,sizeof (u));
	for (int i=1; i<=n; i++)
	{
		u[a[i]]++;
		ll x=a[i];
		while (u[x]>=2)
		{
			u[x]-=2;
			u[++x]+=1;
		}
	}
	ll res=0;
	for (int i=0; i<=10*m; i++) res+=u[i];
	return res<=k;
}
void dfs(int r)
{
	if (r>n)
	{
		if (check())
		{
			ll w=1;
			for (int i=1; i<=n; i++)
			{
				w*=v[a[i]];
				w%=mod;
			}
			ans%=mod;
			w%=mod;
			ans+=w;
			ans%=mod;
		}
	}
	else
	{
		for (int i=0; i<=m; i++)
		{
			a[r]=i;
			dfs(r+1);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for (int i=0; i<=m; i++)
	{
		scanf("%lld",&v[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
