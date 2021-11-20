#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 999, M = 2e6;
int T, n, vib[N], vis[N], pr[M], a[N], num, tot;
int get(int x) {
  int u = x;
  while(u) {
    if(u % 10 == 7) return true;
    u /= 10;
  }
  return false;
}
void pre(int n) {
  for(int i = 1; i <= n; i++) {
    if(get(i)) vib[i] = 1;
  }
}
void factor(int n) {
  for(int i = 1; i <= n; i++) {
    int x = i;
    for(int j = 1; j <= n / x; j++) {
      vib[x * j] |= vib[x];
    }
  }
}
signed main () {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> T;
  int mx = 0;
  for(int i = 1; i <= T; i++) {
    cin >> pr[i];
    mx = max(mx, pr[i]);
  }
  if(mx <= 2e5) {
    pre(2e5 + 50);
    factor(2e5 + 50);
    int t = 2e5 + 50;
    for(int i = 1; i <= t; i++) {
      if(!vib[i]){
        a[++num] = i;
      }
    }
    for(int i = 1; i <= T; i++) {
      int now = pr[i];
      if(vib[now]) {
        cout << "-1\n";
      }  else{
        int ans = upper_bound(a + 1, a + num + 1, now) - a;
        cout << a[ans] << "\n";
      }
    }
  }  else{
    int t = 1e7 + 1;
    t = min(t, mx + 120);
    pre(t);
    for(int i = 1; i <= t; i++) if(vib[i]) a[++num] = i;
    for(int i = 1; i <= num; i++) {
      int x = a[i];
      for(int j = 1; j <= t / x; j++) vib[j * x] |= vib[x];
    }
    num = 0;
    for(int i = 1; i <= t; i++) if(!vib[i]) a[++num] = i;
    for(int i = 1; i <= T; i++) {
      int x = pr[i];
      if(vib[x]) cout << "-1\n";
      else {
        int ans = upper_bound(a + 1, a + num + 1, x) - a;
        cout << a[ans] << "\n";
      }
    }
  }
  return 0;
}
/*
1
6314263
*/
