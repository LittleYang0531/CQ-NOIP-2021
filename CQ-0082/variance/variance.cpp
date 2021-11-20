#include <fstream>
#include <set>

using namespace std;

const int P = 998244353;
inline void inc(int& a, int b) { if ((a += b) >= P) a -= P; }
inline void dec(int& a, int b) { a -= b; a += (a >> 31) & P; }
inline int add(int a, int b) { inc(a, b); return a; }
inline int sub(int a, int b) { dec(a, b); return a; }
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline void scl(int& a, int b) { a = mul(a, b); }

typedef long long ll;

inline ll sqr(ll x) { return x * x; }

const int N = 10000;

int n;
ll a[N];

set<int> c;
ll minD = 0x7fffffffffffffffll;
void dfs(ll S, ll S2, ll D) {
	int x = 0;
	for (int i = 0; i < n; ++i) {
		scl(x, 677);
		inc(x, a[i]);
	}
	if (c.find(x) != c.end()) return;
	c.insert(x);
	minD = min(minD, D);
	for (int i = 1; i < n - 1; ++i) {
		ll dS = a[i - 1] + a[i + 1] - 2 * a[i];
		ll dS2 = sqr(a[i - 1] + a[i + 1] - a[i]) - sqr(a[i]);
		ll dD = n * dS2 - (2 * dS * S + sqr(dS));
		if (dD) {
			a[i] = a[i - 1] + a[i + 1] - a[i];
			dfs(S + dS, S2 + dS2, D + dD);
			a[i] = a[i - 1] + a[i + 1] - a[i];
		}
	}
}

int main() {
	ifstream cin("variance.in");
	ofstream cout("variance.out");

	cin >> n;
	ll S = 0, S2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		S += a[i];
		S2 += a[i] * a[i];
	}
	dfs(S, S2, n * S2 - sqr(S));
	cout << minD;

	return 0;
}

