/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef long long LL;

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

const int MAXNM = 2e5, MAXQ = 1e5;
const int MOVE[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int n, m, q, lev[MAXNM + 5], clr[MAXNM + 5];
std::vector<char> row[MAXNM + 5], col[MAXNM + 5];

inline int id(const int i, const int j) { return (i - 1) * m + j; }
inline int type(const int i, const int j, const int k) {
	if (!k) return row[i - 1][j] - '0';
	else if (k == 1) return col[i][j - 1] - '0';
	else if (k == 2) return row[i][j] - '0';
	else return col[i][j] - '0';
}
inline bool inside(const int i, const int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

namespace Subtask123 {

int curt, ans, vist[MAXNM + 5], rst[MAXNM + 5];

inline void dfs(const int x, const int y, const int lv, const int cl) {
  	int u = id(x, y);
	if (vist[u] == curt) return ;
	if (lev[u] && (lev[u] > lv || clr[u] == cl)) return ;
	vist[id(x, y)] = curt, ans += rst[id(x, y)] != curt;
	if (lev[u]) return ;
	rep (i, 0, 3) {
		int tx = x + MOVE[i][0], ty = y + MOVE[i][1];
		if (inside(tx, ty) && type(x, y, i) == 3) {
			dfs(tx, ty, lv, cl);
		}
	}
}

inline void main() {
	rep (i, 1, n * m) lev[i] = clr[i] = vist[i] = rst[i] = 0;
	rep (i, 1, q) {
		int c = rint(), v = rint(), x = rint(), y = rint();
		++curt, ans = 0;
		
		rep (j, 0, 3) {
			int tx = x, ty = y;
			if (inside(x + MOVE[j][0], y + MOVE[j][1])
			  && type(x, y, j) == 1) {
				int u = id(x + MOVE[j][0], y + MOVE[j][1]);
				if (lev[u] && (lev[u] > v || clr[u] == c)) ;
				else ++ans, rst[u] = curt;
			}
			while (inside(tx + MOVE[j][0], ty + MOVE[j][1])
			  && type(tx, ty, j) == 2) {
				tx += MOVE[j][0], ty += MOVE[j][1];
				int u = id(tx, ty);
				if (lev[u] && (lev[u] > v || clr[u] == c)) break;
				++ans, rst[u] = curt;
				if (lev[u]) break;
			}
		}
		dfs(x, y, v, c);
		clr[id(x, y)] = c, lev[id(x, y)] = v;
		printf("%d\n", ans - 1);
	}
}

} // namespace Subtask123.

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);

	for (int T = rint(); T--;) {
		n = rint(), m = rint(), q = rint();
		
		bool sub3 = true;
		rep (i, 1, n) {
			col[i].resize(m + 1);
			rep (j, 1, m - 1) {
				char c = fgc();
				while (c < '0' || '4' < c) c = fgc();
				col[i][j] = c, sub3 &= c < '2';
			}
		}
		
		rep (i, 1, n - 1) {
			row[i].resize(m + 1);
			rep (j, 1, m) {
				char c = fgc();
				while (c < '0' || '4' < c) c = fgc();
				row[i][j] = c, sub3 &= c < '2';
			}
		}
		
		Subtask123::main();
	}
	return 0;
}

