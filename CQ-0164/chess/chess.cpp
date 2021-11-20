#include <stdio.h>

int n, m;
int a[5007][5007], b[5007][5007], color[5007][5007], level[5007][5007];
bool vis[5007][5007];

void walk1(int x, int y, int col, int lv){
	if (color[x][y] == col || level[x][y] > lv) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
}

void walk2(int x, int y, int col, int lv, int dx, int dy){
	if (color[x][y] == col || level[x][y] > lv) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (color[x][y] != 2) return;
	if (dx == -1){
		if (b[x - 1][y] != 2) return;
	} else if (dx == 1){
		if (b[x][y] != 2) return;
	} else if (dy == -1){
		if (a[x][y - 1] != 2) return;
	} else {
		if (a[x][y] != 2) return;
	}
	int nx = x + dx, ny = y + dy;
	if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) walk2(nx, ny, col, lv, dx, dy);
}

int ddx[] = {0, -1, 0, 0, 1}, ddy[] = {0, 0, -1, 1, 0};

void walk3(int x, int y, int col, int lv){
	if (color[x][y] == col || level[x][y] > lv) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (color[x][y] != 2) return;
	for (int i = 1; i <= 4; i++){
		int nx = x + ddx[i], ny = y + ddy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
			if (ddx[i] == 0){
				if (ddy[i] == -1){
					if (a[x][y - 1] == 3) walk3(nx, ny, col, lv);
				} else {
					if (a[x][y] == 3) walk3(nx, ny, col, lv);
				}
			} else if (ddx[i] == -1){
				if (b[x - 1][y] == 3) walk3(nx, ny, col, lv);
			} else {
				if (b[x][y] == 3) walk3(nx, ny, col, lv);
			}
		}
	}
}

int main(){
	int t;
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int q;
		scanf("%d %d %d", &n, &m, &q);
		for (int j = 1; j <= n; j++){
			for (int k = 1; k < m; k++){
				scanf("%1d", &a[j][k]);
			}
		}
		for (int j = 1; j < n; j++){
			for (int k = 1; k <= m; k++){
				scanf("%1d", &b[j][k]);
			}
		}
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= m; k++){
				color[j][k] = 2;
				level[j][k] = 0;
			}
		}
		for (int j = 1; j <= q; j++){
			int col, lv, x, y;
			scanf("%d %d %d %d", &col, &lv, &x, &y);
			color[x][y] = col;
			level[x][y] = lv;
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= m; l++){
					vis[k][l] = false;
				}
			}
			vis[x][y] = true;
			for (int k = 1; k <= 4; k++){
				int nx = x + ddx[k], ny = y + ddy[k];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
					if (ddx[k] == 0){
						if (ddy[k] == -1){
							if (a[x][y - 1] == 1){
								walk1(nx, ny, col, lv);
							} else if (a[x][y - 1] == 2){
								walk2(nx, ny, col, lv, ddx[k], ddy[k]);
							} else if (a[x][y - 1] == 3){
								walk3(nx, ny, col, lv);
							}
						} else {
							if (a[x][y] == 1){
								walk1(nx, ny, col, lv);
							} else if (a[x][y] == 2){
								walk2(nx, ny, col, lv, ddx[k], ddy[k]);
							} else if (a[x][y] == 3){
								walk3(nx, ny, col, lv);
							}
						}
					} else if (ddx[k] == -1){
						if (b[x - 1][y] == 1){
							walk1(nx, ny, col, lv);
						} else if (b[x - 1][y] == 2){
							walk2(nx, ny, col, lv, ddx[k], ddy[k]);
						} else if (b[x - 1][y] == 3){
							walk3(nx, ny, col, lv);
						}
					} else {
						if (b[x][y] == 1){
							walk1(nx, ny, col, lv);
						} else if (b[x][y] == 2){
							walk2(nx, ny, col, lv, ddx[k], ddy[k]);
						} else if (b[x][y] == 3){
							walk3(nx, ny, col, lv);
						}
					}
				}
			}
			int ans = -1;
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= m; l++){
					ans += vis[k][l];
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
