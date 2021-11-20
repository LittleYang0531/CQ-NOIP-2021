#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std ;

void fl()
{
	freopen("chess.in" , "r" , stdin) ;
	freopen("chess.out" , "w" , stdout) ;
}

const int N = 105 ;

int rd()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1 ; ch =  getchar() ;} 
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - 48 ; ch = getchar() ;}
	return x * f ;
}

struct Node
{
	int l , r , u , d ;
	int c , lv ;	
} road[N][N] ;

int n , m , q ;
char str[N] ;

void dfs(int x , int y , int ls)
{
	
	if(x > 1)
	{
		if(road[x - 1][y].c != road[x][y].c && road[x - 1][y].lv <= road[x][y].lv)
		{
			if(ls == -1 || ls == road[x][y].u);
		}
	}
}

int main()
{
	fl() ;
	cout << "Finally u can know cxf!" ;
//	int T = rd() ;
//	while(T--)
//	{
//		n = rd() ; m = rd() ; q = rd() ;
//		for(int i = 1 ; i <= n ; i++)
//		{
//			scanf("%s"str+1) ;
//			for(int j = 1 ; j < m ; j++)
//				road[i][j + 1].l = road[i][j].r = str[j] - 48 ;
//		}
//		for(int i = 1 ; i < n ; i++)
//		{
//			scanf("%s"str+1) ;
//			for(int j = 1 ; j <= m ; j++)
//				road[i + 1][j].u = road[i][j].d = str[j] - 48 ;
//		}
//		while(q--)
//		{
//			int c = rd() , lv = rd() , x = rd() , y = rd() ;
//			road[x][y].c = c ; road[x][y].lv = lv ;
//			dfs(x , y , -1) ;
//		}
//	}
	return 0 ;
}
