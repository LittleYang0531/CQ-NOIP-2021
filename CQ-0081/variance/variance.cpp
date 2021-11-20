#include<bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
int n,a[N];
ll ans=1ll<<60,ans0,sum;
void Dfs(ll ans0,ll sum) {
	ans=min(ans,ans0);
	for(int i=2; i<n; ++i) {
		ll t1=1ll*n*(a[i-1]+a[i+1]-2*a[i]),tmp=a[i];
		ll t2=2*a[i]-2*sum+(n-1ll)*a[i-1]+(n-1ll)*a[i+1];
		if(t1*t2<0) {
			a[i]=a[i-1]+a[i+1]-a[i];
			Dfs(ans0+t2*t1,sum+a[i]-tmp);
			a[i]=tmp;
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)scanf("%d",&a[i]),sum+=a[i];
	for(int i=1; i<=n; ++i)ans0+=1ll*(n*a[i]-sum)*(n*a[i]-sum);
	Dfs(ans0,sum),cout<<ans/n;
	return 0;
}
