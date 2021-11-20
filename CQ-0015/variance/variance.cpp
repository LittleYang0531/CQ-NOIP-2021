#include <bits/stdc++.h>

int d[int(1E4) + 5], an, n;
void solve1() {
	static int f[2][400 + 5][400 * 600 + 5];
	
	std::sort(d + 1, d + n);
	for (int i = n - 1; i >= 1; i--) {
		
	}
}
void solve2() {
	
}

int a[int(1E4) + 5];
int main() {
//	freopen("variance.in", "r", stdin);
//	freopen("variance.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]); an = a[n];
	for (int i = 1; i < n; i++) d[i] = a[i + 1] - a[i];
		
	if (n <= 400) solve1(); else solve2();
}
