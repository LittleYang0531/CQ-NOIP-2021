#include <cstdio>
#include <algorithm>

bool mark[10000505];
int nxt[10000505];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (register int i = 1, lst = 0; i <= 10000500; ++ i) if (!mark[i]) {
		int x = i;
		bool flag = false;
		while (x) {
			if (x % 10 == 7) {flag = true; break;}
			x /= 10;
		}
		if (flag) {
			for (register int j = i; j <= 10000500; j += i) mark[j] = true;
		} else nxt[lst] = i, lst = i;
	} else {
		for (int j = i; j <= 10000500; j += i) mark[j] = true;
	}
	while (T --) {
		int n;
		scanf("%d", &n);
		printf("%d\n", mark[n] ? -1 : nxt[n]);
	}
	return 0;
}
/*
I ball ball u
give me accepted
*/
