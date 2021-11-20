#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n;
long double bef,a[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%Lf",a+i);
		bef+=a[i];
	}
	bool check=true;
	while(check)
	{
		check=false;
		for(int i=2;i^n;i++)
		{
			long double now=bef+a[i+1]+a[i-1]-a[i]*2;
			if(abs(a[i]-bef/n)>abs(a[i+1]+a[i-1]-a[i]-now/n))
			{
				a[i]=a[i+1]+a[i-1]-a[i];
				check=true;
				bef=now;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=(a[i]*a[i]*n*n-2*a[i]*n*bef+bef*bef);
	printf("%lld\n",ans/n);
	fclose(stdin);fclose(stdout);
	return 0;
}
