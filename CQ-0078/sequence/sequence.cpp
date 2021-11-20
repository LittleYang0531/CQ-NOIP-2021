#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 35, mod = 998244353, S = (1 << 20) + 10;
typedef long long LL;

int val[N], b, Max, fl, n;
LL f[2][N][S], c[N][N], p[N], ans;

template <typename T>
void read(T &x) {
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9') {
		s = getchar();
	}
	while(s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar();
	}
}

void dfs(int Now, int sum, int add) {
	if(add > Max) {
		return;
	}
	if(Now == b + 1) {
		ans = (ans + f[fl][n][sum]) % mod;
		return;
	}
	dfs(Now + 1, sum << 1, add);
	dfs(Now + 1, sum << 1 | 1, add + 1);
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int m;
	scanf("%d %d %d", &n, &m, &Max);
	for(int i = 0; i <= m; ++i) {
		scanf("%d", &val[i]);
	}
	c[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	int End = (1 << m);
	f[1][0][0] = 1;
	for(int i = 0; i <= m; ++i) {
		int k = i & 1, K = !k;
		p[0] = 1;
		for(int j = 1; j <= n; ++j) {
			p[j] = p[j - 1] * val[i] % mod;
		}
		for(int j = 0; j <= n; ++j) {
			int End = j * (1 << i);
			for(int t = j; t <= End; ++t) {
				f[k][j][t] = 0;
			}
		}
		for(int j = 0; j <= n; ++j) {
			for(int l = 0; l <= j; ++l) {
				int End = j * (1 << i), x = l * (1 << i);
				for(int t = x + (j - l); t <= End; ++t) {
					f[k][j][t] = (f[k][j][t] + f[K][j - l][t - x] * c[j][l] % mod * p[l]) % mod;
				}
			}
		}
	}
	int x = n * (1 << m);
	while(x) {
		++b, x >>= 1;
	}
	fl = m & 1;
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
