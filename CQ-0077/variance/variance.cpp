#include <bits/stdc++.h>
using namespace std;

namespace Elaina {

#define rep(i, l, r) for (int i = l, i##_end_ = r; i <= i##_end_; ++i)
#define drep(i, l, r) for (int i = l, i##_end_ = r; i >= i##_end_; --i)
#define fi first
#define se second
#define Endl putchar('\n')

    template<class T> inline T fab(T x) { return x < 0? -x: x; }
    template<class T> inline void getmax(T& x, const T& y) { x = max(x, y); }
    template<class T> inline void getmin(T& x, const T& y) { x = min(x, y); }

    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> pii;

    template<class T> inline void readin(T& x) {
        x = 0; char c; int f = 0;
        while (!isdigit(c = getchar())) if (c == '-') f = 1;
        for (x = (c ^ 48); isdigit(c = getchar()); x = (x << 1) + (x << 3) + (c ^ 48));
        if (f) x = -x;
    }

} // namespace Elaina
using namespace Elaina;

const int maxn = 10000;
const int mod = 1e9 + 7;

ull modpow[maxn + 5];

int a[maxn + 5], n;

inline void input() {
    readin(n);
    rep (i, 1, n) readin(a[i]);
    modpow[0] = 1;
    rep (i, 1, n) modpow[i] = modpow[i - 1] * mod;
}

int b[maxn + 5];
map<ull, bool> vis;
inline void change(ull& h, ll& pows, ll& s, int p) {
    h -= (b[p] ^ mod) * modpow[n - p];
    pows -= b[p] * b[p], s -= b[p];
    b[p] = b[p - 1] + b[p + 1] - b[p];
    h += (b[p] ^ mod) * modpow[n - p];
    pows += b[p] * b[p], s += b[p];
}
ll ans = 1ll << 50;
void dfs(ull h, ll pows, ll s) {
    if (vis.count(h)) return;
    getmin(ans, pows * n - s * s);
    vis[h] = 1;
    rep (i, 2, n - 1) {
        change(h, pows, s, i);
        dfs(h, pows, s);
        change(h, pows, s, i);
    }
}

namespace Guess {

int b[maxn + 5];
inline ll calc(int p) {
    memcpy(b + 1, a + 1, n << 2);
    for (int i = p - 1; i >= 2; --i)
        b[i] = b[i + 1] - min(a[i] - a[i - 1], a[i + 1] - a[i]);
    for (int i = p + 1; i < n; ++i)
        b[i] = b[i - 1] + min(a[i] - a[i - 1], a[i + 1] - a[i]);
    ll ans = 0, s = 0;
    rep (i, 1, n) ans += b[i] * b[i], s += b[i];
    return ans * n - s * s;
}

inline void launch() {
    ll ans = 1ll << 50;
    rep (i, 2, n - 1) getmin(ans, calc(i));
    printf("%lld\n", ans);
}

} // namespace Guess

signed main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    input();
    if (n > 30) return Guess::launch(), 0;
    memcpy(b + 1, a + 1, n << 2);
    ull h = 0; ll pows = 0, s = 0;
    rep (i, 1, n) {
        h = h * mod + (b[i] ^ mod);
        pows += b[i] * b[i], s += b[i];
    }
    dfs(h, pows, s);
    printf("%lld\n", ans);
    return 0;
}

/*

D' = n * (sum ai^2) - S^2

we wanna minimize D'

consequencely operate one position twice is useless

a1 and an won't be changed

how many steps after will a sequence be stable?

I guess it'll be n - 1, but no proof

operation will not change the increasing of the sequence

the data range is interesting, when n too large ai is smaller, maybe the aim is
to avoid the overflow of long long?

Or, the range of ai is related to the steps?

maybe I'll get a brute to check it

no, not, fuck it up

f(x) = x^2, f'(x) is increasing

enumerate the standard, how to calc the mini cost to this std

*/