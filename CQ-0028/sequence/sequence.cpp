#include <cstdio>
#define ll long long
#define maxm 14
#define maxn 32
#define mod 998244353
int mi[maxm][maxn];
int n, m, k;
int v[maxm];
int f[maxm][maxn][122900];
int c[maxn][maxn];

int main() {
	freopen( "sequence.in", "r", stdin );
	freopen( "sequence.out", "w", stdout );
	scanf( "%d %d %d", &n, &m, &k );
	for( int i = 0;i <= m;i ++ ) scanf( "%d", &v[i] );
	for( int i = 0;i <= n;i ++ ) {
		c[i][0] = c[i][i] = 1;
		for( int j = 1;j < i;j ++ )
			c[i][j] = ( 1ll * c[i - 1][j - 1] + c[i - 1][j] ) % mod;
	}
	for( int i = 0;i <= m;i ++ ) {
		mi[i][0] = 1;
		for( int j = 1;j <= n;j ++ )
			mi[i][j] = 1ll * mi[i][j - 1] * v[i] % mod;
	}
	for( int i = 0;i <= n;i ++ ) f[0][i][i] = 1ll * mi[0][i] * c[n][i] % mod;
	for( int i = 0;i < m;i ++ ) //前i位 
		for( int j = 0;j <= n;j ++ ) //一共选了j个人 
			for( int sum = 0;sum <= ( 1 << i ) * j;sum ++ ) //这些人的和 显然最多只可能全选i位置
				for( int x = 0;x <= n - j;x ++ ) //第i+1位有x个人选择
					f[i+1][j+x][sum+(1<<(i+1))*x] = ( 1ll * f[i+1][j+x][sum+(1<<(i+1))*x] + 1ll * f[i][j][sum] * mi[i+1][x] % mod * 1ll * c[n - j][x] % mod ) %mod;
	int ans = 0;
	for(int i=n;i<=n*(1<<m);i++){
		int x = i, cnt = 0;
		while( x ) cnt += ( x & 1 ), x >>= 1;
		if( cnt <= k ) ans = ( 1ll * ans + f[m][n][i] ) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
