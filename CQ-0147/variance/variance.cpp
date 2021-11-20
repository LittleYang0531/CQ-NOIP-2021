#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;

const int maxn=30;
const int inf=0x3f3f3f3f;

int n;
int ans=inf;
vector<int> a;
int tp[maxn];
map<vector<int>,bool> mp;

int calc() {
	int s=0;
	for(int i=1; i<=n; i++) {
		s+=a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		ans+=(n*a[i]-s)*(n*a[i]-s);
	}
//	assert(ans%n==0);
	return ans/n;
}

void dfs() {
	if(1.0*clock()/CLOCKS_PER_SEC>0.85) {
		return ;
	}
//	vector<int> v;
//	for(int i=1;i<=n;i++) {
//		v.push_back(a[i]);
//	}
	if(mp[a]) {
		return ;
	}
	mp[a]=true;
	ans=min(ans,calc());
	for(int i=2; i<=n-1; i++) {
		if(a[i-1]+a[i+1]-a[i]!=a[i]) {
			int tp=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs();
			a[i]=tp;
		}
	}
}

signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	a.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs();
	cout<<ans<<"\n";
}
