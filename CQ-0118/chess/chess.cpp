#include <bits/stdc++.h>
using namespace std;
inline void read(int& val) {
	val = 0; bool negative = false; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') negative = true; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { val = val * 10 + ch - '0'; ch = getchar(); }
	if (negative) val = -val;
}
inline void readState(int& val) {
	val = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	val = ch - '0';
}
inline void write(int val) {
	if (val < 0) { putchar('-'); write(-val); return; }
	if (val >= 10) { write(val / 10); }
	putchar(val % 10 + '0');
}
int n, m, q, **horizontal, **vertical, ans, curColor, curLevel;
bool **vis, **dfsVis;
struct chess {
	bool color;
	int level;
} **plate;
void resetVis() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = false;
			dfsVis[i][j] = false;
		}
	}
}
int getType(int y, int x, int dir) {
	if (dir == 0) { // 上 
		return y - 1 < 0 ? 0 : vertical[y - 1][x];
	} else if (dir == 1) { // 右 
		return x + 1 >= m ? 0 : horizontal[y][x];
	} else if (dir == 2) { // 下
		return y + 1 >= n ? 0 : vertical[y][x];
	} else { // 左 
		return x - 1 < 0 ? 0 : horizontal[y][x - 1];
	}
}
void getDest(int y, int x, int dir, int& destY, int& destX) {
	destY = y;
	destX = x; 
	if (dir == 0) { // 上 
		destY--;
	} else if (dir == 1) { // 右 
		destX++;
	} else if (dir == 2) { // 下 
		destY++;
	} else { // 左 
		destX--;
	}
}
bool canEat(int destY, int destX) {
	if (plate[destY][destX].level == 0) {
		return true;
	} else {
//		printf("%d %d %d %d\n", plate[destY][destX].color, plate[y][x].color, plate[destY][destX].level, plate[y][x].level); 
//		printf("%d %d %d %d\n", destY + 1, destX + 1, y + 1, x + 1); 
		return plate[destY][destX].color != curColor && plate[destY][destX].level <= curLevel;
	}
}
void dfs(int y, int x) {
	if (!vis[y][x] && canEat(y, x)) {
		vis[y][x] = true;
		ans++;
//		printf("互通: %d %d\n", y + 1, x + 1);
	}
	if (plate[y][x].level != 0 || dfsVis[y][x]) {
		return;
	}
	dfsVis[y][x] = true;
	int destY, destX;
	if (getType(y, x, 0) == 3) {
		getDest(y, x, 0, destY, destX);
		dfs(destY, destX);
	}
	if (getType(y, x, 1) == 3) {
		getDest(y, x, 1, destY, destX);
		dfs(destY, destX);
	}
	if (getType(y, x, 2) == 3) {
		getDest(y, x, 2, destY, destX);
		dfs(destY, destX);
	}
	if (getType(y, x, 3) == 3) {
		getDest(y, x, 3, destY, destX);
		dfs(destY, destX);
	}
}
void walk(int y, int x, int dir) {
	int type = getType(y, x, dir);
	if (type == 0) { // 无路可走
		// 空的 
	} else if (type == 1) { // 普通道路
		int destY, destX;
		getDest(y, x, dir, destY, destX);
		if (!vis[destY][destX] && canEat(destY, destX)) {
//			printf("普通: %d %d\n", destY + 1, destX + 1);
			vis[destY][destX] = true;
			ans++;
		}
	} else if (type == 2) { // 直行道路
		int destY, destX; 
		for (;;) {
			getDest(y, x, dir, destY, destX);
			if (plate[destY][destX].level == 0) {
				if (!vis[destY][destX]) {
//					printf("直行: %d %d\n", destY + 1, destX + 1);
					vis[destY][destX] = true;
					ans++;
				}
				if (getType(destY, destX, dir) == 2) {
					y = destY;
					x = destX;
				} else {
					break;
				}
			} else {
				if (!vis[destY][destX] && canEat(destY, destX)) {
//					printf("直行: %d %d\n", destY + 1, destX + 1);
					vis[destY][destX] = true;
					ans++;
				}
				break;
			}
		}
	} else { // 互通道路
		dfs(y, x); 
	}
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t;
	read(t);
	while (t--) {
		read(n), read(m), read(q);
		// 10^5 * 10^5 的数组太大了，编译不了，只能动态开数组
		horizontal = new int*[n];
		for (int i = 0; i < n; i++) {
			horizontal[i] = new int[m - 1];
		}
		vertical = new int*[n - 1];
		for (int i = 0; i < n - 1; i++) {
			vertical[i] = new int[m];
		}
		plate = new chess*[n];
		vis = new bool*[n];
		dfsVis = new bool*[n];
		for (int i = 0; i < n; i++) {
			plate[i] = new chess[m];
			vis[i] = new bool[m];
			dfsVis[i] = new bool[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				readState(horizontal[i][j]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				readState(vertical[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				plate[i][j].color = false;
				plate[i][j].level = 0;
			}
		} 
		for (int i = 0; i < q; i++) {
			int y, x;
			read(curColor), read(curLevel), read(y), read(x);
			y--, x--;
			resetVis(); 
			vis[y][x] = true;
			ans = 0;
			walk(y, x, 0);
			walk(y, x, 1);
			walk(y, x, 2);
			walk(y, x, 3); 
			write(ans);
			putchar('\n');
//			fflush(stdout);
			plate[y][x].color = curColor;
			plate[y][x].level = curLevel;
		}
		for (int i = 0; i < n; i++) {
			delete[] horizontal[i];
		}
		delete[] horizontal;
		for (int i = 0; i < n - 1; i++) {
			delete[] vertical[i];
		}
		delete[] vertical;
		for (int i = 0; i < n; i++) {
			delete[] plate[i];
			delete[] vis[i];
			delete[] dfsVis[i];
		}
		delete[] plate;
		delete[] vis;
		delete[] dfsVis;
	}
	return 0; 
}
