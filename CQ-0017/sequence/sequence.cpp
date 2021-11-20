#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 32
#define M 105
#define ll long long
#define mod 998244353
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, m, k;
int C[N][N], V[M];
int Add(int a, int b){return a + b >= mod ? a + b - mod : a + b;}
void Inc(int &a, int b){a = Add(a, b);}
int F[2][N][N][N];
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	for (int i = 0; i <= 30; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = Add(C[i - 1][j - 1], C[i - 1][j]);
	}
	Read(n), Read(m), Read(k);
	for (int i = 0; i <= m; i++)
		Read(V[i]);
	F[0][0][0][0] = 1;
	int z = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int s = 0; s <= n; s++)
			{
				for (int p = 0; p <= k; p++)
				{
					if (!F[z][j][s][p])continue;
					int w = F[z][j][s][p];
					for (int d = 0; d <= n - j; d++)
					{
						int v = (ll)w * C[n - j][d] % mod;
						Inc(F[z ^ 1][j + d][(s + d) >> 1][p + ((s + d) & 1)], v);
						w = (ll)w * V[i] % mod;
					}
					F[z][j][s][p] = 0;
				}
			}
		}
		z ^= 1;
	}
	int ans = 0;
	for (int s = 0; s <= n; s++)
	{
		int w = 0, t = s;
		while (t)
			w += t & 1, t >>= 1;
		for (int p = 0; p + w <= k; p++)
			Inc(ans, F[z][n][s][p]);
	}
	printf("%d\n", ans);
}
