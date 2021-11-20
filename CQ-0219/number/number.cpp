#include <bits/stdc++.h>
using namespace std;
namespace c {
	template <typename T>
	inline void read(T &x) {
		char ch; int f = 1; x = 0;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}
}
using namespace c;
const int N = 2e6 + 5;
int T, n;
bool chk(int x) {
	while (x) {
		if (x % 10 == 7) return false;
		x /= 10;
	}
	return true;
}
bool p[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("1.txt", "w", stdout);
//	for (int i = 1; i <= 200; ++i) cout << i << ' ' << p[i] << endl;
	read(T);
	for (int i = 2; i <= (int)2e5; ++i) {
		if (p[i]) continue;
		if (i % 7 == 0 || !chk(i)) {
			for (int j = i; j <= 2e5; j += i) {
				p[j] = 1;
			}
		}
	}
	while (T--) {
		read(n);
		if (p[n]) puts("-1");
		else {
			for (int i = n + 1; i <= 2e5; ++i) {
				if (!p[i]) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}

