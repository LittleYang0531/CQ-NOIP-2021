#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define LL long long
#define ULL unsigned long long
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define per(i,j,k) for (int i = (j); i >= (k); i--)

template <typename T> T Max (T x, T y) { return x > y ? x : y; }
template <typename T> T Min (T x, T y) { return x < y ? x : y; }
template <typename T> T Abs (T x) { return x > 0 ? x : -x; }
template <typename T>
void read (T &x) {
	T f = 1; x = 0;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == -1) f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar ();
	}
	x *= f;
}
int tp, Print_F[25];
template <typename T>
void write (T x) {
	if (x == 0) {
		putchar ('0');
		return;
	}
	if (x < 0) {
		putchar ('-');
		x = -x;
	}
	tp = 0;
	while (x) {
		Print_F[++tp] = x % 10;
		x /= 10;
	}
	while (tp) putchar (Print_F[tp--] + '0');
}
template <typename T>
void print (T x, char ch) {
	write (x); putchar (ch);
}

const int Maxn = 1000;
const LL Mod = 998244353;

int n, m, k;
int val[Maxn + 5], a[Maxn + 5];

LL fac[Maxn + 5], inv_fac[Maxn + 5];
LL quick_pow (LL x, LL y) {
	LL res = 1;
	while (y) {
		if (y & 1) res = (res * x) % Mod;
		x = (x * x) % Mod; y >>= 1;
	}
	return res;
}
LL inv (LL x) {
	return quick_pow (x, Mod - 2);
}

LL ans;
int bak[Maxn + 5];
void dfs (int step, int last, LL tot) {
	if (step == n + 1) {
		rep (i, 1, n) bak[a[i]]++;
		LL sum = 0, cnt = fac[n];
		rep (i, 0, Maxn) {
			if (bak[i] == 0 && i > m) break;
			if (bak[i] == 0) continue;
			cnt = (cnt * inv_fac[bak[i]]) % Mod;
		}
		rep (i, 0, Maxn) {
			if (bak[i] == 0 && i > m) break;
			bak[i + 1] += bak[i] / 2;
			sum += (bak[i] % 2);
			bak[i] = 0;
		}
		if (sum > k) return;
		ans = (ans + cnt * tot) % Mod;
		return;
	}
	per (i, last, 0) {
		a[step] = i;
		dfs (step + 1, i, tot * val[i] % Mod);
	}
}

const int Maxm = 17;

LL dp[2][(1 << Maxm) + 5];

int main () {
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	fac[1] = 1; rep (i, 2, Maxn) fac[i] = fac[i - 1] * i % Mod;
	inv_fac[Maxn] = inv (fac[Maxn]); per (i, Maxn - 1, 1) inv_fac[i] = inv_fac[i + 1] * (i + 1) % Mod;
	
	read (n); read (m); read (k);
	rep (i, 0, m) read (val[i]);
	
	if (n <= 8) {
		dfs (1, m, 1);
		write (ans);
	}
	else {
		dp[0][0] = 1;
		rep (i, 1, n) {
			memset (dp[i & 1], 0, sizeof dp[i & 1]);
			rep (j, 0, (1 << Maxm) - 1) {
				rep (k, 0, m) {
					if (j - (1 << k) < 0) break;
					dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j - (1 << k)] * val[k] % Mod) % Mod;
				}
			}
		}
		LL res = 0;
		rep (i, 0, (1 << Maxm) - 1) {
			int sum = 0;
			rep (j, 0, Maxm)
				if ((i >> j) & 1)
					sum++;
			if (sum <= k)
				res = (res + dp[n & 1][i]) % Mod;
		}
		write (res);
	}
	return 0;
}
