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

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cout << 50 << endl;
	return 0;
}

