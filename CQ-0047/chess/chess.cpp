#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define pii pair< int , int >
#define fi first
#define sc second
#define mp make_pair

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

const int MAXN = 2e5;
int T , n , m , q , Ans[ MAXN + 5 ] , col[ MAXN + 5 ] , lv[ MAXN + 5 ] , x[ MAXN + 5 ] , y[ MAXN + 5 ];
vector< pii > Mp[ MAXN + 5 ]; int vis[ MAXN + 5 ];
int Graph[ MAXN + 5 ][ 4 ] , dx[ 4 ] = { 1 , -1 , 0 , 0 } , dy[ 4 ] = { 0 , 0 , 1 , -1 };
//об ио ср вС 

int id( pii x ) { return ( x.fi - 1 ) * m + x.sc; }
int id( int x , int y ) { return ( x - 1 ) * m + y; }
bool ins( pii x , pii val ) {
	if( x.fi < 1 || x.fi > n || x.sc < 1 || x.sc > m ) return 0;
	pii loc = Mp[ x.fi ][ x.sc ]; if( !loc.sc ) return 1;
	if( val.fi == loc.fi ) return 0;
	return val.sc >= loc.sc;
}
int bfs1( pii s , pii val ) {
	int cnt = 0;
	for( int i = 0 ; i < 4 ; i ++ ) {
		pii t = mp( s.fi + dx[ i ] , s.sc + dy[ i ] );
		if( ins( t , val ) && Graph[ id( s ) ][ i ] == 1 ) vis[ id( t ) ] = 1 , cnt ++;
	}
	return cnt;
}
void bfs2( pii s , pii val ) {
	queue< pii > Que;
	Que.push( s );
	while( !Que.empty() ) {
		pii u = Que.front(); Que.pop(); if( Mp[ u.fi ][ u.sc ].sc ) continue;
		for( int i = 0 ; i <= 1 ; i ++ ) {
			pii t = mp( u.fi + dx[ i ] , u.sc + dy[ i ] );
			if( ins( t , val ) && vis[ id( t ) ] != 2 && Graph[ id( u ) ][ i ] == 2 ) vis[ id( t ) ] = 2 , Que.push( t );
		}
	}
	Que.push( s );
	while( !Que.empty() ) {
		pii u = Que.front(); Que.pop(); if( Mp[ u.fi ][ u.sc ].sc ) continue;
		for( int i = 2 ; i <= 3 ; i ++ ) {
			pii t = mp( u.fi + dx[ i ] , u.sc + dy[ i ] );
			if( ins( t , val ) && vis[ id( t ) ] != 2 && Graph[ id( u ) ][ i ] == 2 ) vis[ id( t ) ] = 2 , Que.push( t );
		}
	}
}
void bfs3( pii s , pii val ) {
	queue< pii > Que;
	Que.push( s );
	while( !Que.empty() ) {
		pii u = Que.front(); Que.pop(); if( Mp[ u.fi ][ u.sc ].sc ) continue;
		for( int i = 0 ; i <= 3 ; i ++ ) {
			pii t = mp( u.fi + dx[ i ] , u.sc + dy[ i ] );
			if( ins( t , val ) && vis[ id( t ) ] != 3 && Graph[ id( u ) ][ i ] == 3 ) vis[ id( t ) ] = 3 , Que.push( t );
		}
	}
}

char str[ MAXN + 5 ];
int main( ) {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	Read( T );
	while( T -- ) {
		Read( n ) , Read( m ) , Read( q );
		for( int i = 1 ; i <= n ; i ++ ) {
			scanf("%s", str + 1 );
			for( int j = 1 ; j <= m - 1 ; j ++ ) {
				Graph[ id( i , j ) ][ 2 ] = str[ j ] - '0';
				Graph[ id( i , j + 1 ) ][ 3 ] = str[ j ] - '0';
			}
		}
		for( int i = 1 ; i <= n - 1 ; i ++ ) {
			scanf("%s", str + 1 );
			for( int j = 1 ; j <= m; j ++ ) {
				Graph[ id( i , j ) ][ 0 ] = str[ j ] - '0';
				Graph[ id( i + 1 , j ) ][ 1 ] = str[ j ] - '0';
			}
		}
		for( int i = 1 ; i <= n ; i ++ ) Mp[ i ].resize( m + 1 );
		
		for( int i = 1 ; i <= q ; i ++ ) {
			Read( col[ i ] ) , Read( lv[ i ] ) , Read( x[ i ] ) , Read( y[ i ] );
			int Ans = 0;
			if( n * m <= 5000 ) {
				memset( vis , 0 , sizeof( vis ) );
				bfs1( mp( x[ i ] , y[ i ] ) , mp( col[ i ] , lv[ i ] ) ); bfs2( mp( x[ i ] , y[ i ] ) , mp( col[ i ] , lv[ i ] ) ); bfs3( mp( x[ i ] , y[ i ] ) , mp( col[ i ] , lv[ i ] ) );
				for( int j = 1 ; j <= n * m ; j ++ ) if( vis[ j ] && j != id( x[ i ] , y[ i ] ) ) Ans ++;
			}
			else {
				Ans = bfs1( mp( x[ i ] , y[ i ] ) , mp( col[ i ] , lv[ i ] ) );
			}
			Write( Ans );
			Mp[ x[ i ] ][ y[ i ] ] = mp( col[ i ] , lv[ i ] );
		}
		for( int i = 1 ; i <= q ; i ++ ) Mp[ x[ i ] ][ y[ i ] ] = mp( 0 , 0 );
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

4
3
3
3
2

2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2

3
4
4
2
5
5
1
*/
