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
constexpr int maxn = 1e7 + 64;
bool p[maxn];
int nxt[maxn];
inline bool check7(int x) {
  while (x) {
    if (x % 10 == 7)
      return true;
    x /= 10;
  }
  return false;
}
int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 1; i < maxn; ++i) {
    if (p[i])
      continue;
    if (check7(i)) {
      for (int j = i; j < maxn; j += i) {
        p[j] = true;
      }
    }
  }
  int la = maxn;
  for (int i = maxn - 1; i; --i) {
    nxt[i] = la;
    if (not p[i])
      la = i;
  }
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    if (p[x]) {
      cout << -1 << '\n';
    } else {
      cout << nxt[x] << '\n';
    }
  }
  return 0;
}
