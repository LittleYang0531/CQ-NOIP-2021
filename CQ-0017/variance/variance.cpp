#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 10005
#define ll long long
int n, m, w, A[N];
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
bool cmp(int a, int b){return a > b;}
ll F[2][605][36005];
void Chk(ll &a, ll b){a = min(a, b);}
int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	Read(n);
	for (int i = 1; i <= n; i++)
		Read(A[i]);
	m = A[n] - A[1];
	for (int i = 1; i < n; i++)
		A[i] = A[i + 1] - A[i];
	n--;
	sort(A + 1, A + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		if (A[i] != 0)
			w = i;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= w * m; k++)
				F[i][j][k] = 1ll << 60;
	F[0][0][m] = m * m;
	int z = 0, all = 0;
	for (int i = 1; i < w; i++)
	{
		all += A[i];
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= w * m; k++)
			{
				if (F[z][j][k] == 1ll << 60)
					continue;
				ll v;
				v = F[z][j][k];
				v += (ll)(j + A[i]) * (j + A[i]);
				Chk(F[z ^ 1][j + A[i]][k + j + A[i]], v);
				v = F[z][j][k];
				v += (ll)(m - all + j) * (m - all + j);
				Chk(F[z ^ 1][j][k + m - all + j], v);
				F[z][j][k] = 1ll << 60;
			}
		}
		z ^= 1;
	}
	ll ans = 1ll << 60;
	for (int j = 0; j <= m; j++)
	{
		for (int k = 0; k <= w * m; k++)
		{
			if (F[z][j][k] == 1ll << 60)
				continue;
			//printf("%d %d %lld\n", j, k, F[z][j][k]);
			int s = k + (ll)(n - w) * j;
			Chk(ans, (n + 1) * (F[z][j][k] + (ll)j * j * (n - w)) - (ll)s * s);
		}
	}
	printf("%lld\n", ans);
}
