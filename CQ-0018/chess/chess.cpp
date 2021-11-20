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
constexpr int maxn = 2e5 + 4;
struct ufset {
  int par[maxn];
  int sz[maxn];
  inline void clear() {
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
  }
  int getpar(int x) {
    return x == par[x] ? x : par[x] = getpar(par[x]);
  }
  inline void merge(int a, int b) {
    a = getpar(a);
    b = getpar(b);
    if (sz[a] < sz[b])
      swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
  }
};
vector<pair<int, int>> verts[maxn];
int n, m;
inline int encode(int x, int y) {
  return (x - 1) * m + y - 1;
}
inline pair<int, int> decode(int v) {
  return make_pair(v / m + 1, v % m + 1);
}
bool vis[maxn][5];
int col[maxn];
int lv[maxn];
int main() {
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  stack<pair<int, int>> que;
  while (T--) {
    int q;
    cin >> n >> m >> q;
    const int nm = n * m;
    fill(verts, verts + nm, vector<pair<int, int>>());
    memset(lv, 0, sizeof(lv));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < m; ++j) {
        char c;
        cin >> c;
        const int u = encode(i, j), v = u + 1;
        if (c != '0') {
          verts[u].emplace_back(v, c - '0');
          verts[v].emplace_back(u, c - '0');
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= m; ++j) {
        char c;
        cin >> c;
        const int u = encode(i, j), v = encode(i + 1, j);
        if (c != '0') {
          verts[u].emplace_back(v, c == '2' ? 4 : c - '0');
          verts[v].emplace_back(u, c == '2' ? 4 : c - '0');
        }
      }
    }
    for (int i = 1; i <= q; ++i) {
      int c, l, x, y;
      cin >> c >> l >> x >> y;
      const int d = encode(x, y);
      col[d] = c;
      lv[d] = l;
      set<int> cnt;
      memset(vis, 0, sizeof(vis));
      for (auto p : verts[d]) {
        que.emplace(p.second, p.first);
      }
      while (not que.empty()) {
        const int op = que.top().first, u = que.top().second;
        que.pop();
        if (vis[u][op] or (lv[u] and col[u] == col[d]) or l < lv[u])
          continue;
        vis[u][op] = true;
        cnt.emplace(u);
        if (lv[u])
          continue;
        for (auto p : verts[u]) {
          if (p.second != op or op == 1)
            continue;
          que.emplace(op, p.first);
        }
      }
      cnt.erase(d);
//      for (int v : cnt)
//        cout << decode(v).first << ' ' << decode(v).second << '\n';
      cout << cnt.size() << '\n';
    }
  }
  return 0;
}
