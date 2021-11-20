#include <bits/stdc++.h>
using namespace std;
const int MAXM = 10005, MOD = 998244353;

#define LL long long

int n, m, k;
int v[MAXM], a[MAXM], q;
int flag[MAXM];
LL ans;

void get(int x, int k) {
	a[q = 1] = x;
	while (q < k) {
		for (int i = 1; i <= q && q < k; i++)
			if (a[i] > 1) {
				if ((a[i] & (a[i] - 1)) == 0) {
					a[i] >>= 1;
					a[++q] = a[i];
				}
				else {
					int tmp = a[i];
					a[i] = 1 << (int(log2(a[i])));
					a[++q] = tmp - a[i];
				}
			}
	}
	for (int i = 1; i <= q; i++)
		flag[int(log2(a[i]))]++;
}

unsigned LL A(int n) {
	unsigned LL res = 1;
	for (int i = 2; i <= n; i++) res *= i;
	return res;
}

int get_val(LL x) {
	int res = 0;
	while (x) {res++; x &= x - 1;}
	return res;
}

LL mul(int a, int b, int p) {
	if (!b) return 1;
	LL res = mul(a, b >> 1, p);
	if (b & 1) return res * res % p * a % p;
	else return res * res % p;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	// cout << mul(2, 10, 5) << endl;
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", v + i);
	for (int j = n; j <= n * (1 << m); j++) {
		if (get_val(j) <= k) {
			// cout << j << endl;
			// j 是一个可行解
			memset(a, 0, sizeof(a));
			memset(flag, 0, sizeof(flag));
			get(j, n);
			LL res = 1;
			unsigned LL t = A(n);
			for (int i = 0; flag[i]; i++) {
				res = res * mul(v[i], flag[i], MOD) % MOD;
				t /= A(flag[i]);
			}
			res = res * t % MOD;
			ans = (ans + res) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

// 感觉没问题啊。。。
// xiba!... 
