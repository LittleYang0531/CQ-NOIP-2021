#include<bits/stdc++.h>
using namespace std;

long long a[10005];

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while( ch < '0' or ch > '9' ) f *= ch=='-' ? -1 : 1, ch=getchar();
	while( ch >= '0' and ch <= '9' ) x=x*10+ch-'0', ch=getchar();
	return x*f;
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read(),tem=1;
	long long ans,suma=0,sumsa=0;
	for(int i=1;i<=n;i++) a[i]=read(),suma+=a[i],sumsa+=a[i]*a[i];
	long long ada=a[1]+a[n]>>1;
	for(int j=1;j<=n;j++) if( abs(ada-a[tem]) > abs(ada-a[j]) ) tem=j;
	ans=(long long)n*sumsa-suma*suma;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=2;j<=n-1;j++)
		{
			long long x=a[j-1]+a[j+1]-a[j];
			if( (long long)n*(sumsa+x*x-a[j]*a[j])-(suma+x-a[j])*(suma+x-a[j]) < (long long)n*sumsa-suma*suma )
			{
				sumsa+=x*x-a[j]*a[j];
				suma+=x-a[j];
				a[j]=x;
				ans=min(ans,(long long)n*sumsa-suma*suma);
			}
		}
		for(int j=n-2;j>=2;j--)
		{
			long long x=a[j-1]+a[j+1]-a[j];
			if( (long long)n*(sumsa+x*x-a[j]*a[j])-(suma+x-a[j])*(suma+x-a[j]) < (long long)n*sumsa-suma*suma )
			{
				sumsa+=x*x-a[j]*a[j];
				suma+=x-a[j];
				a[j]=x;
				ans=min(ans,(long long)n*sumsa-suma*suma);
			}
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=2;j<=n-1;j++)
		{
			long long x=a[j-1]+a[j+1]-a[j];
//			if( (long long)n*(sumsa+x*x-a[j]*a[j])-(suma+x-a[j])*(suma+x-a[j]) < (long long)n*sumsa-suma*suma )
//			{
				sumsa+=x*x-a[j]*a[j];
				suma+=x-a[j];
				a[j]=x;
				ans=min(ans,(long long)n*sumsa-suma*suma);
//			}
		}
	}
	printf("%d",ans);
	return 0;
}
