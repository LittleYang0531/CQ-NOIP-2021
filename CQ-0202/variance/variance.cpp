#include <bits/stdc++.h>

using namespace std;



double p, c[10007], ans;
int n, a[10007], sum;




int main () {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	p = (double)sum / n;
	for (register int i = 1; i <= n; i ++) {
		ans += (p - a[i]) * (p - a[i]);
	}
	cout << (int)(ans * n) << endl;
	return 0;
}
