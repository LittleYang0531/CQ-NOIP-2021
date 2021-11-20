#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5,mod=998244353;
int n,m,k;
bool vis[M];
long long ans,sum,a[M];
bool check(long long x){
	int tot=0;
	for(int i=0;i<=25;i++){
		if(x&(1ll<<i)){
			tot++;
		}
	}
	if(tot>k) return 0;
	return 1;
}
void dfs(int x,long long sum,long long p){
	if(x==n+1){
		if(check(sum)){
			ans+=p;
			ans%=mod;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		dfs(x+1,sum+(1<<i),p*a[i]%mod);
	}
}
/*bool check(node l,node r){
	if(n*(2*r.y-l.x+r.x)*(r.x-l.x)<2*sum+r.x-l.x){
		return 1;
	}
	return 0;
}*/
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	ans=1e18;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,1);
	printf("%lld",ans);
	return 0;
}
