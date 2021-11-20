#include <cstdio>
const int N = 35, M = 105, mod = 998244353;
int n, m, p, a[N], v[M];
long long b[N], ans;
bool pd(long long x) {
	int t = 0;
	while(x) t += x & 1, x >>= 1;
	return t <= p;
}
void dfs(int k, int lst, long long t, int x, long long s) {
//	printf("%d %d %lld %d %lld\n", k, lst, t, x, s);
	if(k > n) {
		if(pd(s)) {
			t = b[n] / (t * b[x]) % mod;
			for(int i = 1; i <= n; i++) t = t * v[a[i]] % mod;
			ans = (ans + t) % mod;
		}
		return;
	}
	for(int i = lst; i <= m; i++) {
		a[k] = i;
		if(i == lst) dfs(k + 1, i, t, x + 1, s + (1ll << i));
		else dfs(k + 1, i, t * b[x], 1, s + (1ll << i));
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &p), b[0] = 1;
	for(int i = 1; i <= n; i++) b[i] = b[i - 1] * i;
	for(int i = 0; i <= m; i++) scanf("%d", &v[i]);
	dfs(1, 0, 1, 0, 0), printf("%lld", ans);
	return 0;
}
