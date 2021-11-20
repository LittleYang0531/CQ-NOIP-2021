#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int T, n, m, q, e[maxn][4], ans[maxn], qid[maxn];
bool vis[maxn], isans[maxn];
char s[maxn];
struct question {
	int col, lv, x, y;
} a[maxn];
inline int id(int x, int y) {
	return (x - 1) * m + y;
}
void dfs(int x, int y, int pos) {
	vis[id(x, y)] = 1;
	if(qid[id(x, y)] == 0) {
		if(!isans[id(x, y)]) ans[pos]++;
	}
	else {
		if(!isans[id(x, y)] && a[qid[id(x, y)]].col != a[pos].col && a[qid[id(x, y)]].lv <= a[pos].lv) ans[pos]++;
		return;
	}
	for(int i = 0; i < 4; i++) {
		int xx = dx[i] + x, yy = y + dy[i];
		if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if(e[id(x, y)][i] == 3 && !vis[id(xx, yy)]) dfs(xx, yy, pos);
	}
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> m >> q;
		for(int i = 1; i <= n; i++) {
			cin >> (s + 1);
			for(int j = 1; j < m; j++) {
				e[id(i, j)][0] = s[j] - 48;
				e[id(i, j + 1)][1] = s[j] - 48;
			}
		}
		for(int i = 1; i < n; i++) {
			cin >> (s + 1);
			for(int j = 1; j <= m; j++) {
				e[id(i, j)][3] = s[j] - 48;
				e[id(i + 1, j)][2] = s[j] - 48;
			}
		}
		for(int i = 1; i <= n * m; i++) qid[i] = 0;
		for(int i = 1, col, lv, x, y; i <= q; i++) {
			ans[i] = 0;
			cin >> col >> lv >> x >> y;
			a[i].col = col, a[i].lv = lv, a[i].x = x, a[i].y = y;
			bool fl = 0;
			for(int j = 1; j <= n * m; j++) vis[j] = isans[j] = 0;
			isans[id(x, y)] = 1;
			for(int j = 0; j < 4; j++) {
				int xx = x + dx[j], yy = y + dy[j];
				if(xx < 1 || xx > n || yy < 1 || yy > m || e[id(x, y)][j] == 0) continue;
				if(e[id(x, y)][j] == 1) {
					if(qid[id(xx, yy)] == 0) ans[i]++;
					else if(a[qid[id(xx, yy)]].col != col && a[qid[id(xx, yy)]].lv <= lv) ans[i]++;
					isans[id(xx, yy)] = 1;
				}
				else if(e[id(x, y)][j] == 2) {
					while(xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
						if(qid[id(xx, yy)] == 0) ans[i]++;
						else {
							if(a[qid[id(xx, yy)]].col != col && a[qid[id(xx, yy)]].lv <= lv) { ans[i]++; isans[id(xx, yy)] = 1; }
							break;
						}
						isans[id(xx, yy)] = 1;
						if(e[id(xx, yy)][j] != 2) break;
						xx += dx[j], yy += dy[j];
					}
				}
				else fl = 1;
			}
			if(fl) dfs(x, y, i);
			qid[id(x, y)] = i;
		}
		for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	}
	return 0;
}
