#include <cstdio>
#include <queue>
#include <map>
using namespace std;

long long Max(long long a, long long b) { return (a > b) ? a : b; }
long long Min(long long a, long long b) { return (a < b) ? a : b; }

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

long long sq(long long x) { return x * x; }

const int P = 13331;
const int MAX_n = 1e4;

int n;
long long x[MAX_n + 5];

struct node
{
	long long a[25];
	long long sq1, sq2, ans;
	unsigned ha;
} o;

map<unsigned long long, bool> vis;

unsigned long long h(node p)
{
	unsigned long long res = 0;
	for (int i = 1; i <= n; i++)
		res = res * P + (p.a[i] + 1);
	return res;
}

void print(node p)
{
	for (int i = 1; i <= n; i++)
		printf("%lld ", p.a[i]);
	printf("\n");
}

long long bfs()
{
	long long res = 8e18;
	queue<node> q;
	q.push(o);
	vis[o.ha] = true;
	while (!q.empty())
	{
		node u = q.front(); q.pop();
		res = Min(res, u.ans);
		for (int i = 2; i < n; i++)
		{
			node v = u;
			v.sq1 -= v.a[i]; v.sq2 -= sq(v.a[i]);
			v.a[i] = v.a[i - 1] + v.a[i + 1] - v.a[i];
			v.sq1 += v.a[i]; v.sq2 += sq(v.a[i]);
			v.ans = n * v.sq2 - sq(v.sq1);
			v.ha = h(v);
			if (vis[v.ha]) continue;
			vis[v.ha] = true;
			q.push(v);
		}
	}
	return res;
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	n = rint();
	if (n <= 20)
	{
		for (int i = 1; i <= n; i++)
		{
			o.a[i] = (long long)rint();
			o.sq1 += o.a[i];
			o.sq2 += sq(o.a[i]);
		}
		o.ans = n * o.sq2 - sq(o.sq1); o.ha = h(o);
		printf("%lld\n", bfs());
	}
	else
	{
		long long sq1 = 0, sq2 = 0;
		for (int i = 1; i <= n; i++)
		{
			x[i] = (long long)rint();
			sq1 += x[i];
			sq2 += sq(x[i]);
		}
		printf("%lld\n", n * sq2 - sq(sq1));
	}
	return 0;
}

