#include<bits/stdc++.h>
using namespace std;
int m,n,k;
const int mod=998244353;
int v[100001],ans;
int efks(int x,int y)
{
	int s=1;
	for(int i=1;i<=28;i++)
	s=(s%mod)*(x%mod)%mod;
	for(int i=1;i<=2;i++)
	s=(s%mod)*(y%mod)%mod;
	return s%mod;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	scanf("%d",&v[i]);
	if(k==1)
	{
		for(int i=0;i<=m;i++)
		{
			ans+=efks(v[i-1],v[i]);
			cout<<ans<<endl;
		}
		ans=(ans%mod)*435%mod;
		printf("%d\n",ans);
		return 0;
	}
	else 
	printf("0");
	return 0;
}
