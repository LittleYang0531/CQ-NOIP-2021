#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
inline void read(ull& val) {
	val = 0; bool negative = false; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') negative = true; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { val = val * 10 + ch - '0'; ch = getchar(); }
	if (negative) val = -val;
}
inline void write(ull val) {
	if (val < 0) { putchar('-'); write(-val); return; }
	if (val >= 10) { write(val / 10); }
	putchar(val % 10 + '0');
}
ull n, m, k, v[101], arr[30], ans = 0;
void find(ull i) {
	if (i == n) {
		ull s = 0, res = 1;
		for (ull j = 0; j < n; j++) {
			s += 1 << arr[j];
			res *= v[arr[j]];
			res %= 998244353;
		}
		ull count = 0;
		for (ull j = 0; j < 64; j++) {
			count += (s >> j) & 1;
		}
		if (count <= k) {
			ans += res;
		}
		return;
	}
	for (ull j = 0; j <= m; j++) {
		arr[i] = j;
		find(i + 1);
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n), read(m), read(k);
	for (ull i = 0; i <= m; i++) {
		read(v[i]);
	}
	find(0);
	write(ans);
	return 0;
}
