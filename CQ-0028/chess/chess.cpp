#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 200005
int n, m, Q, ans;
int **vis, **vis1, **vis2, **vis3, **row, **col, **ch, **lev;
char s[maxn];
struct node { int x, y, k, d; };
queue < node > q;

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
	if( x > 9 ) print( x / 10 );
	putchar( x % 10 + '0' );
}

bool inside( int x, int y ) {
	if( x < 1 or y < 1 or x > n or y > m ) return 0;
	else return 1;
}

void bfs( int c, int l, int sx, int sy, int t ) {
	q.push( { sx, sy, 1, -1 } );
	q.push( { sx, sy, 2, 0 } );
	q.push( { sx, sy, 2, 1 } );
	q.push( { sx, sy, 3, -1 } );
//	printf( "%d\n", ans );
	while( ! q.empty() ) {
		node now = q.front(); q.pop();
		int x = now.x, y = now.y, k = now.k, d = now.d;
//		printf( "%d %d %d[][]\n", x, y, k );
		if( vis[x][y] ^ t and ( x ^ sx or y ^ sy ) ) ans ++;
		vis[x][y] = t;
//		printf( "start ::: %d\n", ans );
		if( k == 1 ) {
			if( inside( x - 1, y ) and row[x - 1][y] == k and t != vis1[x - 1][y] ) {
				if( ! ~ ch[x - 1][y] ) {
//					printf( " ??? " );
					vis1[x - 1][y] = t;
					if( vis[x - 1][y] ^ t ) ans ++, vis[x - 1][y] = t;
				}
				else if( ch[x - 1][y] ^ ch[sx][sy] ) {
//					printf( )
					if( lev[x - 1][y] <= l ) {
						if( vis[x - 1][y] ^ t ) ans ++;
						vis[x - 1][y] = t;
					}
				}
			}
			if( inside( x + 1, y ) and row[x][y] == k and t != vis1[x + 1][y] ) {
				if( ! ~ ch[x + 1][y] ) {
					vis1[x + 1][y] = t;
					if( vis[x + 1][y] ^ t ) ans ++, vis[x + 1][y] = t;
				}
				else if( ch[x + 1][y] ^ ch[sx][sy] ) {
					if( lev[x + 1][y] <= l ) {
						if( vis[x + 1][y] ^ t ) ans ++;
						vis[x + 1][y] = t;
					}
				}
			}
			if( inside( x, y - 1 ) and col[x][y - 1] == k and t != vis1[x][y - 1] ) {
				if(! ~ ch[x][y - 1] ) {
					vis1[x][y - 1] = t; if( vis[x][y - 1] ^ t)ans ++, vis[x][y - 1] = t;}
				else if( ch[x][y - 1] ^ ch[sx][sy] ) {
					if( lev[x][y - 1] <= l ) {
						if( vis[x][y - 1] ^ t ) ans ++;
						vis[x][y - 1] = t;
					}
				}
			}
			if( inside( x, y + 1 ) and col[sx][sy] == k and t != vis1[x][y + 1] ) {
				if(! ~ ch[x][y + 1] ) {
					vis1[x][y + 1] = t; if( vis[x][y + 1] ^ t ) ans ++, vis[x][y + 1] = t; }
				else if( ch[x][y + 1] ^ ch[sx][sy] ) {
					if( lev[x][y + 1] <= l ) {
						if( vis[x][y + 1] ^ t ) ans ++;
						vis[x][y + 1] = t;
					}
				}
			}
		}
		if( k == 2 ) {
//			printf( "%d[][][]][][[][][]]\n", col[x][y - 1] );
			if( d == 0 and inside( x - 1, y ) and row[x - 1][y] == k and t != vis2[x - 1][y] ) {
				if( ! ~ ch[x - 1][y] ) q.push( { x - 1, y, k, d } ), vis2[x - 1][y] = t;
				else if( ch[x - 1][y] ^ ch[sx][sy] ) {
					if( lev[x - 1][y] <= l ) {
						if( vis[x - 1][y] ^ t ) ans ++;
						vis[x - 1][y] = t;
					}
				}
			}
			if( d == 0 and inside( x + 1, y ) and row[x][y] == k and t != vis2[x + 1][y] ) {
//				printf( "{%d  %d} %d %d\n", x + 1, y, ch[x + 1][y], lev[x + 1][y] );
				if( ! ~ ch[x + 1][y] ) q.push( { x + 1, y, k, d } ), vis2[x + 1][y] = t;
				else if( ch[x + 1][y] ^ ch[sx][sy] ) {
					if( lev[x + 1][y] <= l ) {
						if( vis[x + 1][y] ^ t ) ans ++;
						vis[x + 1][y] = t;
					}
				}
			}
			if( d == 1 and inside( x, y - 1 ) and col[x][y - 1] == k and t != vis2[x][y - 1] ) {
//				printf( "%d inside(%d)\n", ch[x][y - 1], inside( x, y - 1) );
				if( ! ~ ch[x][y - 1] ) q.push( { x, y - 1, k, d } ), vis2[x][y - 1] = t;
				else if( ch[x][y - 1] ^ ch[sx][sy] ) {
					if( lev[x][y - 1] <= l ) {
						if( vis[x][y - 1] ^ t ) ans ++;
						vis[x][y - 1] = t;
					}
				}
			}
			if( d == 1 and inside( x, y + 1 ) and col[x][y] == k and t != vis2[x][y + 1] ) {
				if( ! ~ ch[x][y + 1] ) q.push( { x, y + 1, k, d } ), vis2[x][y + 1] = t;
				else if( ch[x][y + 1] ^ ch[sx][sy] ) {
					if( lev[x][y + 1] <= l ) {
						if( vis[x][y + 1] ^ t ) ans ++;
						vis[x][y + 1] = t;
					}
				}
			}
		}
		if( k == 3 ) {
			if( inside( x - 1, y ) and row[x - 1][y] == k and t != vis3[x - 1][y] ) {
				if( ! ~ ch[x - 1][y] ) q.push( { x - 1, y, k } ), vis3[x - 1][y] = t;
				else if( ch[x - 1][y] ^ ch[sx][sy] ) {
					if( lev[x - 1][y] <= l ) {
						if( vis[x - 1][y] ^ t ) ans ++;
						vis[x - 1][y] = t;
					}
				}
			}
			if( inside( x + 1, y ) and row[x][y] == k and t != vis3[x + 1][y] ) {
				if( ! ~ ch[x + 1][y] ) q.push( { x + 1, y, k } ), vis3[x + 1][y] = t;
				else if( ch[x + 1][y] ^ ch[sx][sy] ) {
					if( lev[x + 1][y] <= l ) {
						if( vis[x + 1][y] ^ t ) ans ++;
						vis[x + 1][y] = t;
					}
				}
			}
			if( inside( x, y - 1 ) and col[x][y - 1] == k and vis3[x][y - 1] != t ) {
				if( ! ~ ch[x][y - 1] ) q.push( { x, y - 1, k } ), vis3[x][y - 1] = t;
				else if( ch[x][y - 1] ^ ch[sx][sy] ) {
//					printf( " >>>>>>>>>>\n " );
					if( lev[x][y - 1] <= l ) {
						if( vis[x][y - 1] ^ t ) ans ++;
						vis[x][y - 1] = t;
					}
				}
			}
			if( inside( x, y + 1 ) and col[x][y] == k and t != vis3[x][y + 1] ) {
				if( ! ~ ch[x][y + 1] ) q.push( { x, y + 1, k } ), vis3[x][y + 1] = t;
				else if( ch[x][y + 1] ^ ch[sx][sy] ) {
					if( lev[x][y + 1] <= l ) {
						if( vis[x][y + 1] ^ t ) ans ++;
						vis[x][y + 1] = t;
					}
				}
			}
		}
//		printf( "%d\n", ans );
	}
}

int main() {
	freopen( "chess.in", "r", stdin );
	freopen( "chess.out", "w", stdout );
	int T = read();
	while( T -- ) {
		n = read(), m = read(), Q = read();
		vis1 = new int *[n + 5];
		vis2 = new int *[n + 5];
		vis3 = new int *[n + 5];
		vis = new int *[n + 5];
		row = new int *[n + 5];
		col = new int *[n + 5];
		lev = new int *[n + 5];
		ch = new int *[n + 5];
		for( int i = 1;i <= n;i ++ ) {
			vis1[i] = new int [m + 5];
			vis2[i] = new int [m + 5];
			vis3[i] = new int [m + 5];
			vis[i] = new int [m + 5];
			row[i] = new int [m + 5];
			col[i] = new int [m + 5];
			lev[i] = new int [m + 5];
			ch[i] = new int[m + 5];
			for( int j = 1;j <= m;j ++ ) {
				ch[i][j] = -1;
				lev[i][j] = vis[i][j] = vis1[i][j] = vis2[i][j] = vis3[i][j] = 0;
			}
		}
		for( int i = 1;i <= n;i ++ ) {
			scanf( "%s", s + 1 );
			for( int j = 1;j < m;j ++ ) 
				col[i][j] = s[j] ^ 48;
		}
		for( int i = 1;i < n;i ++ ) {
			scanf( "%s", s + 1 );
			for( int j = 1;j <= m;j ++ )
				row[i][j] = s[j] ^ 48;
		}
		for( int i = 1;i <= Q;i ++ ) {
			int c = read(), l = read(), x = read(), y = read();
			ch[x][y] = c;
			lev[x][y] = l;
			bfs( c, l, x, y, i );
			print( ans );
			putchar( '\n' );
			ans = 0;
		}
	}
	return 0;
}
