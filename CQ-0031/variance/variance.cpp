/*---And in that light,I find deliverance.---*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll mn=1e12;
int a[100000];
void dfs(int u,ll ans,ll sum){
	if(pow(n-2,u)>=1e7){
		mn=min(ans*n-sum*sum,mn);
		return ;
	}
	for(int i=2;i<n;++i){
		int tmp=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		if(a[i]!=tmp)
			dfs(u+1,ans-tmp*tmp+a[i]*a[i],sum-tmp+a[i]);
		a[i]=tmp;
	}
	return ;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ll sum=0,ans=0;
	for(int i=1;i<=n;++i) cin>>a[i],sum+=a[i],ans+=a[i]*a[i];
	dfs(0,ans,sum);
	cout<<mn<<'\n';
	return 0;
}
