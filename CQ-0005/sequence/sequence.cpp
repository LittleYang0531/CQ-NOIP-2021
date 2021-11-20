#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ ) 
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 35, MAXM = 105;

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

int fac[MAXN], ifac[MAXN];
int cnt[MAXN];

int dp[2][MAXN][MAXN][MAXN];
int pw[MAXM][MAXN];

int N, M, K;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline void Upt( int &x, const int v ) { x = Add( x, v ); }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

int main() {
    freopen( "sequence.in", "r", stdin );
    freopen( "sequence.out", "w", stdout );
    read( N ), read( M ), read( K );
    rep( i, 0, M ) {
        pw[i][0] = 1, read( pw[i][1] );
        rep( j, 2, N ) 
            pw[i][j] = Mul( pw[i][j - 1], pw[i][1] );
    }
    fac[0] = 1; rep( i, 1, N ) fac[i] = Mul( fac[i - 1], i );
    ifac[N] = Inv( fac[N] ); per( i, N - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );

    int pre = 1, nxt = 0;
    memset( dp, 0, sizeof dp );
    dp[nxt][0][0][0] = 1;
    rep( i, 0, M ) {
        pre ^= 1, nxt ^= 1;
        rep( j, 0, N ) 
            rep( k, 0, K )
                rep( s, 0, N )
                    dp[nxt][j][k][s] = 0;
        rep( j, 0, N ) 
            rep( k, 0, K )
                rep( s, 0, N ) 
                    if( dp[pre][j][k][s] && k + ( s & 1 ) <= K ) {
                        rep( delt, 0, N - j ) 
                            Upt( dp[nxt][j + delt][k + ( s & 1 )][( s >> 1 ) + delt],
                                Mul( dp[pre][j][k][s], Mul( pw[i][delt], ifac[delt] ) ) );
                    }
    }
    int ans = 0;
    rep( i, 1, N ) cnt[i] = cnt[i >> 1] + ( i & 1 );
    rep( k, 0, K ) rep( s, 0, N )
        if( dp[nxt][N][k][s] && k + cnt[s] <= K )
            Upt( ans, Mul( dp[nxt][N][k][s], fac[N] ) );
    write( ans ), putchar( '\n' );
    return 0;
}