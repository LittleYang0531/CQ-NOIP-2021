#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 2e5 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct node{
	int col, lv;
};
int n, m, q, ans, T;
//bool vis[N][N], Judge[N][N];
//int mp[2][N][N];
string s;
vector<int> mp[2][N];
vector<node> arr[N];
vector<bool> vis[N], Judge[N];
inline void DFS(int x, int y, int opt, int from, int v, int c)
{
//	cout << x << " " << y << "\n";
	if(!Judge[x][y]) ans++, Judge[x][y] = true;
	vis[x][y] = true;
	for(register int i = 0; i <= 3; i++){
		if(opt == 2 && i != from) continue;
		int nx = x + dx[i], ny = y + dy[i], flag = -1;
		if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if(i == 0) flag = mp[0][x][y];
		if(i == 1) flag = mp[0][x][y - 1];
		if(i == 2) flag = mp[1][x][y];
		if(i == 3) flag = mp[1][x - 1][y];
		if(flag != opt) continue;
		if(vis[nx][ny]) continue;
		if(arr[nx][ny].col != -1){
			if(arr[nx][ny].col == c) continue;
			if(arr[nx][ny].lv > v) continue;
			else{
				if(!Judge[nx][ny]) ans++, Judge[nx][ny] = true;
				continue;
			}
		}
		DFS(nx, ny, opt, from, v, c);
	}
}
int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	T = read();
	while(T--){
		n = read(), m = read(), q = read();
		for(register int i = 1; i <= n; i++){
			arr[i].clear(); vis[i].clear(); Judge[i].clear();
			for(register int j = 0; j <= m; j++){
				arr[i].push_back((node){-1, -1});
				vis[i].push_back(false), Judge[i].push_back(false);
			}
		}
		for(register int i = 1; i <= n; i++){
			cin >> s;
			mp[0][i].clear();
			mp[0][i].push_back(-1);
			for(register int j = 0; j < s.size(); j++)
				mp[0][i].push_back(s[j] - '0');
		}
		for(register int i = 1; i < n; i++){
			cin >> s;
			mp[1][i].clear();
			mp[1][i].push_back(-1);
			for(register int j = 0; j < s.size(); j++)
				mp[1][i].push_back(s[j] - '0');
		}
		while(q--){
			ans = 0;
			int c = read(), v = read(), x = read(), y = read();
			for(register int i = 1; i <= n; i++)
				for(register int j = 1; j <= m; j++) vis[i][j] = Judge[i][j] = false;
			for(register int i = 0; i <= 3; i++){
				int nx = x + dx[i], ny = y + dy[i], opt;
				if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if(i == 0) opt = mp[0][x][y];
				if(i == 1) opt = mp[0][x][y - 1];
				if(i == 2) opt = mp[1][x][y];
				if(i == 3) opt = mp[1][x - 1][y];
				if(arr[nx][ny].col != -1){
					if(arr[nx][ny].col == c) continue;
					if(arr[nx][ny].lv > v) continue;
					else{
						if(!Judge[nx][ny]) ans++, Judge[nx][ny] = true;
						continue;
					}
				}
				if(opt == 0) continue;
				if(opt == 1){
					if(!Judge[nx][ny]) ans++, Judge[nx][ny] = true;
					continue;
				}
				for(register int i = 1; i <= n; i++)
					for(register int j = 1; j <= m; j++) vis[i][j] = false;
				vis[x][y] = true;
				DFS(nx, ny, opt, i, v, c);
			}
			printf("%d\n", ans);
			arr[x][y].col = c, arr[x][y].lv = v;
		}
	}
	return 0;
}
