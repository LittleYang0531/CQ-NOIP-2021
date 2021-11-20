#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define pii pair<int, int>
#define MAXNM 500005
using namespace std;

namespace _MAIN{
	int n, m, q;
	inlint read(){
		register int nega = 1, num = 0, c = getchar();
		for(;~c&&!isdigit(c);c=getchar()) if(c=='-')nega=-1;
		for(;~c&& isdigit(c);c=getchar()) (num*=10)+=c-'0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	int r[MAXNM], u[MAXNM], d[MAXNM], l[MAXNM];
	int inq[MAXNM], vis[MAXNM], vcnt;
	inlint p(int x, int y){
		return (x - 1) * m + y;
	}
	inbool inb(int x, int y) {
		return x >= 1 && x <= n && y >= 1 && y <= m;
	}
	int ches[MAXNM];
	inloid addP(int x, int y, int che) {
		if(ches[p(x, y)] != 0 && (ches[p(x, y)] * che > 0 || abs(ches[p(x, y)]) > abs(che))) return;
		if(!vis[p(x, y)]) vis[p(x, y)] = 1, vcnt++;
	}
	inloid dfs(int x, int y, int dx, int dy, int che) {
		addP(x, y, che);
		if(ches[p(x, y)]) return;
		if(dx == -1 && u[p(x, y)] ==2) dfs(x - 1, y, dx, dy, che);
		if(dx == 1 && d[p(x, y)] == 2) dfs(x + 1, y, dx, dy, che);
		if(dy == -1 && l[p(x, y)] ==2) dfs(x, y - 1, dx, dy, che);
		if(dy == 1 && r[p(x, y)] == 2) dfs(x, y + 1, dx, dy, che);
	}
	// l x - 1 
	// r x + 1
	// u y - 1
	// d y + 1
	inloid bfs(int sx, int sy, int che) {
		queue<pii> q;
		q.push(make_pair(sx, sy)), inq[p(sx, sy)] = 1;
		for(; !q.empty(); q.pop()) {
			pii h = q.front();
			int x = h.first, y = h.second;
			if(x != sx || y != sy) addP(x, y, che);
			if(ches[p(x, y)]) continue;
			if(l[p(x, y)] == 3 && !inq[p(x, y - 1)]) q.push(make_pair(x, y - 1)), inq[p(x, y - 1)] = 1;
			if(r[p(x, y)] == 3 && !inq[p(x, y + 1)]) q.push(make_pair(x, y + 1)), inq[p(x, y + 1)] = 1;
			if(u[p(x, y)] == 3 && !inq[p(x - 1, y)]) q.push(make_pair(x - 1, y)), inq[p(x - 1, y)] = 1;
			if(d[p(x, y)] == 3 && !inq[p(x + 1, y)]) q.push(make_pair(x + 1, y)), inq[p(x + 1, y)] = 1;
		}
	}
	inloid sea(int x, int y, int che){
		memset(inq, 0, sizeof(inq)), vcnt = 0, memset(vis, 0, sizeof(vis));
		if(u[p(x, y)] == 2) dfs(x - 1, y, -1, 0, che);
		if(d[p(x, y)] == 2) dfs(x + 1, y, 1, 0, che);
		if(l[p(x, y)] == 2) dfs(x, y - 1, 0, -1, che);
		if(r[p(x, y)] == 2) dfs(x, y + 1, 0, 1, che);
		if(u[p(x, y)] == 1) addP(x - 1, y, che);
		if(d[p(x, y)] == 1) addP(x + 1, y, che);
		if(l[p(x, y)] == 1) addP(x, y - 1, che);
		if(r[p(x, y)] == 1) addP(x, y + 1, che);
		bfs(x, y, che);
		ches[p(x, y)] = che;
		cout << vcnt << "\n";
	}
	char str[MAXNM];
	inloid clr() {
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(u, 0, sizeof(u));
		memset(d, 0, sizeof(d));
		memset(ches, 0, sizeof(ches));
	}
} using namespace _SOLV;

signed main(void){
	freopen("chess.in", "r", stdin), freopen("chess.out", "w", stdout);
for(int t = read(); t--;) {
	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) {
		scanf("%s", str + 1);
		for(int j = 1; j < m; j++) 
			r[p(i, j)] = l[p(i, j + 1)] = str[j] - '0';
	}
	for(int i = 1; i < n; i++) {
		scanf("%s", str + 1);
		for(int j = 1; j <= m; j++) 
			d[p(i, j)] = u[p(i + 1, j)] = str[j] - '0';
	}
//	return 0;	
	for(int i = 1; i <= q; i++) {
		int col = read() == 0 ? -1 : 1, che = col * read(), x = read(), y = read();
		sea(x, y, che);
	}
	clr();
}
	return fclose(stdin), fclose(stdout), 0;
}

