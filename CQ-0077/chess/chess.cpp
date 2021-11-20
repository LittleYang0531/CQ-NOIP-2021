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

#define F int

F**k_shit;
F**k_CCF;
F**k_your_mother;

signed main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    puts("YOU are SON OF BITCH!");
    return 0;
}