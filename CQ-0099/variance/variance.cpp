#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],sum=0,ans=1e12,cnt=0,b[10010],sumb=0,c[10010],sumc=0,d[10010],sumd=0,_d=0;
double _a=0;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i],d[i]=b[i]=c[i]=a[i];
	_d=_a=(double)sum/(double)n;
	sumd=sumb=sumc=sum;
	for(int t=1;t<=n;t++)
	{
		for(int i=n-1;i>1;i--)
		{
			if(abs((double)((double)d[i]-_d))>abs((double)((double)d[i-1]+(double)d[i+1]-(double)d[i]-_d)))
			{
				sum+=d[i+1]+d[i-1]-d[i]-d[i];
				_d=(double)sum/n;
				d[i]=d[i+1]+d[i-1]-d[i];
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
		//	cout<<d[i]<<" ";
			cnt+=(d[i]*4-sum)*(d[i]*4-sum);
		}
		cnt/=n;
		//cout<<endl<<cnt<<endl;
		ans=min(cnt,ans);
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=2;i<n;i++)
		{
			if(abs((double)((double)a[i]-_a))>abs((double)((double)a[i-1]+(double)a[i+1]-(double)a[i]-_a)))
			{
				sum+=a[i+1]+a[i-1]-a[i]-a[i];
				_a=(double)sum/n;
				a[i]=a[i+1]+a[i-1]-a[i];
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
	//		cout<<a[i]<<" ";
			cnt+=(a[i]*4-sum)*(a[i]*4-sum);
		}
		cnt/=n;
	//	cout<<endl<<cnt<<endl;
		ans=min(cnt,ans);
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=2;i<n;i++)
		{		
				sum+=b[i+1]+b[i-1]-b[i]-b[i];
				b[i]=b[i+1]+b[i-1]-b[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
	//		cout<<b[i]<<" ";
			cnt+=(b[i]*4-sum)*(b[i]*4-sum);
		}
		cnt/=n;
	//	cout<<endl<<cnt<<endl;
		ans=min(cnt,ans);
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=n-1;i>1;i--)
		{		
				sum+=c[i+1]+c[i-1]-c[i]-c[i];
		//		cout<<c[i]<<"="<<c[i+1]<<"+"<<c[i-1]<<"-"<<c[i]<<endl;
				c[i]=c[i+1]+c[i-1]-c[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
		//	cout<<c[i]<<" ";
			cnt+=(c[i]*4-sum)*(c[i]*4-sum);
		}
		cnt/=n;
	//	cout<<endl<<cnt<<endl;
		ans=min(cnt,ans);
	}
	cout<<ans<<endl;
	return 0;
}
