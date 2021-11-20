/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

inline char fgc() {
	static char buf[1 << 17], *p = buf, *q = buf;
	return p == q && (q = buf + fread(p = buf, 1, 1 << 17, stdin), p == q)
	  ? EOF : *p++;
}

template <typename Tp = int>
inline Tp rint() {
	Tp x = 0, f = 1, s = fgc();
	for (; s < '0' || '9' < s; s = fgc()) f = s == '-' ? -f : f;
	for (; '0' <= s && s <= '9'; s = fgc()) x = x * 10 + (s ^ '0');
	return x * f;
}

template <typename Tp>
inline void wint(Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (9 < x) wint(x / 10);
	putchar(x % 10 ^ '0');
}

const int MAXX = 1e7 + 10;
bool cant[MAXX + 5];
int nex[MAXX + 5];

inline void init() {
	rep (i, 1, MAXX) if (!cant[i]) {
		bool flg = true;
		for (int t = i; t && flg; t /= 10) flg = t % 10 != 7;
		if (!flg) for (int j = i; j <= MAXX; j += i) cant[j] = true;
	}
	int las = 0;
	per (i, MAXX, 1) {
		nex[i] = las;
		if (!cant[i]) las = i;
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	init();
	for (int T = rint(), x; T--;) {
		x = rint();
		wint(cant[x] ? -1 : nex[x]), putchar('\n');
	}
	return 0;
}

