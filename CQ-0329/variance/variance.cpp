#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define inf 1e18
#define mem(a,b) memset(a,b,sizeof(a))
#define enter putchar('\n')
#define N 10005
#define int long long
using namespace std;
int n,a[N];
int ans=inf;
int js()
{
	int sum=0,tmp=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	for(int i=1;i<=n;i++)
		tmp+=(a[i]*n-sum)*(a[i]*n-sum);
	return tmp/n;
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=3;j++)
	{
		for(int i=2;i<n;i++)
		{
			a[i]=a[i-1]+a[i+1]-a[i];
			ans=min(ans,js());
		}
	}
	for(int j=1;j<=6;j++)
	{
		for(int i=n-1;i>1;i--)
		{
			a[i]=a[i-1]+a[i+1]-a[i];
			ans=min(ans,js());
		}
	}
	cout<<ans;
	return 0;
}

