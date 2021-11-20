#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 998244353;
ll n, m, k, x, ans, v[105], sum[256], a[256];
bool check() {
	x = a[0] = 0;
	for(int i = 0; i < 150; ++i) {
		a[i] += sum[i];
		a[i + 1] = a[i] / 2;
		x += a[i] % 2;
		if(x > k) return false;
	}
	return true;
}
void dfs(ll pos, ll num, ll va, ll mul) {
	if(pos > m || num == n) {
		if(num == n && check()) {
			ans = (ans + va * mul) % p;
		}
		return;
	}
	dfs(pos + 1, num, va, mul);
	ll x = 1, t = 0;
	for(++num; num <= n; ++num) {
		++sum[pos], va = va * v[pos] % p, mul = mul * num / ++t % p;
		dfs(pos + 1, num, va, mul);
	}
	sum[pos] = 0;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 0; i <= m; ++i) scanf("%lld", &v[i]);
	dfs(0, 0, 1, 1);
	printf("%lld", ans);
	return 0;
	//QAQ
	//QAQ
	//QAQ
	//QAQ
}
