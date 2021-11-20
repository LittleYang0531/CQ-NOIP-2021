#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int T, nxt[maxn + 5];
bool vis[maxn + 5];
bool check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i = 1; i <= maxn; i++) {
		if(vis[i]) continue;
		if(check(i)) for(int j = 1; j <= maxn / i; j++) vis[i * j] = 1;
	}
	int p = maxn + 1;
	for(int i = maxn; i >= 1; i--) {
		nxt[i] = p;
		if(!vis[i]) p = i;
	}
	cin >> T;
	while(T--) {
		int x;
		cin >> x;
		if(vis[x]) cout << "-1\n";
		else cout << nxt[x] << '\n';
	}
	return 0;
}
