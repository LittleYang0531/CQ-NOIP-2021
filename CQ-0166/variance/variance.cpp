#include <set>
#include <ctime>
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

const ULL P = 31;
const int Maxn = 1e4;
const LL Inf = 0x3f3f3f3f3f3f3f;

int n;
LL a[Maxn + 5];

LL ans;
set <ULL> vis;
ULL Get () {
	ULL Hash = 0;
	rep (i, 2, n - 1)
		Hash = Hash * P + a[i];
	return Hash;
}
LL solve () {
	LL tot1 = 0, res1 = 0;
	rep (i, 1, n) tot1 += a[i];
	res1 += tot1 * tot1; rep (i, 1, n) res1 += n * a[i] * a[i] - 2 * a[i] * tot1;
	return res1;
}
bool check (int idx) {
	LL res1 = 0, res2 = 0;
	res1 = solve ();
	
	a[idx] = a[idx - 1] + a[idx + 1] - a[idx];
	res2 = solve ();
	a[idx] = a[idx - 1] + a[idx + 1] - a[idx];
	
	return res2 < res1;
}
void dfs () {
	if (vis.size () > 100000) {
		write (ans);
		exit (0);
	}
	ans = Min (ans, solve ());
	if (n <= 10) {
		rep (i, 2, n - 1) {
			a[i] = a[i - 1] + a[i + 1] - a[i];
			ULL tmp = Get ();
			if (vis.find (tmp) == vis.end ()) {
				vis.insert (tmp);
				dfs ();
			}
			a[i] = a[i - 1] + a[i + 1] - a[i];
		}
	}
	else {
		int tmp = rand () % 20;
		while (tmp--) {
			int i = (rand () - 1) % n + 1;
			if (check (i) == 0 && ((rand () & 1))) continue;
			a[i] = a[i - 1] + a[i + 1] - a[i];
			ULL tmp = Get ();
			if (vis.find (tmp) == vis.end ()) {
				vis.insert (tmp);
				dfs ();
			}
			a[i] = a[i - 1] + a[i + 1] - a[i];
		}
	}
}

int main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	
	srand (time (0));
	
	read (n);
	rep (i, 1, n)
		read (a[i]);
	
	ans = Inf;
	dfs ();
	write (ans);
	return 0;
}
