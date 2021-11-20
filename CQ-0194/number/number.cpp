#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,cnt,mx;
ll x[200005],p[1000005];
bitset<10000005> vis;
bool check(ll x)
{
	while(1)
	{
		if(x%10==7) return 1;
		x/=10;
		if(!x) return 0;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vis[1]=1,p[++cnt]=1;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++)
	{
		scanf("%lld",&x[i]);
		mx=max(mx,x[i]);
	}
	mx+=10000;
	for(ll i=2;i<=mx;i++)
	{
		if(!vis[i]&&!check(i)) p[++cnt]=i;
		if(vis[i]||check(i))
		{
			for(ll j=2;j*i<=mx;j++)
				vis[i*j]=1;
		}
	}
	for(ll i=1;i<=T;i++)
	{
		ll L=1,R=cnt,ans=-1;
		while(L<=R)
		{
			ll mid=L+R>>1;
			if(p[mid]==x[i])
			{
				ans=mid;
				break;
			}
			if(p[mid]<x[i]) L=mid+1;
			if(p[mid]>x[i]) R=mid-1;
		}
		if(ans==-1)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",p[ans+1]);
	}
}
