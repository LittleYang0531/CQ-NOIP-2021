#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define ll int
#define MA 10004 
inline void rd(ll &x) {ll f=0;int p=1;char c=getchar();while(!isdigit(c)) {if(c=='-')p=0;c=getchar();}while(isdigit(c)) {f=(f<<1)+(f<<3)+(c^48);c=getchar();}if(p) x=f;else x=-f;return;}
ll n;
ll a[MA],as[MA];
#define aj a[j-1]+a[j+1]
int tot=0;
inline void print() {
	ll i;
	for(i=1;i<=n;++i)
		printf("%lld ",a[i]);
	puts("");
	printf("as=%lld\n",as[tot]);
}
inline ll ping(ll x) {
	return x*x;
}
bool check(int j) {
	if(n*( aj-2*a[j] )*( aj ) -2*(aj-2*a[j])*a[0]-ping(aj-2*a[j])<0)
		return 1;
	return 0;
}
inline void dfs(int now,ll pw,ll he) {//到第几个了 
	if(now==n) {
		as[++tot]=(pw+ping(a[now]))*n-ping(he+a[now]);
//		printf("%lld %lld\n",pw,he);
//		print();
		return;
	}
	int i;
	bool p=0;
	for(i=1;i<=6;++i) {
		dfs(now+1,pw+ping(a[now]),he+a[now]);
		if(p==0) {
			p=1;
			if(!check(now))
				continue;
			a[now]=a[now-1]+a[now+1]-a[now];
		}
		else if(now!=n-1){
			p=0;
			if(!check(now+1))
				continue;
			a[now+1]=a[now]+a[now+2]-a[now+1];
		}
	}
	return;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
//	scanf("%d",&n);
	rd(n);
	int i;
	a[0]=(ll)0;
	for(i=1;i<=n;++i) {
		rd(a[i]);
//		scanf("%lld",&a[i]);
		a[0]+=a[i];
	}
	dfs(2,ping(a[1]),a[1]);
	ll ans=1e18;
	for(i=1;i<=tot;++i) {
		ans=min(as[i],ans);
	}
	printf("%lld\n",ans);
	return 0;
}
