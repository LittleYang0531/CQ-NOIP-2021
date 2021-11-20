#include <bits/stdc++.h>
using namespace std;
const int N = 35, M = 110, S = 4, mod = 998244353;
typedef long long ll;
int n, m, kk, v[M], ans;
int f[2][N][N][N][1 << S], s[1 << S];
int c[N][N];
int pow(int a,int b)
{
	int r = 1;
	for (;b;b >>= 1)
	{
		if (b & 1) r = (ll)r * a % mod;
		a = (ll)a * a % mod;
	}
	return r;
}
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	for (int i = 0;i < (1 << S);i ++)
	{
		int x = i;
		while (x) s[i] ++, x -= x & -x;
	}
	scanf("%d%d%d", &n, &m, &kk);
	c[0][0] = 1;
	for (int i = 1;i <= n;i ++)
	{
		c[i][0] = 1;
		for (int j = 1;j <= i;j ++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	for (int i = 0;i <= m;i ++) scanf("%d", &v[i]);
	for (int i = 0;i <= n;i ++)
	{
		int x = 0, y = i;
		if (y > 16) x = 1, y -= 16;
		f[m&1][n - i][0][s[y] + x][y] = (ll)pow(v[m], i) * c[n][i] % mod;
//		cout << m << ' ' << n - i << 0 << ' ' << s[y] + x << ' ' << y << ' '<<f[m][n - i][0][s[y] + x][y]<<endl;
	}
	for (int i = m - 1;i >= 0;i --)//v
	{
		memset(f[i&1], 0, sizeof f[i&1]);
		for (int j = 0;j <= n;j ++)//restn
			for (int k = 0;k <= j;k ++)//usen
				for (int xx = 0;xx <= n;xx ++)//usedk
					for (int yy = 0;yy <= xx;yy ++)//long k
						for (int zz = 0;zz < 1 << S;zz ++)//state
						{
							int lastf = f[(i+1)&1][j][yy][xx][zz];
							if (lastf == 0) continue;
//							if (lastf) cout << zz << endl;
							int nzz = (zz << 1) + k, nxx = xx - s[zz], nyy = yy;
							bool linked = 0;
							if (nzz >= 32)
								nzz -= 32,  nxx += 1 - yy, nyy = 0;
							if (nzz >= 16)
								nzz -= 16, nyy += 1, nxx += 1, linked = 1;
							if (!linked) nyy = 0;
							nxx += s[nzz];
							f[i&1][j - k][nyy][nxx][nzz] = (f[i&1][j - k][nyy][nxx][nzz] + (ll)lastf * pow(v[i], k) % mod * c[j][k]) % mod;
//							cout << i << ' ' << j - k << ' ' << nyy << ' ' << nxx << ' ' << nzz << ' ' <<f[i][j - k][nyy][nxx][nzz] << endl;
						}
	}
		
	for (int xx = 0;xx <= kk;xx ++)//usedk
		for (int yy = 0;yy <= xx;yy ++)//long k
			for (int zz = 0;zz < 1 << S;zz ++)//state
				ans = (ans + f[0][0][yy][xx][zz]) % mod;
	printf("%d", ans);
	return 0;
}
