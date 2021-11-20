#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10000010
int num[maxn];
bool vis[maxn + 5];
int T, cnt;

int read() {
	int x = 0; char s = getchar();
	while( s < '0' or s > '9' ) s = getchar();
	while( '0' <= s and s <= '9' ) {
		x = ( x << 1 ) + ( x << 3 ) + ( s ^ 48 );
		s = getchar();
	}
	return x;
}

void print( int x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( x > 9 ) print( x / 10 );
	putchar( x % 10 + '0' );
}

int main() {
	freopen( "number.in", "r", stdin );
	freopen( "number.out", "w", stdout );
	T = read();
	for( int i = 1;i <= maxn;i ++ ) {
		int x = i, flag = 0;
		while( x ) {
			if( x % 10 == 7 ) flag = 1;
			x /= 10;
		}
		if( ! flag ) continue;
		for( int k = i;k <= maxn;k += i ) vis[k] = 1;
	}
	for( int i = 1;i <= maxn;i ++ ) if( ! vis[i] ) num[++ cnt] = i;
	for( int i = 1, x;i <= T;i ++ ) {
		x = read();
		if( vis[x] ) {
			puts( "-1" );
			continue;
		}
		else {
			int p = upper_bound( num + 1, num + cnt + 1, x ) - num;
			print( num[p] );
			putchar( '\n' );
		}
	}
	return 0;
}
