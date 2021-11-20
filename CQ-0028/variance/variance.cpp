#include <cstdio>
#include <iostream>
using namespace std;
#define maxn 10005
double a[maxn];
int n;
double ans, ans1, ans2;

int main() {
	freopen( "variance.in", "r", stdin );
	freopen( "variance.out", "w", stdout );
	scanf( "%d", &n );
	for( int i = 1;i <= n;i ++ ) scanf( "%lf", &a[i] );
	if( n == 2 ) {
		double ave = ( a[1] + a[2] ) / 2;
		for( int i = 1;i <= n;i ++ ) ans += ( a[i] - ave ) * ( a[i] - ave );
		return ! printf( "%0.f\n", ans * n );
	}
	if( n == 3 ) {
		double ave = ( a[1] + a[2] + a[3] ) / 2;
		for( int i = 1;i <= n;i ++ ) ans += ( a[i] - ave ) * ( a[i] - ave );
		a[2] = a[1] + a[3] - a[2];
		double ave1 = ( a[1] + a[2] + a[3] ) / 2;
		for( int i = 1;i <= n;i ++ ) ans1 += ( a[i] - ave1 ) * ( a[i] - ave1 );
		return ! printf( "%.0f\n", min( ans, ans1 ) * n );
	}
	double ave = ( a[1] + a[n] ) / 2;
	printf( "%.0f\n", ( ( a[1] - ave ) * ( a[1] - ave ) + ( a[n] - ave ) * ( a[n] - ave ) ) * n );
	return 0;
}
