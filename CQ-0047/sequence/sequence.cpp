#include <cstdio>

const int MAXN = 30 , MAXM = 100 , Mod = 998244353;
#define Add( x , y ) ( x + y >= Mod ? x + y - Mod : x + y )
#define Sub( x , y ) ( x < y ? x + Mod - y : x - y )
#define Mul( x , y ) ( (int)( 1ll * x * y % Mod ) )
int Qkpow( int x , int po ) { int p = 1; for( ; po ; po >>= 1 , x = Mul( x , x ) ) if( po & 1 ) p = Mul( p , x ); return p; }
int Inv( int x ) { return Qkpow( x , Mod - 2 ); }
int fac[ MAXN + 5 ] , ivf[ MAXN + 5 ];
void Init( ) {
	fac[ 0 ] = 1;
	for( int i = 1 ; i <= MAXN ; i ++ ) fac[ i ] = Mul( fac[ i - 1 ] , i );
	ivf[ MAXN ] = Inv( fac[ MAXN ] );
	for( int i = MAXN ; i >= 1 ; i -- ) ivf[ i - 1 ] = Mul( ivf[ i ] , i );
}

int n , m , k , v[ MAXM + 5 ][ MAXN + 5 ];
int dp[ MAXM + 5 ][ MAXN + 5 ][ MAXN + 5 ][ MAXN + 5 ];

int chk( int x ) { int cnt = 0; for( ; x ; x -= ( x & -x ) ) cnt ++; return cnt; }
int main( ) {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	Init();
	scanf("%d %d %d",&n,&m,&k);
	for( int i = 0 ; i <= m ; i ++ ) {
		v[ i ][ 0 ] = 1; scanf("%d",&v[ i ][ 1 ]);
		for( int j = 2 ; j <= n ; j ++ ) v[ i ][ j ] = Mul( v[ i ][ j - 1 ] , v[ i ][ 1 ] );
	}
	
	for( int s = 0 ; s <= n ; s ++ ) dp[ 0 ][ s & 1 ][ s / 2 ][ s ] = Mul( v[ 0 ][ s ] , ivf[ s ] );
	for( int i = 0 ; i < m ; i ++ ) {
		for( int j = 0 ; j <= k ; j ++ ) {
			for( int a = 0 ; a <= n / 2 ; a ++ ) {
				for( int s = 0 ; s <= n ; s ++ ) {
					for( int l = 0 ; s + l <= n ; l ++ ) {
						int nj = j + ( ( l + a ) & 1 ) , na = ( l + a ) / 2 , val = Mul( v[ i + 1 ][ l ] , ivf[ l ] );
						dp[ i + 1 ][ nj ][ na ][ s + l ] = Add( dp[ i + 1 ][ nj ][ na ][ s + l ] , Mul( dp[ i ][ j ][ a ][ s ] , val ) );
					}
				}
			}
		}	
	}
	int Ans = 0;
	for( int j = 0 ; j <= k ; j ++ ) {
		for( int a = 0 ; a <= n ; a ++ ) {
			if( chk( a ) + j <= k ) Ans = Add( Ans , dp[ m ][ j ][ a ][ n ] );
		}
	}
	printf("%d\n", Mul( fac[ n ] , Ans ) );
	return 0;
}
/*
n^3mk

5 1 1
2 1

40

8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699

642171527

*/
