#include <bits/stdc++.h>
using namespace std;

#define r(i, j) for (int i = 1; i <= (j); ++i)
#define re(i, j, k) for (int i = (j); i <= (k); ++i)
#define rr(i, j) for (int i = (j); i >= 1; --i)
#define rre(i, j, k) for (int i = (k); i >= (j); --i)

typedef long long intx;
const int maxn = 1e4 + 4;
const intx inf = ~0ull>>2;

int n, dt_a[maxn], seq[maxn];
int op[maxn], fact = 1;
intx ans = inf;

inline void update() {
	intx acu = 0, sum = 0, val;
	r (i, n) acu += 1ll * seq[i] * seq[i], sum += seq[i];
	val = acu * n - sum * sum;
	if (val < ans) ans = val;
}

void deploy() {
	memcpy(seq + 1 + n, dt_a + 1 + n, sizeof(int) * n);
	r (i, n - 2) {
		int v = op[i] + 1;
		seq[v] = seq[v - 1] + seq[v + 1] - seq[v];
		update();
	}
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	r (i, n) cin >> dt_a[i], seq[i] = dt_a[i];
	r (i, n - 2) op[i] = i, fact *= i;
	r (i, fact) {
		deploy();
		next_permutation(op + 1, op + n - 1);
	}
	cout << ans << endl;
	return 0;
}
