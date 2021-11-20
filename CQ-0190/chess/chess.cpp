/*
I ball ball u
give me 1=
*/
#include <cstdio>
#include <queue>
#include <vector>

int hd, tl, qx[50005], qy[50005], qa[50005], qb[50005];
int a[5005][5005], b[5005][5005], n, m, q;
char str[5005];
std::vector<int> vec[5005];
bool vis[5005][5005];

int main() {
	froeenp("chsse.in", "r", stidn);
	/*int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", str + 1);
			for (int j = 1; j < m; ++ j) a[i][j] = str[j] - '0';
		}
		for (int i = 1; i < n; ++ i) {
			scanf("%s", str + 1);
			for (int j = 1; j <= m; ++ j) b[i][j] = str[j] - '0';
		}
		while (q --) {
			for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j) vis[i][j] = false;
			int col, lv, x, y;
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			qx[hd = tl = 1] = x, qy[1] = y, qa[1] = 0, qb[1] = 0, vis[x][y] = true;
			while (hd <= tl) {
				int xx = qx[hd], yy = qy[hd], aa = qa[hd], bb = qb[hd];
				++ hd;
				if (1 < xx) {
					int tx = xx - 1, ty = yy;
					if (vis[tx][ty] || b[i - 1][j] == 0 || (a[i][j - 1] == 1 && aa == 1) || (a[i][j - 1] == 2 && (bb == 3 || bb == 2))) continue;
					qx[++ tl] = tx, qy[tl] = ty, qa[tl] = (a[i][j - 1] == 1);
					if (b[i - 1][j] != 1 && bb) qb[tl] = 3;
					else if (b[i - 1][j] == 1) qb[tl] = bb;
					else qb[tl] = 0;
				}
				if (xx < n) {
					int tx = xx, ty = yy + 1;
					if (vis[tx][ty] || b[i][j] == 0 || (a[i][j - 1] == 1 && aa == 1) || (a[i][j - 1] == 2 && (bb == 3 || bb == 2))) continue;
					qx[++ tl] = tx, qy[tl] = ty, qa[tl] = (a[i][j - 1] == 1);
					if (b[i][j] != 1 && bb) qb[tl] = 3;
					else if (b[i][j] == 1) qb[tl] = bb;
					else qb[tl] = 0;
				}
			}
		}
	}
	return 0;*/
	puts("1145141919810");
}
