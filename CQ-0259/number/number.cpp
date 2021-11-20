#include <cstdio>
#include <cstring>
void QRead(int &n) {
	n = 0; char c = getchar(); bool ckl = 0;
	while (c < '0' || c > '9') {
		if (c == '-') ckl = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	if (ckl) n = -n;
}
const int MAXN = 1e7 + 5;
int cnt, n, nxt[MAXN];
bool vis[MAXN];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 10000001; i++) {
		int n = i;
		bool fgal = 0;
		while (n) {
			if (n % 10 == 7) fgal = 1;
			n /= 10;
		}
		if (fgal) {
			for (int j = 1; 1LL * i * j <= 10000001; j++) {
				vis[i * j] = 1;
			}
		}
	}
	int last = 1;
	for (int i = 2; i <= 10000001; i++) {
		if (!vis[i]) {
			nxt[last] = i;
			last = i;
		}
	}
	int T;
	QRead(T);
	while (T--) {
		QRead(n);
		if (vis[n]) {
			printf("-1\n");
		}
		else {
			printf("%d\n", nxt[n]);
		}
	}
	return 0;
}
