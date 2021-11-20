/*
n - 1 个能互换的空隙
俺可能确实不太适合OI，为什么这样都想这么久/kk
结果还是想不出来/ll
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10, M = 404;
int n, a[N], var[N], rev[N], ans;
int dp[M][M], now[N], st = 1;
inline int read() {
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch > '9') {if (ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
inline void dfs(int l, int r, int id) {
	if (id == n - 1) {
		int res = n * a[1] * a[1], ret = a[1];
		for (int i = 2; i <= n; ++i) {
			a[i] = a[i - 1] + now[i - 1];
			res += n * a[i] * a[i]; ret += a[i];
		}
		ret *= ret;
		ans = min(ans, res - ret);
		return ;
	}
	if (l != 1) {
		now[l - 1] = var[id + 1];
		dfs(l - 1, r, id + 1);
	}
	if (r != n) {
		now[r + 1] = var[id + 1];
		dfs(l, r + 1, id + 1);
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		if (a[i] != 1) var[i - 1] = a[i] - a[i - 1];
	}
	sort(var + 1, var + n);
	if (n <= 20) {
		int res, ret;
		ans = 1e9;
		for (int i = 1; i < n; ++i) rev[i] = i;
		do {
			res = n * a[1] * a[1]; ret = a[1];
			for (int i = 2; i <= n; ++i) {
				a[i] = a[i - 1] + var[rev[i - 1]];
				res += n * a[i] * a[i]; ret += a[i];
			}
			ret *= ret;
			ans = min(ans, res - ret);
		} while (next_permutation(rev + 1, rev + n));
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}
