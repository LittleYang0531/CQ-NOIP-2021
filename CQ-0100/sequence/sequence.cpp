#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=105;
int n,m,K,v[N];
int seq[N],seqtot;
ll ans;
void dfs(int x,ll sum){
	if(x>n){
		int cnt=0;
		while(sum) cnt+=(sum&1),sum>>=1;
		if(cnt<=K){
			ll tmp=1;
			for(int i=1;i<=n;++i) (tmp*=v[seq[i]])%=mod;
			ans+=tmp;
			if(ans>mod) ans-=mod; 
		}
		return;
	}
	for(int i=0;i<=m;++i){
		seq[x]=i;
		dfs(x+1,sum+(1ll<<i));
		seq[x]=0;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	cin>>n>>m>>K;
	for(int i=0;i<=m;++i) cin>>v[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
