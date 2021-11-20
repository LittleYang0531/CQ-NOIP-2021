#include <cstdio>
#include <cstring>

#define Maxn 30
#define Maxm 100
#define LL long long
#define Mod 998244353
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

template < typename _T >
_T Max (_T x, _T y) { return x > y ? x : y; }
template < typename _T >
_T Min (_T x, _T y) { return x < y ? x : y; }

template < typename _T >
void Read (_T &x) {
	x = 0; int f = 1; char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') { f = -1; }
		c = getchar ();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar ();
	}
	x *= f;
}

int n, m, k;
LL ans, jc[Maxn + 5], inv[Maxn + 5];
int v[Maxm + 5], cnt[Maxm + 5];

void Init () {
	jc[0] = 1;
	rep (i, 1, Maxn) jc[i] = jc[i - 1] * i % Mod;
	inv[1] = 1;
	rep (i, 2, Maxn) inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	inv[0] = 1;
	rep (i, 1, Maxn) inv[i] = inv[i - 1] * inv[i] % Mod;
}

LL C (int x, int y) {
	if (x < y) return 0;
	return jc[x] * inv[y] % Mod * inv[x - y] % Mod;
}

LL Pow (int x, int y) {
	LL ret = 1;
	for (int i = y; i; i >>= 1) {
		if (i & 1) ret = ret * x % Mod;
		x = (LL) x * x % Mod;
	}
	return ret;
}

void Dfs (int ct, int pre) {
	if (ct > n) return ;
	if (ct == n) {
//		rep (i, 0, m) {
//			printf ("%d ", cnt[i]);
//		}
//		printf ("FUCK %d\n", ct);
		LL val = 1;
		rep (i, 0, m) val = val * Pow (v[i], cnt[i]) % Mod;
		int res = n;
		LL fas = 1;
		rep (i, 0, m) {
			if (!cnt[i]) continue;
			fas = fas * C (res, cnt[i]) % Mod;
			res -= cnt[i];
		}
		ans = (ans + val * fas % Mod) % Mod;
		return ;
	} 
	int i = pre;
	if (i != 0) {
		rep (j, 0, cnt[i]) {
			if (ct + j > n) break;
			int now = cnt[i];
//			printf ("~~ %d %d\n", cnt[i], cnt[i - 1]);
			cnt[i] -= j;
			cnt[i - 1] += 2 * j;
//			printf ("(%d)-- %d %d   %d %d\n", ct, i, j, cnt[i], cnt[i - 1]);
			Dfs (ct + j, i - 1);
			cnt[i] += j;
			cnt[i - 1] -= 2 * j;
		}	
	}
}

int main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	Read (n), Read (m), Read (k);
	
	Init ();
	
	rep (i, 0, m) {
		Read (v[i]);
	}
	
	if (m <= 12) {
		ans = 0;
		rep (i, n, n * (1 << m)) {
			int s = 0, lim = 0;
			rep (j, 0, 30) {
				cnt[j] = 0;
				if (i & (1 << j)) {
					s ++;
					lim = Max (lim, j);
					cnt[j] = 1;
				}
			}
			if (s > k) continue;
			s = 0;
//			printf ("%d %d\n", i, lim);
			per (j, lim, m + 1) cnt[m] += cnt[j] * (1 << j - m);
			rep (j, 0, m) s += cnt[j];
//			printf ("FFF\n");
			Dfs (s, m);
		}
		
		printf ("%lld", ans);
	}
	else if (k == 1) {
		rep (i, 0, m) {
			memset (cnt, 0, sizeof cnt);
			cnt[i] = 1;
			Dfs (1, m);
		}
		printf ("%lld", ans);
	}
	
	return 0;
}
