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
const int MAXN = 2e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;
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
int T, n;

il bool isprime(int k)
{
	if (k <= 1) return false;
	rep1(i, 2, sqrt(k) + 1)
		if (k % i == 0) return false;
	return true;
}

il bool ct7(int k)
{
	while (k)
		if (k % 10 == 7) return true;
		else k /= 10;
	return false;
}

il bool cw(int k)
{
	if (ct7(k)) return false;
	if (isprime(k)) return true;
	rep1(i, 2, sqrt(k) + 1)
		if (k % i == 0 && (ct7(i) || ct7(k / i))) return false;
	return true;
}

int qus[MAXN], dl[MAXN];
map <int, int>ans;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	read(T);
	rep1(i, 1, T) read(qus[i]), dl[i] = qus[i];
	sort(dl + 1, dl + 1 + T);
	int mq = dl[1];
	rep1(i, 1, T)
	{
		if (!cw(dl[i]) || dl[i] % 7 == 0)
		{
			ans[dl[i]] = -1;
			continue;
		}
		if (mq > dl[i])
		{
			ans[dl[i]] = mq;
			continue;
		}
		mq = max(mq, dl[i]);
		mq += 2;
		while (true)
		{
//			cout << "!!!" << mq << endl;
			if (cw(mq) && mq % 7)
			{
				ans[dl[i]] = mq;
				break;
			}
			++mq;
		}
	}
	rep1(i, 1, T) write(ans[qus[i]]), ptc('\n');
	return 0;
}
// 10000001
