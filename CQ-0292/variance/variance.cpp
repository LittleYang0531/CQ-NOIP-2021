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
const int N = 1e4 + 5, inf = 0x3f3f3f3f;
long long ans = 0;
int n, a[N], b[N], sum;
map <long long, int> cnt;
il void dfs(int last, int llast) {
	long long s = 0;
	rep1(i, 1, n) s += pow((1LL * a[i] * n - sum), 2);
	s /= n;
	++cnt[s];
	if (s == llast) return ;
	if (cnt[s] >= 3) return ;
	ans = min(ans, s);
	rep1(i, 2, n - 1) {
		if ((a[i + 1] + a[i - 1] - a[i]) ^ a[i]) {
			sum -= a[i]; sum += a[i + 1] + a[i - 1] - a[i]; int t = a[i];
			a[i] = a[i + 1] + a[i - 1] - a[i];
			dfs(s, last);
			sum += t; sum -= a[i]; a[i] = t;
		}
	}
}
signed main(void) {
	fpr("variance.in"); fpw("variance.out");
	read(n); 
	rep1(i, 1, n) read(a[i]), sum += a[i];
	ans = 0x3f3f3f3f3f3f3fLL;
	dfs(1145141919, 1145141919);
	printf("%lld\n", ans);
} //48·Ö±©Á¦ 
//STO sro liangruichen orz OTZ 

//40min
