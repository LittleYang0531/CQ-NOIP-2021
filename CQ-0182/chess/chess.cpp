#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#define Geths(x,y) ((x-1)*m+y)
#define LL long long
#define uint unsigned int
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, q, a[MAXN][5], T, col[MAXN], lv[MAXN], X[MAXN], Y[MAXN];
int dfn, head, tail, ans, t, Cas;
int Lv[MAXN], Col[MAXN], vis[MAXN], F[MAXN][5];
int fuckfuck, fa[MAXN][5];
int zbx[MAXN], zby[MAXN];
int qaq[MAXN];
char s[MAXN];
int tox[5] = {-1, 0, 1, 0}, toy[5] = {0, -1, 0, 1};
queue <int> que;
// 0123，上左下右 
// ri，大模拟？
void read(int &x) {
	x = 0; bool f = 1; char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') f = 0;
	for(; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = (f ? x : -x);
} 
void bfs(int x) {
	for(int i = X[x] + 1; i <= n; i ++) {
		if(F[Geths(i - 1, Y[x])][2] != 2) break;
		t = Geths(i, Y[x]);
		if(Lv[t]) {
			if(lv[x] >= Lv[t] && col[x] != Col[t]) {
				ans += (vis[t] != dfn); vis[t] = dfn;
			}
			break;
		}
		ans += (vis[t] != dfn); vis[t] = dfn;
	}
	for(int i = X[x] - 1; i >= 1; i --) {
		if(F[Geths(i + 1, Y[x])][0] != 2) break;
		t = Geths(i, Y[x]);
		if(Lv[t]) {
			if(lv[x] >= Lv[t] && col[x] != Col[t]) {
				ans += (vis[t] != dfn); vis[t] = dfn;
			}
			break;
		}
		ans += (vis[t] != dfn); vis[t] = dfn;
	}
	for(int i = Y[x] + 1; i <= m; i ++) {
		if(F[Geths(X[x], i - 1)][3] != 2) break;
		t = Geths(X[x], i);
		if(Lv[t]) {
			if(lv[x] >= Lv[t] && col[x] != Col[t]) {
				ans += (vis[t] != dfn); vis[t] = dfn;
			}
			break;
		}
		ans += (vis[t] != dfn); vis[t] = dfn;
	}
	for(int i = Y[x] - 1; i >= 1; i --) {
		if(F[Geths(X[x], i + 1)][1] != 2) break;
		t = Geths(X[x], i); 
		if(Lv[t]) {
			if(lv[x] >= Lv[t] && col[x] != Col[t]) {
				ans += (vis[t] != dfn); vis[t] = dfn;
			}
			break;
		}
		ans += (vis[t] != dfn); vis[t] = dfn;
	}
	for(int i = 0; i <= 3; i ++) {
		if(F[Geths(X[x], Y[x])][i] == 1) {
			int fuckx = X[x] + tox[i], fucky = Y[x] + toy[i];
			t = Geths(fuckx, fucky);
			if(fuckx >= 1 && fuckx <= n && fucky >= 1 && fucky <= m && lv[x] >= Lv[t] && col[x] != Col[t]) {
				ans += (vis[t] != dfn); vis[t] = dfn;
			}
		}
	}
	que.push(Geths(X[x], Y[x])); qaq[Geths(X[x], Y[x])] = dfn;
	while(!que.empty()) {
		t = que.front(); que.pop();
		for(int i = 0; i <= 3; i ++) {
			if(F[t][i] != 3) continue;
			q = a[t][i];
			if(!q || qaq[q] == dfn) continue;
			if(vis[q] != dfn && Col[q] != col[x] && lv[x] >= Lv[q]) vis[q] = dfn, ans ++;
			qaq[q] = dfn;
			if(!Lv[q]) que.push(q);
		}
	}
	Col[Geths(X[x], Y[x])] = col[x]; Lv[Geths(X[x], Y[x])] = lv[x];
}
int Abs(int x) { return x > 0 ? x : -x; }
//int Find_Set(int x, int eee) { return fa[x][eee] != x ? fa[x][eee] = Find_Set(fa[x][eee]) : fa[x][eee]; }
//void Subtask7to11() {
//	for(int i = 0; i <= 3; i ++) {
//		if(F[Geths(X[x], Y[x])][i] == 1) {
//			int fuckx = X[x] + tox[i], fucky = Y[x] + toy[i];
//			t = Geths(fuckx, fucky);
//			if(fuckx >= 1 && fuckx <= n && fucky >= 1 && fucky <= m && lv[x] >= Lv[t] && col[x] != Col[t]) {
//				ans += (vis[t] != dfn); vis[t] = dfn;
//			}
//		}
//	}
//	for(int i = 0; i <= 3; i ++) {
//		int g = Find_Set(Geths(X[x], Y[x]), i);
//		int xxx = zbx[g], yyy = zby[g];
//		if(xxx == X[x] && yyy == Y[x]) continue;
//		if(xxx == X[x]) ans += Abs(yyy - Y[x]) - 1;
//		else ans += Abs(xxx - X[x]) - 1;
//		if(col[x] != Col[g] && Lv[g] <= lv[x]) ans ++;
//	}
//	Col[Geths(X[x], Y[x])] = col[x]; Lv[Geths(X[x], Y[x])] = lv[x];
//	for(int i = X[x] + 1; i <= n; i ++) {
//		t = Geths(i, Y[x]); q = Geths(i - 1, Y[x]);
//		if(F[q][2] != 2) break;
//		if(Find_Set(t) == Find_Set(q)) 
//		t = Geths(i, Y[x]);
//		fa[Geths(i - 1, Y[x])][2] = Geths(i, Y[x]);
//		fa[Geths(i, Y[x])][0] = Geths(i - 1, Y[x]);
//	}
//	for(int i = X[x] - 1; i >= 1; i --) {
//		if(F[Geths(i - 1, Y[x])][2] != 2) break;
//		t = Geths(i, Y[x]);
//		fa[Geths(i - 1, Y[x])][2] = Geths(i, Y[x]);
//		fa[Geths(i, Y[x])][0] = Geths(i - 1, Y[x]);
//	}
//}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	read(Cas);
	while(Cas --) {
		read(n); read(m); read(T); fuckfuck = 0; memset(a, 0, sizeof(a));
		for(int i = 0; i <= n * m; i ++) Lv[i] = 0, Col[i] = -1, vis[i] = -1, qaq[i] = -1;
		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) zbx[Geths(i, j)] = i, zby[Geths(i, j)] = j;
		for(int i = 1; i <= n; i ++) {
			scanf("%s", s + 1);
			for(int j = 1; j <= m - 1; j ++) {
				t = Geths(i, j); q = Geths(i, j + 1); fuckfuck = max(fuckfuck, s[j] - '0');
				a[t][3] = q; a[q][1] = t; F[t][3] = s[j] - '0'; F[q][1] = s[j] - '0'; 
			}
		}
		for(int i = 1; i <= n - 1; i ++) {
			scanf("%s", s + 1);
			for(int j = 1; j <= m; j ++) {
				t = Geths(i, j); q = Geths(i + 1, j); fuckfuck = max(fuckfuck, s[j] - '0');
				a[t][2] = q; a[q][0] = t; F[t][2] = s[j] - '0'; F[q][0] = s[j] - '0'; 
			}
		}
		for(int i = 1; i <= T; i ++) read(col[i]), read(lv[i]), read(X[i]), read(Y[i]);
	//	if(T <= 2000 && n * m <= 5000) {
			for(int i = 1; i <= T; i ++) {
				dfn = i; ans = 0; bfs(i); printf("%d\n", ans);
			}
			continue;
	//	}
//		if(fuckfuck <= 2) {
//			dfn = i; ans = 0; Subtask7to11(); printf("%d\n", ans); continue;
//		}
	}
	
	return 0;
}

