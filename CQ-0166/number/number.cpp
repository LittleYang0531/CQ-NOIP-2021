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

const int Maxn = 1e7 + 10;
const int Maxm = 1e6 + 10;

bool vis[Maxn + 5];
int t, n;
int cnt, road[Maxm + 5];

bool check (int x) {
    while (x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);

    rep (i, 1, Maxn) {
        if (check (i)) {
            for (int j = i; j <= Maxn; j += i) {
                vis[j] = 1;
            }
        }
    }
    rep (i, 1, Maxn)
        if (vis[i] == 0)
        	road[++cnt] = i;
    
    read (t);
    while (t--) {
    	read (n);
    	if (vis[n] == 1) {
    		putchar ('-');
    		putchar ('1');
    		putchar ('\n');
		}
		else {
//    		printf ("%d\n", road[idx[n] + 1]);
			print (road[upper_bound (road + 1, road + 1 + cnt, n) - road], '\n');
		}
	}
	return 0;
}
