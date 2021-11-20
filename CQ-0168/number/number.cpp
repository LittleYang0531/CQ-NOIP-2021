#include <cstdio>
#include <cstring>

#define Maxn 10000000
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

int T, n;
int vis[Maxn + 5], nxt[Maxn + 5];

bool Check (int x) {
	int num = x;
	if (num % 7 == 0) return true;
	while (num) {
		if (num % 10 == 7) return true;
		num /= 10;
	}
	return false;
}

void Init (int N) {
	rep (i, 1, N) {
		if (vis[i]) continue;
		if (Check (i)) {
			for (int j = i; j <= N; j += i) {
				vis[j] = 1;
				if (j > N - i) break;
			}
		}
	}
	
	int pos = 0;
	per (i, N, 1) {
		nxt[i] = pos;
		if (!vis[i]) pos = i;
	}
}

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	Read (T);
	
	Init (Maxn + 1);
	
	while (T --) {
		Read (n);
		
		if (vis[n]) printf ("-1\n");
		else printf ("%d\n", nxt[n]);
	}	
	return 0;
}

