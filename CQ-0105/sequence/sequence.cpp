#include<bits/stdc++.h>

using namespace std;
int N,M,K;
int v[300];
int ans;
int MOD=998244353;
int fa[300];
void dfs(int now,int s,int val){
	if(now>N){
		int cnt=0;
		while(s){
			if((s&1)==1)
				cnt++;
			s=(s>>1);	
		}
		if(cnt<=K){
			ans=(ans+val)%MOD;
		}
		return ;	
	}
	
	for(int i=0;i<=M;i++){
		dfs(now+1,s+fa[i],val*v[i]);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>N>>M>>K;
	fa[0]=1;
	for(int i=1;i<=M;i++){
		fa[i]=fa[i-1]*2;
	}
	for(int i=0;i<=M;i++)
		cin>>v[i];
	dfs(1,0,1);
	cout<<ans;	
	return 0;
}
