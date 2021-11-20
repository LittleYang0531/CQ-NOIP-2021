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

const int maxn = 1e7 + 5000;

inline bool judge(int x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

bool vis[maxn * 2 + 5];
int nxt[maxn * 2 + 5];
inline void prelude() {
    rep (i, 1, maxn + 5) if (!vis[i] && judge(i)) {
        for (int j = i; j <= maxn + 5; j += i)
            vis[j] = true;
    }
    int las = -1;
    drep (i, maxn + 5, 1) if (!vis[i])
        nxt[i] = las, las = i;
}

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    prelude();
    int T, x; readin(T);
    while (T--) {
        readin(x);
        if (vis[x]) puts("-1");
        else printf("%d\n", nxt[x]);
    }
    return 0;
}