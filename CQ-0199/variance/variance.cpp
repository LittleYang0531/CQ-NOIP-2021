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
int n, a[10010]; ll ot = ~0Ull >> 1;

il bool chg()
{
	rep1(i, 2, n - 1)
		if (a[i - 1] + a[i + 1] - a[i] > a[i]) return true;
	return false;
}

il pll operator * (const pll &l, const pll &r)
{
	pll ans = mp(1ll * l.fst * r.fst, 1ll * l.snd * r.snd);
	ll p = __gcd(ans.fst, ans.snd);
	ans.fst /= p, ans.snd /= p;
	return ans;
}

il pll operator - (const pll &l, const pll &r)
{
	pll al = l, ar = r;
	al.fst *= 1ll * r.snd, al.snd *= 1ll * r.snd;
	ar.fst *= 1ll * l.snd, ar.snd *= 1ll * l.snd;
	pll ans = mp(al.fst - ar.fst, al.snd);
	ll p = __gcd(ans.fst, ans.snd);
	ans.fst /= p; ans.snd /= p;
	return ans;
}

il pll operator + (const pll &l, const pll &r)
{
	pii al = l, ar = r;
	ar.fst = -ar.fst;
	pll ans = al - ar;
	return ans;
}

il ll solve()
{
	int sum = 0;
	rep1(i, 1, n) sum += a[i];
	pll av = mp(sum, 1) * mp(1, n), ans = mp(0, 1);
	rep1(i, 1, n)
	{
		pll t = (mp(a[i], 1) - av) * (mp(a[i], 1) - av);
		ans = ans + t;
	}
	ans = ans * mp(n, 1);
	return ans.fst;
}

il bool operator < (const pll &l, const pll &r)
{
	pll al = l, ar = r;
	al.fst *= 1ll * r.snd; ar.fst *= 1ll * l.snd;
	return al.fst < ar.fst;
}

pll ans = mp(INF, INF);

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	rep1(i, 1, n) read(a[i]);
	int sum = 0;
	rep1(i, 1, n) sum += a[i];
	pll av = mp(sum, 1) * mp(1, n), fd = mp(0, 1);
	rep1(i, 1, n)
	{
		pll t = (mp(a[i], 1) - av) * (mp(a[i], 1) - av);
		fd = fd + t;
	}
	ans = fd * mp(1, n);
	
	bool f = true;
	while (f)
	{
		f = false;
		rep1(i, 2, n - 1)
		{
			int sum2 = sum - a[i] + (a[i - 1] + a[i + 1] - a[i]);
			pll avn = mp(sum2, 1) * mp(1, n), fdn = mp(0, 1);
			rep1(j, 1, n)
			{
				int p = (j ^ i ? a[j] : a[i - 1] + a[i + 1] - a[i]);
				pll t = (mp(p, 1) - avn) * (mp(p, 1) - avn);
				fdn = fdn + t;
			}
			fdn = fdn * mp(1, n);
//			write(fdn); puts("");
			if (fdn < ans)
			{
				ans = fdn; f = true;
				a[i] = a[i - 1] + a[i + 1] - a[i];
			}
		}
	}
	
	ans = ans * mp(n * n, 1);
	write(ans.fst);
	return 0;
}

