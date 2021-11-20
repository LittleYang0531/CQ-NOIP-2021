//CJG生日快乐
//CJG一战成冥
//CJGYYDS 
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 30
#define MAXM 100
#define INF 998244353

long long s[MAXM + 5];
long long dp[MAXM + 5][MAXN + 5][MAXN + 5][MAXN + 5];
long long fac[MAXN + 5], inv_fac[MAXN + 5];

long long Pow (long long a, int b) {
	long long ans = 1;
	
	while (b) {
		if (b & 1) {
			ans *= a;
			ans %= INF;
		}
		a *= a;
		a %= INF;
		b >>= 1;
	}
	
	return ans;
}

long long C(int n, int m) {
	return fac[n] * inv_fac[m] % INF * inv_fac[n - m] % INF;
}
int f (int x) {
	int ans = 0;
	
	while (x) {
		ans += (x & 1);
		x >>= 1;
	}
	
	return ans;
}

int main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	int n, m, K;
	
	scanf ("%d %d %d", &n, &m, &K);
	m ++;
	for (int i = 1; i <= m; i ++) {
		scanf ("%lld", &s[i]);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i ++) {
		fac[i] = fac[i - 1] * i % INF;
	}
	inv_fac[n] = Pow (fac[n], INF - 2);
	for (int i = n - 1; i >= 0; i --) {
		inv_fac[i] = inv_fac[i + 1] * (i + 1) % INF;
	}
	dp[0][0][0][0] = 1;
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j <= K; j ++) {
			for (int k = 0; k <= n; k ++) {
				for (int l = 0; l <= n; l ++) {
					long long Powr = 1;
					
					for (int r = 0; r <= k; r ++) {
						Powr %= INF;
						if ((l & 1) == (r & 1)) {
							dp[i][j][k][(l + r) >> 1] += dp[i - 1][j][k - r][l] * C(n - (k - r), r) % INF * Powr % INF;
							dp[i][j][k][(l + r) >> 1] %= INF;
						}
						else {
							if (j > 0) {
								dp[i][j][k][(l + r) >> 1] += dp[i - 1][j - 1][k - r][l] * C(n - (k - r), r) % INF * Powr % INF;
								dp[i][j][k][(l + r) >> 1] %= INF;
							}
						}
						Powr *= s[i];
					}
				}
			}
		}
	}
	
	long long ans = 0;
	
	for (int i = 0; i <= K; i ++) {
		for (int j = 0; j <= n; j ++) {
			if (f (j) + i <= K) {
				ans += dp[m][i][n][j];
				ans %= INF;
			}
		}
	}
	printf ("%lld", ans);
	
	return 0;
}
