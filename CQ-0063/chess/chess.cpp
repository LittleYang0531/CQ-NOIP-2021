/*
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
int n, m, q, col[N], lv[N], _x[N], _y[N];
int vis[N][N], ans, sig[N][N];
char hoz[N][N], vet[N][N];
inline int read() {
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch > '9') {if (ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
inline void dfs(int x, int y, int p1, int p2, int p3, int zs) {
	if (sig[x][y] == zs) return ;
	sig[x][y] = zs;
	if (vis[x][y]) {
		if (col[vis[x][y]] != col[zs] && lv[vis[x][y]] <= lv[zs]) {
			++ans;
		}
		return ;
	}
	else ++ans;
	if (y != 1 && hoz[x][y - 1] != '0') {
		if (hoz[x][y - 1] == '1' && (!p1) && (!p2) && (!p3)) {
			dfs(x, y - 1, 1, p2, p3, zs);
		}
		if (hoz[x][y - 1] == '2' && (!p1) && (p2 == 1 || (!p2)) && (!p3)) {
			dfs(x, y - 1, p1, 1, p3, zs);
		}
		if (hoz[x][y - 1] == '3' && (!p1) && (!p2)) {
			dfs(x, y - 1, p1, p2, 1, zs);
		}
	}
	if (x != 1 && vet[x - 1][y] != '0') {
		if (vet[x - 1][y] == '1' && (!p1) && (!p2) && (!p3)) {
			dfs(x - 1, y, 1, p2, p3, zs);
		}
		if (vet[x - 1][y] == '2' && (!p1) && (p2 == 2 || (!p2)) && (!p3)) {
			dfs(x - 1, y, p1, 2, p3, zs);
		}
		if (vet[x - 1][y] == '3' && (!p1) && (!p2)) {
			dfs(x - 1, y, p1, p2, 1, zs);
		}
	}
	if (y != m && hoz[x][y] != '0') {
		if (hoz[x][y] == '1' && (!p1) && (!p2) && (!p3)) {
			dfs(x, y + 1, 1, p2, p3, zs);
		}
		if (hoz[x][y] == '2' && (!p1) && (p2 == 1 || (!p2)) && (!p3)) {
			dfs(x, y + 1, p1, 1, p3, zs);
		}
		if (hoz[x][y] == '3' && (!p1) && (!p2)) {
			dfs(x, y + 1, p1, p2, 1, zs);
		}
	}
	if (x != n && vet[x][y] != '0') {
		if (vet[x][y] == '1' && (!p1) && (!p2) && (!p3)) {
			dfs(x + 1, y, 1, p2, p3, zs);
		}
		if (vet[x][y] == '2' && (!p1) && (p2 == 2 || (!p2)) && (!p3)) {
			dfs(x + 1, y, p1, 2, p3, zs);
		}
		if (vet[x][y] == '3' && (!p1) && (!p2)) {
			dfs(x + 1, y, p1, p2, 1, zs);
		}
	}
}
inline void mian() {
	n = read(); m = read(); q = read();
	if (n > 5000) {
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%s", hoz[i] + 1);
	}
	for (int i = 1; i < n; ++i) {
		scanf("%s", vet[i] + 1);
	}
	for (int i = 1; i <= q; ++i) {
		col[i] = read(), lv[i] = read();
		_x[i] = read(), _y[i] = read();
		ans = 0;
		dfs(_x[i], _y[i], 0, 0, 0, i);
		vis[_x[i]][_y[i]] = i;
		printf("%d\n", ans - 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) sig[i][j] = 0;
	}
	for (int i = 1; i <= q; ++i) {
		vis[_x[i]][_y[i]] = 0;
	}
	//»¹Òªclear
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t = read();
	while (t--) mian();
	return 0;
}
