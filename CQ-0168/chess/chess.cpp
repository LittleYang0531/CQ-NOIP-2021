#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define Maxnm 200000
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

template < typename _T >
_T Max (_T x, _T y) { return x > y ? x : y; }
template < typename _T >
_T Min (_T x, _T y) { return x < y ? x : y; }

template < typename _T >
void Read (_T &x) {
	x = 0; int f = 1; char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') { f = -1; }
		c = getchar ();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar ();
	}
	x *= f;
}

int T, n, m, q;
int bl[Maxnm + 5], vis[Maxnm + 5][5], ans[Maxnm + 5];
char s[Maxnm + 5], opt1[Maxnm + 5], opt2[Maxnm + 5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Chess {
	int col, lv;
} ch[Maxnm + 5];

struct Node {
	int x, y, op, dir;
	Node () {}
	Node (int a, int b, int o, int d) {
		x = a, y = b, op = o, dir = d;
	}
} ;

int ID (int x, int y) {
	return (x - 1) * m + y;
}

int Bfs (int X, int Y, int id) {
	memset (vis, 0, sizeof vis);
	memset (ans, 0, sizeof ans);
	rep (i, 0, 4) vis[ID (X, Y)][i] = 1;
	queue < Node > que;
	
	que.push (Node (X, Y, -1, -1));
	
	while (que.size ()) {
		Node now = que.front ();
		que.pop ();
//		printf ("-- %d %d  %d\n", now.x, now.y, now.dir);
		rep (i, 0, 3) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
//			if (xx == 1 && yy == 3) printf ("%d %d\n", X, vis[ID (xx, yy)][now.op + 1]);
			if (vis[ID (xx, yy)][now.op + 1]) continue;
			vis[ID (xx, yy)][now.op + 1] = 1;
			if (xx == now.x + 1) {
				if (opt2[ID (now.x, now.y)] - '0' == 0) continue;
				if (now.op != -1 && opt2[ID (now.x, now.y)] - '0' != now.op) continue;
				int dir = -1;
				if (opt2[ID (now.x, now.y)] - '0' == 2) {
					if (now.dir == -1) dir = 2;
					else if (now.dir != 2) continue;
					dir = 2;
				}
				if (bl[ID (xx, yy)]) {
					int x = bl[ID (xx, yy)];
					if (ch[id].col != ch[x].col && ch[id].lv >= ch[x].lv) {
//						printf ("%d %d\n", xx, yy);
						ans[ID (xx, yy)] = 1;
					}
					continue;
				}
//				printf ("(%d %d)\n", xx, yy);
				ans[ID (xx, yy)] = 1;
				que.push (Node (xx, yy, opt2[ID (now.x, now.y)] - '0', dir));
			}
			if (xx + 1 == now.x) {
				if (opt2[ID (xx, now.y)] - '0' == 0) continue;
				if (now.op != -1 && opt2[ID (xx, now.y)] - '0' != now.op) continue;
				int dir = -1;
				if (opt2[ID (xx, now.y)] - '0' == 2) {
					if (now.dir == -1) dir = 0;
					else if (now.dir != 0) continue;
					dir = 0;
				}
				if (bl[ID (xx, yy)]) {
					int x = bl[ID (xx, yy)];
					if (ch[id].col != ch[x].col && ch[id].lv >= ch[x].lv) {
//						printf ("(%d %d)\n", xx, yy);
						ans[ID (xx, yy)] = 1;
					}
					continue;
				}
				ans[ID (xx, yy)] = 1;
//				printf ("(%d %d)\n", xx, yy);
				que.push (Node (xx, yy, opt2[ID (xx, now.y)] - '0', dir));
			}
			if (yy == now.y + 1) {
				if (opt1[ID (now.x, now.y)] - '0' == 0) continue;
				if (now.op != -1 && opt1[ID (now.x, now.y)] - '0' != now.op) continue;
				int dir = -1;
				if (opt1[ID (now.x, now.y)] - '0' == 2) {
					if (now.dir == -1) dir = 3;
					else if (now.dir != 3) continue;
					dir = 3;
				}
				if (bl[ID (xx, yy)]) {
					int x = bl[ID (xx, yy)];
//					printf ("%d %d  vs %d %d\n", ch[i].col, ch[i].lv, ch[x].col, ch[x].lv);
					if (ch[id].col != ch[x].col && ch[id].lv >= ch[x].lv) {
//						printf ("(%d %d)\n", xx, yy);
						ans[ID (xx, yy)] = 1;
					}
					continue;
				}
				ans[ID (xx, yy)] = 1;
//				printf ("(%d %d)\n", xx, yy);
				que.push (Node (xx, yy, opt1[ID (now.x, now.y)] - '0', dir));
			}
			if (yy + 1 == now.y) {
				if (opt1[ID (now.x, yy)] - '0' == 0) continue;
				if (now.op != -1 && opt1[ID (now.x, yy)] - '0' != now.op) continue;
				int dir = -1;
				if (opt1[ID (now.x, yy)] - '0' == 2) {
					if (now.dir == -1) dir = 1;
					else if (now.dir != 1) continue;
					dir = 1;
				}
//				printf ("(%d %d) and DIR is %d\n", xx, yy, dir);
				if (bl[ID (xx, yy)]) {
					int x = bl[ID (xx, yy)];
					if (ch[id].col != ch[x].col && ch[id].lv >= ch[x].lv) {
						ans[ID (xx, yy)] = 1;
//						printf ("(%d %d)\n", xx, yy);
					}
					continue;
				}
				ans[ID (xx, yy)] = 1;
//				printf ("(%d %d)\n", xx, yy);
				que.push (Node (xx, yy, opt1[ID (now.x, yy)] - '0', dir));
			}
		}
	}
	int tot = 0;
	rep (i, 1, n) {
		rep (j, 1, m) tot += ans[ID (i, j)];
	}
	return tot;
}

int main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	
	Read (T);
	
	while (T --) {
		Read (n), Read (m), Read (q);
		
		rep (i, 1, n) {
			memset (s, 0, sizeof s);
			scanf ("%s", s + 1);
			rep (j, 1, m - 1) opt1[ID (i, j)] = s[j];
		}
		rep (i, 1, n - 1) {
			memset (s, 0, sizeof s);
			scanf ("%s", s + 1);
			rep (j, 1, m) opt2[ID (i, j)] = s[j];
		}
		
		rep (i, 1, q) {
			int x, y;
			Read (ch[i].col), Read (ch[i].lv), Read (x), Read (y);
			
			bl[ID (x, y)] = i;
			printf ("%d\n", Bfs (x, y, i));
		}
		
		memset (bl, 0, sizeof bl);
		memset (opt1, 0, sizeof opt1);
		memset (opt2, 0, sizeof opt2);
		rep (i, 1, q) ch[i].col = 0, ch[i].lv = 0;
	}
	

	return 0;
}

