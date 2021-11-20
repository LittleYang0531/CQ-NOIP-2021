#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 99991, mod = 1e8 + 9;
struct chess{
	int col, lv;
}a[mod + 5];
struct pd{
	int x, y, face;
	char op;
	pd (const int x_, const int y_, const char op_, const int face_):
		x(x_), y(y_), op(op_), face(face_)
	{}
};
string opt1[100005], opt2[100005];
int T, n, m, t, col, lv, x, y;
bool vis[mod + 5][4];
queue<pd> q;
int H(ll x, ll y){
	ll sum = (x * P + y) % mod;
	ll mul = (x * P * y) % mod;
	return (sum + mul) % mod;
}
int bfs(int sx, int sy, int col, int lv){
//	printf("Judging:\n");
	memset(vis, 0, sizeof(vis));
	int p = H(sx, sy), res = 0;
	vis[p][0] = vis[p][1] = vis[p][2] = vis[p][3] = 1;
	if (x > 1 && opt2[x - 1][y] != '0')
		q.push(pd(sx - 1, sy, opt2[sx - 1][sy] - '0', 1));
	if (y < m - 1 && opt1[x][y] != '0')
		q.push(pd(sx, sy + 1, opt1[sx][sy] - '0', 2));
	if (x < n && opt2[x][y] != '0')
		q.push(pd(sx + 1, sy, opt2[sx][sy] - '0', 3));
	if (y > 0 && opt1[x][y - 1] != '0')
		q.push(pd(sx, sy - 1, opt1[sx][sy - 1] - '0', 4));
	while(!q.empty()){
		int x = q.front().x, y = q.front().y, op = q.front().op, face = q.front().face;
		q.pop();
		p = H(x, y);
//		printf("%d %d(%d) %d %d\n", x, y + 1, p, op, face);
		if (vis[p][op]) continue;
		if (a[p].lv){
			if (!vis[p][0] && !vis[p][1] && !vis[p][2] && !vis[p][3] && a[p].col != col && a[p].lv <= lv) res++, vis[p][op] = 1;
			continue;
		}
		if (!vis[p][0] && !vis[p][1] && !vis[p][2] && !vis[p][3]) res++;
		vis[p][op] = 1;
		if (op == 1) continue;
		if (op == 2){
			if (x > 1 && face == 1 && opt2[x - 1][y] == '2' && !vis[H(x - 1, y)][op]) q.push(pd(x - 1, y, op, face));
			if (y < m - 1 && face == 2 && opt1[x][y] == '2' && !vis[H(x, y + 1)][op]) q.push(pd(x, y + 1, op, face));
			if (x < n && face == 3 && opt2[x][y] == '2' && !vis[H(x + 1, y)][op]) q.push(pd(x + 1, y, op, face));
			if (y > 0 && face == 4 && opt1[x][y - 1] == '2' && !vis[H(x, y - 1)][op]) q.push(pd(x, y - 1, op, face));
		}
		if (op == 3){
			if (x > 1 && opt2[x - 1][y] == '3' && !vis[H(x - 1, y)][op]) q.push(pd(x - 1, y, op, 1));
			if (y < m - 1 && opt1[x][y] == '3' && !vis[H(x, y + 1)][op]) q.push(pd(x, y + 1, op, 2));
			if (x < n && opt2[x][y] == '3' && !vis[H(x + 1, y)][op]) q.push(pd(x + 1, y, op, 3));
			if (y > 0 && opt1[x][y - 1] == '3' && !vis[H(x, y - 1)][op]) q.push(pd(x, y - 1, op, 4));
		}
	}
	return res;
}
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &m, &t);
		for (int i = 0; i <= n; i++)	
			for (int j = 0; j <= n; j++)
				a[H(i, j)].col = 0, a[H(i, j)].lv = 0;
		for (int i = 1; i <= n; i++)
			cin >> opt1[i];
		for (int i = 1; i < n; i++)
			cin >> opt2[i];
		while(t--){
			scanf("%d %d %d %d", &col, &lv, &x, &y);
			y--;
			int p = H(x, y);
			a[p].col = col, a[p].lv = lv;
			printf("%d\n", bfs(x, y, col, lv));
		}
	}
	return 0;
};

