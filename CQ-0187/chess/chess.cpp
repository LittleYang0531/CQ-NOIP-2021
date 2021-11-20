#include <cstdio>
#include <cstring>
int kd() {
	int n = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') n = (n << 3) + (n << 1) + (c ^ '0'), c = getchar();
	return n;
}
void kx(int n) {
	if(n == -1) putchar('-'), putchar('1');
	else {
		int a[15], t = 0;
		while(n) a[++t] = n % 10, n /= 10;
		while(t) putchar(a[t] ^ '0'), t--;
	}
	putchar('\n');
}
const int NM = 4e5 + 5, d_x[4] = {-1, 1, 0, 0}, d_y[4] = {0, 0, -1, 1};
int n, m, T, Q, Col[NM], Lv[NM], col, lv, x, y, ans;
char c[NM], d[NM];
bool vst[NM];
struct node { int x, y; } q, qu[NM];
int f(int i, int j) { return i * m + j; }
char r(int xa, int ya, int xb, int yb) {
	if(xa == xb) return ya < yb ? c[f(xa, ya)] : c[f(xb, yb)];
	return xa < xb ? d[f(xa, ya)] : d[f(xb, yb)];
}
int str() {
	int dx, dy, tot = 0;
	for(int i = 0; i < 4; i++) {
		dx = x + d_x[i], dy = y + d_y[i];
		if(r(dx, dy, x, y) == '1') {
			if(Col[f(dx, dy)] != col && Col[f(dx, dy)]) tot += Lv[f(dx, dy)] <= lv;
		}
	}
	dx = x, dy = y;
	while(dx > 1 && r(dx - 1, dy, dx, dy) == '2') {
		dx--;
		if(Col[f(dx, dy)] == col) break;
		if(Col[f(dx, dy)]) { tot += Lv[f(dx, dy)] <= lv; break; }
		tot++;
	}
	dx = x, dy = y;
	while(dx < n && r(dx + 1, dy, dx, dy) == '2') {
		dx++;
		if(Col[f(dx, dy)] == col) break;
		if(Col[f(dx, dy)]) { tot += Lv[f(dx, dy)] <= lv; break; }
		tot++;
	}
	dx = x, dy = y;
	while(dy > 1 && r(dx, dy - 1, dx, dy) == '2') {
		dy--;
		if(Col[f(dx, dy)] == col) break;
		if(Col[f(dx, dy)]) { tot += Lv[f(dx, dy)] <= lv; break; }
		tot++;
	}
	dx = x, dy = y;
	while(dy < m && r(dx, dy + 1, dx, dy) == '2') {
		dy++;
		if(Col[f(dx, dy)] == col) break;
		if(Col[f(dx, dy)]) { tot += Lv[f(dx, dy)] <= lv; break; }
		tot++;
	}
	return tot;
}
int bfs() {
	int head = 0, tail = 0, dx, dy, tot = 0;
	qu[++tail] = q, memset(vst, false, sizeof(vst)), vst[f(x, y)] = true;
	while(head < tail) {
		head++;
		for(int i = 0; i < 4; i++) {
			dx = qu[head].x + d_x[i], dy = qu[head].y + d_y[i];
			if(dx > 0 && dx <= n && dy > 0 && dy <= m && r(q.x, q.y, dx, dy) == '3' && !vst[f(dx, dy)]) {
				if(Col[f(dx, dy)] == col) continue;
				if(Col[f(dx, dy)]) { tot += Lv[f(dx, dy)] <= lv; continue; }
				q.x = dx, q.y = dy, qu[++tail] = q, tot++;
			}
		}
	}
	return tot;
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	T = kd();
	while(T--) {
		n = kd(), m = kd(), Q = kd();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < m; j++) c[f(i, j)] = getchar();
			getchar();
		}
		for(int i = 1; i < n; i++) {
			for(int j = 1; j <= m; j++) d[f(i, j)] = getchar();
			getchar();
		}
		while(Q--) {
			col = kd() + 1, lv = kd(), q.x = x = kd(), q.y = y = kd();
//			printf(">>>%d %d %d %d", col, lv, x, y);
			printf("%d\n", str() + bfs()), Col[f(x, y)] = col, Lv[f(x, y)] = lv;
		}
	}
	return 0;
}
