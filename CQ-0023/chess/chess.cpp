#include <bits/stdc++.h>
using namespace std;
int T , n , m , q , col[220000] , lv[220000] , f2 , f3 , x , y;
vector< int > re[220000] , ce[220000] , id[220000] , vis[5][220000] , f[220000]; 
char ch[330000];
struct item
{
	int x , y , tp;
};
queue< item > p;
//re[i][j]: i,j -> i,j+1; ce[i][j]: i,j -> i+1,j
int main()
{
	freopen("chess.in" , "r" , stdin);
	freopen("chess.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &n , &m , &q); 
		for(int i = 1 ; i <= 200000 ; i++ ) re[i].resize(0) , ce[i].resize(0) , id[i].resize(0) , f[i].resize(0);
		for(int i = 1 ; i <= 200000 ; i++ ) vis[0][i].resize(0) , vis[1][i].resize(0) , vis[2][i].resize(0) , vis[3][i].resize(0) , vis[4][i].resize(0);
		for(int i = 1 ; i <= n ; i++ ) re[i].resize(m + 1);
		for(int i = 1 ; i <= n ; i++ ) ce[i].resize(m + 1);
		for(int i = 1 ; i <= n ; i++ ) 
		{
			id[i].resize(m + 1); vis[0][i].resize(m + 1); vis[1][i].resize(m + 1); vis[2][i].resize(m + 1); vis[3][i].resize(m + 1); vis[4][i].resize(m + 1); f[i].resize(m + 1); 
			for(int j = 1 ; j <= m ; j++ ) id[i][j] = vis[0][i][j] = vis[1][i][j] = vis[2][i][j] = vis[3][i][j] = vis[4][i][j] = f[i][j] = 0;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%s" , ch);
			for(int j = 1 ; j < m ; j++ )
			{
				re[i][j] = ch[j - 1] - '0';
				if(re[i][j] == 2) re[i][j] = 4;
			}
		}
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%s" , ch);
			for(int j = 1 ; j <= m ; j++ )
			{
				ce[i][j] = ch[j - 1] - '0';
			}
		}
//		if(!f3)
//		{
//			
//			
//			return 0;
//		}
		for(int i = 1 ; i <= q ; i++ )
		{
			scanf("%d%d%d%d" , &col[i] , &lv[i] , &x , &y);
			int ans = 0;
			p.push((item){x , y , -1}); vis[0][x][y] = vis[1][x][y] = vis[2][x][y] = vis[3][x][y] = vis[4][x][y] = i; f[x][y] = i;
			while(!p.empty())
			{
				int x = p.front().x , y = p.front().y , tp = p.front().tp; 
				p.pop(); 
				if(tp == 1) continue;
				if(y < m && (re[x][y] == tp || tp == -1)
				 && re[x][y] && vis[re[x][y]][x][y + 1] != i)
				{
					vis[re[x][y]][x][y + 1] = i;
					if(id[x][y + 1])
					{
//						if(i == 3) cerr << x << ' ' << y + 1 << endl;
						int d = id[x][y + 1];
						if(col[d] != col[i] && lv[d] <= lv[i]) ans += (f[x][y + 1] != i) , f[x][y + 1] = i;
					}
					else
					{
						ans += (f[x][y + 1] != i); f[x][y + 1] = i;
						p.push((item){x , y + 1 , re[x][y]});
					}
//					if(x == 1 && y + 1 == 3) cerr << x << ' ' << y << endl;
//					cerr << x << ' ' << y + 1 << endl;
				}
				if(y > 1 && (re[x][y - 1] == tp || tp == -1)
				 && re[x][y - 1] && vis[re[x][y - 1]][x][y - 1] != i)
				{
					vis[re[x][y - 1]][x][y - 1] = i;
					if(id[x][y - 1])
					{
//						if(i == 3) cerr << x << ' ' << y - 1 << ' ' << T << endl;
						int d = id[x][y - 1];
						if(col[d] != col[i] && lv[d] <= lv[i]) ans += (f[x][y - 1] != i) , f[x][y - 1] = i;
					}
					else
					{
						ans += (f[x][y - 1] != i); f[x][y - 1] = i;
						p.push((item){x , y - 1 , re[x][y - 1]});
					}
//					cerr << x << ' ' << y - 1 << endl;
//					if(x == 1 && y - 1 == 3) cerr << x << ' ' << y << endl;
				}
				if(x < n && (ce[x][y] == tp || tp == -1)
				 && ce[x][y] && vis[ce[x][y]][x + 1][y] != i)
				{
					vis[ce[x][y]][x + 1][y] = i;
					if(id[x + 1][y])
					{
//						if(i == 3) cerr << x + 1 << ' ' << y << ' ' << T << endl;
						int d = id[x + 1][y];
						if(col[d] != col[i] && lv[d] <= lv[i]) ans += (f[x + 1][y] != i) , f[x + 1][y] = i;
					}
					else
					{
						ans += (f[x + 1][y] != i); f[x + 1][y] = i;
						p.push((item){x + 1 , y , ce[x][y]});
					}
//					cerr << x + 1 << ' ' << y << endl;
//					if(x + 1 == 1 && y == 3) cerr << x << ' ' << y << endl;
				}
				if(x > 1 && (ce[x - 1][y] == tp || tp == -1)
				 && ce[x - 1][y] && vis[ce[x - 1][y]][x - 1][y] != i)
				{
					vis[ce[x - 1][y]][x - 1][y] = i;
					if(id[x - 1][y])
					{
//						if(i == 3) cerr << x - 1 << ' ' << y << ' ' << T << endl;
						int d = id[x - 1][y];
						if(col[d] != col[i] && lv[d] <= lv[i]) ans += (f[x - 1][y] != i) , f[x - 1][y] = i;
					}
					else
					{
						ans += (f[x - 1][y] != i); f[x - 1][y] = i;
						p.push((item){x - 1 , y , ce[x - 1][y]});
					}
//					cerr << ce[x - 1][y] << endl;
//					cerr << x - 1 << ' ' << y << endl;
//					if(x - 1 == 1 && y == 3) cerr << x << ' ' << y << endl;
				}
			}
			printf("%d\n" , ans);
			id[x][y] = i;
		}
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
