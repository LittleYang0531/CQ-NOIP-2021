#include <map>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXM = 1 << 15;
const int MOD = 998244353;
int n, m, k, tot;
int dp[2][31][MAXM];
int c[105][105];
void Init() {
	c[0][0] = 1;
	for (int i = 1; i <= 100; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	Init();
	scanf("%d %d %d", &n, &m, &k);
	dp[0][0][0] = 1;
	for (int i = 0, a; i <= m; i++) {
		scanf("%d", &a);
		for (int w = 0; w <= n; w++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k < (1 << 15); k++) {
					dp[(i + 1) & 1][j][k] = 0;
				}
			}
		}
		int noww = 0, ad = (1 << i);
		int nowv = 1;
		for (int w = 0; w <= n; w++) {
			for (int j = 0; j <= n - w; j++) {
				for (int k = 0; k < (1 << 15); k++) {
					dp[(i + 1) & 1][j + w][k + noww] = (1LL * dp[i & 1][j][k] * nowv % MOD * c[n - j][w] % MOD + dp[(i + 1) & 1][j + w][k + noww]) % MOD;
				}
			}
			nowv = 1LL * nowv * a % MOD;
			noww += ad;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 17); i++) {
		int tmp = 0;
		for (int j = 0; j < 17; j++) {
			if ((i >> j) & 1) tmp++;
		}
		if (tmp > k) continue;
		ans = (ans + dp[(m + 1) & 1][n][i]) % MOD;
	}
	printf("%d", ans);
	return 0;
}
