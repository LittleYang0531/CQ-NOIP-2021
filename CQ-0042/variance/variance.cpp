#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10005;
int n,m,q,lim;
ll mn=1e18,ans,sum;
ll a[N],b[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(unsigned(time(0)));
	scanf("%d",&n);
	if(n<=20)lim=75870;
	else if(n<=50)lim=4500;
	else if(n<=100)lim=1000;
	else if(n<=400)lim=200;
	else lim=14;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++)b[i-1]=a[i]-a[i-1];
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=lim;j++)
		{
			random_shuffle(b+1,b+n);
			sort(b+1,b+i+1);
			sort(b+i+1,b+n);
			m=i;ans=n*a[1]*a[1];sum=a[1];q=1;
			for(int k=m;k>=1;k--)a[q+1]=a[q]+b[k],ans+=n*a[q+1]*a[q+1],sum+=a[q+1],q++;
			for(int k=m+1;k<n;k++)a[q+1]=a[q]+b[k],ans+=n*a[q+1]*a[q+1],sum+=a[q+1],q++;
			mn=min(mn,ans-sum*sum);
		}
	}
	printf("%lld",mn);
	return 0;
}
