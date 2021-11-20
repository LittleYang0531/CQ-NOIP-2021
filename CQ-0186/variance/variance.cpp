#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int n;
bool vis[M];
long long ans,sum,a[M],c[M],b[M];
void dfs(int x,long long sum1,long long sum2,long long sum){
	if(x==n){
		ans=min(ans,sum2*1ll*n-sum1*sum1);
		return;
	}
	for(int i=1;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,sum1+sum+b[i],sum2+(sum+b[i])*(sum+b[i]),sum+b[i]);
			vis[i]=0;
		}
	}
}
/*bool check(node l,node r){
	if(n*(2*r.y-l.x+r.x)*(r.x-l.x)<2*sum+r.x-l.x){
		return 1;
	}
	return 0;
}*/
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ans=1e18;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i!=1){
			b[i-1]=a[i]-a[i-1];
		}
	}
	dfs(1,a[1],a[1]*a[1],a[1]);
	printf("%lld",ans);
	return 0;
}
