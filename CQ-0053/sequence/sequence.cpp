/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

inline char fgc() {
	static char buf[1 << 17], *p = buf, *q = buf;
	return p == q && (q = buf + fread(p = buf, 1, 1 << 17, stdin), p == q)
	  ? EOF : *p++;
}

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

const int MAXN = 30, MAXM = 100, MOD = 998244353;
int N, M, K, val[MAXM + 5], bino[MAXN + 5][MAXN + 5];
int f[2][MAXN + 5][MAXN / 2 + 5][MAXN + 5];

inline int imin(const int u, const int v) { return u < v ? u : v; }
inline int mul(const int u, const int v) { return 1ll * u * v % MOD; }
inline void addeq(int& u, const int v) { (u += v) >= MOD && (u -= MOD); }
inline int add(int u, const int v) { return (u += v) < MOD ? u : u - MOD; }

inline void init() {
	bino[0][0] = 1;
	rep (i, 1, N) {
		bino[i][0] = 1;
		rep (j, 1, i) bino[i][j] = add(bino[i - 1][j - 1], bino[i - 1][j]);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	N = rint(), M = rint(), K = rint();
	rep (i, 0, M) val[i] = rint();
	init();
	
	int sta = 0; f[0][0][0][0] = 1;
	rep (i, 0, M) { // val[i].
		static int pwr[MAXN + 5]; pwr[0] = 1;
		rep (j, 1, N) pwr[j] = mul(pwr[j - 1], val[i]);
	
		rep (j, 0, N) { // j a used.
			rep (k, 0, j >> 1) { // up digits.
				rep (t, 0, imin(j, K)) { // t 1.
					int& cur = f[sta][j][k][t];
					if (!cur) continue;
					rep (c, 0, N - j) {
						addeq(f[!sta][j + c][k + c >> 1][t + (k + c & 1)],
						  mul(cur, mul(pwr[c], bino[j + c][c])));
					}
					cur = 0;
				}
			}
		}
		sta ^= 1;
	}
	
	int ans = 0;
	rep (i, 0, N >> 1) {
		rep (j, 0, N) {
			if (j + __builtin_popcount(i) <= K) {
				addeq(ans, f[sta][N][i][j]);
			}
		}
	}
	wint(ans), putchar('\n');
	return 0;
}

