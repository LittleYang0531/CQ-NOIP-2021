#include <bits/stdc++.h>


using namespace std;
const int N = 5e3 + 10;
int n,m,q;
int vis[N][N][4];
int rec[N][N],rel[N][N];
int heng[N][N],shu[N][N];
int mp[N][N];
//vector<int> S[N];
//vec
char s[N];
int ans = 0;
inline void dfs(int x,int y,int opt,int c,int l,int di) {
	if(vis[x][y][opt]) return ;
	vis[x][y][opt] = 1;
	if(rel[x][y]) {
		if(rec[x][y] != c && rel[x][y] <= l) {
			ans += (mp[x][y] == 0);
			mp[x][y] = 1;
		}
		return ;
	} 
	ans = ans + (mp[x][y] == 0);
	mp[x][y] = 1;
	if(opt == 1) return ;
	if(opt == 2) {
		if(di == 0) {
			if(heng[x][y] == opt && vis[x][y + 1][opt] == 0 && y < m) 
			dfs(x,y + 1,opt,c,l,0);
			if(heng[x][y - 1] == opt && vis[x][y - 1][opt] == 0 && y > 1) 
			dfs(x,y - 1,opt,c,l,0);
		}
		else {
			if(shu[x][y] == opt && vis[x + 1][y][opt] == 0 && x < n)
			dfs(x + 1,y,opt,c,l,1);
			if(shu[x - 1][y] == opt && vis[x - 1][y][opt] == 0 && x > 1)
			dfs(x - 1,y,opt,c,l,1);
		}
	}
	if(opt == 3) {
		if(opt == heng[x][y] && y < m && vis[x][y + 1][opt] == 0)	dfs(x,y + 1,heng[x][y],c,l,0);
		if(opt == shu[x][y] && x < n && vis[x + 1][y][opt] == 0) dfs(x + 1,y,shu[x][y],c,l,1);
		if(opt == heng[x][y - 1] && y > 1 && vis[x][y - 1][opt] == 0) dfs(x,y - 1,heng[x][y - 1],c,l,0);
		if(opt == shu[x - 1][y] && x > 1 && vis[x - 1][y][opt] == 0) dfs(x - 1,y,shu[x - 1][y],c,l,1);
	}
}

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int times;
	cin >> times;
	while(times--) {
		
		cin >> n >> m >> q;
		if(n * m <= 5e3) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= m;j++) rec[i][j] = 0,rel[i][j] = 0;
			}
			for(int i = 1;i <= n;i++) {
				cin >> (s + 1);
				for(int j = 1;j < m;j++) heng[i][j] = s[j] - '0';
			}
			for(int i = 1;i < n;i++) {
				cin >> (s + 1);
				for(int j = 1;j <= m;j++) shu[i][j] = s[j] - '0';
			}
			for(int i = 1;i <= q;i++) {
				for(int j = 1;j <= n;j++) {
					for(int k = 1;k <= m;k++) vis[j][k][0] = vis[j][k][1] = vis[j][k][2] = vis[j][k][3] = mp[j][k] = 0;
				}
				int col,lv,x,y;
				cin >> col >> lv >> x >> y;
				vis[x][y][0] = vis[x][y][1] = vis[x][y][2] = vis[x][y][3] = 1,rec[x][y] = col,rel[x][y] = lv;
				ans = 0;
				if(heng[x][y] && y < m)	dfs(x,y + 1,heng[x][y],col,lv,0);
				if(shu[x][y] && x < n) dfs(x + 1,y,shu[x][y],col,lv,1);
				if(heng[x][y - 1] && y > 1) dfs(x,y - 1,heng[x][y - 1],col,lv,0);
				if(shu[x - 1][y] && x > 1) dfs(x - 1,y,shu[x - 1][y],col,lv,1);
				cout << ans << '\n';
			}
		} else {
			
		}
	}
	return 0;
}
