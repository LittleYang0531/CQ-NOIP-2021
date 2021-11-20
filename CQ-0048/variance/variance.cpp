#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
using namespace std;
using ll=long long;
const int maxn=1e4;
int n,a[maxn+1];
ll ans;
vector<int> origin;
set<vector<int>> exist;
void dfs(vector<int> x){
	if(exist.count(x))return;
	exist.insert(x);
	loop(i,1,n-2){
		auto t=x;
		t[i]=t[i-1]+t[i+1]-t[i],dfs(t);
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin),freopen("variance.out","w",stdout);
	scanf("%d",&n),ans=LLONG_MAX;
	loop(i,1,n)scanf("%d",&a[i]),origin.push_back(a[i]);
	dfs(origin);
	for(auto a:exist){
		ll sum_1=0,sum_2=0;
		for(auto i:a)sum_1+=i,sum_2+=(ll)n*i*i;
		ans=min(ans,sum_2-sum_1*sum_1);
	}
	printf("%lld",ans);
	return 0;
}
