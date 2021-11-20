#include<bits/stdc++.h>
using namespace std;
int n,ans=1000000;
int a[10005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int son=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),son+=a[i];
	for(int i=2;i<n;i++)
	{
		int v=son;
		int k=a[i+1]-a[i-1],y=a[i];
		int ans1=0,ans2=0;
		for(int j=1;j<=n;j++)ans1+=(v-a[j]*n)*(v-a[j]*n);
		ans=min(ans1,ans);
		v=v-a[i]+k;
		a[i]=k;
		for(int j=1;j<=n;j++)ans2+=(v-a[j]*n)*(v-a[j]*n);
		ans=min(ans,ans2);
		if(ans1<ans2)a[i]=y;
		else son-y+k;
	}
	printf("%d\n",ans/n);
	return 0;
}
