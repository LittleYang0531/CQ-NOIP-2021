#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

template<typename _T>
void Read( _T &x ) {
	x = 0; int f = 1;
	char s = getchar();
	for( ; s < '0' || s > '9' ; s = getchar() ) if( s == '-' ) f = -1;
	for( ; s >= '0' && s <= '9' ; s = getchar() ) x = x * 10 + s - '0';
	x *= f;
}
int pb , buf[ 100 ];
template<typename _T>
void Write( _T x , char ed = '\n' ) {
	if( x == 0 ) { putchar('0'); return; }
	if( x < 0 ) x = -x , putchar('-');
	for( ; x ; x /= 10 ) buf[ ++ pb ] = x % 10;
	while( pb ) putchar( buf[ pb -- ] + '0' );
	putchar( ed );
}

const int MAXN = 10000; const LL Inf = 0x3f3f3f3f3f3f3f3fll;
int n , a[ MAXN + 5 ] , d[ MAXN + 5 ] , na[ MAXN + 5 ] , nd[ MAXN + 5 ];
vector< int > d1 , d2;

int main( ) {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[ i ]) , d[ i ] = a[ i ] - a[ i - 1 ];
	sort( d + 2 , d + n + 1 );
	
	LL Ans = Inf; nd[ 1 ] = d[ 1 ];
	for( int S = 0 ; S < ( n <= 20 ? ( 1 << n ) : 1000000 ) ; S ++ ) if( S & 1 ) {
		d1.clear(); d2.clear();
		for( int i = 1 ; i < n ; i ++ ) {
			if( ( S >> i ) & 1 ) d1.push_back( d[ i + 1 ] );
			else d2.push_back( d[ i + 1 ] );
		}
		int hd = 2 , tl = n;
		for( int j = 0 ; j < (int)d1.size() ; j ++ ) {
			nd[ hd ++ ] = d1[ (int)d1.size() - j - 1 ];
		}
		for( int j = 0 ; j < (int)d2.size() ; j ++ ) {
			nd[ tl -- ] = d2[ (int)d2.size() - j - 1 ];
		}
		LL S1 = 0 , S2 = 0;
		for( int i = 1 ; i <= n ; i ++ ) na[ i ] = na[ i - 1 ] + nd[ i ] , S1 += na[ i ] , S2 += 1ll * na[ i ] * na[ i ];
		Ans = min( Ans , n * S2 - S1 * S1 );
	}
	printf("%lld", Ans );
	return 0;
}
/*
4
1 2 4 6

52

10
6 19 34 35 56 63 82 82 83 99

59865
*/
