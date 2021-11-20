/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef long long LL;
typedef unsigned long long ULL;

inline char fgc() {
	static char buf[1 << 17], *p = buf, *q = buf;
	return p == q && (q = buf + fread(p = buf, 1, 1 << 17, stdin), p == q)
	  ? EOF : *p++;
}

//#ifdef RYBY
#define fgc getchar
//#endif

template <typename Tp = int>
inline Tp rint() {
	Tp x = 0, f = 1, s = fgc();
	for (; s < '0' || '9' < s; s = fgc()) f = s == '-' ? -f : f;
	for (; '0' <= s && s <= '9'; s = fgc()) x = x * 10 + (s ^ '0');
	return x * f;
}

template <typename Tp>
inline void wint(Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (9 < x) wint(x / 10);
	putchar(x % 10 ^ '0');
}

inline int imin(const int u, const int v) { return u < v ? u : v; }
inline int imax(const int u, const int v) { return u < v ? v : u; }
inline LL sqr(const int u) { return 1ll * u * u; }

const int MAXN = 1e4;
int n, a[MAXN + 5];

namespace Subtask12 {

int ans = 0x7ffffff;
std::vector<int> cur;
std::set<ULL> vis;

inline ULL hval() {
	static const ULL BASE = 127;
	ULL ret = 0;
	for (int u: cur) ret = ret * BASE + u;
	return ret;
}

inline void dfs(int sum, int sqr) {
	ULL t = hval();
	if (vis.find(t) != vis.end()) return ;
	vis.insert(t), ans = imin(ans, n * sqr - sum * sum);
	rep (i, 1, n - 2) {
		sum -= cur[i], sqr -= cur[i] * cur[i];
		cur[i] = cur[i - 1] + cur[i + 1] - cur[i];
		sum += cur[i], sqr += cur[i] * cur[i];
		dfs(sum, sqr);
		sum -= cur[i], sqr -= cur[i] * cur[i];
		cur[i] = cur[i - 1] + cur[i + 1] - cur[i];
		sum += cur[i], sqr += cur[i] * cur[i];
	}
}

inline void main() {
	int sum = 0, sqr = 0;
	std::vector<int> ori;
	rep (i, 1, n) sum += a[i], sqr += a[i] * a[i], cur.push_back(a[i]);
	dfs(sum, sqr);
	printf("%d\n", ans);
}

} // namespace Subtask12.

namespace SA {

LL ans, sum, sqr;

inline void sa() {
	std::mt19937 emt((ULL)sum ^ 20120712);
	std::uniform_int_distribution<> pdtr(2, n - 1);
	for (double T = 2012.0712; T > 1e-7; T *= 0.99712) {
		int i = pdtr(emt);
		sum -= a[i], sqr -= a[i] * a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		sum += a[i], sqr += a[i] * a[i];
		
		LL cur = sqr * n - sum * sum, de = cur - ans;
		if (de < 0) ans = cur;
		else if (exp(-de / T) * n > pdtr(emt)) {
			sum -= a[i], sqr -= a[i] * a[i];
			a[i] = a[i - 1] + a[i + 1] - a[i];
			sum += a[i], sqr += a[i] * a[i];
		}
	}
}

inline void main() {
	rep (i, 1, n) sum += a[i], sqr += a[i] * a[i];
	ans = sqr * n - sum * sum;
	rep (i, 1, 712) sa();
	printf("%lld\n", ans);
}

} // namespace SA.

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	n = rint();
	rep (i, 1, n) a[i] = rint();
	
	if (n <= 10) Subtask12::main();
	else SA::main();
	return 0;
}

