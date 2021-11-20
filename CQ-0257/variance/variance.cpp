#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0x3f3f3f3f;
double a[401];
void ver()
{
	double v_,s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	v_=s/(double)n;
	s=0;
	for (int i=1;i<=n;i++) s+=(a[i]-v_)*(a[i]-v_);
	s*=n;
	ans=min(ans,(int)s);
}
void bt()
{
	for (int i=2;i<n;i++)
	{
		int u=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		ver();
		a[i]=u;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i+=1)
	{
		scanf("%lf",&a[i]);
	}
	ver();
	bt();
	printf("%d",ans);
	return 0;
}
