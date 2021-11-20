#include <cstdio>
#include <iostream>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
	return x;
}

inline bool check(int n) {
	while (n) {
		if (n % 10 == 7) return true;
		n /= 10;
	}
	return false;
}

int prime[1000005], suf[10000005];
bool is_prime[10000005], p[10000005];
inline void init(int n) {
	for (int i = 2; i <= n; i++) is_prime[i] = true;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) prime[++prime[0]] = i;
		if (check(i)) p[i] = true;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			is_prime[i * prime[j]] = false;
			if (p[i] || p[prime[j]]) p[i * prime[j]] = true;
		}
	}
	int now = 0;
	for (int i = n; i; i--) {
		suf[i] = now;
		if (!p[i]) now = i;
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init(1e7 + 2);
	int T;
	T = read();
	while (T--) {
		int x;
		x = read();
		if (p[x]) {puts("-1"); continue;}
		printf("%d\n", suf[x]);
	}
	return 0;
}
