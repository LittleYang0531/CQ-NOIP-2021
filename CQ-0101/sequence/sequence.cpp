#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,M=200;
int n,cnt,k,m;
ll ans;
ll a[M],v[M];
void dfs(int s){
	if(s>n){
		ll num=0,t=0;
		for(int i=1;i<=cnt;i++)num+=(1ll<<a[i]);
		while(num){
			if(num&1)t++;
			num>>=1;
		}
		if(t<=k){		
			ans++;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		a[++cnt]=i,dfs(s+1);
		cnt--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	dfs(1);
	//for(int i=1;i<=n;i++)cout<<
	cout<<ans;
	return 0;
}
