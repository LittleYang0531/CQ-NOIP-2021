#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= r; ++i)
#define rep2(i, l, r) for (int i = l; i >= r; --i)
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ptc putchar
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 1e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
namespace lrc
{
	template <typename T>
	il void read(T &x)
	{
		x = 0; int f = 1; char ch;
		while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T>
	il void read(pair <T, T> &p)
	{
		read(p.fst); read(p.snd);
	}

	template <typename T>
	il void write(T x)
	{
		if (x < 0) ptc('-'), x = -x;
		if (x > 9) write(x / 10);
		ptc(x % 10 + '0');
	}

	template <typename T>
	il void write(pair <T, T> p)
	{
		write(p.fst); ptc(' '); write(p.snd);
	}
}
using namespace lrc;
int n, m, k, v[110], a[40];
const int mod = 998244353;
ll ans;

il int cnt1(int p)
{
	int cnt = 0;
	while (p)
		cnt += p & 1, p >>= 1;
	return cnt;
}

il void dfs(int step)
{
	if (step > n)
	{
		ll s = 0;
		rep1(i, 1, n) s += (1 << a[i]);
		if (cnt1(s) <= k)
		{
			ll vs = 1;
			rep1(i, 1, n) (vs *= v[a[i]]) %= mod;
			(ans += vs) %= mod;
		}
		return;
	}
	rep1(i, 0, m) a[step] = i, dfs(step + 1);
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m); read(k);
	rep1(i, 0, m) read(v[i]);
	dfs(1); write(ans);
	return 0;
}
// 又炸了，只会暴力
// L_h_ AK IOI!!!
// IOI AK me!!!
// zdx AK NOIp!!1
