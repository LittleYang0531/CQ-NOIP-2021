#include<bits/stdc++.h>
#define re register
#define pair pair<int, int>
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
const int N = 1e7 + 7;
inline bool check(int x)
{
	while (x)
	{
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
bool vis[N];
int nex[N];
signed main()
{
	File("number");
	int la = 0;
	for (re int i = 1; i <= 10000000; ++i)
	{
		if (!vis[i]) vis[i] = check(i);
		if (vis[i])
		{
			for (re int j = 2; i * j <= 10000000; ++j)
			{
				vis[i * j] = 1;
			}
		}
		else nex[la] = i, la = i;
	}
	nex[la] = 10000001;
	int T = read();
	while (T--)
	{
		int x = read();
		if (!nex[x]) puts("-1");
		else printf("%d\n", nex[x]);
	}
	return 0;
}
