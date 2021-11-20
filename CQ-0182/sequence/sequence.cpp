#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define uint unsigned int
using namespace std;
const int Mod = 998244353, MAXN = 105;
int n, m, K, v[MAXN], dp[15][35][((1 << 13) + 5)];
int power[MAXN][MAXN], t, cnt, res, jc[MAXN], inv[MAXN];
int Qpow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) ans = (LL)ans * x % Mod;
		x = (LL)x * x % Mod;
	}
	return ans;
}
void Subtaskpts35() {
	dp[0][0][0] = 1;
	for(int i = 0; i <= m; i ++) {
		for(int j = 0; j <= n; j ++) {
			for(int k = 0; k <= n * (1 << m); k ++) {
				for(int p = 0; p <= j; p ++) {
					if(k - (1 << i) * p < 0) break;
				//	printf("")
					dp[i + 1][j][k] = (dp[i + 1][j][k] + (LL)dp[i][j - p][k - (1 << i) * p] * power[i][p] % Mod * inv[p % Mod]) % Mod;
				}
			}
		}
	}
	for(int i = 0; i <= n * (1 << m); i ++) {
		t = i; cnt = 0;
		while(t) {
			cnt += (t & 1); t >>= 1;
		}
		if(cnt <= K) res = (res + dp[m + 1][n][i]) % Mod;
	}
	res = (LL)res * jc[n] % Mod;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
//	printf("|%d|", 12 * (1 << 12) * 12 * 30 * 30);
	scanf("%d%d%d", &n, &m, &K); jc[0] = 1;
	for(int i = 1; i <= 100; i ++) jc[i] = (LL)jc[i - 1] * i % Mod;
	inv[100] = Qpow(jc[100], Mod - 2);
	for(int i = 99; i >= 0; i --) inv[i] = (LL)inv[i + 1] * (i + 1) % Mod;
	for(int i = 0; i <= m; i ++) scanf("%d", &v[i]);
	for(int i = 0; i <= m; i ++) {
		power[i][0] = 1;
		for(int j = 1; j <= n; j ++) power[i][j] = (LL)power[i][j - 1] * v[i] % Mod;
	}
//	if(m <= 10) {
		Subtaskpts35(); printf("%d", res); return 0;
//	}
	
	return 0;
}

