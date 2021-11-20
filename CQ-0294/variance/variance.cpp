#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int a[maxn],n;
long double ans=1e18;
long double p;
void dfs(int x,long double z)
{
	int d;
	if(ans>z)
	ans=z;
	for(int i=x;i<=n-1;i++)
	{
			d=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			double u=0,l=0;
			for(int j=1;j<=n;j++)
			{
				u+=a[j];
			}
			u/=n;
			for(int j=1;j<=n;j++)
			{
				l+=(a[j]-u)*(a[j]-u);
			}
			l/=n;
			dfs(x+1,l);
			a[i]=d;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	double o;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),o+=a[i];
	o/=n;
	for(int i=1;i<=n;i++)
	{
		p+=(a[i]-o)*(a[i]-o);
	}
	p/=n;
	dfs(2,p);
	cout<<ans*n*n;
	return 0;
}
