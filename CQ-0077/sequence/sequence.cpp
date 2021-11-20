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

const int maxn = 30;
const int maxm = 100;
const int mod = 998244353;
inline int qkpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = 1ll * a * a % mod)
        if (n & 1) ret = 1ll * ret * a % mod;
    return ret;
}

int fac[maxn + 5], ifac[maxn + 5], inv[maxn + 5];
inline void prelude() {
    fac[0] = fac[1] = ifac[0] = ifac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
    }
}
inline int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int val[maxm + 5], n, m, k;
inline void input() {
    readin(n), readin(m), readin(k);
    rep (i, 0, m) readin(val[i]);
}

inline bool check(int p, int resi) {
    while (resi) p += (resi & 1), resi >>= 1;
    return p <= k;
}
bool vis[maxm + 5][maxn + 5][maxn + 5][maxn + 5];
int dp[maxm + 5][maxn + 5][maxn + 5][maxn + 5];
/**
 * @param i the current number
 * @param j the unused position
 * @param resi residuel of the last number
 * @param p counter of 1
*/
int dfs(int i, int j, int resi, int p) {
    if (p > k) return 0;
    if (i == m + 1) {
        if (j > 0) return 0; // not full
        if (check(p, resi)) return 1;
        return 0;
    }
    if (vis[i][j][resi][p]) return dp[i][j][resi][p];
    vis[i][j][resi][p] = true;
    int& ret = dp[i][j][resi][p]; ret = 0;
    for (int c = 0; c <= j; ++c) {
        int cur = (c + resi) & 1;
        ret = (ret + 1ll * C(j, c) * qkpow(val[i], c) % mod
          * dfs(i + 1, j - c, (c + resi) >> 1, p + cur) % mod) % mod;
    }
    return ret;
}

signed main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    prelude();
    input();
    int ans = dfs(0, n, 0, 0);
    printf("%d\n", ans);
    return 0;
}

/*

brute DP:> 50pts(maybe)

f[i][S]: the first i-th element, and the sum is S

When k == 1, we shall enumerate the position of the only 1

and the question was tranform to this below:

    construct a sequence to ensure that the sum equals to 2^p

we shall enumerathe the numbers of each number from [0, m]

and that's exactly the solution to this problem

*/