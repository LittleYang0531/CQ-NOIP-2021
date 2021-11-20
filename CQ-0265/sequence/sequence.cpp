#include<bits/stdc++.h>
using namespace std;
#define maxn 100
#define maxm 200
long long n,m,k,v[maxn],two[maxm],tow[maxm],ans[maxn],sum;
void dfs(long long x);
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	dfs(1);
	printf("%lld",sum%998244353);
	cout<<sum%998244353;
	return 0;
}
void dfs(long long x){
	if(x==n+1){
		for(long long i=0;i<=m+20;i++){
			tow[i]=two[i];
		}
		long long many=0;
		for(long long i=0;i<=m+20;i++){
			if(tow[i]%2==1){
				many++;
			}
			tow[i+1]+=tow[i]/2;
		}
		if(many<=k){
			long long j=1;
			for(long long i=1;i<=n;i++){
				j=(j%998244353)*(v[ans[i]]%998244353)%998244353;
			}
			sum=(sum%998244353+j%998244353)%998244353;
		}
		return;
	}
	for(long long i=0;i<=m;i++){
		two[i]++,ans[x]=i;
		dfs(x+1);
		two[i]--;
	}
}
