#include <bits/stdc++.h>

const int N = int(1E7) + 10;

bool f1[N + 5], f2[N + 5];
int nxt[N + 5];

void init() {
	for (int x = 0, i = 0; x < N; x += 10, i++) {
		for (int y = x, j = 0; j < 10; y++, j++) {
			if (j == 7 || f1[i]) {
				f1[y] = true;
				if (!f2[y]) {
					for (int z = y; z <= N; z += y)
						f2[z] = true;
				}
			}
		}
	}
	for (int i = N - 1; i >= 1; i--) {
		nxt[i] = (f2[i + 1] ? nxt[i + 1] : i + 1);
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	init(); int T, x; scanf("%d", &T);
	while (T--) {
		scanf("%d", &x); // x > 0
		printf("%d\n", f2[x] ? -1 : nxt[x]);
	}
}
