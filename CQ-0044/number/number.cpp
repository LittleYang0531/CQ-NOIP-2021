#include <bits/stdc++.h>
using namespace std;

#define r(i, j) for (int i = 1; i <= (j); ++i)
#define re(i, j, k) for (int i = (j); i <= (k); ++i)
#define rr(i, j) for (int i = (j); i >= 1; --i)
#define rre(i, j, k) for (int i = (k); i >= (j); --i)

const int maxn = 1e7 + 4;

int T, n = 1e7;
int x, mark[maxn], nxt[maxn];

inline bool checkseven(int v) {
	while (v) {
		if (v % 10 == 7) return true;
		v /= 10;
	}
	return false;
}

inline void init() {
	r (i, n) {
		if (mark[i]) continue;
		mark[i] = checkseven(i);
		if (mark[i]) re (j, 2, n / i) {
			mark[j * i] = 1;
		}
	}
	nxt[n] = n + 1;
	rr (i, n - 1) {
		if (!mark[i + 1]) nxt[i] = i + 1;
		else nxt[i] = nxt[i + 1];
	}
}

inline void solve() {
	cin >> x;
	if (mark[x]) cout << -1 << endl;
	else cout << nxt[x] << endl;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	init();
	cin >> T;
	while (T--) solve();
	return 0;
}
