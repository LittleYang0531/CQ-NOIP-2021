#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=998244353;
const int M=1e2+10;
const int N=1<<13;
int k,n,m;
ll v[M],vis[M],ans;
int vis3[N+5],a[M],vis4[M];
ll jc[M];
void dfs(int x,int y){
	if(x==n+1){
		for(int i=0;i<=m;i++){
			vis4[i]=0;
		}
		ll s=0;
		for(int i=1;i<=n;i++){
			s+=vis[a[i]];
			vis4[a[i]]++;
		}
		if(!vis3[s])return;
		ll ss=jc[n];
		for(int i=0;i<=m;i++){
			ss/=jc[vis4[i]];
		}
		ll v2=1;
		for(int i=1;i<=n;i++){
			v2*=v[a[i]];
			v2%=P;
		}
		ss%=P;
		v2%=P;
		ans+=(ss*v2%P);
		ans%=P;
		return;
	}
	for(int i=y;i<=m;i++){
		a[x]=i;
		x++;
		dfs(x,i);
		x--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	vis[0]=1;
	for(int i=1;i<=m;i++){
		vis[i]=vis[i-1]*2;
	}
	ll vis2=vis[m]*n;
	for(int i=n;i<=vis2;i++){
		int x=i,cnt=0;
		for(int j=14;j>=0;j--){
			if((x>>j)&1){
				cnt++;
			}
		}
		if(cnt<=k){
			vis3[i]=1;
		}
	}
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i;
	}
	dfs(1,0);
	printf("%lld",ans%P);
	return 0;
}
