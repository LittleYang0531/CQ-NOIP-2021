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
const int N = 3e3 + 5, inf = 0x3f3f3f3f;
int t, n, m, q, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; char l[N][N], r[N][N];
bool vis[N][N];
struct node {int col, lv;} a[N][N];
il int dfs(int x, int y, char lop, int li, bool hl, int ncl, int nlv) {
	int mcnt = 0;
//	cout << x << ' '<< y << ' ' << a[x][y].col << endl;
	if (a[x][y].col != -1) {
		if (ncl == a[x][y].col) return 0;
		if (ncl != a[x][y].col && nlv >= a[x][y].lv) return 1;
		else if (ncl != a[x][y].col) return 0;
	}
	rep1(i, 0, 3) {
		int nx = x + dx[i], ny = dy[i] + y;
		if (nx && ny && nx <= n && ny <= m) {
			char opt;
			if (!i) opt = l[x][y];
			else if (i == 1) opt = l[x][y - 1];
			else if (i == 2) opt = r[x - 1][y];
			else if (i == 3) opt = r[x][y];
			if (!vis[nx][ny] && opt != '0' && (lop == opt || lop == ' ')) {
				if (lop != '3' && i != li && li != 114514) continue;
				if (opt == '1' && hl) continue;
				vis[nx][ny] = 1; 
				mcnt += dfs(nx, ny, opt, i, (opt == '1') | hl, ncl, nlv);
			}
		}
	}
	return mcnt + 1;
}
signed main(void) {
	fpr("chess.in"); fpw("chess.out");
	read(t);
	while (t--) {
		read(n); read(m); read(q); 
		rep1(i, 1, n) scanf("%s", l[i] + 1);
		rep1(i, 1, n - 1) scanf("%s", r[i] + 1);
		rep1(i, 1, n) rep1(j, 1, m) a[i][j] = (node) {-1, 114514};
		while (q--) {
			memset(vis, 0, sizeof vis);
			int x, y, col, lv; read(col); read(lv); read(x); read(y);
			vis[x][y] = 1;
			printf("%d\n", dfs(x, y, ' ', 114514, 0, col, lv) - 1);
			a[x][y] = (node) {col, lv};
		}
	}
} //20~24 ·Ö±©Á¦ 
// STO sro cool_milo orz OTZ

//1h
