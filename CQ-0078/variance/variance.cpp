#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e4 + 10;

int a[N];

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(NULL));
	int n, p, x;
	LL ans = 1e18, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum1 += a[i];
		sum2 += a[i] * a[i];
	}
	while(clock() < 985) {
		p = rand() % (n - 2) + 2;
		x = a[p - 1] + a[p + 1] - a[p];
		sum1 += x - a[p];
		sum2 += x * x - a[p] * a[p];
		a[p] = x;
		ans = min(ans, sum2 * n - sum1 * sum1);
	}
	printf("%lld\n", ans);
	return 0;
}
