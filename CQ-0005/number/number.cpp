#ifdef TIME_MESSURE
#include <ctime>
#endif

#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ ) 
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e7 + 20;

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

int rnk[MAXN], seq[MAXN], tot;

bool isPrime[MAXN];
bool avai[MAXN], sevn[MAXN];
int prime[MAXN], pn;

// sevn[x]: if there is a '7' in the digits of x
// avai[x]: if one can call x <=> sevn[] of none of its divisors is true.

void Init( const int n = 1e7 + 5 ) {
    isPrime[1] = true; 
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) prime[++ pn] = i;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) break;
        }
    }
    for( int i = 1 ; i <= n ; i ++ ) {
        sevn[i] = sevn[i / 10] | ( i % 10 == 7 );
        avai[i] = sevn[i];
    }
    for( int i = 1, lim ; i <= pn ; i ++ ) {
        lim = n / prime[i];
        for( int j = 1 ; j <= lim ; j ++ )
            avai[j * prime[i]] |= avai[j];
    }
    for( int i = 1 ; i <= n ; i ++ ) {
        if( avai[i] ) rnk[i] = -1;
        else seq[rnk[i] = ++ tot] = i;
    }
}

int main() {
    freopen( "number.in", "r", stdin );
    freopen( "number.out", "w", stdout );
    Init();
    int T; read( T );
    while( T -- ) {
        int N;
        read( N );
        if( rnk[N] == -1 ) puts( "-1" );
        else write( seq[rnk[N] + 1] ), putchar( '\n' );
    }
#ifdef TIME_MESSURE
    fprintf( stderr, "Run time: %.3fs\n", 1.0 * clock() / CLOCKS_PER_SEC );
#endif
    return 0;
}