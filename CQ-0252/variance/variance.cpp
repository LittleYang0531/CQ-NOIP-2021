#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e4+5 ;
int n,ans=1e9 ;
int a[N],b[N] ;
double s = 0.993 ;
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
double Time()
{
	return (double)clock()/CLOCKS_PER_SEC ;
}
void SA()
{
	double T = 5000 ;
	while(T >= 1e-12)
	{
		int now = 0,sum = 0 ;
		int x = rand()%n+1 ;
		if(x == 1 || x == n) continue ;
		if(b[x+1]+b[x-1]-b[x] < b[x-1] || b[x+1]+b[x-1]-b[x] > b[x+1]) continue ;
		int y = b[x] ;
		b[x] = b[x+1]+b[x-1]-b[x] ;
		for(int i = 1 ; i <= n ; ++i ) sum += b[i] ;
		for(int i = 1;  i <= n ; ++i )
			now += ((n*n*b[i]*b[i])-(2*b[i]*sum*n)+sum*sum) ;
		now /= n ;
	 	if(now < ans) ans = now ;
	 	else 
	 	{
	 		if(exp((now-ans)/T) < double(rand()/RAND_MAX)) b[x] = y ;
		 }
		 T *= s ;
	 } 
}
signed main()
{
	freopen("variance.in","r",stdin) ;
	freopen("variance.out","w",stdout) ;
	srand(114*514/191*810) ;
	read(n) ;
	for(int i = 1 ; i <= n ; ++i ) read(a[i]) ;
	while(Time() < 0.8) 
	{
		for(int i = 1 ; i <= n ; ++i ) b[i] = a[i] ;
		SA() ; 
	}
	print(ans) ;
	return 0 ;
}
