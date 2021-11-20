#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <climits>
const int nn = 1e4 + 5;
int a[nn], d[nn], n, b[nn], c[nn];
typedef long long ll;
ll ans = 1e18, sum, sum2;
void check() {
	sum = sum2 = 0;
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + d[b[i]];
		sum += c[i]; sum2 += c[i] * c[i];
	}
	ans = std::min(ans, n * sum2 - sum * sum);
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(11220840);
	int t = clock();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		d[i] = a[i] - a[i - 1];
	}
	std::sort(d + 2, d + n + 1);
	b[1] = 1;
	for (int i = n, l = 2, r = n; i >= 2; i--) {
		if (l - 2 > n - r) b[r--] = i;
		else b[l++] = i;
	}
	check();
	for (int i = n, l = 2, r = n; i >= 2; i--) {
		if (l - 2 >= n - r) b[r--] = i;
		else b[l++] = i;
	}
	check();
	ll lsum = 0, rsum = 0;
	for (int i = n, l = 2, r = n; i >= 2; i--) {
		if (lsum > rsum) b[r--] = i, rsum += d[i];
		else b[l++] = i, lsum += d[i];
	}
	check(); lsum = rsum = 0;
	for (int i = n, l = 2, r = n; i >= 2; i--) {
		if (lsum >= rsum) b[r--] = i, rsum += d[i];
		else b[l++] = i, lsum += d[i];
	}
	check();
	for (int i = 1; i <= n; i++) b[i] = i;
	if (n <= 10) {
		do {
			check();
		} while (std::next_permutation(b + 2, b + n + 1));
	} else {
		do {
			std::random_shuffle(b + 2, b + n + 1);
			check();
		} while (clock() - t < 0.9 * CLOCKS_PER_SEC);
	}
	printf("%lld\n", ans);
	return 0;
}
