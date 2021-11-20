#include <set>
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ ) 
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 10005, MAXA = 605;

template<typename _T>
void read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

int A[MAXN];
int N;

namespace Force {
    std :: set<std :: vector<int> > s;
    std :: vector<int> cur;

    LL ans;

    LL Calc() {
        LL q = 0, s = 0;
        rep( i, 1, N )
            q += 1ll * cur[i] * cur[i], s += cur[i];
        return N * q - s * s;
    }

    void DFS() {
        if( s.find( cur ) != s.end() )
            return ;
        s.insert( cur );
        ans = MIN( ans, Calc() );
        rep( i, 2, N - 1 ) {
            int tmp = cur[i];
            cur[i] = cur[i - 1] + cur[i + 1] - cur[i];
            DFS();
            cur[i] = tmp;
        }
    }  

    void Solve() {
        ans = 1e18;
        cur.resize( N + 5 );
        rep( i, 1, N ) cur[i] = A[i];
        DFS();
        write( ans ), putchar( '\n' );
    }
}

int main() {
    freopen( "variance.in", "r", stdin );
    freopen( "variance.out", "w", stdout );
    read( N );
    rep( i, 1, N ) read( A[i] );
    Force :: Solve();
    return 0;
}