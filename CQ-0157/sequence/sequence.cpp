#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int MAXN = 1e2 + 5;
const int Mod = 998244353;

int n, m, k, v[MAXN], a[MAXN], ans, cnt, fac[MAXN], inv[MAXN];

bool check(int x) {
	int tot = 0;
	while (x) {
		if (x & 1) tot++;
		x >>= 1;
	}
	return (tot <= k);
}

int qpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % Mod;
		x = x * x % Mod;
		y >>= 1;
	}
	return res;
}

void dfs(int len) {
	if (len > n) {
		int res = 1ll, mul = fac[n];
		for (int i = 0; i <= m; i++) {
			mul = mul * inv[a[i]] % Mod;
			res = res * qpow(v[i], a[i]) % Mod;
		}
		ans = (ans + res * mul % Mod) % Mod;
		return;
	}
	for (int i = 1; i <= m; i++) if (a[i] >= 1) {
		a[i]--;
		a[i - 1] += 2;
		dfs(len + 1);
		a[i]++;
		a[i - 1] -= 2;
	}
}

signed main() {
	
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 0; i <= m; i++) {
		scanf("%lld", &v[i]);
	}
	
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = qpow(fac[i], Mod - 2);
	}
	
	for (int i = n; i <= n * (1 << m); i++) if (check(i)) {
		
//		printf("%d\n", i);
		cnt = 0;
		int x = i;
		for (int j = m; j >= 0; j--) {
			while (x >= (1 << j)) {
				a[j]++;
				cnt++;
				x -= (1 << j);
			}
		}
		if (cnt > n) {
			continue;
		}
		
		dfs(cnt + 1);
		
//		printf("%d\n", ans);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
