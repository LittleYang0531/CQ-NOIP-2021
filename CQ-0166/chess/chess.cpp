#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define LL long long
#define ULL unsigned long long
#define PII pair <int, int>
#define MP(x,y) make_pair (x, y)
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define per(i,j,k) for (int i = (j); i >= (k); i--)

template <typename T> T Max (T x, T y) { return x > y ? x : y; }
template <typename T> T Min (T x, T y) { return x < y ? x : y; }
template <typename T> T Abs (T x) { return x > 0 ? x : -x; }
template <typename T>
void read (T &x) {
	T f = 1; x = 0;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == -1) f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar ();
	}
	x *= f;
}
int tp, Print_F[25];
template <typename T>
void write (T x) {
	if (x == 0) {
		putchar ('0');
		return;
	}
	if (x < 0) {
		putchar ('-');
		x = -x;
	}
	tp = 0;
	while (x) {
		Print_F[++tp] = x % 10;
		x /= 10;
	}
	while (tp) putchar (Print_F[tp--] + '0');
}
template <typename T>
void print (T x, char ch) {
	write (x); putchar (ch);
}

const int Maxn = 1e5;

int t, n, m, q;
vector <PII> a[Maxn + 5];
vector <bool> vis[Maxn + 5];
string r[Maxn + 5], c[Maxn + 5];

int tox[10] = { 1, -1, 0, 0 };
int toy[10] = { 0, 0, 1, -1 };
bool check (int x, int y) {
	if (x < 0 || x >= n) return 0;
	if (y < 0 || y >= m) return 0;
	return 1;
}
bool check (int i, int j, int op, int road_op) {
	if (op == 0) {
		if (check (i + 1, j) == 0 || c[i][j] - '0' != road_op) return 0;
		else return 1;
	}
	else if (op == 1) {
		if (check (i - 1, j) == 0 || c[i - 1][j] - '0' != road_op) return 0;
		else return 1;
	}
	else if (op == 2) {
		if (check (i, j + 1) == 0 || r[i][j] - '0' != road_op) return 0;
		else return 1;
	}
	else {
		if (check (i, j - 1) == 0 || r[i][j - 1] - '0' != road_op) return 0;
		else return 1;
	}
}
int eat (int col, int lv, int nx, int ny) {
	if (a[nx][ny] == MP (-1, -1)) return 2;
	else if (a[nx][ny].fi != col && a[nx][ny].se <= lv) return 1;
	else return 0;
}

int main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	
	read (t);
	while (t--) {
		read (n); read (m); read (q);
		for (int i = 0; i < n; i++) {
			a[i].resize (m + 5);
			vis[i].resize (m + 5);
			for (int j = 0; j < m + 5; j++) {
				a[i][j] = MP (-1, -1);
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) cin >> r[i];
		for (int i = 0; i < n - 1; i++) cin >> c[i];
		while (q--) {
			int col, lv, sx, sy; read (col); read (lv); read (sx); read (sy); sx--; sy--;
			
			set <PII> vis;
			queue <PII> q; q.push (MP (sx, sy)); 
			while (q.size ()) {
				PII tmp = q.front (); q.pop ();
				int x = tmp.fi, y = tmp.se;
				for (int op = 0; op < 4; op++) {
					int nx = x + tox[op], ny = y + toy[op];
					if (check (x, y, op, 3) == 0) continue;
					if (vis.find (MP (nx, ny)) != vis.end ()) continue;
					if (eat (col, lv, nx, ny) == 0) continue;
					vis.insert (MP (nx, ny)); 
					if (eat (col, lv, nx, ny) == 2) q.push (MP (nx, ny));
				}
			}
			a[sx][sy] = MP (col, lv);
			
			for (int op = 0; op < 4; op++) {
				int i = sx, j = sy;
				if (check (i, j, op, 1)) {
					int nx = i + tox[op], ny = j + toy[op];
					if (eat (col, lv, nx, ny) == 0) continue;
					i = nx; j = ny;
					vis.insert (PII (i, j));
				}
			}
			for (int op = 0; op < 4; op++) {
				int i = sx, j = sy;
				while (check (i, j, op, 2)) {
					int nx = i + tox[op], ny = j + toy[op];
					if (eat (col, lv, nx, ny) == 0) break;
					i = nx; j = ny;
					vis.insert (PII (i, j));
					if (eat (col, lv, nx, ny) == 1) break;
				}
			}
			vis.erase (MP (sx, sy));
			print (vis.size (), '\n');
		}
		
		rep (i, 1, n) {
			r[i].clear ();
			c[i].clear ();
			a[i].clear ();
			vis[i].clear ();
		}
	}
	return 0;
}
