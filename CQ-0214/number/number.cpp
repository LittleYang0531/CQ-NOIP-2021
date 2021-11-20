#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std ;

const int N = 1e7 + 5 ;

void fl()
{
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
}

vector<int> _type7 ;
int p[N] ;
long long limit ;

bool judge(int x)
{
	while(x)
	{
		if(x % 10 == 7) return true ;
		x /= 10 ;
	}
	return false ;
}

void init()
{ 
	for(int i = 1 ; i <= limit ; i++)
	{
		if(p[i] != 2 && judge(i) )
		{
			p[i] = 1 ;
			for(int j = i + i ; j <= limit ; j += i)
				p[j] = 2 ;
		}
		else if(p[i] == 0)
			_type7.push_back(i) ;
	}
}

int main()
{
	fl() ;
	
	int t ; 
	scanf("%d",&t) ;
	if(t <= 1000) limit = 1e4 + 5 ;
	else if(t <= 100000) limit = 2e5 + 5 ;
	else limit = 1e7 + 5 ;

	init() ;
	while(t--)
	{
		int x ; scanf("%d",&x) ;
		if(p[x]){ puts("-1") ; continue ; }
		vector<int>::iterator it = lower_bound(_type7.begin() , _type7.end() , x) ;
		printf("%d\n",*(++it)) ;
	}
	
	return 0 ;
}
