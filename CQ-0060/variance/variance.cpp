#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int M = 100005;
#define ll long long
#define ull unsigned long long
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,cnt,a[M];ll ans;map<ull,bool> mp;
ll check()
{
	ll sum=0,res=0;cnt++;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		res+=a[i]*a[i];
	}
	res=n*res+sum*sum;
	for(int i=1;i<=n;i++)
		res-=2*a[i]*sum;
	return res;
}
void dfs()
{
	ull hs=0;
	for(int i=1;i<=n;i++)
		hs=371*hs+a[i];
	if(mp[hs]) return ;mp[hs]=1;
	ans=min(ans,check());
	for(int i=2;i<n;i++)
	{
		int tmp=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs();
		a[i]=tmp;
	}
}
void dfs2()
{
	ull hs=0;
	for(int i=1;i<=n;i++)
		hs=371*hs+a[i];
	if(mp[hs]) return ;mp[hs]=1;
	if(check()>ans) return ;
	ans=min(ans,check());
	for(int i=2;i<n;i++)
	{
		int tmp=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs2();
		a[i]=tmp;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();ans=1e18;
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n>10)
	{
		dfs2();
		printf("%lld\n",ans);
		return 0;
	}
	dfs();
	printf("%lld\n",ans);
	return 0;
}
