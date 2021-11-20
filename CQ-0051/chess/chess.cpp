#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
const int nn = 2e5 + 5;
int n, m, q;
std::string map[2][nn];
char str[nn];
struct chess {
	int col, lv;
	chess(int c = -1, int l = -1) { col = c; lv = l; }
	int operator< (const chess &rhs)const {
		return col != rhs.col && lv <= rhs.lv;
	}
};
std::vector<chess> a[nn];
std::vector<int> vis[nn];
struct pos {
	int x, y;
} que[nn];
int head, tail;
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &q);
			str[0] = ' ';
		for (int i = 1; i <= n; i++) {
			scanf("%s", str + 1);
			map[0][i] = str;
			std::vector<chess>(m + 5).swap(a[i]);
			std::vector<int>(m + 5, -1).swap(vis[i]);
		}
//		puts("ok");
		for (int i = 1; i < n; i++) {
			scanf("%s", str + 1);
			map[1][i] = str;
		}
		while (q--) {
			int c, l, x, y, ans = 0;
			scanf("%d %d %d %d", &c, &l, &x, &y);
			a[x][y] = (chess){c, l};
			que[head = tail = 1] = (pos){x, y};
			vis[x][y] = q;
			while (head <= tail) {
				int px = que[head].x, py = que[head].y;
//				printf("%d %d\n", px, py);
				head++;
				if (py < m && map[0][px][py] == '3') {
					if (a[px][py + 1].col == -1 && vis[px][py + 1] != q) ans += (vis[px][py + 1] != q), vis[px][py + 1] = q, que[++tail] = (pos){px, py + 1};
					else if (a[px][py + 1] < a[x][y]) ans += (vis[px][py + 1] != q), vis[px][py + 1] = q;
				}
				if (py > 1 && map[0][px][py - 1] == '3') {
					if (a[px][py - 1].col == -1 && vis[px][py - 1] != q) ans += (vis[px][py - 1] != q), vis[px][py - 1] = q, que[++tail] = (pos){px, py - 1};
					else if (a[px][py - 1] < a[x][y]) ans += (vis[px][py - 1] != q), vis[px][py - 1] = q;
				}
				if (px < n && map[1][px][py] == '3') {
					if (a[px + 1][py].col == -1 && vis[px + 1][py] != q) ans += (vis[px + 1][py] != q), vis[px + 1][py] = q, que[++tail] = (pos){px + 1, py};
					else if (a[px + 1][py] < a[x][y]) ans += (vis[px + 1][py] != q), vis[px + 1][py] = q;
				}
				if (px > 1 && map[1][px - 1][py] == '3') {
					if (a[px - 1][py].col == -1 && vis[px - 1][py] != q) ans += (vis[px - 1][py] != q), vis[px - 1][py] = q, que[++tail] = (pos){px - 1, py};
					else if (a[px - 1][py] < a[x][y]) ans += (vis[px - 1][py] != q), vis[px - 1][py] = q;
				}
//				printf("%d\n", ans);
			}
//			printf("%d\n", ans);
			if (y < m && map[0][x][y] == '1' && a[x][y + 1] < a[x][y])
				ans += (vis[x][y + 1] != q), vis[x][y + 1] = q;
			if (y > 1 && map[0][x][y - 1] == '1' && a[x][y - 1] < a[x][y])
				ans += (vis[x][y - 1] != q), vis[x][y - 1] = q;
			if (x < n && map[1][x][y] == '1' && a[x + 1][y] < a[x][y])
				ans += (vis[x + 1][y] != q), vis[x + 1][y] = q;
			if (x > 1 && map[1][x - 1][y] == '1' && a[x - 1][y] < a[x][y])
				ans += (vis[x - 1][y] != q), vis[x - 1][y] = q;
			for (int i = y; i < m; i++)
				if (map[0][x][i] == '2') {
					if (a[x][i + 1].col != -1) {
						if (a[x][i + 1] < a[x][y])
							ans += (vis[x][i + 1] != q), vis[x][i + 1] = q;
						break;
					} else ans += (vis[x][i + 1] != q), vis[x][i + 1] = q;
				} else break;
			for (int i = y - 1; i >= 1; i--)
				if (map[0][x][i] == '2') {
					if (a[x][i].col != -1) {
						if (a[x][i] < a[x][y])
							ans += (vis[x][i] != q), vis[x][i] = q;
						break;
					} else ans += (vis[x][i] != q), vis[x][i] = q;;
				} else break;
			for (int i = x; i < n; i++)
				if (map[1][i][y] == '2') {
					if (a[i + 1][y].col != -1) {
						if (a[i + 1][y] < a[x][y])
							ans += (vis[i + 1][y] != q), vis[i + 1][y] = q;
						break;
					} else ans += (vis[i + 1][y] != q), vis[i + 1][y] = q;
				} else break;
			for (int i = x - 1; i >= 1; i--)
				if (map[1][i][y] == '2') {
					if (a[i][y].col != -1) {
						if (a[i][y] < a[x][y])
							ans += (vis[i][y] != q), vis[i][y] = q;
						break;
					} else ans += (vis[i][y] != q), vis[i][y] = q;
				} else break;
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*

1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2


2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2

*/
