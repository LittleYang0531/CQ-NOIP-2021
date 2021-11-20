#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};

int t, n, m, q, ans, root, col[MAXN], lv[MAXN];
bool vis[MAXN];

struct edge {
	int v, w;
	edge() {}
	edge(int V, int W) {
		v = V, w = W;
	}
};
vector<edge> G[MAXN];

int ind(int x, int y) {
	return (x - 1) * m + y;
}

void dfs(int now, int turn) {
	if (lv[now] != 0 && turn != 0) {
		vis[now] = 1;
		if (col[now] != col[root] && lv[root] >= lv[now]) {
			ans++;
		}
		return;
	}
	
	vis[now] = 1, ans++;
	if (turn == -1) {
		return;
	}
	
	for (int i = 0; i < G[now].size(); i++) {
		
		int v = G[now][i].v, w = G[now][i].w;
		if (vis[v]) continue;
		
		if (w == 1 && turn == 0) {
			dfs(v, -1);
		}
		
		if (w == 2 && (0 <= turn && turn <= 4)) {
			int tmp = 0;
			
			if (v + 1 == now) {
				tmp = 4;
			}
			if (v - 1 == now) {
				tmp = 3;
			}
			if (v + m == now) {
				tmp = 2;
			}
			if (v - m == now) {
				tmp = 1;
			}
			
			if (tmp == turn || turn == 0) {
				dfs(v, tmp);
			}
			
		}
		
		if (w == 3 && (turn == 0 || turn == 5)) {
			dfs(v, 5);
		}
		
	}
	
}

int main() {
	
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 0; i <= 1e5; i++) {
			G[i].clear();
		}
		memset(lv, 0, sizeof(lv));
		memset(col, 0, sizeof(col));
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1, x; j < m; j++) {
				char c; cin >> c;
				x = (c - '0');
				G[ind(i, j)].push_back(edge(ind(i, j + 1), x));
				G[ind(i, j + 1)].push_back(edge(ind(i, j), x));
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 1, x; j <= m; j++) {
				char c; cin >> c;
				x = (c - '0');
				G[ind(i, j)].push_back(edge(ind(i + 1, j), x));
				G[ind(i + 1, j)].push_back(edge(ind(i, j), x));
			}
		}
		
		while (q--) {
			
			int x, y, c, l;
			scanf("%d %d %d %d", &c, &l, &x, &y);
			
			memset(vis, 0, sizeof(vis));
			ans = 0; root = ind(x, y);
			col[root] = c, lv[root] = l;
			dfs(root, 0);
			
			printf("%d\n", ans - 1);
			
		}
		
	}
	
	return 0;
}
