#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define LL long long
const int MAXN = 1e4 + 5;
int n, a[MAXN], b[MAXN], c[MAXN];
LL Get() {
	double pj = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		pj += c[i];
	}
	pj /= 1.0 * n;
	for (int i = 1; i <= n; i++) {
		ans += (1.0 * c[i] - pj) * (1.0 * c[i] - pj);
	}
	LL res = round(ans * n);
	return res;
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(998244353);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int T = 100000000 / (n * n * n);
	if (n > 10) T = 200000000 / (n * n * n);
	LL ans = 2147483647;
	while (T--) {
		for (int i = 1; i <= n * n; i++) b[i] = rand() % (n - 2) + 2;
		for (int i = 1; i <= n; i++) {
			c[i] = a[i];
		}
		for (int i = 1; i <= n * n; i++) {
			ans = min(ans, Get());
			c[b[i]] = c[b[i] - 1] + c[b[i] + 1] - c[b[i]];
		}
	}
	printf("%lld", ans);
	return 0;
}
