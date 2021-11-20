#ifdef TIME_MESSURE
#include <ctime>
#endif

#include <set>
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ ) 
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int col[MAXN], lvl[MAXN];
int rig[MAXN], dn[MAXN];

int N, M, Q;

#define ID( x, y ) ( ( (x) - 1 ) * M + (y) )

int GetType( const int x, const int y, const int d ) {
    if( d == 0 ) return dn[ID( x - 1, y )];
    if( d == 1 ) return dn[ID( x, y )];
    if( d == 2 ) return rig[ID( x, y - 1 )];
    if( d == 3 ) return rig[ID( x, y )];
    return -1;
}

inline bool Inside( const int x, const int y ) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

int Reach( const int x, const int y, const int d, const int c, const int l ) {
    int tx = x + dir[d][0], ty = y + dir[d][1];
    if( ! Inside( tx, ty ) ) return 0;
    if( col[ID( tx, ty )] == -1 ) return 1;
    if( col[ID( tx, ty )] == c ||
        lvl[ID( tx, ty )] > l ) return 0;
    return 2;
}

namespace Force {
    int q[MAXN];
    bool vis[MAXN];

    void Voyage( const int s, const int ned, const int c, const int l ) {
        if( ned == 0 ) {
            vis[s] = true;
            return ;
        }
        int ux, uy;
        if( ned == 1 ) {
            ux = ( s - 1 ) / M + 1;
            uy = ( s - 1 ) % M + 1;
            for( int k = 0 ; k < 4 ; k ++ )
                if( Inside( ux + dir[k][0], uy + dir[k][1] ) &&
                    GetType( ux, uy, k ) == ned && Reach( ux, uy, k, c, l ) )
                    vis[ID( ux + dir[k][0], uy + dir[k][1] )] = true;
            return ;
        }
        if( ned == 2 ) {
            ux = ( s - 1 ) / M + 1;
            uy = ( s - 1 ) % M + 1;
            for( int d = 0 ; d < 4 ; d ++ )
                for( int k = 0 ; ; k ++ ) {
                    int tx = ux + k * dir[d][0],
                        ty = uy + k * dir[d][1];
                    if( ! Inside( tx + dir[d][0], ty + dir[d][1] ) ) break;
                    if( GetType( tx, ty, d ) != ned ) break;
                    int typ = Reach( tx, ty, d, c, l );
                    if( ! typ ) break;
                    vis[ID( tx + dir[d][0], ty + dir[d][1] )] = true;
                    if( typ == 2 ) break;
                }
        }
        if( ned == 3 ) {
            // this type of move must be performed first.
            int h = 1, t = 0;
            q[++ t] = s, vis[s] = true;
            while( h <= t ) {
                ux = ( q[h] - 1 ) / M + 1;
                uy = ( q[h] - 1 ) % M + 1;
                h ++;
                for( int d = 0 ; d < 4 ; d ++ ) {
                    int tx = ux + dir[d][0],
                        ty = uy + dir[d][1];
                    if( Inside( tx, ty ) && ! vis[ID( tx, ty )] && 
                        GetType( ux, uy, d ) == ned ) {
                        int tmp = Reach( ux, uy, d, c, l );
                        if( tmp == 0 ) continue;
                        vis[ID( tx, ty )] = true;
                        if( tmp == 2 ) continue;
                        q[++ t] = ID( tx, ty );
                    }
                }
            }
        }
    }

    void Solve() {
        while( Q -- ) {
            int c, l, x, y;
            read( c ), read( l );
            read( x ), read( y );
            rep( i, 1, N * M ) vis[i] = false;
            per( k, 3, 0 ) 
                Voyage( ID( x, y ), k, c, l );
            int ans = 0;
            rep( i, 1, N * M ) ans += vis[i];
            write( ans - 1 ), putchar( '\n' );
            col[ID( x, y )] = c;
            lvl[ID( x, y )] = l; 
        }
    }
}

namespace NoHighway {
    std :: set<int> rowApp[MAXN], colApp[MAXN];

    int mst[4][MAXN];

    bool Chk() {
        rep( i, 1, N ) rep( j, 1, M - 1 )
            if( rig[ID( i, j )] == 3 ) return false;
        rep( i, 1, N - 1 ) rep( j, 1, M )
            if( dn[ID( i, j )] == 3 ) return false;
        return true;
    }

    void Solve() {
        rep( i, 1, N ) rowApp[i].clear();
        rep( j, 1, M ) colApp[j].clear();
        rep( i, 1, N ) rep( j, 1, M ) {
            int cur = ID( i, j );
            if( i > 1 && GetType( i, j, 0 ) == 2 )
                mst[0][cur] = mst[0][ID( i - 1, j )];
            else mst[0][cur] = i;
            if( j > 1 && GetType( i, j, 2 ) == 2 )
                mst[2][cur] = mst[2][ID( i, j - 1 )];
            else mst[2][cur] = j;
        }
        per( i, N, 1 ) per( j, M, 1 ) {
            int cur = ID( i, j );
            if( i < N && GetType( i, j, 1 ) == 2 )
                mst[1][cur] = mst[1][ID( i + 1, j )];
            else mst[1][cur] = i;
            if( j < M && GetType( i, j, 3 ) == 2 )
                mst[3][cur] = mst[3][ID( i, j + 1 )];
            else mst[3][cur] = j;
        }
        while( Q -- ) {
            int ans = 0;
            int c, l, x, y;
            read( c ), read( l );
            read( x ), read( y );
            for( int d = 0 ; d < 4 ; d ++ ) 
                if( Inside( x + dir[d][0], y + dir[d][1] ) ) {
                    if( GetType( x, y, d ) == 0 ) continue;
                    if( GetType( x, y, d ) == 1 ) 
                        if( Reach( x, y, d, c, l ) )
                            ans ++;
                    if( GetType( x, y, d ) == 2 ) {
                        if( d == 0 ) {
                            std :: set<int> :: iterator it = 
                                colApp[y].lower_bound( x );
                            if( it == colApp[y].begin() ) 
                                ans += x - mst[d][ID( x, y )];
                            else {
                                int tar = * -- it;
                                if( col[ID( tar, y )] == c || l < lvl[ID( tar, y )] ) 
                                    ans += x - MAX( tar + 1, mst[d][ID( x, y )] );
                                else ans += x - MAX( tar, mst[d][ID( x, y )] );
                            }
                        }
                        if( d == 1 ) {
                            std :: set<int> :: iterator it = 
                                colApp[y].lower_bound( x );
                            if( it == colApp[y].end() )
                                ans += mst[d][ID( x, y )] - x;
                            else {
                                int tar = * it;
                                if( col[ID( tar, y )] == c || l < lvl[ID( tar, y )] )
                                    ans += MIN( tar - 1, mst[d][ID( x, y )] ) - x;
                                else ans += MIN( tar, mst[d][ID( x, y )] ) - x;
                            }
                        }
                        if( d == 2 ) {
                            std :: set<int> :: iterator it = 
                                rowApp[x].lower_bound( y );
                            if( it == rowApp[x].begin() )
                                ans += y - mst[d][ID( x, y )];
                            else { 
                                int tar = * -- it;
                                if( col[ID( x, tar )] == c || l < lvl[ID( x, tar )] )
                                    ans += y - MAX( tar + 1, mst[d][ID( x, y )] );
                                else ans += y - MAX( tar, mst[d][ID( x, y )] );
                            }
                        }
                        if( d == 3 ) {
                            std :: set<int> :: iterator it =
                                rowApp[x].lower_bound( y );
                            if( it == rowApp[x].end() )
                                ans += mst[d][ID( x, y )] - y;
                            else {
                                int tar = * it;
                                if( col[ID( x, tar )] == c || l < lvl[ID( x, tar )] )
                                    ans += MIN( tar - 1, mst[d][ID( x, y )] ) - y;
                                else ans += MIN( tar, mst[d][ID( x, y )] ) - y;
                            }
                        }
                    }
                }
            write( ans ), putchar( '\n' );
            col[ID( x, y )] = c;
            lvl[ID( x, y )] = l;
            rowApp[x].insert( y );
            colApp[y].insert( x );
        }
    }
}

int main() {
    freopen( "chess.in", "r", stdin );
    freopen( "chess.out", "w", stdout );
    int T; read( T );
    while( T -- ) {
        read( N ), read( M ), read( Q );
        rep( i, 1, N ) rep( j, 1, M )
            col[ID( i, j )] = lvl[ID( i, j )] = -1,
            rig[ID( i, j )] = dn[ID( i, j )] = 0;
        rep( i, 1, N ) rep( j, 1, M - 1 )
            scanf( "%1d", &rig[ID( i, j )] );
        rep( i, 1, N - 1 ) rep( j, 1, M )
            scanf( "%1d", &dn[ID( i, j )] );
        if( NoHighway :: Chk() )
            NoHighway :: Solve();
        else Force :: Solve();
        // if( NoHighway :: Chk() )
        //     NoHighway :: Solve();
    }
#ifdef TIME_MESSURE
    fprintf( stderr, "Run time: %.3fs\n", 1.0 * clock() / CLOCKS_PER_SEC );
#endif
    return 0;
}