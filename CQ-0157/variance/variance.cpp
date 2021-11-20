#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;

int n, m, cnt, t;
double a[MAXN];
double mid, mid2, ans;

double Abs(double x) {
	return x < 0 ? -x : x;
}

int main() {
	
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	
	mid = (a[1] + a[n]) / 2;
	
	while (1) {
		bool flag = false;
		for (int i = n; i > 1; i--) {
			if ((Abs(a[i] - mid)) > (Abs(a[i - 1] + a[i + 1] - a[i] - mid))) {
				a[i] = a[i - 1] + a[i + 1] - a[i];
				flag = 1;
				break;
			}
		}
		for (int i = 2; i < n; i++) {
			if ((Abs(a[i] - mid)) > (Abs(a[i - 1] + a[i + 1] - a[i] - mid))) {
				a[i] = a[i - 1] + a[i + 1] - a[i];
				flag = 1;
				break;
			}
		}
		if (!flag) break;
	}
	
	mid = 0;
	for (int i = 1; i <= n; i++) {
		mid += a[i];
		mid2 += a[i];
	}
	mid /= n;
	
	for (int i = 1; i <= n; i++) {	
		ans += n * a[i] * a[i] + mid2 * mid - 2 * mid2 * a[i];
	}
	
	printf("%.0lf\n", ans);
	return 0;
}
