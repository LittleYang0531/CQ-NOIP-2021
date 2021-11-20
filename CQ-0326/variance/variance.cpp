#include <iostream>
#include <cstdio>
using namespace std;
inline int rd() {
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int n,a[10005];
long long sum,ans;
void dfs(long long s,int a[],long long wans) {
//	printf("%d",wans);
	ans=min(ans,wans);
	for(int i=2; i<n; i++) {
		int x=a[i+1]+a[i-1]-(a[i]*2);
		if(a[i]*x*n*2+x*x*n-x*x-2*s*x<0) {
			int t=a[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			dfs(s+a[i]-t,a,wans+(t*2)*x*n+x*x*n-x*x-2*s*x);
			a[i]=t;
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=rd();
	for(int i=1; i<=n; i++) {
		a[i]=rd();
		sum+=a[i];
		ans+=a[i]*a[i];
	}
	ans*=n;
	ans-=sum*sum;
	dfs(sum,a,ans);
	printf("%d",ans);
	return 0;
}
