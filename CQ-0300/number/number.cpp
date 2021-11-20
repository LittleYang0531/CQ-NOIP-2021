#include <cstdio>
const int MAXN = 1e7 + 10;
int t, n, a[MAXN];
bool p[MAXN], flag[MAXN];
inline void read(int &t) {
	t = 0;
	int x = 1;
	char s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')
			x = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		t = t * 10 + s - '0';
		s = getchar();
	}
	t *= x;
}
inline bool check(int t) {
	if (t % 10 == 7) {
		flag[t] = 1;
		return 1;
	}
	for (int i = t / 10; i > 0; i /= 10) {
		if (flag[i] == 1) {
			flag[t] = 1;
			return 1;
		}
	}
	return 0;
}
inline void write(int t) {
	if (t < 10) {
		putchar(t + '0');
		return ;
	}
	write(t / 10);
	putchar(t % 10 + '0');
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	flag[7] = 1;
	for (int i = 0; i <= MAXN; i++)
		p[i] = 1;
	int x = 0;
	for (int i = 1; i <= MAXN; i++) {
		bool y = check(i);
		if (p[i] == 0) 
			continue;
		if (i % 7 == 0)
			p[i] = 0;
		else if (y) {
			for (int j = 1; j * i <= MAXN; j++)
				p[j * i] = 0;
		}
		if (p[i] == 1) {
			a[x] = i;
			x = i;
		}
	}
	read(t);
	while (t--) {
		read(n);
		if (p[n] == 0)
			puts("-1");
		else {
			write(a[n]);
			putchar('\n');
		}
	}
	return 0;
}
