#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int a[N],n,b[N];
bool mark[N];
ll ans=1e18;
void dfs(int u,ll sum,ll s1,ll s2) {
	if(u==n+1) {
//		printf("%lld\n",n*s1)
		ans=min(ans,n*s1-s2*s2);
		return;
	}
	for(int i=2;i<=n;i++) {
		if(mark[i])continue;
		mark[i]=1,sum+=b[i];
		dfs(u+1,sum,s1+sum*sum,s2+sum);
		mark[i]=0,sum-=b[i];
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i]-a[i-1];
	if(n<=10) {
		dfs(2,a[1],a[1]*a[1],a[1]);
		printf("%lld",ans);
	}
	else {
		ll s1=0,s2=0;
		for(int i=1;i<=n;i++) s1+=a[i],s2+=a[i]*a[i];
		printf("%lld\n",n*s2-s1*s1);
	}
	return 0;
}

