#include <cstdio>

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

long long qpow(long long a, long long b, int mod)
{
	long long res = 1 % mod; a %= mod;
	while (b > 0)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return res;
}

const int mod = 998244353;

const int MAX_n = 30;
const int MAX_m = 100;
const int MAX_k = 30;

int n, m, k;
long long v[MAX_m + 5][MAX_n + 5];
long long fac[MAX_n + 5], inv[MAX_n + 5];
long long dp[MAX_m + 5][MAX_n + 5][MAX_n + 5][MAX_k + 5];
// dp[i][j][x][y] 二进制前 i 位选择了 j 个 a, 选了之后第 i 位还剩 x 个, 前面 1 的个数 

long long A(long long N, long long M) { return (N < M) ? 0 : (fac[N] * inv[N - M] % mod); }
long long C(long long N, long long M) { return A(N, M) * inv[M] % mod; }

void init()
{
	fac[0] = 1;
	for (int i = 1; i <= MAX_n; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[MAX_n] = qpow(fac[MAX_n], mod - 2, mod);
	for (int i = MAX_n; i >= 1; i--)
		inv[i - 1] = inv[i] * i % mod;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	init();
	n = rint(), m = rint(), k = rint();
	for (int i = 0; i <= m; i++)
	{
		v[i][0] = 1ll;
		v[i][1] = (long long)rint();
		for (int j = 2; j <= n; j++)
			v[i][j] = v[i][j - 1] * v[i][1] % mod;
	}
	for (int j = 0; j <= n; j++)
		dp[0][j][j][0] = v[0][j] * C(n, j) % mod;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int x = 0; x <= n; x++)
			{
				for (int y = 0; y + (x & 1) <= k; y++)
				{
					if (dp[i][j][x][y])
					{
						int upz = n - j;
						for (int z = 0; z <= upz; z++)
							dp[i + 1][j + z][x / 2 + z][y + (x & 1)] = (dp[i + 1][j + z][x / 2 + z][y + (x & 1)] + dp[i][j][x][y] * v[i + 1][z] % mod * C(n - j, z) % mod) % mod;
//						printf(" dp[%d][%d][%d][%d] = %lld\n", i, j, x, y, dp[i][j][x][y]);
					}
				}
			}
		}
	}
	long long res = 0;
	for (int x = 0; x <= n; x++)
	{
		int tmp = x, cnt = 0;
		while (tmp)
		{
			cnt += (tmp & 1);
			tmp >>= 1;
		}
		for (int y = 0; y + cnt <= k; y++)
			res = (res + dp[m][n][x][y]) % mod;
	}
	printf("%lld\n", res);
	return 0;
}
/*
5 1 1
2 1
*/

