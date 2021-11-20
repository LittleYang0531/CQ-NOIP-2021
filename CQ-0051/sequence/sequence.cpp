#include <iostream>
#include <cstdio>
const int nn = 35, mm = 105;
const int mod = 998244353;
int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}
int mul(int a, int b) {
	return 1ll * a * b % mod;
}
int C[nn][nn], v[mm][nn], cnt[nn];
int f[mm][mm][nn][nn], n, m, k;
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; i++) {
		scanf("%d", v[i] + 1); v[i][0] = 1;
		for (int j = 2; j <= n; j++) {
			v[i][j] = mul(v[i][j - 1], v[i][1]);
		}
	}
	C[0][0] = 1; cnt[0] = 0;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1; cnt[i] = cnt[i >> 1] + (i & 1);
		for (int j = 1; j <= n; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	f[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= n; k++) {
				for (int l = 0; l <= n; l++) {
					if (!f[i][j][k][l]) continue;
					for (int s = 0; s <= n - l; s++) {
						int ii = i + 1, jj = j + (k + s & 1), kk = k + s >> 1, ll = l + s;
						f[ii][jj][kk][ll] = add(f[ii][jj][kk][ll], mul(f[i][j][k][l], mul(C[n - l][s], v[i][s])));
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k - cnt[i]; j++)
			ans = add(ans, f[m + 1][j][i][n]);
	printf("%d", ans);
	return 0;
}
