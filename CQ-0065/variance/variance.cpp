#include<bits/stdc++.h>
#define re register
#define pair pair<int, int>
#define int long long
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
const int N = 1e4 + 4, b = 131, P = 1e9 + 7;
int n;
double ans = P;
struct node
{
	int a[N], sum;
};
unordered_map<int, bool> vis;
inline int hah(node x)
{
	int res = 0, B = b;
	for (re int i = 1; i <= n; ++i)
	{
		res = (res + B * x.a[i] % P) % P;
		B = B * b % P;
	}
	return res;
}
inline double cal(node x)
{
	double ave = double(x.sum) / n;
	double sum = 0;
	for (re int i = 1; i <= n; ++i) sum += double(x.a[i] - ave) * (x.a[i] - ave);
	return 1.0 * n * sum;
}
queue<node> q;
signed main()
{
	File("variance");
	n = read();
	node p;
	for (re int i = 1; i <= n; ++i) p.a[i] = read(), p.sum += p.a[i];
	q.push(p);
	while (!q.empty())
	{
		node x = q.front(); q.pop();
		if (vis[hah(x)]) continue;
		vis[hah(x)] = 1;
		ans = min(ans, cal(x));
		node y = x;
		for (re int i = 2; i < n; ++i)
		{
			int yy = y.a[i];
			y.sum -= yy;
			y.a[i] = x.a[i - 1] + x.a[i + 1] - x.a[i];
			y.sum += y.a[i];
			if (y.a[i] == yy) continue;
			q.push(y);
			y.a[i] = yy;
			y.sum = x.sum;
		}
	}
	printf("%lld", (int)(ans + 0.5));
	return 0;
}
