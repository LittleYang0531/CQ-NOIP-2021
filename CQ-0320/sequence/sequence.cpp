#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,k,l,r,b,v[505],a[100005];
int C(int n1,int m1) {
	int c=1;
	for(int i=n1; i>=n1-m1+1; i--)c=c*i%p;
	for(int i=m1; i>=m1-m1+1; i--)c=c/i%p;
	return c%p;
}
bool check(int x) {
	int tx=x,ans=0;
	while(tx!=0) {
		int y=tx%2;
		tx/=2;
		if(y==1)ans++;
		if(ans>k)return 0;
	}
	return 1;
}
bool dfs(int x,int goal,int sum) {
	if(x==n+1) {
		if(sum==goal)return 1;
		return 0;
	}
	for(int i=0; i<=m; i++) {
		if(pow(2,i)>goal-sum)continue;
		a[i]++;
		if(dfs(x+1,goal,sum+pow(2,i)))return 1;
		a[i]--;
	}
	return 0;
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	l=n;
	r=n*pow(2,m);
	for(int i=0; i<=m; i++)scanf("%lld",&v[i]);
	for(int i=l; i<=r; i++) {
		int sum=1;
		memset(a,0,sizeof(a));
		if(dfs(1,i,0)==0)continue;
		if(check(i)) {
			int t=0;
			for(int j=0; j<=m; j++) {
				if(a[j]==0)continue;
				t++;
				for(int k=1; k<=a[j]; k++)sum=sum*v[j]%p;
			}
			b+=sum*C(n,t)%p;
		}
	}
	printf("%lld\n",b);
	return 0;
}
