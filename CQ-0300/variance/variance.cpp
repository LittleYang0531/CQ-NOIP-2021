#include <cstdio>
const int MAXN = 1e4 + 10;
int a[MAXN], n, sum, Min_ans = 2147483647;
inline void read(int &t) {
	t = 0;
	int x = 1;
	char s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')
			x = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		t = t * 10 + s - '0';
		s = getchar();
	}
	t *= x;
}
inline void write(int t) {
	if (t < 10) {
		putchar(t + '0');
		return ;
	}
	write(t / 10);
	putchar(t % 10 + '0');
}
inline int gcd(int z, int j) { return !j ? z : gcd(j, z % j); }
inline int min(int h, int t) { return h < t ? h : t; };
inline int max(int y, int l) { return y > l ? y : l; }
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		sum += a[i];
	}
	int x = 0;
	for (int i = 1; i <= n; i++) 
		x += (a[i] * n - sum) * (a[i] * n - sum);
	Min_ans = min(Min_ans, x / n);
	for (int i = 2; i < n; i++) {
		int ans = 0;
		sum = sum - 2 * a[i] + a[i + 1] + a[i - 1];
		for (int j = 1; j <= n; j++) {
			ans += (a[j] * n - sum) * (a[j] * n - sum);
			printf("%d ", a[j] * n - sum);
		}
		Min_ans = min(Min_ans, ans / n);
		printf("%d %d\n", sum, ans);
	}
	write(Min_ans);
	return 0;
}
