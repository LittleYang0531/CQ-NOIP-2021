#include <fstream>

const int P = 998244353;
inline void inc(int& a, int b) { if ((a += b) >= P) a -= P; }
inline void dec(int& a, int b) { a -= b; a += (a >> 31) & P; }
inline int add(int a, int b) { inc(a, b); return a; }
inline int sub(int a, int b) { dec(a, b); return a; }
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline void scl(int& a, int b) { a = mul(a, b); }
inline int pow(int b, int p, int r = 1) { for (; p; scl(b, b), p >>= 1) if (p & 1) scl(r, b); return r; }
inline int inv(int a) { return pow(a, P - 2); }

int n, m, k;
int f[31];
int v[101];
int c[101];

int S = 0;
void dfs(int i, int l, int p, int s) {
	if (p > k) return;
	if (i == m) {
		s += (c[m] = l);
		if (p + __builtin_popcount(s) <= k) {
			int y = 1, d = 1;
			for (int i = 0; i <= m; ++i) {
				scl(y, pow(v[i], c[i]));
				scl(d, f[c[i]]);
			}
			inc(S, mul(y, mul(f[n], inv(d))));
		}
		return;
	}
	for (c[i] = 0; c[i] <= l; ++c[i])
		dfs(i + 1, l - c[i], p + ((s + c[i]) & 1), (s + c[i]) >> 1);
}

int main() {
	using namespace std;

	ifstream cin("sequence.in");
	ofstream cout("sequence.out");

	cin >> n >> m >> k;
	for (int i = 0; i <= m; ++i) cin >> v[i];
	f[0] = 1; for (int i = 1; i <= n; ++i) f[i] = mul(f[i - 1], i);
	dfs(0, n, 0, 0);
	cout << S;

	return 0;
}

