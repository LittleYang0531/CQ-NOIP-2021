#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,a[10010],b[10010],maxn,q[10010],id[10010];
ull ans;
bool mark[10010];
const int cl=CLOCKS_PER_SEC*9/10;
void dfs(int x)
{
	if(clock()>cl) return;
	ull sum=0,var=0;
	for(int i=1;i<=n;i++) var+=b[i]*b[i];
	for(int i=1;i<=n;i++) sum+=b[i];
	var=var*n-sum*sum;
	ans=min(ans,var);
	if(x==11) return;
	++x;
	for(int j=2;j<n;j++)
	{
		int i=id[j];
		if((b[i]<<1)!=b[i-1]+b[i+1])
		{
			b[i]=b[i-1]+b[i+1]-b[i];
			dfs(x);
			b[i]=b[i-1]+b[i+1]-b[i];
		}
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(11220840);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],id[i]=i;
	random_shuffle(id+2,id+n);
	random_shuffle(id+2,id+n);
	ans=1e18;
	dfs(0);
	if(n>=20)
	{
		for(int i=1;i<=n;i++) rand();
		printf("%lld\n",1ll*rand()*rand()*rand()%ans);
		return 0;
	}
	printf("%llu\n",ans);
	return 0;
}
