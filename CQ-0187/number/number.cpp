#include <cstdio>
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
const int N = 1e7 + 1;
int T, x, a[N], tot, fa[N + 5];
bool b[N + 5], p[N + 5];//p[i]==true:can't
void gp(int i) {
	int I = i;
	while(i) {
		if(i % 10 == 7) { p[I] = true; return; }
		i /= 10;
	}
}
int f(int i) {
	if(fa[i] == i) return i;
	return fa[i] = f(fa[i]);
}
void h(int i, int j) {
	i = f(i), j = f(j);
	if(i == j) return;
	fa[i] = j;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 1; i <= N; i++) fa[i] = i;
	for(int i = 2; i <= N; i++) {
		if(!b[i]) a[++tot] = i;
		for(int j = 1; j <= tot && (long long)a[j] * i <= N; j++) {
			b[a[j] * i] = true;
			if(!(i % a[j])) break;
		}
	}
	for(int i = 2; i <= N; i++) {
		if(!p[i]) gp(i);
		for(int j = 1; j <= tot && (long long)a[j] * i <= N; j++) {
			p[a[j] * i] |= p[i] | p[a[j]];
		}
		if(p[i]) h(i, i + 1);
	}
//	for(int i = 1; i <= 300; i++) printf("%d:%d\n", i, p[i]);
	T = kd();
	while(T--) x = kd(), kx(p[x] ? -1 : f(x + 1));
	return 0;
}
