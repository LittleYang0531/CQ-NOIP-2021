#include<bits/stdc++.h>
using namespace std;
int n,minn=0x7fffffff/2;
int a[100005],b[100005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memcpy(b,a,sizeof(a));
	while(1)
	{
		bool flag=0;
		int sum1=a[1],sum2=a[n];
		for(int i=2,cnt=1;cnt<=n-2;i=n-i+((cnt&1)==0?2:1),cnt++)
		{
//			cout<<i<<" "<<cnt<<endl;
			int temp=a[i+1]+a[i-1]-a[i];
			if(cnt==n-2 && (n&1))
			{
				if((n>>1)*a[i]-sum1>=sum2-(n>>1)*a[i])
				{
					if(temp<a[i])a[i]=temp,flag=1;
				}
				else
				{
					if(temp>a[i])a[i]=temp,flag=1;
				}
				break;
			}
			if(i<=n/2)
			{
				if(temp>a[i])a[i]=temp,flag=1;
				sum1+=a[i];
			}
			else
			{
				if(temp<a[i])a[i]=temp,flag=1;
				sum2+=a[i];
			}
		}
		if(flag==0)break;
	}
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(n*a[i]-sum)*(n*a[i]-sum);
	}
//	printf("%d\n",ans/n);
	minn=min(minn,ans/n);
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
//	cout<<endl;
	memcpy(a,b,sizeof(b));
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	while(1)
	{
		bool flag=0;
		for(int i=2;i<=n-1;i++)
		{
//			cout<<i<<" "<<cnt<<endl;
			int temp=a[i+1]+a[i-1]-a[i];
			if(temp<a[i])a[i]=temp,flag=1;
		}
		if(flag==0)break;
	}
	sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(n*a[i]-sum)*(n*a[i]-sum);
	}
//	printf("%d\n",ans/n);
	minn=min(minn,ans/n);
	memcpy(a,b,sizeof(b));
	while(1)
	{
		bool flag=0;
		for(int i=n-1;i>=2;i--)
		{
//			cout<<i<<" "<<cnt<<endl;
			int temp=a[i+1]+a[i-1]-a[i];
			if(temp>a[i])a[i]=temp,flag=1;
		}
		if(flag==0)break;
	}
	sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(n*a[i]-sum)*(n*a[i]-sum);
	}
//	printf("%d\n",ans/n);
	minn=min(minn,ans/n);
	printf("%d",minn);
	return 0;
}
/*
4
1 2 4 6
*/
