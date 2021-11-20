#include<cstdio>
#include<iostream>
using namespace std;
int n,a[10005],ans=0x7fffffff;
void dfs(int x)
{
	if(x==n)
	{
		double avg=0,var=0;
		for(int i=1;i<=n;i++)
			avg+=a[i];
		avg/=n;
		for(int i=1;i<=n;i++)
			var+=(a[i]-avg)*(a[i]-avg);
		var/=n;
		ans=min(ans,int(var*n*n));
		return;
	}
	dfs(x+1);
	a[x]=a[x+1]+a[x-1]-a[x];
	dfs(x+1);
	a[x]=a[x+1]+a[x-1]-a[x];
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(2);
	printf("%d",ans);

	return 0;
}
