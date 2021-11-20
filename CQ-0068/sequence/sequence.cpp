#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200, mod = 998244353;
int n, sum, m, k, v[N], njc, a[N], b[N];
int fac[N], inv[N];
int get(int s) {
  int cnt = 0;
  while(s) {
    if(s % 2 == 1) cnt++;
    s /= 2;
  }
  return cnt;
}
int pow2(int a,int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int c(int n,int m) {
  if(n == m) return 1;
  if(!m) return 1;
  if(!n) return 1;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void dfs(int x,int las) {
  if(x == n + 1) {
    int s = 0;
    for(int i = 1; i <= n; i++) s += pow2(2, a[i]);
    if(get(s) <= k) {
      int ab = 1;
      for(int i = 1; i <= m; i++) b[i] = 0;
      for(int i = 1; i <= n; i++) ab *= v[a[i]], ab %= mod, b[a[i]]++;
      int now = n, pt = 1;
      for(int i = 1; i <= m; i++) {
        pt = pt * c(now, b[i]) % mod;
        now -= b[i];
      }
      ab = ab * pt % mod;
      sum += ab % mod; sum %= mod;
    }
    return;
  }
  for(int i = las; i <= m; i++) {
    a[x] = i;
    dfs(x + 1, i);
  }
}
const int tttt = 1 << 20;
int f[tttt + 5], g[tttt + 5], tot, cc[65], bt[65], py;
int vis[tttt + 5], vib[tttt + 5];
signed main () {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  int ppp = k;
  for(int i = 0; i <= m; i++) cin >> v[i];
  fac[0] = 1;
  for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n] = pow2(fac[n], mod - 2);
  for(int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  if(n <= 8 && m <= 9) {
    dfs(1, 0);
    cout << sum % mod << "\n";
    return 0;
  }
  if(n == 5) {
    int s = 0, ans = 0;
    for(int i = 0; i <= m; i++) {
      for(int j = i; j <= m; j++) {
        for(int k = j; k <= m; k++) {
          for(int l = k; l <= m; l++) {
            for(int p = l; p <= m; p++) {
              s = pow2(2 ,i) + pow2(2, j) + pow2(2, k) + pow2(2, l) + pow2(2, m);
              if(get(s) > ppp) continue; 
              py = 0;
              cc[1] = i; cc[2] = j; cc[3] = k; cc[4] = l; cc[5] = p;
              for(int qq = 1; qq <= 5; qq++) {
                if(cc[qq] != cc[qq - 1]) py++;
                bt[py]++;
              }
              int now = 5, pt = 1;
              for(int qq = 1; qq <= 5; qq++) {
                pt = pt * c(now, bt[qq]) % mod;
                now -= bt[qq];
              }
              ans += v[i] * v[j] % mod * v[k] % mod * v[p] % mod * v[l] % mod * pt % mod;           
            }
          }
        }
      }
    }
    cout << ans << "\n";
    return 0;
  }
  int lim = (1 << (m)) * n + 1;
  for(int i = 0; i <= m; i++) {
    vib[pow2(2, i)] = 1;
    vis[pow2(2, i)] = i;
  }
  g[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < lim; j++) {
      for(int kr = 0; kr < j; kr++) {
        int val = j - kr;
        if(!vib[val]) continue;
        int now = vis[val];
        f[j] += g[kr] * v[now] % mod;
        f[j] = (f[j] + mod) % mod;
      }
    }
    for(int j = 0; j < lim; j++) {
      g[j] = f[j];
      f[j] = 0;
    }
  }
  int ans = 0;
  for(int j = 0; j < lim; j++) {
    if(get(j) <= k) ans += g[j], ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
/*
5 1 1
2 1
*/
/*
30 7 7
1 2 3 4 5 6 7 8
*/
