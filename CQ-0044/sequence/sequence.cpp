#include <bits/stdc++.h>
using namespace std;

#define r(i, j) for (int i = 1; i <= (j); ++i)
#define re(i, j, k) for (int i = (j); i <= (k); ++i)
#define rr(i, j) for (int i = (j); i >= 1; --i)
#define rre(i, j, k) for (int i = (k); i >= (j); --i)

const int maxn = 32;
const int maxm = 1e2 + 4;
const int modn = 998244353;

template <typename T>
inline T Max(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
inline T Min(T a, T b) {
	return a < b ? a : b;
}

inline int kasumi(int a, int b) {
	int res = 1;
	a %= modn;
	while (b) {
		if (b&1) res = 1ll * res * a % modn;
		a = 1ll * a * a % modn, b >>= 1;
	}
	return res;
}

int n, m, K, fact[maxm], ift[maxm];
int dt_v[maxm], vpow[maxm][maxn];
	
inline int C(int x, int y) {
	if (x < y) return 0;
	return 1ll * fact[x] * ift[y] % modn * ift[x - y] % modn;
}

namespace bf1 {
	
	const int maxs = 2e5 + 4;
	
	int f[maxs][maxn][15];
	
	inline void init() {
		re (i, 0, maxs - 1) re (j, 0, maxn - 1) {
			re (k, 0, 14) f[i][j][k] = -1;
		}
	}
	
	int dfs(int msk, int x, int y) {
		if (!msk || !x) return !msk && !x;
		if (!~y) return 0;
		if (~f[msk][x][y]) return f[msk][x][y];
		int& ret = f[msk][x][y];
		ret = 0;
		re (l, 0, x) {
			int v = (1 << y) * l;
			if (v > msk) break;
			ret = (ret + 1ll * dfs(msk - v, x - l, y - 1)
				* C(x, l) % modn * vpow[y][l] % modn) % modn;
		}
		return ret;
	}
	
}

inline int pc(int v) {
	int ret = 0;
	while (v) ret += (v & 1), v >>= 1;
	return ret;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> K;
	re (i, 0, m) {
		cin >> dt_v[i], vpow[i][0] = 1;
		r (j, n) vpow[i][j] = 1ll * vpow[i][j - 1] * dt_v[i] % modn;
	}
	fact[0] = 1;
	r (i, n) fact[i] = 1ll * fact[i - 1] * i % modn;
	ift[n] = kasumi(fact[n], modn - 2);
	rre (i, 0, n - 1) ift[i] = 1ll * ift[i + 1] * (i + 1) % modn;
	
	int ans = 0;
	bf1::init();
	rre (i, 0, (1 << m) * n) {
		if (pc(i) <= K) {
			ans = (ans + bf1::dfs(i, n, m)) % modn;
		}
	}
	cout << ans << endl;
	
	return 0;
}
