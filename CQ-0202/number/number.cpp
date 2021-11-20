#include <bits/stdc++.h>

using namespace std;



bool a[10000100];
int ans[800007], len, T, x, u;

bool check(int x) {
	if (x % 7 == 0)
		return true;
	while (x) {
		if ((x % 10) == 7)
			return true;
		x /= 10;
	}
	return false;
}




int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (register int i = 1; i <= 10000000; i ++) {
		if (a[i])
			continue;
		if (check(i)) {
			for (register int j = 1; i * j <= 10000001; j ++) {
				a[i * j] = true;
			}
		}
	}
	for (register int i = 1; i <= 10000001; i ++) {
		if (a[i] == false)
			ans[++ len] = i;
	}
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &x);
		u = lower_bound(ans + 1, ans + len + 1, x) - ans;
		if (ans[u] == x) {
			printf("%d\n", ans[u + 1]);
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
