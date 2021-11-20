#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,k;
ll v[103],dp[103][33][33];
inline void safe(ll &a,ll b){
	a=(a+b)%mod;
}
int main(){
	freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);dp[0][0][0]=1;
	for(int i=0;i<=m;i++)scanf("%lld",&v[i]);
	for(int i=0;i<=m;i++)
	for(int use=0;use<=n;use++)
	for(int add=0;use+add<=n;add++){
		ll tmp=1;if(add)tmp=tmp*v[i]%mod;
		for(int sing=0;sing+(bool)(add&1)<=min(i,k);sing++)
		safe(dp[i+1][use+add][sing+(bool)(add&1)],(bool)(use+add)*dp[i][use][sing]*tmp%mod);
	}
	ll ans=0;for(int sing=0;sing<=k;sing++)safe(ans,dp[m+1][n][sing]);
	printf("%lld",ans);return 0;
}
