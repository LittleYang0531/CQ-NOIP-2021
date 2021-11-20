/*
wpcakioi
*/
#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n;
double a[N],b[N];
double sum,s,ans;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		b[i]=a[i];
		s=s+a[i];
	}
	s=s/n;
	for(int i=1;i<=n;i++)
	{
		sum=sum+(a[i]-s)*(a[i]-s);
	}
	if(n==1||n==2)
	{
		cout<<sum*n;
	}
	if(n==3)
	{
		ans=sum;sum=0;s=0;
		a[2]=a[1]+a[3]-a[2];
		for(int i=1;i<=3;i++)
		{
			s=s+a[i];
		}
		s=s/n;
		for(int i=1;i<=3;i++)
		{
			sum=sum+(a[i]-s)*(a[i]-s);
		}
		cout<<min(sum*n,ans*n);
	}
	if(n==4)
	{
		ans=sum;sum=0;s=0;
		b[2]=a[1]+a[3]-a[2];
		for(int i=1;i<=4;i++)
		{
			s=s+b[i];
		}
		s=s/n;
		for(int i=1;i<=4;i++)
		{
			sum=sum+(b[i]-s)*(b[i]-s);
		}
		ans=min(sum,ans);
		for(int i=1;i<=4;i++)
		{
			b[i]=a[i];
		}
		sum=0;s=0;
		b[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=4;i++)
		{
			s=s+b[i];
		}
		s=s/n;
		for(int i=1;i<=4;i++)
		{
			sum=sum+(b[i]-s)*(b[i]-s);
		}
		ans=min(sum,ans);
		sum=0;s=0;
		b[2]=a[1]+a[3]-a[2];b[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=4;i++)
		{
			s=s+b[i];
		}
		s=s/n;
		for(int i=1;i<=4;i++)
		{
			sum=sum+(b[i]-s)*(b[i]-s);
		}
		ans=min(sum,ans);
		b[3]=a[2]+a[4]-a[3];b[2]=a[1]+a[3]-a[2];
		sum=0;s=0;
		for(int i=1;i<=4;i++)
		{
			s=s+b[i];
		}
		s=s/n;
		for(int i=1;i<=4;i++)
		{
			sum=sum+(b[i]-s)*(b[i]-s);
		}
		ans=min(sum,ans);
		cout<<ans*n;
	}
	if(n>=5)
	{
		cout<<sum*n;
	}
	return 0;
}
