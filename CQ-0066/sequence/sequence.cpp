#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n, m, limit;
ll v[105], ans;
ll dp[105][35][35][35], power[105][35], fac[205], inv[205];
void dfs(int x, ll sum, ll res) {
	if(x == n + 1) {
		if(__builtin_popcount(sum) <= limit) ans = (ans + res) % mod;
		return;
	}
	for(int i = 0; i <= m; i++) dfs(x + 1, sum + (1ll << i), res * v[i] % mod);
}
ll ksm(ll x, ll y) {
	ll res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;
		x = x * x % mod, y >>= 1;
	}
	return res;
}
ll binom(ll x, ll y) {
	return fac[x] * inv[x - y] % mod * inv[y] % mod;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> limit;
	for(int i = 0; i <= m; i++) cin >> v[i];
	if(n <= 8 && m <= 9) {
		dfs(1, 0, 1);
		cout << ans << '\n';
		return 0;
	}
	for(int i = (fac[0] = 1); i <= 200; i++) fac[i] = fac[i - 1] * i % mod;
	inv[200] = ksm(fac[200], mod - 2);
	for(int i = 199; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	for(int i = 0; i <= m; i++)
	for(int j = (power[i][0] = 1); j <= n; j++) power[i][j] = power[i][j - 1] * v[i] % mod;
	for(int j = 0; j <= n; j++) if(__builtin_popcount(j) <= limit) dp[0][j][j][__builtin_popcount(j)] = power[0][j];
	for(int i = 0; i < m; i++)
	for(int j = 0; j <= n; j++)
	for(int x = 0; x < 32; x++)
	for(int s = 0; s <= limit; s++) {
		if(!dp[i][j][x][s]) continue;
		for(int k = 0; k <= n; k++) {
			if(j + k > n || s + k > n) continue;
			int tos = s - __builtin_popcount(x) + __builtin_popcount((x >> 1) + k) + (x & 1);
			if(tos > limit) continue;
			(dp[i + 1][j + k][(x >> 1) + k][tos] += (dp[i][j][x][s] * power[i + 1][k] % mod * binom(j + k, j) % mod) % mod) %= mod;
		}		
	}
	for(int x = 0; x < 32; x++)
	for(int s = 0; s <= limit; s++)
		ans = (ans + dp[m][n][x][s]) % mod;
	cout << ans << '\n';
	return 0;
}
