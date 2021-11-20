#include<iostream>
#include<cstdio>
#include<cmath>
#define _DEBUG
#ifdef _DEBUG
#endif//DEBUG
#define _INOUT
#ifdef _INOUT
#endif//INOUT
using namespace std;
int a[1005]={0},b[1005]={0},c[1005]={0};
int ATP[1005]={0};
int Aum=0,ans=0;
int main()
{
	#ifdef _INOUT
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	#endif//INOUT
	register int n=0,sum=0,pd=0;
	scanf(" %d",&n);
	for(register int i=1;i<=n;i++)
	{
		scanf(" %d",&a[i]);
		sum+=a[i];
		b[i]=a[i]*4;
		c[i-1]= i>2&&a[i-2]+a[i]-a[i-1]!=a[i-1] ? (a[i-2]+a[i]-a[i-1])*4 : 0;
	}
	for(register int i=1;i<=n;i++)
	{
		ATP[i]=abs(sum-b[i]);
		Aum+=ATP[i]*ATP[i];
		/*if(!pd&&b[i]>sum)
			pd=i;*/
	}
	ans=Aum;
	for(register int i=2;i<n;i++)
		if(c[i]!=0)
		{
			//register int ls=ATP[i],lls=abs(sum-c[i]),lsum=sum;
			sum+=(c[i]-b[i])/4;
			b[i]=c[i];
			c[i+1]= a[i+2]+a[i]-a[i+1]!=a[i+1] ? (a[i+2]+a[i]-a[i+1])*4 : 0;
			Aum=0;
			for(register int j=1;j<=n;j++)
			{
				ATP[j]=abs(sum-b[j]);
				Aum+=ATP[j]*ATP[j];
			}
			ans=min(ans,Aum);
		}
	printf("%d\n",ans/n);
	return 0;
}


