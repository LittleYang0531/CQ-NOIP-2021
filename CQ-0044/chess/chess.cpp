#include <bits/stdc++.h>
using namespace std;

#define r(i, j) for (int i = 1; i <= (j); ++i)
#define re(i, j, k) for (int i = (j); i <= (k); ++i)
#define rr(i, j) for (int i = (j); i >= 1; --i)
#define rre(i, j, k) for (int i = (k); i >= (j); --i)
#define forced [[gnu::always_inline]]

enum NodeStat {
	WHI = 0,
	HOR = 1,
	VER = 2,
	CON = 3,
	BLA = 4,
};

typedef pair<int, int> Pi;
const int maxn = 2e5 + 4;
const int maxq = 1e5 + 4;

int T, n, m, Q;

forced inline int npos(int x, int y) {
	return (x - 1) * m + y;
}
/*
namespace Midsc {
	
	const int maxp = maxn * 8;
	const int maxlog = 20;

	int rmvt[maxn];
	
	forced inline int pos(int x, int y, int st) {
		static int blast = n * m * 4;
		int ret = npos(x, y) * (st & 3);
		if (st & BLA) ret += blast;
		return ret;
	}
	
	struct SegI {
		int cnt[maxq * maxlog * 8], newp;
		int ch[maxq * maxlog * 8][2];
		int update(int k, int L, int R, int x) {
			int ret = ++newp;
			cnt[ret] = cnt[k];
			ch[ret][0] = ch[k][0], ch[ret][1] = ch[k][1];
			k = ret;
			if (L == R) ++cnt[k];
			else {
				int mid = (L + R) >> 1;
				if (x <= mid) ch[k][0] = update(ch[k][0], L, mid, x);
				else ch[k][1] = update(ch[k][1], mid + 1, R, x);
				cnt[k] = cnt[ch[k][0]] + cnt[ch[k][1]];
			}
			return k;
		}
		int merge(int k1, int k2, int L, int R) {
			if (!k1) return k2;
			if (!k2) return k1;
			int mid = (L + R) >> 1, k = ++newp;
			ch[k][0] = merge(ch[k1][0], ch[k2][0], L, mid);
			ch[k][1] = merge(ch[k1][1], ch[k2][1], L, mid);
			cnt[k] = cnt[ch[k][0]] + cnt[ch[k][1]];
			return k;
		}
	} seg1;
	
	struct Ufset {
		int root[maxp], fa[maxp], dep[maxp];
		int modstk[maxp * 2], stop;
		int proroot[maxp * 2], profa[maxp * 2];
		inline int top(int x) {
			while (fa[x] != x) x = fa[x];
			return x;
		}
		inline void record(int x) {
			modstk[++stop] = x;
			proroot[stop] = root[x];
			profa[stop] = fa[x];
		}
		inline void merge(int x, int y) {
			if (dep[x] < dep[y]) swap(x, y);
			x = top(x), y = top(y);
			record(x), record(y);
			fa[y] = x, root[x] = seg1.merge(root[x], root[y], 1, Q);
		}
		inline void undo(int) {
			int x = modstk[stop];
			root[x] = proroot[stop];
			fa[x] = profa[stop--];
		}
		inline void undo() {
			undo(114), undo(514);
		}
	};
	
	inline void deploy(const Pi& a) {
		
	}
	
	inline void undo() {
		
	}
	
	struct SegII {
		vector<Pi> dat[maxq * 4];
		void update(int k, int L, int R, int x, int y, Pi sd) {
			if (L > y || R < x) return;
			else if (L >= x && R <= y) dat[k].push_back(sd);
			else {
				int mid = (L + R) >> 1;
				if (y <= mid) update(k << 1, L, mid, x, y, sd);
				else if (x > mid) update(k << 1 | 1, mid + 1, R, x, y, sd);
				else update(k << 1, L, mid, x, y, sd), update(k << 1 | 1, mid + 1, R, x, y, sd);
			}
		}
		void surf(int k, int L, int R) {
			if (L == R) return launch(L), void();
			re (i, 0, (int)dat[k].size() - 1) deploy(dat[k][i]);
			int mid = (L + R) >> 1;
			surf(k << 1, L, mid);
			surf(k << 1 | 1, mid + 1, R);
			r (i, (int)dat[k].size()) undo();
		}
		inline void launch(int u) {
			
		}
	};

}
*/
namespace BruteForce {
	
	enum EDG_TYPE {
		NOR = 0,
		HOR = 1,
		VER = 2,
		CON = 3,
	};
	
	vector<int> edg[4][maxn];
	int vis[maxn], pnt[maxn], lvl[maxn];
	int ans, stk[maxn], top;
	
	void dfs(int x, int c, int p, int l) {
		if (pnt[x] == p) return;
		if (!vis[x] && lvl[x] <= l) ++ans;
		vis[x] = c, stk[++top] = x;
		if (lvl[x]) return;
		re (i, 0, (int)edg[c][x].size() - 1) {
			int v = edg[c][x][i];
			if (vis[v] != c) dfs(v, c, p, l);
		}
	}
	
	inline void con(int x, int y, int c) {
		edg[c][x].push_back(y);
		edg[c][y].push_back(x);
	}
	
	void init() {
		r (i, n * m) {
			re (j, 0, 3) edg[j][i].clear();
			lvl[i] = pnt[i] = 0;
		}
		r (i, n) {
			char c; int et;
			r (j, m - 1) {
				cin >> c;
				switch (c) {
					case '0': continue;
					case '1': et = NOR; break;
					case '2': et = HOR; break;
					case '3': et = CON; break;
				}
				con(npos(i, j), npos(i, j + 1), et);
			}
		}
		r (i, n - 1) {
			char c; int et;
			r (j, m) {
				cin >> c;
				switch (c) {
					case '0': continue;
					case '1': et = NOR; break;
					case '2': et = VER; break;
					case '3': et = CON; break;
				}
				con(npos(i, j), npos(i + 1, j), et);
			}
		}
	}
	
	void run() {
		init();
		r (i, Q) {
			int col, l, x, y, u; ans = 0;
			cin >> col >> l >> x >> y;
			u = npos(x, y), ++col;
			r (j, 3) dfs(u, j, col, l);
			re (i, 0, (int)edg[0][u].size() - 1) {
				int v = edg[0][u][i];
				if (pnt[v] != col && !vis[v] && lvl[v] <= l) ++ans;
			}
			while (top) vis[stk[top--]] = 0;
			lvl[u] = l, pnt[u] = col;
			cout << ans - 1 << endl;
		}
	}
	
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> Q;
		if (1ll * n * m * Q <= 6e7)
			BruteForce::run();
		else {
			BruteForce::run();
		}
	}
	return 0;
}
