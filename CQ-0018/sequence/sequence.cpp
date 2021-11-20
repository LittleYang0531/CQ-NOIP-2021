#include <bits/stdc++.h>
using namespace std;
template<typename T, typename G> inline
T& minimize(T& l, const G& r) {
  return l > r ? l = r : l;
}
template<typename T, typename G> inline
T& maximize(T& l, const G& r) {
  return l < r ? l = r : l;
}
constexpr int maxn = 31, maxm = 104, mods = 998244353;
int64_t v[maxm][maxn];
int f[maxm][maxn][maxn][maxn];
int binom[maxn][maxn];
int m;
int dp(int i, int j, int r, int a) {
  if (j < 0)
    return 0;
  if (i < 0)
    return r == 0 and __builtin_popcount(a) <= j;
  if (f[i][j][r][a] >= 0)
    return f[i][j][r][a];
  int64_t ans = 0;
  for (int k = 0; k <= r; ++k) {
    const int va = k + a;
    (ans += v[m - i][k] * binom[r][k] % mods * dp(i - 1, j - (va & 1), r - k, va >> 1)) %= mods;
  }
  return f[i][j][r][a] = ans;
}
int main() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(f, -1, sizeof(f));
  int n, k;
  cin >> n >> m >> k;
  for (int i = 0; i < maxn; ++i)
    binom[i][0] = 1;
  for (int i = 1; i < maxn; ++i)
    for (int j = 1; j < maxn; ++j)
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % mods;
  for (int i = 0; i <= m; ++i) {
    cin >> v[i][1];
    v[i][0] = 1;
    for (int j = 2; j < maxn; ++j)
      v[i][j] = v[i][j - 1] * v[i][1] % mods;
  }
  cout << dp(m, k, n, 0) << '\n';
  return 0;
}
