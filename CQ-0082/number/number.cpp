#include <fstream>

namespace tkz {
	struct reader {
		std::istream& is;

		template <typename T>
		operator T() { T t; is >> t; return t; }
	};
}

bool p(int x) {
	do if (x % 10 == 7) return true;
	while (x /= 10);
	return false;
}

const int X = 1e7;

bool v[X + 2];
int s[X + 2];

int main() {
	for (int i = 1, c = 0; i <= X + 1; ++i) {
		if (v[i]) continue;
		else if (p(i)) for (int j = i; j <= X; j += i) v[j] = true;
		else { s[c] = i; c = i; }
	}

	using namespace std;
	using namespace tkz;

	ifstream cin("number.in");
	ofstream cout("number.out");
	reader read{cin};
	for (int T = read; T--; ) {
		int x = read;
		cout << (v[x] ? -1 : s[x]) << '\n';
	}

	return 0;
}
