#include <bits/stdc++.h>

using namespace std;

bool vis[10100005], mk[10100005], ok[10100005];
int num[10100005], nxt[10100005], cnt[10100005], p[15];

void init()
{
	p[0] = 1;
	for (int i = 1; i <= 8; i++) p[i] = p[i - 1] * 10;
	int lst = 0;
	for (int i = 1; lst <= 10000000; i++)
	{
		cnt[i] = cnt[i / 10] + 1;
		if (i == 7 || ok[i % p[cnt[i] - 1]] || ((i - i % p[cnt[i] - 1]) == 7 * p[cnt[i] - 1])) ok[i] = vis[i] = 1;
		if (ok[i] && !mk[i]) for (int j = 2; i * j <= 10100000; j++)
			mk[i * j] = vis[i * j] = 1;
		if (!vis[i]) nxt[lst] = i, lst = i;
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init(); 
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x;
		scanf("%d", &x);
		if (vis[x]) puts("-1");
		else printf("%d\n", nxt[x]);
	}
}
