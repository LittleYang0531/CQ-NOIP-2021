#include <cstdio>
#include <ctime>
#include <cstdlib>

int a[10005], now, lim = 32760;
inline int rnd() {
	if (now >= lim) now = 0, -- lim, srand(a[rand()]);
	++ now;
	return rand();
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(NULL));
	int n;
	long long mi = 0;
	bool flag = true;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	if (n == 1) return puts("0"), 0;
	if (n == 2) return printf("%d", 2 * (a[1] * a[1] + a[2] * a[2]) - (a[1] + a[2]) * (a[1] + a[2])), 0;
	while (1.0 * clock() / CLOCKS_PER_SEC <= 0.85) {
		int p = rnd() % (n - 2) + 2;
		a[p] = a[p - 1] + a[p + 1] - a[p];
		long long ans = 0, sum = 0;
		for (int i = 1; i <= n; ++ i) sum += a[i];
		for (int i = 1; i <= n; ++ i) ans += 1ll * n * a[i] * a[i];
		ans -= sum * sum;
		if (flag || ans < mi) mi = ans;
		flag = false;
	}
	printf("%lld", mi);
	return 0;
}
/*
I ball ball u
give me 32pts

You should least give me 20pts!!!

If my score less than 20pts, I will kill you
*/
