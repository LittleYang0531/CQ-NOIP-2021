#include<bits/stdc++.h>
using namespace std;
const int N=35,mod=998244353;
int n,m,k,v[N],a[N];
long long ans;
void check()
{
	long long tot=0;
	for(int i=1;i<=n;i++) tot+=(1<<a[i]);
	if(__builtin_popcount(tot)>k) return;
	tot=1;
	for(int i=1;i<=n;i++) tot=tot*v[a[i]]%mod;
	ans=(ans+tot)%mod;
	return;
}
void dfs(int x)
{
	if(x>n) return check();
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1);
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",v+i);
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
