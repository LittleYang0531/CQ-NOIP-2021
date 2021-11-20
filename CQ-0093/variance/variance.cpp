 #include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t,a[10005],an;
double jdz(double x){return x<0?-x:x;}
double s,now;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for(t=1;t<=5000000/n;++t)
	{
		s=0;
		for(i=1;i<=n;++i)
		s+=a[i];
		for(i=2;i<n;++i)
		{
			if(jdz(a[i]-s/n)>jdz(a[i-1]+a[i+1]-a[i]-(s+a[i-1]+a[i+1]-a[i]-a[i])/n))
			{
				s=s+a[i-1]+a[i+1]-a[i]-a[i];
				a[i]=a[i-1]+a[i+1]-a[i];
			}
		}
		for(i=n;i>1;--i)
		{
			if(jdz(a[i]-s/n)>jdz(a[i-1]+a[i+1]-a[i]-(s+a[i-1]+a[i+1]-a[i]-a[i])/n))
			{
				s=s+a[i-1]+a[i+1]-a[i]-a[i];
				a[i]=a[i-1]+a[i+1]-a[i];
			}
		}
	}
	s=0;
	for(i=1;i<=n;++i)s+=a[i];
	for(i=1;i<=n;++i)now+=(a[i]-s/n)*(a[i]-s/n);
	an=now*n;
	cout<<an<<endl;
	return 0;
}
/*
4
1 2 4 6
*/
