#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= r; ++i)
#define rep2(i, l, r) for (int i = l; i >= r; --i)
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ptc putchar
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 1e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
namespace lrc
{
	template <typename T>
	il void read(T &x)
	{
		x = 0; int f = 1; char ch;
		while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T>
	il void read(pair <T, T> &p)
	{
		read(p.fst); read(p.snd);
	}

	template <typename T>
	il void write(T x)
	{
		if (x < 0) ptc('-'), x = -x;
		if (x > 9) write(x / 10);
		ptc(x % 10 + '0');
	}

	template <typename T>
	il void write(pair <T, T> p)
	{
		write(p.fst); ptc(' '); write(p.snd);
	}
}
using namespace lrc;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int T, n, m, q, cnt;
char k[MAXN];
queue <pii> qe;

il bool check(int x, int y)
{
	return x && y && x <= n && y <= m;
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	read(T);
	while (T--)
	{
		read(n); read(m); read(q);
		const int l = n, r = m;
		char s[l + 10][r + 10][5];
		// 0 1 2 3 ио об вС ср 
		bool vis[l + 10][r + 10], col[l + 10][r + 10];
		int lv[l + 10][r + 10];
		rep1(i, 1, l) rep1(j, 1, r) vis[i][j] = false, lv[i][j] = -1, col[i][j] = -1;
		rep1(i, 1, n)
		{
			scanf("%s", k + 1);
			rep1(j, 1, m - 1)
			{
				s[i][j][3] = k[j] - '0';
				s[i][j + 1][2] = k[j] - '0';
			}
		}
		rep1(i, 1, n - 1)
		{
			scanf("%s", k + 1);
			rep1(j, 1, m)
			{
				s[i][j][1] = k[j] - '0';
				s[i + 1][j][0] = k[j] - '0';
			}
		}
		while (q--)
		{
			int c, t, x, y; cnt = 0;
			read(c); read(t); read(x); read(y);
			lv[x][y] = t, col[x][y] = c; vis[x][y] = true;
			if (x > 1)
			{
				const int sm = s[x][y][0];
				if (!sm);
				else if (sm == 1)
				{
					if (!vis[x - 1][y]) vis[x - 1][y] = true, ++cnt;
					else if (!~col[x - 1][y] && col[x][y] ^ col[x - 1][y] && lv[x][y] >= lv[x - 1][y])
						++cnt;
				}
				else if (sm == 2)
				{
					rep2(i, x - 1, 1)
					{
						if (vis[i][y])
						{
							if (!~col[i][y] && col[x][y] ^ col[i][y] && lv[x][y] >= lv[i][y])
								++cnt;
							else break;
						}
						else ++cnt, vis[i][y] = true;
					}
				}
				else
				{
					qe.push(mp(x, y));
					while (qe.size())
					{
						pii now = qe.front(); qe.pop();
						if (!vis[now.fst][now.snd]) cnt += (vis[now.fst][now.snd] = true);
						rep1(i, 0, 3)
						{
							int nx = now.fst + dx[i], ny = now.snd + dy[i];
							if (check(nx, ny) && s[x][y][i] == sm)
							{
								if (vis[nx][ny] && !~col[nx][ny] && col[x][y] ^ col[nx][ny] && lv[x][y] >= lv[nx][ny])
									++cnt;
								else qe.push(mp(nx, ny));
							}
						}
					}
				}
			}
			if (x < n)
			{
				const int sm = s[x][y][1];
				if (!sm);
				else if (sm == 1)
				{
					if (!vis[x + 1][y]) vis[x + 1][y] = true, ++cnt;
					else if (!~col[x + 1][y] && col[x][y] ^ col[x + 1][y] && lv[x][y] >= lv[x + 1][y])
						++cnt;
				}
				else if (sm == 2)
				{
					rep1(i, x + 1, n)
					{
						if (vis[i][y])
						{
							if (!~col[i][y] && col[x][y] ^ col[i][y] && lv[x][y] >= lv[i][y])
								++cnt;
							else break;
						}
						else ++cnt, vis[i][y] = true;
					}
				}
				else
				{
					qe.push(mp(x, y));
					while (qe.size())
					{
						pii now = qe.front(); qe.pop();
						if (!vis[now.fst][now.snd]) cnt += (vis[now.fst][now.snd] = true);
						rep1(i, 0, 3)
						{
							int nx = now.fst + dx[i], ny = now.snd + dy[i];
							if (check(nx, ny) && s[x][y][i] == sm)
							{
								if (vis[nx][ny] && !~col[nx][ny] && col[x][y] ^ col[nx][ny] && lv[x][y] >= lv[nx][ny])
									++cnt;
								else qe.push(mp(nx, ny));
							}
						}
					}
				}
			}
			if (y > 1)
			{
				const int sm = s[x][y][2];
				if (!sm);
				else if (sm == 1)
				{
					if (!vis[x][y - 1]) vis[x][y - 1] = true, ++cnt;
					else if (!~col[x][y - 1] && col[x][y] ^ col[x][y - 1] && lv[x][y] >= lv[x][y - 1])
						++cnt;
				}
				else if (sm == 2)
				{
					rep2(i, y - 1, 1)
					{
						if (vis[x][i])
						{
							if (!~col[x][i] && col[x][y] ^ col[x][i] && lv[x][y] >= lv[x][i])
								++cnt;
							else break;
						}
						else ++cnt, vis[x][i] = true;
					}
				}
				else
				{
					qe.push(mp(x, y));
					while (qe.size())
					{
						pii now = qe.front(); qe.pop();
						if (!vis[now.fst][now.snd]) cnt += (vis[now.fst][now.snd] = true);
						rep1(i, 0, 3)
						{
							int nx = now.fst + dx[i], ny = now.snd + dy[i];
							if (check(nx, ny) && s[x][y][i] == sm)
							{
								if (vis[nx][ny] && !~col[nx][ny] && col[x][y] ^ col[nx][ny] && lv[x][y] >= lv[nx][ny])
									++cnt;
								else qe.push(mp(nx, ny));
							}
						}
					}
				}
			}
			if (y < n)
			{
				const int sm = s[x][y][3];
				if (!sm);
				else if (sm == 1)
				{
					if (!vis[x][y + 1]) vis[x][y + 1] = true, ++cnt;
					else if (!~col[x][y + 1] && col[x][y] ^ col[x][y + 1] && lv[x][y] >= lv[x][y + 1])
						++cnt;
				}
				else if (sm == 2)
				{
					rep1(i, y + 1, n)
					{
						if (vis[x][i])
						{
							if (!~col[x][i] && col[x][y] ^ col[x][i] && lv[x][y] >= lv[x][i])
								++cnt;
							else break;
						}
						else ++cnt, vis[x][i] = true;
					}
				}
				else
				{
					qe.push(mp(x, y));
					while (qe.size())
					{
						pii now = qe.front(); qe.pop();
						if (!vis[now.fst][now.snd]) cnt += (vis[now.fst][now.snd] = true);
						rep1(i, 0, 3)
						{
							int nx = now.fst + dx[i], ny = now.snd + dy[i];
							if (check(nx, ny) && s[x][y][i] == sm)
							{
								if (vis[nx][ny] && !~col[nx][ny] && col[x][y] ^ col[nx][ny] && lv[x][y] >= lv[nx][ny])
									++cnt;
								else qe.push(mp(nx, ny));
							}
						}
					}
				}
				write(cnt); puts(""); cnt = 0;
				rep1(i, 1, n) rep1(j, 1, m) vis[i][j] = false;
			} 
		}
	}
	return 0;
}
