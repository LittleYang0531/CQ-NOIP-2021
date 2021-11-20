#include <cstdio>

int read() {
	int x = 0, k = 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-')
			k = -1;
		s = getchar();
	}
	while('0' <= s && s <= '9') {
		x = (x << 3) + (x << 1) + (s ^ 48);
		s = getchar();
	}
	return x * k;
}

void write(int x) {
	if(x < 0) {
		x = -x;
		putchar('-');
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

void print(int x, char s) {
	write(x);
	putchar(s);
}

const int MAXN = 35;
const int MAXM = 1e2 + 5;
const int mod = 998244353;

int v[MAXM];

int main() {
	int n = read(), m = read(), k = read();
	for(int i = 0; i <= m; i++)
		v[i] = read();
	
	return 0;
}
