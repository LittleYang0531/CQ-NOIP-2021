#include <iostream>
#include <cstdio>
const int nn = 1e7 + 5;
const int lim = 1e7;
int p[nn], ans[nn], pow10[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	pow10[0] = 1;
	for (int i = 1; i <= 7; i++)
		pow10[i] = pow10[i - 1] * 10;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < pow10[i]; j++) {
			for (int k = 0; k < pow10[6 - i]; k++) {
				int s = j + k * pow10[i + 1] + 7 * pow10[i];
				for (int t = s; t <= lim; t += s) p[t] = 1;
			}
		}
	}
	for (int i = lim, last = lim + 1; i >= 1; i--) {
		if (!p[i]) ans[i] = last, last = i;
		else ans[i] = -1;
	}
	int t, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}
