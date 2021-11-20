#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

#define Maxn 10000
#define LL long long
#define uLL unsigned long long
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

int n;
LL ans;
int a[Maxn + 5];

map < uLL , bool > mp;

uLL H (int x[]) {
	uLL hsh = 0;
	rep (i, 1, n) {
		hsh = hsh * 1331 + x[i];
	}	
	return hsh;
}

LL Calc (LL s1, LL s2) {
	return 1ll * n * s2 - s1 * s1;
}

void Dfs (int x[], LL s1, LL s2) {
//	rep (i, 1, n) {
//		printf ("%d ", x[i]);
//	}
//	printf ("\n");
	ans = Min (ans, Calc (s1, s2));
	rep (i, 2, n - 1) {
		int k = x[i];
		x[i] = x[i - 1] + x[i + 1] - x[i];
		uLL h = H (x);
		if (mp.find (h) == mp.end ()) {
			mp[h] = 1;
			if (Calc (s1 + x[i] - k, s2 - k * k + x[i] * x[i]) <= ans + 10000) 
				Dfs (x, s1 + x[i] - k, s2 - k * k + x[i] * x[i]);
		}
		x[i] = k;
	}
}

int main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	
	Read (n);
	
	LL sum1 = 0, sum2 = 0;
	rep (i, 1, n) {
		scanf ("%d", &a[i]);
		sum1 += a[i];
		sum2 += a[i] * a[i];
	}
	
	ans = 1ll << 60;
	Dfs (a, sum1, sum2);
	
	printf ("%lld", ans);
	return 0;
}

