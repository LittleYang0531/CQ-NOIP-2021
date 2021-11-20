#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 30 + 5;
const int MAX_M = 100 + 5;
const ll mod = 998244353;
int n,m,k;
ll ans,v[MAX_M],m2[MAX_N];
bool check(ll x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt<=k;
}
void dfs(int x,ll sum,ll val){
	if(x==n+1){
		if(check(sum)){
			ans=(ans+val)%mod;
		}
		return;
	}
	for(int i=0;i<=m;++i){
		dfs(x+1,sum+m2[i],val*v[i]%mod);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i) scanf("%lld",&v[i]);
	m2[0]=1;
	for(int i=1;i<=m;++i) m2[i]=m2[i-1]*2;
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
