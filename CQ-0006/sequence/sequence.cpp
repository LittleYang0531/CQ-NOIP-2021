#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 998244353; 
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int v[1005]; 
int dp[105][35][35][35];
void Add (int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int quickmod (int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = (1ll * ans * x) % mod;
		x = (1ll * x * x) % mod;
		y >>= 1;
	}
	return ans;
}
int fac[105], inv[105];
int pw[105][105];
int main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i <= 100; i++) fac[i] = (1ll * fac[i-1] * i) % mod; 
	for (int i = 0; i <= 100; i++) inv[i] = quickmod (fac[i], mod - 2);
	int n = read (), m = read (), k = read ();
	for (int i = 1; i <= m + 1; i++) v[i] = read ();
	for (int i = 1; i <= m + 1; i++) {
		pw[i][0] = 1; 
		for (int j = 1; j <= n; j++) {
			pw[i][j] = 1ll * pw[i][j-1] * v[i] % mod; 
		}
	}
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p <= k; p++) {
				for (int t = 0; t <= n / 2; t++) {
					int num = dp[i][j][p][t];
					if (num) {
						for (int x = 0; x + j <= n; x++) {
							Add (dp[i+1][x+j][((x+t)&1)+p][(x+t)/2], 1ll * num * pw[i+1][x] % mod * inv[x] % mod);
						}
					}
				}
			}
		}
	}
	int Ans = 0;
	for (int p = 0; p <= k; p++) {
		for (int t = 0; t <= n / 2; t++) {
			int x = t;
			int all = p;
			while (x) {
				all += (x & 1);
				x /= 2; 
			} 
			if (all <= k) Add (Ans, dp[m+1][n][p][t]);
		}
	}
	printf ("%lld\n", 1ll * Ans * fac[n] % mod);
	return 0;
}
/*
这特么就是你的大样例。。。
5 1 1
2 1
40

8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
642171527

不难注意到，n,m,k 的数据范围都很小
会发现到，k 限制到其实是 a 的取值，可以明显的感受到
这特么的伞兵题有DP的味道
m 较大，显然也是限制 a 的范围
考虑数位从低到高 DP
设 dp_{i,j,p,t} 表示到了第i位，前面已经用了j个a，已经有了p个数位上为1，前面那一个进了t位的总和是多少 
i <= 100, j <= 30, p <= 30, t <= 15 
每次转移的时候枚举当前位置上用了多少个
时间复杂度O(m*n^4) 
哦，还要考虑 a 的排列顺序的问题，DP 的时候处理一下就好了。 
easy game，可能还要预处理一下 

他妈的，一遍就把样例过完了。。。
后面做完了再来对拍（暴力比正解还难打。。。） 
*/

