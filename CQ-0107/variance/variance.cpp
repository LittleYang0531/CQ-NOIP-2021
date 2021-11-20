#include<bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
using namespace std;
int N,ans;
int a[10010];
int get() {
	int sum=0,sum2=0;
	for (int i=1;i<=N;i++) sum+=a[i],sum2+=a[i]*a[i];
	return N*sum2-sum*sum;
}
void sub1() {
	if (N<=2) return;
	if (N==3) {
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,get());
		return;
	}
	for (int i=1;i<=40;i++) {
		if (i%2) a[2]=a[1]+a[3]-a[2],ans=min(ans,get());
		else a[3]=a[2]+a[4]-a[3],ans=min(ans,get());
	}
	return;
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>N;
	for (int i=1;i<=N;i++) scanf("%lld",&a[i]);
	ans=get();
	if (N<=4) sub1();
	cout<<ans<<endl;
	return 0;
}
