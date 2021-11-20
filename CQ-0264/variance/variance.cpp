#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,inf=0x3f3f3f3f;
int n;
int a[N],b[N];
double mid;
int l,r;
int ans1,ans2;
int get(int s[])
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=s[i];
	int res=0;
	for(int i=1;i<=n;i++)
		res+=n*s[i]*s[i]-2*sum*s[i];
	res+=sum*sum;
	return res;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	mid=(a[1]+a[n])/2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<mid) l=i;
		else break;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]>mid) r=i;
		else break;
	}
	for(int i=2;i<=l;i++)
	{
		double x=abs(mid-a[i]);
		double y=abs(mid-a[i-1]-a[i+1]+a[i]);
		if(y<=x)
			a[i]=a[i-1]+a[i+1]-a[i];
	}
	for(int i=n-1;i>=r;i--)
	{
		double x=abs(mid-a[i]);
		double y=abs(mid-a[i-1]-a[i+1]+a[i]);
		if(y<=x)
			a[i]=a[i-1]+a[i+1]-a[i];
	}
	ans1=get(a);
	
	for(int i=n-1;i>=r;i--)
	{
		double x=fabs(mid-b[i]);
		double y=fabs(mid-b[i-1]-b[i+1]+b[i]);
		if(y<=x)
			b[i]=b[i-1]+b[i+1]-b[i];
	}
	for(int i=2;i<=l;i++)
	{
		double x=fabs(mid-b[i]);
		double y=fabs(mid-b[i-1]-b[i+1]+b[i]);
		if(y<=x)
			b[i]=b[i-1]+b[i+1]-b[i];
	}
	ans2=get(b);
	printf("%d",min(ans1,ans2));
	return 0;
}
