#include <cstdio>

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int MAX_T = 2e5;
const int MAX_x = 1e7 + 1;

int ok[MAX_x + 5];
int pre[MAX_x + 5];
int minp[MAX_x + 5];
int prime[MAX_x + 5], cnt;
bool vis[MAX_x + 5];
bool chk[MAX_x + 5]; // if have 7

void init()
{
	vis[0] = vis[1] = true;
	for (int i = 1; i <= MAX_x; i++)
	{
		if ((i % 10 == 7) || (chk[i / 10])) chk[i] = true, ok[i] = 1;
		if (!vis[i]) { prime[++cnt] = minp[i] = i; }
		for (int j = 1, k = i * prime[j]; j <= cnt && k <= MAX_x; k = i * prime[++j])
		{
			minp[k] = prime[j]; vis[k] = true;
			if (i % prime[j] == 0) break;
		}
		int x = i;
		while (x > 1 && !ok[i])
		{
			if (ok[i / minp[x]]) ok[i] = 1;
			x /= minp[x];
		}
		pre[i] = pre[i - 1] + (!ok[i]);
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	int T = rint(), x, l, r;
	while (T--)
	{
		x = rint();
		if (ok[x]) { printf("-1\n"); continue; }
		l = x + 1, r = MAX_x;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (pre[mid] - pre[x]) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}

