#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int n , m , k , P[1 << 10];
long long v[110][33] , fac[110] , inv[110] , inc[110];
long long f[33][1 << 5][105][33] , ans;
const int mod = 998244353;
void init()
{
	fac[0] = fac[1] = inv[0] = inv[1] = inc[0] = inc[1] = 1;
	for(int i = 2 ; i <= 100 ; i++ ) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2 ; i <= 100 ; i++ ) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2 ; i <= 100 ; i++ ) inc[i] = inc[i - 1] * inv[i] % mod;
	P[0] = 0;
	for(int i = 1 ; i <= 1000 ; i++ ) P[i] = P[i - lowbit(i)] + 1;
}
long long C( int a , int b )
{
	if(a < b || b < 0) return 0;
	return fac[a] * inc[b] % mod * inc[a - b] % mod;
}
int main()
{
	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	init();
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 0 ; i <= m ; i++ )
	{
		scanf("%lld" , &v[i][1]);
		v[i][0] = 1;
		for(int j = 2 ; j <= n ; j++ ) v[i][j] = v[i][j - 1] * v[i][1] % mod;
	}
	f[0][0][0][0] = 1;
	for(int b = 0 ; b <= m ; b++ )
	{
		for(int S = 0 ; S < 32 ; S++ )
		{
			for(int ppc = 0 ; ppc <= k ; ppc++ )
			{
				for(int t = 0 ; t <= n ; t++ )
				{
					if(!f[ppc][S][b][t]) continue;
//					if(ppc == 0 && S == 1 && b == 3 && t == n) cerr << 111111 << endl;
					for(int d = 0 ; d <= n - t ; d++ )
					{
						int msk = S + 2 * d;
//						cerr << ppc << ' ' << S << ' ' << b << ' ' << t << ' ' << d << endl;
//						if(msk > 64) cerr << msk << endl;
						f[ppc + (msk & 1)][msk >> 1][b + 1][t + d] += f[ppc][S][b][t] * v[b][d] % mod * C(t + d , d) % mod;
						if(f[ppc + (msk & 1)][msk >> 1][b + 1][t + d] >= mod) f[ppc + (msk & 1)][msk >> 1][b + 1][t + d] -= mod;
//						f[ppc + (msk & 1)][msk >> 1][b + 1][t + d] %= mod;
					}
				}
			}
		}
	}
//	cerr << f[0][1][3][n] << endl;
	for(int ppc = 0 ; ppc <= k ; ppc++ )
	{
		for(int S = 0 ; S < 32 ; S++ )
		{
//			if(ppc + P[S] <= k && f[ppc][S][m + 1][n])
//			cerr << ppc << ' ' << S << ' ' << f[ppc][S][m + 1][n] << endl;
			if(ppc + P[S] <= k) (ans += f[ppc][S][m + 1][n]) %= mod;
		}
	}
	printf("%lld\n" , ans);
	return 0;
}
/*
5 1 2
2 1
*/
