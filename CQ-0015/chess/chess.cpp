// 至今为止我们所做的一切
// 全 部 木 大 

#include <bits/stdc++.h>

#define I(x, y) ((x) * m + (y))
#define Ixy(x, y) ((x) * m + (y))
#define Iyx(y, x) ((x) + (y) * n)

const int S = 200000;
const int Q = 100000;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

struct chess{int c, l, x, y, i;}c[Q + 5];
int il[Q + 5], ans[Q + 5], opt[4][S + 5], tg[S + 5];
int n, m, s, q;

void read_all() {
	n = read(), m = read(), q = read(), s = n * m;
	
	for (int i = 0; i < s; i++) {
		for (int o = 0; o < 4; o++) opt[o][i] = 0;
		tg[i] = 0;
	}
	
	static char str[S + 5];
	for (int i = 0; i < n; i++) {
		scanf("%s", str + 1);
		for (int j = 1; j < m; j++)
			opt[0][I(i, j - 1)] = opt[2][I(i, j)] = str[j] - '0';
	}
	for (int i = 1; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++)
			opt[1][I(i - 1, j)] = opt[3][I(i, j)] = str[j] - '0';
	}
	
	for (int i = 1; i <= q; i++) {
		c[i].c = read(), c[i].l = read();
		c[i].x = read() - 1, c[i].y = read() - 1;
		tg[I(c[i].x, c[i].y)] = c[i].i = i;
	}
	
	std::sort(c + 1, c + q + 1, [](const chess &A, const chess &B){
		return A.l < B.l;
	});
	for (int i = 1; i <= q; i++) il[c[i].i] = i;
	std::sort(c + 1, c + q + 1, [](const chess &A, const chess &B){
		return A.i < B.i;
	});
}

namespace sgt{
	int ch[2][100*S + 5], sum[100*S + 5], ncnt;
	void insert(int &x, int l, int r, int p) {
		if (!x) x = (++ncnt), ch[0][x] = ch[1][x] = 0, sum[x] = 0;
		if (l == r) {sum[x] = 1; return;}
		
		int m = (l + r) >> 1;
		if (p <= m) insert(ch[0][x], l, m, p);
		else insert(ch[1][x], m + 1, r, p);
		sum[x] = sum[ch[0][x]] + sum[ch[1][x]];
	}
	void erase(int &x, int l, int r, int p) {
		if (!x) return;
		if (l != r) {
			int m = (l + r) >> 1;
			if (p <= m) erase(ch[0][x], l, m, p);
			else erase(ch[1][x], m + 1, r, p);
			sum[x] = sum[ch[0][x]] + sum[ch[1][x]];
		}
		if (!ch[0][x] && !ch[1][x]) x = 0;
	}
	int merge(int x, int y, int l, int r) {
		if (!x || !y) return x + y;
		if (l == r) return x;
		
		int m = (l + r) >> 1;
		ch[0][x] = merge(ch[0][x], ch[0][y], l, m);
		ch[1][x] = merge(ch[1][x], ch[1][y], m + 1, r);
		sum[x] = sum[ch[0][x]] + sum[ch[1][x]];
		return x;
	}
	int query(int x, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return sum[x];
		if (!x || ql > r || qr < l) return 0;
		int m = (l + r) >> 1;
		return query(ch[0][x], l, m, ql, qr)
			+ query(ch[1][x], m + 1, r, ql, qr);
	}
}

namespace ds3{
	int fa[S + 5], rtxy[S + 5], rtyx[S + 5], rtl[2][S + 5];
	void init() {
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			int x = I(i, j); fa[x] = x;
			sgt::insert(rtxy[x], 0, s - 1, Ixy(i, j));
			sgt::insert(rtyx[x], 0, s - 1, Iyx(j, i));
			for (int o = 0; o < 4; o++) if (opt[o][x] == 3) {
				int y = I(i + DX[o], j + DY[o]);
				if (tg[y]) {
					chess &C = c[tg[y]];
					sgt::insert(rtl[C.c][x], 1, q, il[C.i]);
				}
			}
		}
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	bool unite(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy) {
			fa[fx] = fy;
			rtxy[fy] = sgt::merge(rtxy[fy], rtxy[fx], 0, s - 1);
			rtyx[fy] = sgt::merge(rtyx[fy], rtyx[fx], 0, s - 1);
			rtl[0][fy] = sgt::merge(rtl[0][fy], rtl[0][fx], 1, q);
			rtl[1][fy] = sgt::merge(rtl[1][fy], rtl[1][fx], 1, q);
			return true;
		} else return false;
	}
	void del(int x, const chess &C) {
		sgt::erase(rtl[C.c][find(x)], 1, q, il[C.i]);
	}
	int query(const chess &C) {
		int x = find(I(C.x, C.y));
		return sgt::query(rtl[!C.c][x], 1, q, 1, C.l) + sgt::sum[rtxy[x]];
	}
	int get_xy(int x, int l, int r) {
		return sgt::query(rtxy[find(x)], 0, s - 1, l, r);
	}
	int get_yx(int x, int l, int r) {
		return sgt::query(rtyx[find(x)], 0, s - 1, l, r);
	}
};

struct dsu{
	int fa[S + 5], mn[S + 5], mx[S + 5];
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	bool unite(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy) {
			fa[fx] = fy;
			mn[fy] = std::min(mn[fx], mn[fy]);
			mx[fy] = std::max(mx[fx], mx[fy]);
			return true;
		} else return false;
	}
}XY, YX;

void init() {
	read_all();
	
	sgt::ncnt = 0;
	ds3::init();
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int x = I(i, j); if (tg[x]) continue;
		for (int o = 0; o < 4; o++) if (opt[o][x] == 3) {
			int y = I(i + DX[o], j + DY[o]);
			if (!tg[y]) ds3::unite(x, y);
		}
	}
	
	for (int i = 0; i < s; i++) {
		XY.fa[i] = XY.mn[i] = XY.mx[i]
		= YX.fa[i] = YX.mn[i] = YX.mx[i] = i;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int x = I(i, j); if (tg[x]) continue;
		for (int o = 0; o < 4; o++) if (opt[o][x] == 2) {
			int y = I(i + DX[o], j + DY[o]); if (tg[y]) continue;
			if (o == 0 || o == 2) { // XY
				XY.unite(Ixy(i, j), Ixy(i + DX[o], j + DY[o]));
			} else {
				YX.unite(Iyx(j, i), Iyx(j + DY[o], i + DX[o]));
			}
		}
	}
}

int check(const chess &C1, const chess &C2) {
	int x = ds3::find(I(C1.x, C1.y));
	if (C1.c != C2.c && C1.l >= C2.l
		&& !sgt::query(ds3::rtl[C2.c][x], 1, q, il[C2.i], il[C2.i])) {
		return 1;
	} else return 0;
}
int calc3(const chess &C) {
	int x = I(C.x, C.y);
	for (int o = 0; o < 4; o++) if (opt[o][x] == 3)
		ds3::del(I(C.x + DX[o], C.y + DY[o]), C);
	for (int o = 0; o < 4; o++) if (opt[o][x] == 3) {
		int y = I(C.x + DX[o], C.y + DY[o]); if (tg[y]) continue;
		ds3::unite(x, y);
	}
	return ds3::query(C) - 1;
}
int calc1(const chess &C) {
	int x = I(C.x, C.y), ret = 0;
	for (int o = 0; o < 4; o++) if (opt[o][x] == 1) {
		int y = I(C.x + DX[o], C.y + DY[o]);
		if (!tg[y]) {
			ret += (ds3::find(x) != ds3::find(y));
		} else {
			ret += check(C, c[tg[y]]);
		}
	}
	return ret;	
}
int calc2(const chess &C) {
	int x = I(C.x, C.y), ret = 0;
	for (int o = 0; o < 4; o++) if (opt[o][x] == 2) {
		int y = I(C.x + DX[o], C.y + DY[o]); if (tg[y]) continue;
		if (o == 0 || o == 2) { // XY
			XY.unite(Ixy(C.x, C.y), Ixy(C.x + DX[o], C.y + DY[o]));
		} else {
			YX.unite(Iyx(C.y, C.x), Iyx(C.y + DY[o], C.x + DX[o]));
		}
	}
	
	int mn, mx, mxx, mxy, mnx, mny, x1, y1;
	
	mn = XY.mn[XY.find(x)], mx = XY.mx[XY.find(x)];
	ret += (mx - mn + 1) - ds3::get_xy(x, mn, mx);
	
	mxx = mx / m, mxy = mx % m, x1 = mxx + DX[0], y1 = mxy + DY[0];
	if (opt[0][I(mxx, mxy)] == 2 && tg[I(x1, y1)])
		ret += check(C, c[tg[I(x1, y1)]]);
		
	mnx = mn / m, mny = mn % m, x1 = mnx + DX[2], y1 = mny + DY[2];
	if (opt[2][I(mnx, mny)] == 2 && tg[I(x1, y1)])
		ret += check(C, c[tg[I(x1, y1)]]);
	
	mn = YX.mn[YX.find(x)], mx = YX.mx[YX.find(x)];
	ret += (mx - mn + 1) - ds3::get_yx(x, mn, mx);
	
	mxx = mx % n, mxy = mx / n, x1 = mxx + DX[1], y1 = mxy + DY[1];
	if (opt[1][I(mxx, mxy)] == 2 && tg[I(x1, y1)])
		ret += check(C, c[tg[I(x1, y1)]]);
		
	mnx = mn % n, mny = mn / n, x1 = mnx + DX[3], y1 = mny + DY[3];
	if (opt[3][I(mnx, mny)] == 2 && tg[I(x1, y1)])
		ret += check(C, c[tg[I(x1, y1)]]);
	
	return ret;
}

void solve() {
	init();
	for (int i = q; i >= 1; i--) {
		ans[i] = 0;
		ans[i] += calc3(c[i]);
		ans[i] += calc1(c[i]);
		tg[I(c[i].x, c[i].y)] = 0;
		ans[i] += calc2(c[i]);
	}
	for (int i = 1; i <= q; i++)
		write(ans[i]), puts("");
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	for (int T = read(); T; T--) solve();
}
