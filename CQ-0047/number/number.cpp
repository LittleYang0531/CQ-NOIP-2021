#include <cstdio>
#include <algorithm>
using namespace std;

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

const int MAXN = 1e7;
int T , n , k , rg[ MAXN + 5 ]; bool vis[ MAXN + 5 ];

bool Check( int x ) {
	while( x ) {
		if( x % 10 == 7 ) return 1;
		x /= 10;
	}
	return 0;
}
int main( ) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for( int i = 1 ; i <= MAXN ; i ++ ) if( Check( i ) && !vis[ i ] )
		for( int j = i ; j <= MAXN ; j += i ) vis[ j ] = 1;
	for( int i = 1 ; i <= MAXN ; i ++ ) if( !vis[ i ] ) rg[ ++ k ] = i;
	rg[ ++ k ] = 10000001;
	
	Read( T );
	while( T -- ) {
		Read( n );
		if( vis[ n ] ) { puts("-1"); continue; }
		Write( rg[ upper_bound( rg + 1 , rg + k + 1 , n ) - rg ] );
	}
	return 0;
}
