#include<bits/stdc++.h>
#define ll long long
const int N = 1e4 + 10;
using namespace std;
int n, a[N];
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n); ll ans = 0ll, s = 0ll;
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), s += a[i];
	for(int i = 1; i <= n; ++i) {
		int num = 0;
		for(int j = 2; j < n; ++j) {
			int x = a[j - 1] + a[j + 1] - a[j] - a[j];
			int p = 1ll * (2 * a[j] + x) * x * n;
			int q = 1ll * (2 * s + x) * x;
			if(q >= p) a[j] += x, s += x;
		}
	}
//	for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
	ans -= 1ll * s * s;
	for(int i = 1; i <= n; ++i) ans += 1ll * a[i] * a[i] * n;
	printf("%lld", ans);
	return 0;
}
// (o)  (o)
// ||   ||
// || _ || (±¬Áã¿ìÀÖ)
//I LOVE(F***) NOIP!!!
//I want to ac this problem, but it is only my dream.  :-(
