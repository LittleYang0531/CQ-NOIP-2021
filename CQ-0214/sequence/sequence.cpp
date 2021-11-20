#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std ;

typedef long long ll ;
const int N = 1005 ;
const int P = 998244353 ;

void fl()
{
	freopen("sequence.in" , "r" , stdin) ;
	freopen("sequence.out" , "w" , stdout) ;
}

int n , k , m ;
ll v[N] ;

ll jc[N] , inv[N] , po[N] ;
ll qpow(ll a , int b)
{
	ll res = 1 ;	
	while(b){if(b & 1) res = res * a % P ; a = a * a % P ; b = b / 2 ;}
	return res ;
}

ll C(int n , int m)
{
	return jc[n] * inv[m] % P * inv[n - m] % P ;
}

void init()
{
	inv[0] = inv[1] = jc[0] = jc[1] = 1 ;
	po[0] = 1 ; po[1] = 2 ;
	for(int i = 2 ; i <= N ; i++)
	{
		po[i] = po[i - 1] * 2 ;
		jc[i] = jc[i - 1] * i ;
		inv[i] = qpow(jc[i] , P - 2) ;
 	}
}

ll limit ;
ll ans ;
int vis[1228805] , cnt[30] ; 
vector<int> temp ;

void solve()
{ 
	ll t = 1 ;
	temp.clear() ;
	for(int i = 0 ; i <= m ; i++ )
		if(cnt[i])
		{
//			cout << i << ' ' << cnt[i] << '\n' ;
			temp.push_back(cnt[i]) ;
			t = t * qpow(v[i] , cnt[i]) % P ;
		}
//	cout << "----------\n" ;
//	cout << t << '\n' ;
	
	int l = temp.size() - 1 , s = n ;
	for(int i = 0 ; i < l ; i++)
	{
		t = t * C(s , temp[i]) % P , s -= temp[i] ;
//		cout << temp[i] << '\n' ;	
	}
	
	ans = (ans + t) % P ;
}

void dfs2(int s , int ls , int t)
{
	if(t > n) return ;
	if(!s){cnt[0] = n - t ; solve() ; return ; }
	for(int i = ls ; i <= m ; i++)
	{
		if(po[i] - 1 > s) break ;
		cnt[i]++ ;
		dfs2(s - po[i] + 1 , i , t + 1) ;
		cnt[i]-- ;
	}
}

void dfs(int t , int p , ll s)
{
	if(s > limit || t > k || po[(p==0?0:p-1)] > limit) return ;
	if(s >= n && vis[s] == 0)
	{
		//do sth ...
		vis[s] = 1 ;
//		cout << s << '\n' ;
		dfs2(s - n , 1 , 0) ;
	}
	dfs(t , p + 1 , s) ;
	dfs(t + 1 , p + 1 , s + po[p]) ;
}

int main()
{
	fl() ;
//	cout << (long long)pow(2,12)*30 ;
	scanf("%d%d%d",&n,&m,&k) ;
	for(int i = 0 ; i <= m ; i++)
		scanf("%lld",v+i) ;
	init() ;
	limit = (long long)pow(2,m)*n ;
//	cout << limit << '\n' ;
	dfs(0 , 0 , 0) ;
	printf("%lld",ans) ;
	return 0 ;
}
