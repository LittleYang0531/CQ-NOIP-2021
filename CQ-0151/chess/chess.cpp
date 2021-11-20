#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int mx = 2e5;

int n, m, q;
char right[mx + 5];
char down[mx + 5];
bool vis[mx + 5];
bool nvis[mx + 5];

struct chess
{
	int col, lv;
	chess () { col = lv = 0; }
} c[mx + 5];

struct node
{
	int x, y;
	node () {}
	node (int node_x, int node_y) { x = node_x, y = node_y; }
} ;

int h(int x, int y)
{
	return (x - 1) * m + y;
}

int bfs(int col, int lv, int x, int y)
{
	int res = 0;
	for (int i = n * m; i >= 1; i--)
		vis[i] = false;
	for (int tx = x - 1; tx >= 1; tx--)
	{
		int ha = h(tx, y);
		if (down[ha] == '2')
		{
			if (!c[ha].lv)
			{
				vis[ha] = true;
			}
			else
			{
				if (c[ha].col != col && lv >= c[ha].lv)
					vis[ha] = true;
				break;
			}
		}
		else
		{
			break;
		}
	}
	for (int tx = x + 1; tx <= n; tx++)
	{
		int ha = h(tx, y);
		if (down[h(tx - 1, y)] == '2')
		{
			if (!c[ha].lv)
			{
				vis[ha] = true;
			}
			else
			{
				if (c[ha].col != col && lv >= c[ha].lv)
					vis[ha] = true;
				break;
			}
		}
		else
		{
			break;
		}
	}
	for (int ty = y - 1; ty >= 1; ty--)
	{
		int ha = h(x, ty);
		if (right[ha] == '2')
		{
			if (!c[ha].lv)
			{
				vis[ha] = true;
			}
			else
			{
				if (c[ha].col != col && lv >= c[ha].lv)
					vis[ha] = true;
				break;
			}
		}
		else
		{
			break;
		}
	}
	for (int ty = y + 1; ty <= m; ty++)
	{
		int ha = h(x, ty);
		if (right[h(x, ty - 1)] == '2')
		{
			if (!c[ha].lv)
			{
				vis[ha] = true;
			}
			else
			{
				if (c[ha].col != col && lv >= c[ha].lv)
					vis[ha] = true;
				break;
			}
		}
		else
		{
			break;
		}
	}
	for (int s = '1'; s <= '3'; s += 2)
	{
		for (int i = n * m; i >= 1; i--)
			nvis[i] = false;
		queue<node> q;
		q.push(node(x, y));
		while (!q.empty())
		{
			node u = q.front(); q.pop();
//			if (col == 1 && lv == 1328 && x == 141 && y == 30)
//				printf(" 22 %d\n", vis[4260]);
//			if (col == 1 && lv == 1328 && x == 141 && y == 30)
//				printf(" x=%d y=%d hash=%d\n", u.x, u.y, h(u.x, u.y));
			if (u.x > 1)
			{
				int ha = h(u.x - 1, u.y);
				if (down[ha] == s && !nvis[ha])
				{
					if (!c[ha].lv)
					{
						vis[ha] = nvis[ha] = true;
						q.push(node(u.x - 1, u.y));
					}
					else
					{
						if (c[ha].col != col && lv >= c[ha].lv)
							vis[ha] = nvis[ha] = true;
					}
				}
			}
			if (u.x < n)
			{
				int ha = h(u.x + 1, u.y);
				if (down[h(u.x, u.y)] == s && !nvis[ha])
				{
					if (!c[ha].lv)
					{
						vis[ha] = nvis[ha] = true;
						q.push(node(u.x + 1, u.y));
					}
					else
					{
						if (c[ha].col != col && lv >= c[ha].lv)
							vis[ha] = nvis[ha] = true;
					}
				}
			}
			if (u.y > 1)
			{
				int ha = h(u.x, u.y - 1);
//				printf("%d %d %d\n", -1, 4, ha);
				if (right[ha] == s && !nvis[ha])
				{
					if (!c[ha].lv)
					{
						vis[ha] = nvis[ha] = true;
						q.push(node(u.x, u.y - 1));
					}
					else
					{
						if (c[ha].col != col && lv >= c[ha].lv)
							vis[ha] = nvis[ha] = true;
					}
				}
			}
			if (u.y < m)
			{
				int ha = h(u.x, u.y + 1);
				if (right[h(u.x, u.y)] == s && !nvis[ha])
				{
					if (!c[ha].lv)
					{
						vis[ha] = nvis[ha] = true;
						q.push(node(u.x, u.y + 1));
					}
					else
					{
						if (c[ha].col != col && lv >= c[ha].lv)
							vis[ha] = nvis[ha] = true;
					}
				}
			}
		}
//		if (col == 1 && lv == 1328 && x == 141 && y == 30)
//			printf(" 32  %d\n", vis[4260]);
	}
//	if (col == 1 && lv == 1328 && x == 141 && y == 30)
//		printf(" 34    %d\n", vis[4260]);
	for (int i = n * m; i >= 1; i--)
	{
		res += vis[i];
//		if (col == 1 && lv == 1328 && x == 141 && y == 30 && vis[i])
//		{
//			printf("   %d %d %d %d\n", i, n, m, n * m);
//		}
	}
//	if (col == 1 && lv == 1328 && x == 141 && y == 30)
//		printf("%d\n", res);
	return res;
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T = rint();
	while (T--)
	{
		n = rint(), m = rint(), q = rint();
		for (int i = n * m; i >= 1; i--)
			c[i].col = c[i].lv = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", right + (i - 1) * m + 1);
			right[i * m] = '0';
		}
		for (int i = 1; i < n; i++)
			scanf("%s", down + (i - 1) * m + 1);
		while (q--)
		{
			int col = rint(), lv = rint(), x = rint(), y = rint();
			c[h(x, y)].col = col; c[h(x, y)].lv = lv;
			printf("%d\n", bfs(col, lv, x, y));
		}
	}
	return 0;
}

