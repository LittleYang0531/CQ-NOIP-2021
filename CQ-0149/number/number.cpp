#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1e7 + 10;
int t, x, ne[MAXX];
bool st[MAXX];
void solve(int x)
{
	for (int i = 1;i * x <= MAXX;i ++) st[i * x] = 1;
}
void dfs(int cnt, int res, bool seven)
{
	if (cnt == 0)
	{
		if (seven) solve(res);
		return;
	}
	for (int i = 0;i <= 9;i ++) dfs(cnt - 1, res * 10 + i, seven || (i == 7));
}
void prepare()
{
	dfs(7, 0, 0);
	int x = 1e7 + 1;
	for (int i = 1e7;i >= 1;i --)
		if (st[i]) ne[i] = -1;
		else ne[i] = x, x = i;
}


void read()
{
	x = 0;char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	prepare();
	scanf("%d", &t);
	while (t --)
	{
		read();
		printf("%d\n", ne[x]);
	}
	return 0;
}
