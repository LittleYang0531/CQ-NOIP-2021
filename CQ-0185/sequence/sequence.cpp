#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
const int M=1e2+5;
const int mod=998244353;
int n,m,k,v[M],bit[M],a[N];
ll ans,ansnow;
void dfs(int x){
	if(x==n+1){
		memset(bit,0,sizeof(bit));
		ansnow=1;
		for(int i=1;i<=n;i++){
			bit[a[i]]++;
			ansnow=ansnow*v[a[i]]%mod;
		}
		int cnt=0,t=0;
		for(int i=0;i<=m||t;i++){
			bit[i]+=t;
			t=bit[i]/2;
			bit[i]%=2;
			cnt+=bit[i];
		}
		if(cnt<=k){
			ans=(ans+ansnow)%mod;
		}
	}else{
		for(int i=0;i<=m;i++){
			a[x]=i;
			dfs(x+1);
		}
	}
	
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
