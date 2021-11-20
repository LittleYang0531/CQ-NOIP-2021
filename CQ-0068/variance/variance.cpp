#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, lim, ans = INT_MAX, a[N], b[N], c[N], dt[N], id[N];
void dfs(int x) {
  if(x == lim + 1) {
    int sum = 0, ts = 0;
    for(int i = 1; i <= n; i++) c[i] = a[i] * n;
    for(int i = 1; i <= n; i++){
      if(b[i]) c[b[i]] = (c[b[i] + 1] + c[b[i] - 1] - c[b[i]]);
    }
    for(int i = 1; i <= n; i++) sum += c[i];
    sum = sum / n;
    for(int i = 1; i <= n; i++) {
      ts += (c[i] - sum) * (c[i] - sum);
    }
    ts = ts / n;
    ans = min(ans, ts);
    return;
  }
  for(int i = 2; i < n; i++) {
    b[x] = i;
    dfs(x + 1);
  }
  b[x] = 0;
  dfs(x + 1);
}
int getrand(int mod) {
  int x = rand();
  x = x * x % mod + rand() % mod;
  x = x + rand();
  x %= mod;
  x = rand();
  return x % mod + 1;
}
signed main() {
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
  srand(unsigned(time(0)));
  srand(rand());
  srand(rand() + rand());
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    dt[i] = a[i] * n;
  }
  if(n <= 4){
    lim = 11;
    dfs(1);
    cout << ans << "\n";
    return 0;
  }
  else {
    for(int i = 1; i <= n - 2; i++) id[i] = i + 1;
    for(int i = 1; i <= n - 4; i++) {
      int x = rand() % (n - 2) + 1;
      int y = rand() % (n - 2) + 1;
      swap(id[x], id[y]);
    }
    int cnt = 0;
    while(cnt <= 50000) {
      int pq = INT_MAX, gg = 0;
      for(int pos = 2; pos < n; pos++) {
        for(int i = 1; i <= n; i++) c[i] = dt[i];
        int val = c[pos + 1] + c[pos - 1] - c[pos];
        c[pos] = val;
        int sum = 0, ts = 0;
        for(int i = 1; i <= n; i++) sum += c[i];
        sum /= n;
        for(int i = 1; i <= n; i++) {
          ts += (c[i] - sum) * (c[i] - sum);
        }
        ts /= n;
        if(ts < ans) {
          ans = ts;
          gg = pos;
        }
      }
      if(!gg) gg = id[getrand(n - 2)]; 
      int val = dt[gg + 1] + dt[gg - 1] - dt[gg];
      dt[gg] = val;
      cnt++;
    }
    cout << ans << "\n";
    return 0;
  }
  return 0;
}
