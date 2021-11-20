#include<bits/stdc++.h>
using namespace std;
const unsigned int classroom=4274906972ll;
int a[324000],c[324000],n;
long long sum;
long long ans=20060324*1e7;
inline long long variance()
{
	long long ans1=0;
//	cout<<sum<<" ";
	for (int i=1;i<=n;i++)
	{
		ans1+=(a[i]*n-sum)*(a[i]*n-sum);
		//cout<<a[i]<<" "<<ans1<<endl;
	}
	ans1/=n;
	return ans1;
	//O(n)
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for (int i=2;i<=n-1;i++)
	{
		c[i]=a[i-1]+a[i+1]-a[i]; 
	}
	while (1)
	{
		bool if_c=1;
		//int cha=0,num=0;
		for (int i=2;i<=n-1;i++)
		{
			double ave0=double(sum)/n;
			double ave=double(sum+c[i]-a[i])/n;
			if (abs(double(a[i])-ave0)-abs(double(c[i])-ave)>0)
			{
				sum=sum+c[i]-a[i];
				a[i]=a[i-1]+a[i+1]-a[i];
				c[i-1]=a[i-2]+a[i]-a[i-1];
				c[i]=a[i-1]+a[i+1]-a[i];
				c[i+1]=a[i]+a[i+2]-a[i+1];
				ans=min(ans,variance());
				if_c=0;
				//num=i;
			}
		}
		if (if_c==1) 
		{
			printf("%lld",ans);
			return 0;
		}
//		else
//		{
//			sum=sum+c[num]-a[num];
//			a[num]=a[num-1]+a[num+1]-a[num];
//			c[num-1]=a[num-2]+a[num]-a[num-1];
//			c[num]=a[num-1]+a[num+1]-a[num];
//			c[num+1]=a[num]+a[num+2]-a[num+1];
//			ans=min(ans,variance());
//			if_c=0;
//		}
	}
	return 0;
	//ºÍ´ð°¸Ö»²î3%... 0pts 
}
