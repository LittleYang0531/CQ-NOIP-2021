#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
#define il inline
#define fpr(s) freopen(s, "r", stdin)
#define fpw(s) freopen(s, "w", stdout)
using namespace std;
template <typename T>
il void read(T &x) {
   x = 0; T f = 1; char ch = getchar();
   while (!isdigit(ch)) f -= (ch == '-') << 1, ch = getchar();
   while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
   x *= f;
}
const int N = /*STO sro L_h_ orz OTZ*/1e7 + 5/*He AK NOIP everyday!!!!!!!*/, inf = 0x3f3f3f3f;
int t, x; bool v[N], vis[N];
il bool check(int x) {
	while (x) {
		if (x % 10 == 7) return false;
		x /= 10;
	}
	return true;
}
il void write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
signed main(void) {
	fpr("number.in"); fpw("number.out");
	rep1(i, 1, 10000000) vis[i] = !check(i); 
	rep1(i, 1, 10000000) {
		if (vis[i]) 
			for (int j = i; j <= 10000000; j += i) v[j] = 1;
	}
	read(t);
	while (t--) {
		read(x);
		if (v[x]) putchar('-'), putchar('1');
		else {
			++x;
			int y = x, base = 1;
			while (y) {
				if (y % 10 == 7) x += base;
				base *= 10;
				y /= 10;
			}
			while (v[x]) ++x;
			write(x);
		}
		putchar('\n');
	}
} //70·Ö±©Á¦ 

// 30min
