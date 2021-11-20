#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 105 ;
const int MOD = 998244353;
int n,m,k,ans ;
int v[N],a[N] ;
inline void read(int &x)
{
	x = 0 ;
	char c = getchar() ;
	while(!isdigit(c)) c = getchar() ;
	while(isdigit(c)) x = (x<<1)+(x<<3)+(c^48),c = getchar() ;
}
inline void print(int x)
{
	if(x > 9) print(x/10) ;
	putchar(x%10+'0') ;
}
void check(int s)
{
	int ti = 0 ;
	while(s)
	{
		ti += (s&1) ;
		s >>= 1ll ;
	}
	if(ti > k) return ;
	int sum = v[a[1]] ;
	for(int i = 2 ; i <= n ; ++i )
		sum = (sum*v[a[i]])%MOD ;
	ans = (ans+sum)%MOD ;
}
void find(int x,int s)
{
	if(x == n+1)
	{
		check(s) ;
		return ;
	}
	for(int i = 0 ; i <= m ; ++i )
	{
		a[x] = i ;
		find(x+1,s+(int)(1ll<<i)) ;
		a[x] = 0 ;
	}
}
signed main()
{
	freopen("sequence.in","r",stdin) ;
	freopen("sequence.out","w",stdout) ;
	read(n),read(m),read(k) ;
	for(int i = 0 ; i <= m ; ++i ) read(v[i]) ;
	find(1,0) ;
	print(ans) ;
	return 0 ;
}
