#include <bits/stdc++.h>

using namespace std;

//char buf[1 << 21], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//
//inline int rd()
//{
//	char c = getchar(); int x = 0, f = 1;
//	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
//	while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
//	return x * f;
//}

char ch[100005];

bool ok[200005];
int col[200005], lv[200005], mk[200005][4], nowc, nowlv, ans, vis[200005], cnt, n, m, q;

#define pos(x, y) ((x - 1) * m + y)

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int tp, int frm)
{
	if (ok[pos(x, y)] && (nowlv < lv[pos(x, y)] || nowc == col[pos(x, y)])) return;
	else if (ok[pos(x, y)]) 
	{
		if (vis[pos(x, y)] != cnt) vis[pos(x, y)] = cnt, ++ans;
		return;
	} 
	if (vis[pos(x, y)] != cnt) ++ans, vis[pos(x, y)] = cnt; 
	else if (ok[pos(x, y)] && vis[pos(x, y)] != cnt) return;
	if (tp == 1) return;
	if (tp == 2)
	{
		if (mk[pos(x, y)][frm] == 2) dfs(x + dx[frm], y + dy[frm], tp, frm);
		return;
	}
	if (tp == 3)
	{
		for (int i = 0; i < 4; i++) 
		{
			int fx = x + dx[i], fy = y + dy[i];
			if (mk[pos(x, y)][i] == 3) dfs(fx, fy, tp, frm);
		}
	}
}

inline void solve()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", ch + 1);
		for (int j = 1; j < m; j++) mk[pos(i, j)][3] = mk[pos(i, j + 1)][2] = ch[j] - '0';
	}
	for (int i = 1; i < n; i++) 
	{
		scanf("%s", ch + 1);
		for (int j = 1; j <= m; j++) mk[pos(i, j)][1] = mk[pos(i + 1, j)][0] = ch[j] - '0';
	}
	for (int i = 1, c, l, x, y; i <= q; i++)
	{
		scanf("%d%d%d%d", &c, &l, &x, &y), ++cnt, ans = 0;
		ok[pos(x, y)] = 1, col[pos(x, y)] = c, lv[pos(x, y)] = l;
		nowc = c, nowlv = l;
		if (mk[pos(x, y)][2]) dfs(x - 1, y, mk[pos(x - 1, y)][2], 2);
		if (mk[pos(x, y)][3]) dfs(x + 1, y, mk[pos(x + 1, y)][3], 3);
		if (mk[pos(x, y)][0]) dfs(x, y - 1, mk[pos(x, y - 1)][0], 0);
		if (mk[pos(x, y)][1]) dfs(x, y + 1, mk[pos(x, y + 1)][1], 1);
		printf("%d\n", ans);
	}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
