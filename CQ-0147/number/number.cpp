#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;

const int maxn=10000005;
const int inf=0x3f3f3f3f;

int b[maxn];
bool vis[maxn];

bool check(int x) {
	while(x) {
		if(x%10==7) {
			return true;
		}
		x/=10;
	}
	return false;
}

void prepare(int n) {
	for(int i=1; i<=n; i++) {
		if(check(i)) {
			for(int j=i; j<=n; j+=i) {
				vis[j]=true;
			}
		}
	}
	int lst=n;
	for(int i=n; i>=1; i--) {
		if(!vis[i]) {
			lst=i;
		}
		b[i]=lst;
	}
}

signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	prepare(1e7+1);
	while(T--) {
		int x;
		cin>>x;
		if(vis[x]) {
			cout<<"-1\n";
		} else {
			cout<<b[x+1]<<"\n";
		}
	}
}
