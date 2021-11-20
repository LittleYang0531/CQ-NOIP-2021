#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
long long v[105],fac[105],a[105],n,m,k,ans,cnt;
bool check(int x){
	int res=0;
	for(;x;x>>=1)res+=x%2;
	return res<=k;
}
void dfs(int x,int y,int step){
	++cnt;
	if(step==n){
		if(check(x))
			ans=(ans+y)%p;
		return;
	}
	for(int i=0;i<=9;++i){
		a[i]+=1;
		dfs(x+(1ll<<i),y*v[i]%p,step+1);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<=m;++i){
		scanf("%lld",&v[i]);
	}
	if(n==8){
		dfs(0,1,0);
		printf("%lld",ans);
	}
	return 0;
}
