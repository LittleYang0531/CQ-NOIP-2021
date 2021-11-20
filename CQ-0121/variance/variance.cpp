#include<bits/stdc++.h>
using namespace std;
int n;
double a[105],x,sum,minn=10000000;
double work()
{
	x=(a[1]+a[2]+a[3]+a[4])/n;
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=abs(a[i]-x)*abs(a[i]-x);
	}
//	cout<<ans<<endl; 
	return double(ans);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
	scanf("%lf",&a[i]);
	sum+=a[i];
	}
	x=sum/n;
	if(n==4)//n等于4时只有两种变法
	{
		int ans;
		while(a[1]+a[2]!=a[3]||a[2]+a[3]!=a[4])
		{
			ans=work();
			if(ans<minn) minn=ans;
			else break;
			a[2]=a[1]+a[3]-a[2];
			ans=work();
			if(ans<minn) minn=ans;
			else break;
			a[3]=a[2]+a[4]-a[3];
			ans=work();
			if(ans<minn) minn=ans;
			else break;
		}
	 } 
	/*while(true)
	{
		int k;
		double minn=1e7;
		for(int i=2;i<=n-1;i++)//求出距离平均数差值最大的
		{
			if(abs(a[i]-x)<minn) {
				minn=abs(a[i]-x);
				k=i;
			}
		}
	}*/
	cout<<minn*n;
	return 0;
}
