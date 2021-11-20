#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
vector <int> a[200005], a2[200005], chess[200005], vis[200005], e[5][200005];
//int a[5005][5005], a2[5005][5005], chess[5005][5005], vis[5005][5005], e[8][5005][5005];
int n, m, Q;
int dx[8] = {0, 0, 0, 1, -1};
int dy[8] = {0, 1, -1, 0, 0};
struct Node {
	int col, lv;
	Node () {}
	Node (int A, int B) {
		col = A, lv = B;
	}
}q[200005];

int whi, L;
int Ans = 0;
void dfs (int x, int y, int edge, int dir, int id) {
//	if (id == 22) printf ("[%d %d %d]\n", x, y, Ans);
	for (int i = 1; i <= 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
//		if (id == 3) printf ("(%d %d %d)\n", nx, ny, e[x][y][i]);
//		continue;
		if (nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny] == whi || e[i][x][y] != edge|| (dir != i && edge == 2)) continue;
		if (chess[nx][ny] && (q[chess[nx][ny]].col == q[id].col || q[chess[nx][ny]].lv > q[id].lv)) continue;
//		if (id == 3) printf ("(%d %d %d)\n", nx, ny, e[x][y][i]);
		if (vis[nx][ny] < L) Ans++;
		vis[nx][ny] = whi;
		if (edge == 2) {
			if (chess[nx][ny]) continue;
			dfs (nx, ny, edge, dir, id);
		}
		if (edge == 3) {
			if (chess[nx][ny]) continue;
			dfs (nx, ny, edge, dir, id);
		}
	}
}
char ch[200005];
int main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	int TT;
	scanf ("%d", &TT);
	while (TT--) {
		scanf ("%d %d %d", &n, &m, &Q);
//		n = read (), m = read (), Q = read ();
		int flag78 = 1;
		for (int i = 1; i <= n; i++) {
			a2[i].clear();
			a[i].clear();
			chess[i].clear();
			vis[i].clear();
			e[1][i].clear();
			e[2][i].clear();
			e[3][i].clear();
			e[4][i].clear();
			
			a2[i].resize(m + 2);
			a[i].resize(m + 2);
			chess[i].resize(m + 2);
			vis[i].resize(m + 2);
			e[1][i].resize(m + 2);
			e[2][i].resize(m + 2);
			e[3][i].resize(m + 2);
			e[4][i].resize(m + 2);
			scanf ("%s", ch + 1);
			for (int j = 1; j < m; j++) {
				a[i][j] = ch[j] - '0';
				if (a[i][j] == 2 || a[i][j] == 3) flag78 = 0;
			} 
		} 
		for (int i = 1; i < n; i++) {
			scanf ("%s", ch + 1);
			for (int j = 1; j <= m; j++) {
				a2[i][j] = ch[j] - '0';
				if (a2[i][j] == 2 || a2[i][j] == 3) flag78 = 0;
			} 
		} 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j < m) e[1][i][j] = a[i][j];
				if (j > 1) e[2][i][j] = a[i][j-1];
				if (i < n) e[3][i][j] = a2[i][j];
				if (i > 1) e[4][i][j] = a2[i-1][j];
			}
		}
//		return 0;
//		if ((n * m <= 5000 && Q <= 2000) || flag78) {
			for (int T = 1; T <= Q; T++) {
				int col = read (), lv = read (), x = read (), y = read ();
				q[T] = Node (col, lv);
				Ans = 0;
//				memset (vis, 0, sizeof vis);
				vis[x][y] = ++whi;
				L = whi;
				dfs (x, y, 2, 1, T);
				dfs (x, y, 2, 2, T);
				dfs (x, y, 2, 3, T);
				dfs (x, y, 2, 4, T);
				vis[x][y] = ++whi;
				dfs (x, y, 3, 0, T);
				vis[x][y] = ++whi;
				dfs (x, y, 1, 0, T);
				chess[x][y] = T;
				write (Ans), putchar ('\n');
//				if (T == 3) return 0;
//				return 0;
//			} 
		}
//		return 0;
	}
	
	
	return 0;
}
/*
T4 貌似有趣多了。
sb T3 fuck
1~6 直接dfs枚举
7~8 判断相邻的四个
9~11:
若不存在互通，那么主要指判断直行，假设只考虑一个方向
颜色相同可以判
关键是等级，哦，不用管，特殊判断一下就好了
12~14：
不会，也不好写
15~16:
17~18:
其实都不好写，把部分分拿完写乱搞。 
*/

