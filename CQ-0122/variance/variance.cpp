#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,d;
int a[10005],sum[10005];
int fc(int x)
{
	if(x==1)
	{
		for(int i=1;i<=n;i++) sum[x]+=a[i];
	}
	else sum[x]=sum[x-1]+a[x-1]+a[x+1]-2*d;
	double s=(double)sum[x]/n; 
	long long ff=0;
	for(int i=1;i<=n;i++)
	{
		ff+=(int)pow(a[i]-s,2)*n;
	}
	return ff;
} 
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=fc(1);
	cout<<fc(1)<<endl;
	for(int i=2;i<n;i++)
	{
		d=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		if(fc(i)>ans) continue;
		else ans=fc(i);
	}
	cout<<ans;
	return 0;
}
