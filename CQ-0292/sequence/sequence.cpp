#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
#define il inline
#define fpr(s) freopen(s, "r", stdin)
#define fpw(s) freopen(s, "w", stdout)
using namespace std;
template <typename T>
il void read(T &x) {
   x = 0; T f = 1; char ch = getchar();
   while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
   while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
   x *= f;
}
const int N = 101 + 5, M = 30 + 5, mod = 998244353;
#define int long long //fuck ccf!!!!!!!!!!!!!!!!
int n, m, k, v[N], f[M][M], a[N];
int ans = 0; 
il int check(int x) {
	int sum = 0;
	while (x) {
		if (x % 2 == 1) ++sum;
		x /= 2;
	}
	return sum;
}
il void dfs(int step, int sum, int S) {
	if (step > n) {
		if (check(S) <= k) {
			ans += sum;
			if (ans >= 1e16) ans %= mod;
		}
		return ;
	}
	rep1(i, 1, m) {
		sum *= v[i]; a[step] = i - 1;
		dfs(step + 1, (sum >= 2e9 ? sum % mod : sum), S + (1 << a[step]));
		sum /= v[i]; 
	}
}
signed main(void) {
	fpr("sequence.in"); fpw("sequence.out");
	read(n); read(m); read(k); ++m;
	rep1(i, 1, m) read(v[i]);
	dfs(1, 1, 0);
	printf("%lld\n", ans % mod);
} //10·Ö±©Á¦ 
//STO sro C_Y_Y_H orz OTZ

//1h20min
