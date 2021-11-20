#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>

using namespace std ;

typedef long long ll ;
const int N = 1e5 + 5 ;
 

void fl()
{
	freopen("variance.in" , "r" , stdin) ;
	freopen("variance.out" , "w" , stdout) ;
}

int n ;
int a[N] , b[N] ;
ll ans = 1e18 ;

void solve()
{
	ll t = 0 , s = 0 ;
	for(int i = 1 ; i <= n ; i++)
	{
//		cout << b[i] << ' ' ;
		s += b[i] ;
	}
//	cout << '\n' ;
	
	for(int i = 1 ; i <= n ; i++)
	{
		t += (n * b[i] - s) * (n * b[i] - s) / n ;
		if(t > ans) break ;	
	}
//	cout << s << '\n' ;
	ans = min(ans , t) ;
}
 
set<string> st ; 
bool check()
{
	string str ;
	for(int i = 1 ; i <= n ; i++)
	{
		int t = b[i] ;
		while(t)
		{
			str.push_back((t % 10) - 48) ;
			t /= 10 ;
		}	
	}
	if(st.count(str)) return true ;
	st.insert(str) ;
	return false ;
}
void dfs()
{
	if(check()) return ;
	solve() ;
	for(int i = 2 ; i < n ; i++)
	{
		int t = b[i + 1] + b[i - 1] - b[i] ;
//		cout << t << '\n' ;
		if(t < b[i - 1] || t > b[i + 1]) continue ;
		int c = b[i] ;
		b[i] = t ;
		
		dfs() ;
		b[i] = c ;
	}
}

int main()
{
	fl() ;
	scanf("%d",&n) ;

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",a+i) , b[i] = a[i] ;
	dfs() ;
	cout << ans ;
	return 0 ;
}
