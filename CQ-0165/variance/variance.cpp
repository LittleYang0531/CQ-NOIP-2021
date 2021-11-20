#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#define eps 0.998
using namespace std;
long long m,k,ans=(1ll<<40);
int n,s,t,cnt,tot;
int a[100005],c[100005],f[100005];
long long check()
{
	return 1ll*n*m-1ll*k*k;
}
void sa()
{
	long double temp=4000;
	while(temp>=1e-6)
	{
		int x=rand()%(n-2)+2;
		int y=a[x];
		a[x]=a[x-1]+a[x+1]-a[x];
		k+=a[x]-y;m=m-1ll*y*y+1ll*a[x]*a[x];
		long long s=check();
		double sum=s-ans;
		if(sum<=0) ans=s;
		else if(exp(-1.0*sum/temp)*RAND_MAX<rand()) 
			k+=y-a[x],m=m-1ll*a[x]*a[x]+1ll*y*y,a[x]=y;
		temp*=eps;
	}
}
void SA()
{
	int ssh=200;
	while(ssh--)
	{
		sa();
//		k=0;m=0;
//		for(int i=1;i<=n;i++)
//		a[i]=c[i],k+=a[i],m+=1ll*a[i]*a[i];
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	srand(n-2);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),k+=a[i],m+=1ll*a[i]*a[i];
	ans=1ll*n*m-1ll*k*k;
	SA();
	printf("%lld",ans);
}
/*
Ä£ÄâÍË»ð 
RP²âÊÔÒÇ /jk


FUCK
¸øÎÒ+rp!
*/ 
