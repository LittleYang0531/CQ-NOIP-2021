#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110,mod=998244353;
ll n,m,k;
ll v[N];
ll a[N];
ll cnt;
ll ans;
ll lowbits(ll x)
{
	return x&-x;
}
ll num1(ll x)
{
	ll sum=0;
	while(x)
	{
		x-=lowbits(x);
		sum++;
	}
	return sum;
}
ll c(int a,int b)
{
	ll res=1;
	for(int i=0;i<b;i++)
		res=res*(a-i);
	for(int i=1;i<=b;i++)
		res=res/i;
	return res;
}
ll sum(ll a[])
{
	ll res=1;
	for(ll i=0;i<=m;i++)
		for(ll j=1;j<=a[i];j++)
			res=res*v[i]%mod;
	ll t=n,k=1;
	for(int i=0;i<=m;i++)
	{
		k=k*c(t,a[i])%mod;
		t-=a[i];
	}
	return res*k%mod;
}
void dfs(ll x)
{
	if(x==m+1)
	{
		ll s=0;
		for(ll i=0;i<=m;i++)
			s+=(1<<i)*a[i];
		if(num1(s)<=k)
			ans=( ans + sum(a) )%mod;
		return;
	}
	if(x==m)
	{
		a[x]=cnt;
		dfs(x+1);
		return;
	}
	for(int i=0;i<=cnt;i++)
	{
		a[x]=i;
		cnt-=i;
		dfs(x+1);
		cnt+=i;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	cnt=n;
	dfs(0);
	printf("%lld",ans);
	return 0;
}
