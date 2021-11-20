#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,a[N];
bool dp[1005][1005];
int ans=2147483647;
void dfs(int a2,int a3) {
	if (dp[a2][a3]) return;
	dp[a2][a3]=1;
	ans=min(ans,4*(a[1]*a[1]+a2*a2+a3*a3+a[4]*a[4])-(a[1]+a2+a3+a[4])*(a[1]+a2+a3+a[4]));
	dfs(a[1]+a3-a2,a3);
	dfs(a2,a[4]+a2-a3);
	return;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	if (n==1) {
		printf("0");
		return 0;
	} else if (n==2) {
		printf("0");
		return 0;
	} else if (n==3) {
		ans=3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]));
		printf("%d",ans);
	}
	dfs(a[2],a[3]);
	printf("%d",ans);
	return 0;
}
