#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
	return x;
}

int n, m, k, buc[110], a[35];
ll ans, v[105];

inline void dfs(int now) {
	if (now == n + 1) {
		for (int i = 1; i <= n; i++) buc[a[i]]++;
		for (int i = 0; i <= m + 8; i++) buc[i + 1] += buc[i] / 2, buc[i] &= 1;
		int cnt = 0;
		for (int i = 0; i <= m + 8; i++) cnt += buc[i], buc[i] = 0;
		if (cnt <= k) {
			ll w = 1;
			for (int i = 1; i <= n; i++) w = w * v[a[i]] % mod;
			ans = (ans + w) % mod;
		}
		return;
	}
	for (int i = 0; i <= m; i++) a[now] = i, dfs(now + 1);
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 0; i <= m; i++) v[i] = 1ll * read();
	dfs(1);
	printf("%lld", ans);
	return 0;
}
