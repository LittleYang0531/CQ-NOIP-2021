#include <bits/stdc++.h>

#define POPCOUNT(x) __builtin_popcount(x)

typedef long long ll;

const int N = 30;
const int M = 100;
const int P = 998244353;

int norm(int x) {return x >= P ? x - P : x;}
void add(int &x, int y) {x += y; if (x >= P) x -= P;}

int v[M + 5], n, m, k;

int c[N + 5][N + 5], pw[M + 5][N + 5];
void init() {
	for (int i = 0; i <= m; i++) {
		pw[i][0] = 1;
		for (int j = 1; j <= n; j++)
			pw[i][j] = (ll)pw[i][j - 1] * v[i] % P;
	}
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = norm(c[i - 1][j] + c[i - 1][j - 1]);
	}
}

int calc(int ans[][N + 5]) {
	int res = 0;
	for (int p = 0; p <= k; p++)
		for (int s = 0; s <= (n >> 1); s++)
			if (p + POPCOUNT(s) <= k) add(res, ans[p][s]);
	return res;
}

int f[2][N + 5][N + 5][N + 5];
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) scanf("%d", &v[i]);
	init();
	
	f[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++) {
		int o = (i & 1);
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p <= k; p++) {
				for (int s = 0; s <= (j >> 1); s++) if (f[o][j][p][s]) {
					for (int x = 0; x <= n - j; x++) {
						int &F = f[!o][j + x][p + ((s + x) & 1)][(s + x) >> 1];
						F = (F + (ll)f[o][j][p][s] *
							c[n - j][x] % P * pw[i][x]) % P;
					}
					f[o][j][p][s] = 0;
				}
			}
		}
	}
	printf("%d\n", calc(f[!(m & 1)][n]));	
}
