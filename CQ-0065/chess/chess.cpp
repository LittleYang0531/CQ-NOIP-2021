#include<bits/stdc++.h>
#define re register
//#define pair pair<int, int>
//#define int long long
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
using namespace std;
inline int read()
{
	re int x = 0;
	bool f = 0;
	re char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-') f = 1;
		ch = getchar();
	}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 2e5 + 5, b = 131, P = 1e9 + 7;
int n, m, q;
int e[N][4];
pair<int, int> mp[N];
bool vis[N];
int dx[] = {-1, 1, 0 ,0}, dy[] = {0, 0, -1, 1};
inline int id(int i, int j) {return (i - 1) * m + j;}
signed main()
{
	File("chess");
	int T = read();
	while (T--)
	{
		n = read(), m = read(), q = read();
		for (re int i = 1; i <= n * m; ++i) mp[i] = make_pair(-1, 0), e[i][0] = e[i][1] = e[i][2] = e[i][3] = 0;
		for (re int i = 1; i <= n; ++i)
		{
			string s;
			getline(cin, s);
			for (re int j = 0; j < m - 1; ++j)
			{
				int u = id(i, j + 1), v = id(i, j + 2), val = s[j] - '0';
				e[u][3] = e[v][2] = val;
			}
		}
		for (re int i = 1; i < n; ++i)
		{
			string s;
			getline(cin, s);
			for (re int j = 0; j < m; ++j)
			{
				int u = id(i, j + 1), v = id(i + 1, j + 1), val = s[j] - '0';
				e[u][1] = e[v][0] = val;
			}
		}
		while (q--)
		{
			bool col = read();
			int lv = read(), x = read(), y = read(), ans = 0;
			queue<pair<pair<int, int>, pair<int, int> > > q;
			q.push(make_pair(make_pair(-1, -1), make_pair(x, y)));
			mp[id(x, y)] = make_pair(col, lv);
			for (re int i = 1; i <= n * m; ++i) vis[i] = 0;
			vis[id(x, y)] = 1;
			while (!q.empty())
			{
				pair<int, int> u = q.front().second;
				int now = q.front().first.first, dir = q.front().first.second; q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int xx = u.first + dx[i], yy = u.second + dy[i];
					int kind = e[id(u.first, u.second)][i];
					if (xx < 1 || xx > n || yy < 1 || yy > m || !kind) continue;
					if (now != -1 && kind != now) continue;
					if (vis[id(xx, yy)]) continue;
					if (kind == 2 && dir != -1 && dir != i) continue;
					if (mp[id(xx, yy)].first != -1)
					{
						if (mp[id(xx, yy)].first == col || mp[id(xx, yy)].second > lv) continue;
						ans++;
//						cout << xx << ' ' << yy << endl;
						vis[id(xx, yy)] = 1;
						continue;
					}
					ans++;
					vis[id(xx, yy)] = 1;
//					cout << xx << ' ' << yy << endl;
					if (kind != 1) q.push(make_pair(make_pair(kind, i), make_pair(xx, yy)));
				}
			}
			printf("%d\n", ans);
		}
	}
	
	
	return 0;
}
