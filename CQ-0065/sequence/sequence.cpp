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
const int N = 32, M = 1e2 + 2, P = 998244353;
int f[M][N][N][N];
int n, m, K, jc;
int v[M], fac[N], inv[N], cnt[N];
inline int ksm(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % P;
		b >>= 1;
		a = a * a % P;
	}
	return res % P;
}
void init()
{
	fac[0] = fac[1] = 1;
	for (re int i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % P;
	inv[n] = ksm(fac[n], P - 2);
	for (re int i = n - 1; ~i; --i) inv[i] = inv[i + 1] * (i + 1) % P;
	for (re int i = 1; i <= n; ++i)
	{
		bitset<102> s = i;
		cnt[i] = s.count();
	}
}
inline int C(int x, int y)
{
	return fac[x] * inv[y] % P * inv[x - y] % P;
}
signed main()
{
	File("sequence");
	n = read(), m = read(), K = read();
	init();
	for (re int i = 0; i <= m; ++i) v[i] = read();
	for (re int i = 0; i <= n; ++i)
	{
		f[0][i][i][i & 1] = (cnt[i] <= K ? ksm(v[0], i) * C(n, i) % P : 0);
	}
	for (re int i = 0; i < m; ++i)
		for (re int j = 0; j <= n; ++j)
			for (re int k = 0; k <= j; ++k)
				for (re int z = 0; z <= j; ++z)
					for (re int c = 0; c <= n - j; ++c)
					{
						if (z + cnt[k / 2 + c] > K) continue;
						f[i + 1][j + c][k / 2 + c][((k / 2 + c) & 1) + z] = (f[i + 1][j + c][k / 2 + c][((k / 2 + c) & 1) + z] + f[i][j][k][z] * ksm(v[i + 1], c) % P * C(n - j, c) % P) % P;
					}
	int ans = 0;
	for (re int i = 0; i <= n; ++i)
		for (re int j = 0; j <= K; ++j)
			ans = (ans + f[m][n][i][j]) % P;
	printf("%lld", ans);
	return 0;
}
