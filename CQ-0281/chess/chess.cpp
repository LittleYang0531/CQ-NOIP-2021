//打了这么多，能得多少分呢 

#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = (int) 2e5 + 5;

struct node {
	int x, y, line, color, level;
	bool go_pt;
} t1, t2;

struct sto_XSC062_AK_IOI_orz {
	int color, level;
	bool is_there;
} d[5005][5005];

int T, n, m, q, color, level, x, y, ans;
string linex[maxn], liney[maxn];
bool b[5005][5005], QwQ[5005][5005][5];
/* 
dir[0]: 上 
dir[1]: 下
dir[2]: 左
dir[3]: 右 
*/ 
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline void init() {
	memset(d, 0, sizeof(d));
	return;
}

inline void init_for_chess() {
	memset(b, 0, sizeof(b));
	memset(QwQ, 0, sizeof(QwQ));
	ans = 0;
	return;
}

inline void bfs() {
	queue <node> q;
	t1.x = x, t1.y = y, t1.level = level, t1.color = color, t1.line = 1, t1.go_pt = 0;
	q.push(t1);
	while(!q.empty()) {
		t1 = q.front();
		q.pop();
		if(QwQ[t1.x][t1.y][t1.line])
			continue;
		QwQ[t1.x][t1.y][t1.line] = 1;
		//printf("* %d %d %d %d %d\n", t1.x, t1.y, t1.color, t1.level, t1.line);
		// 确定是否经过其他棋子 
		if(d[t1.x][t1.y].is_there) {
			// printf("-> %d %d %d %d\n", t1.x, t1.y, t1.color, d[t1.x][t1.y].color);
			if(d[t1.x][t1.y].color != t1.color && t1.level >= d[t1.x][t1.y].level) //吃子 
				b[t1.x][t1.y] = 1;
			else
				b[t1.x][t1.y] = 0;
			continue;
		} 
		if(!t1.line) {
			b[t1.x][t1.y] = 0;
			continue;
		} else if(t1.line == 1) { // 普通 & 没有确定
			if(t1.go_pt)
				continue;
			for(int i = 0; i < 4; i++) {
				int dx = t1.x + dir[i][0];
				int dy = t1.y + dir[i][1];
				if(dx >= 1 && dx <= n && dy >= 1 && dy <= m) { // 不越界 
					// 确定 line 的类型
					if(i == 0)
						t2.line = liney[dx][dy - 1] - '0';
					else if(i == 1)
						t2.line = liney[dx - 1][dy - 1] - '0';
					else if(i == 2)
						t2.line = linex[dx][dy - 1] - '0';
					else
						t2.line = linex[dx][dy - 1 - 1] - '0';
					// 判断 line 的类型 
					if(t2.line == 0)
						continue;
					else if(t2.line == 1) {
						if(t1.go_pt) continue;
						t2.x = dx, t2.y = dy, t2.color = t1.color, t2.level = t1.level, t2.go_pt = 1;
						b[dx][dy] = 1;
						q.push(t2);
					} else {
						t2.x = dx, t2.y = dy, t2.color = t1.color, t2.level = t1.level, t2.go_pt = t1.go_pt;
						b[dx][dy] = 1;
						q.push(t2);
					}
				}
			}
		} else if(t1.line == 2) { // 直行（上下） 
			for(int i = 0; i < 2; i++) {
				int dx = t1.x + dir[i][0];
				int dy = t1.y + dir[i][1];
				if(dx >= 1 && dx <= n && dy >= 1 && dy <= m) { //不越界 
					// 确定 line 的类型 
					if(i == 0)
						t2.line = liney[dx][dy - 1] - '0';
					else
						t2.line = liney[dx - 1][dy - 1] - '0';
					if(t2.line == t1.line) {
						t2.x = dx, t2.y = dy, t2.color = t1.color, t2.level = t1.level, t2.go_pt = t1.go_pt;
						b[dx][dy] = 1;
						q.push(t2);
					}
				}
			}
		} else if(t1.line == 3) { // 互通 
			for(int i = 0; i < 4; i++) {
				int dx = t1.x + dir[i][0];
				int dy = t1.y + dir[i][1];
				if(dx >= 1 && dx <= n && dy >= 1 && dy <= m) { //不越界 
					// 确定 line 的类型 
					if(i == 0)
						t2.line = liney[dx][dy - 1] - '0';
					else if(i == 1)
						t2.line = liney[dx - 1][dy - 1] - '0';
					else if(i == 2)
						t2.line = linex[dx][dy - 1] - '0';
					else
						t2.line = linex[dx][dy - 1 - 1] - '0';
					if(t2.line == t1.line) {
						t2.x = dx, t2.y = dy, t2.color = t1.color, t2.level = t1.level, t2.go_pt = t1.go_pt;
						b[dx][dy] = 1;
						q.push(t2);
					}
				}
			}
		} else if(t1.line == 4) { // 直行（左右） 
			for(int i = 2; i < 4; i++) {
				int dx = t1.x + dir[i][0];
				int dy = t1.y + dir[i][1];
				if(dx >= 1 && dx <= n && dy >= 1 && dy <= m) { //不越界 
					// 确定 line 的类型 
					if(i == 2)
						t2.line = linex[dx][dy - 1] - '0';
					else
						t2.line = linex[dx][dy - 1 - 1] - '0';
					if(t2.line == t1.line) {
						t2.x = dx, t2.y = dy, t2.color = t1.color, t2.level = t1.level, t2.go_pt = t1.go_pt;
						b[dx][dy] = 1;
						q.push(t2);
					}
				}
			}
		}
	}
	return;
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %d %d", &n, &m, &q);
		for(int i = 1; i <= n; i++)
			cin >> linex[i];
		for(int i = 1; i < n; i++)
			cin >> liney[i];
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < m - 1; j++) {
				if(linex[i][j] == '2')
					linex[i][j] = '4';
			}
		}
		for(int i = 1; i <= q; i++) {
			init_for_chess();
			scanf("%d %d %d %d", &color, &level, &x, &y);
			bfs();
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= m; k++) {
					if(j == x && k == y || d[j][k].is_there && (d[j][k].color == color || d[j][k].level > level))
						continue;
					ans += b[j][k];
					// if(b[j][k]) printf("(%d, %d)\n", j, k);
				}
			}
			printf("%d\n", ans);
			d[x][y].is_there = 1, d[x][y].color = color, d[x][y].level = level;
		}
	}
	return 0;
}

/*
3
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
