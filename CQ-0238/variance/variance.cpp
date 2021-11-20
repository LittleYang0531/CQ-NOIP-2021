#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[100005],b[100005],q[100005],ans=0x7fffffff;
void dfs(int k)
{
	if(k==n-1)
	{
		memcpy(a,b,sizeof(b));
		for(int i=1;i<=n-2;i++)
		{
			a[q[i]]=a[q[i]-1]+a[q[i]+1]-a[q[i]];
			double avg,s;
			int sum;
			for(int i=1;i<=n;i++) sum+=a[i];
			avg=sum*1.0/n;
			for(int i=1;i<=n;i++) s+=((double)a[i]-avg)*((double)a[i]-avg);
			ans=min(ans,(int)s*n);
		}
		return;
	}
	for(int i=2;i<n;i++) q[k]=i,dfs(k+1);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	dfs(1);
	printf("%d",ans);
	return 0;
}

