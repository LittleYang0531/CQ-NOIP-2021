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
// n sigma2 - sigma^2
#define int int64_t
constexpr int maxn = 1e4 + 4;
int a[maxn];
int n;
inline int delta(int i) {
  return a[i] + a[i + 2] - 2 * a[i + 1];
}
inline int p2(int x) {
  return x * x;
}
int sigma;
inline bool comp(int i) {
  return ((2 * a[i + 1] * n - 2 * sigma) * delta(i) + (n - 1) * p2(delta(i)) < 0);
}
int32_t main() {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], sigma += a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = n - 2; j >= 1; --j) {
      if (comp(j)) {
        sigma += delta(j);
        a[j + 1] += delta(j);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += p2(a[i]);
  }
  ans *= n;
  ans -= p2(sigma);
  cout << ans << '\n';
  return 0;
}
