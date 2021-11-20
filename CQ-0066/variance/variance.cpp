#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10005;
int n, a[maxn];
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum1 = sum1 + a[i];
		sum2 = sum2 + a[i] * a[i];
	}
	while(1) {
		bool fl = 0;
		for(int i = 2; i < n; i++) 
			if(a[i - 1] + a[i + 1] - a[i] < a[i]) {
				fl = 1;
				sum1 = sum1 - a[i] + a[i - 1] + a[i + 1] - a[i];
				sum2 = sum2 - a[i] * a[i] + (a[i - 1] + a[i + 1] - a[i]) * (a[i - 1] + a[i + 1] - a[i]);
				a[i] = a[i - 1] + a[i + 1] - a[i];
				break;
			}
		if(!fl) break;
	}
	ll ans = sum2 * n - sum1 * sum1;
	while(1) {
		bool fl = 0;
		for(int i = 2; i < n; i++) 
			if(a[i - 1] + a[i + 1] - a[i] > a[i]) {
				fl = 1;
				sum1 = sum1 - a[i] + a[i - 1] + a[i + 1] - a[i];
				sum2 = sum2 - a[i] * a[i] + (a[i - 1] + a[i + 1] - a[i]) * (a[i - 1] + a[i + 1] - a[i]);
				a[i] = a[i - 1] + a[i + 1] - a[i];
				break;
			}
		if(!fl) break;
	}
	ans = min(ans, sum2 * n - sum1 * sum1);
	cout << ans << '\n';
	return 0;
}
