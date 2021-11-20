#include <cstdio>
#define int long long
#define reg register

const int mod = 998244353ll;
int v[105], dp[105][35][35][35], fact[105], inv[105], C[35][35];
inline void add(int &x, const int y) {
	if ((x += y) >= mod) x -= mod;
}
int qpow(int a, int b) {
	int ret = 1ll;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ret;
}

signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n, m, K;
	scanf("%lld%lld%lld", &n, &m, &K);
	++ m;
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i <= n; ++ i) inv[i] = qpow(fact[i] = fact[i - 1] * i % mod, mod - 2);
	for (int i = 0; i <= n; ++ i)
	for (int j = 0; j <= i; ++ j)
		C[i][j] = fact[i] * inv[i - j] % mod * inv[j] % mod;
	for (int i = 1; i <= m; ++ i) scanf("%lld", v + i);
	dp[0][0][0][0] = 1ll;
	for (reg int i = 0; i < m; ++ i)
	for (reg int j = 0; j <= n; ++ j)
	for (reg int k = 0; k <= j && k <= K; ++ k)
	for (reg int l = 0; l <= j; ++ l) if (dp[i][j][k][l])
	for (reg int x = 0, tmp = dp[i][j][k][l]; j + x <= n; ++ x, tmp = tmp * v[i + 1] % mod) {
		const int t = l / 2 + x;
		add(dp[i + 1][j + x][k + (t & 1)][t - (t & 1)], tmp * C[j + x][x] % mod);
	}
	int ans = 0;
	for (int i = 0; i <= K && i <= n; ++ i)
	for (int j = 0; j <= n; ++ j) {
		int cnt = 0;
		for (int k = 0; k <= 20; ++ k)
			if (j & 1 << k) ++ cnt;
		if (i + cnt <= K) add(ans, dp[m][n][i][j]);
	}
	printf("%lld", ans);
	return 0;
}
/*
I ball ball u
give me accepted
*/
