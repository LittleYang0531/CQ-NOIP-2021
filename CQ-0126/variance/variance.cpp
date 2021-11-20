#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
double ave,va,ans=0x3f3f3f3f;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=2*a[1]-a[2];
	a[n+1]=2*a[n]-a[n-1];
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		va=0;
		ave=0;
		a[i]=a[i-1]+a[i+1]-x;
		for(int j=1;j<=n;j++)
			ave+=a[j];
		ave/=n;
		for(int j=1;j<=n;j++)
			va+=(ave-a[j])*(ave-a[j]);
		ans=min(ans,va);
	}
	cout<<ans*n;
	return 0;
}
