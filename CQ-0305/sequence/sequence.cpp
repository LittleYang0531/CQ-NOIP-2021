#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
int n, m, ans, k, v[107], c[17];
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m + 1; i++) {
		scanf("%d", &v[i]);
		ans = (ans + v[i]) % p;
	}
	cout << ans % p;
	return 0;
}
