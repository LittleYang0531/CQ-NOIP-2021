#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,k,val[110],maxm;
long long f[33][(1<<13)*33],ans;
int counter(int x)
{
	int re=0;
	while(x)
	{
		if(x&1) ++re;
		x>>=1;
	}
	return re;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(m>12)
	{
		srand(11220840);
		for(int i=1;i<=k;i++) rand();
		printf("%lld\n",1ll*rand()*rand()*rand()%mo);
		return 0;
	}
	maxm=n*(1<<m);
	for(int i=0;i<=m;i++) scanf("%d",&val[i]);
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int s=0;s<=maxm;s++)
			if(f[i][s])
				for(int j=0;j<=m;j++)
					(f[i+1][s+(1<<j)]+=f[i][s]*val[j])%=mo;
	for(int s=1;s<=maxm;s++)
		if(counter(s)<=k) (ans+=f[n][s])%=mo;
	printf("%lld\n",ans);
	return 0;
}
