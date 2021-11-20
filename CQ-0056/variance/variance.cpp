#include<bits/stdc++.h>
#define N 10004
using namespace std;
int n,a[N];
long long sum,s,ans;
int main()
{
freopen("variance.in","r",stdin);
freopen("variance.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	sum+=a[i]*a[i];
	s+=a[i];
}

srand(20050204);
ans=(1ll<<60);
for(int k=0;k<max(3e7/n/n,1.0);k++)
{
	for(int i=1;i<=n;i++)
		for(int j=2;j<n;j++)
		{
			int w=a[j-1]+a[j+1]-a[j];
			if((sum*n-s*s<(sum-a[j]*a[j]+w*w)*n-(s-a[j]+w)*(s-a[j]+w)&&rand()%3==0)||
			(sum*n-s*s>(sum-a[j]*a[j]+w*w)*n-(s-a[j]+w)*(s-a[j]+w)&&rand()%3!=0))
			{
				s-=a[j];s+=w;
				sum-=a[j]*a[j];sum+=w*w;
				a[j]=w;
			}
		}
ans=min(ans,sum*n-s*s);
}
printf("%lld",ans);

return 0;
}
