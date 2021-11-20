#include <bits/stdc++.h>

namespace Solve {
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	int const N = 2e5;
	
	struct Node {
		int to;
		int kind;
		int d;
	};
	
	struct State {
		int id;
		int kind;
		int d;
	};
	
	struct Chess {
		int col;
		int lev;
	};
	
	Chess grid[N + 1];
	std::vector<std::vector<int>> id;
	std::vector<Node> graph[N + 1];
	bool vis[N + 1][4][4];
	bool cur[N + 1];
	bool as[N + 1];
	std::vector<int> cnt;
	std::vector<State> roll;
	int ans;
	int n, m, q;
	
	void dfs(int id, int kind, int d, int col, int lev) {
		cur[id] = true;
		vis[id][kind][d] = true;
		
		roll.push_back({ id, kind, d });
		
		for (auto to : graph[id]) {
			if (to.kind == 0) {
				continue;
			}
			
			if (kind && to.kind != kind) {
				continue;
			}
			
			if (kind == 2 && to.d != d) {
				continue;
			}
			
			if (kind == 1) {
				continue;
			}
			
			if (grid[to.to].lev && (grid[to.to].col == col || grid[to.to].lev > lev)) {
				continue;
			}
			
			if (!cur[to.to] && !vis[to.to][to.kind][to.d]) {
				if (!as[to.to]) {
					cnt.push_back(to.to);
					as[to.to] = true;
					ans++;
				}
				
				if (!grid[to.to].lev) {
					dfs(to.to, to.kind, to.d, col, lev);
				}
			}
		}
		
		cur[id] = false;
	}
	
	void init() {
		
	}
	
	void main() {
		std::cin >> n >> m >> q;
		
		id.resize(n + 1, std::vector<int>(m + 1));
		
		int all = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				all++;
				id[i][j] = all;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < m; j++) {
				char c;
				std::cin >> c;
				c -= '0';
				
				graph[id[i][j]].push_back({ id[i][j + 1], c, 0 });
				graph[id[i][j + 1]].push_back({ id[i][j], c, 0 });
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				std::cin >> c;
				c -= '0';
				
				graph[id[i][j]].push_back({ id[i + 1][j], c, 1 });
				graph[id[i + 1][j]].push_back({ id[i][j], c, 1 });
			}
		}
		
		for (int i = 1; i <= q; i++) {
			int col, lev;
			int x, y;
			std::cin >> col >> lev >> x >> y;
			
			ans = 0;
			dfs(id[x][y], 0, 3, col, lev);
//			std::cerr << id[x][y] << '\n';
			grid[id[x][y]] = { col, lev };
			
			std::cout << ans << '\n';
			
			for (auto p : roll) {
				vis[p.id][p.kind][p.d] = false;
			}
			
			for (int p : cnt) {
				as[p] = false;
			}
			
			roll.clear();
			cnt.clear();
		}
	}
	
	void clear() {
		memset(grid, 0, sizeof grid);
		std::vector<std::vector<int>>().swap(id);
		for (int i = 1; i <= n * m; i++) {
			graph[i].clear();
		}
	}
}

signed main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int t;
	std::cin >> t;
	
	Solve::init();
	
	for (; t; t--) {
		Solve::main();	
		Solve::clear();
	}
	
	return 0;
}
