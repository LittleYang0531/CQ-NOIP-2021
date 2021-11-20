#include<bits/stdc++.h>
using namespace std;
const int N=105;
const long long Mod=998244353;
int n,m,k;
long long v[N],dp[1<<19][15];
long long dfs(int p,int cnt) {
	if (cnt==n) {
		int res=0;
		for (int i=0;i<19;i++) {
			if (p&(1<<i)) res++;
		}
		if (res<=k) return 1;
		return 0;
	}
	if (dp[p][cnt]!=-1) return dp[p][cnt];
	long long ans=0;
	for (int i=0;i<=m;i++) {
		int t=i,q=p;
		while (q&(1<<t)) {
			q^=1<<t;
			t++;
		}
		q|=1<<t;
		ans+=dfs(q,cnt+1)*v[i];
		ans%=Mod;
	}
	return dp[p][cnt]=ans;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	memset(dp,-1,sizeof dp);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<=m;i++) scanf("%lld",&v[i]);
	printf("%lld",dfs(0,0));
	return 0;
}
