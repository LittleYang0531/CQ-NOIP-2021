#include <bits/stdc++.h>

using namespace std;

int n, a[10005], ans = 0;

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	printf("%lld", ans * n);
	return 0;
}
