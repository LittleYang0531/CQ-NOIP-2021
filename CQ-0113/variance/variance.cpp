#include<bits/stdc++.h>
using namespace std;
const int N=10000+100;
unsigned long long a[N];
unsigned long long s1=0,s2=0;
unsigned long long now=0,ans=0;
int n;
void find(int i)
{
	unsigned long long x=a[i];
	a[i]=a[i-1]+a[i+1]-a[i];
	s1+=(a[i]-x)*(a[i]+x);
	s2+=a[i]-x;
	now=n*s1-s2*s2;
	ans=min(ans,now);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s2+=a[i];
		s1+=a[i]*a[i];
	}
	ans=now=n*s1-s2*s2;
	for(int j=1;j<=n-2;j++)
		for(int i=2;i<n;i++)
		{
			find(i);
		}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
