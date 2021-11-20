/*NE*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int readInt()
{
	bool neg = 0;
	int num = 0;
	
	char c = getchar();
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c == '-')	neg = !neg,	c = getchar();
	while(c>='0' && c<='9')	num += (num<<1) + (num<<3) + c - '0',	c = getchar();
	
	return neg ? -num : num;
}

const int N = 1e4;
const int M = 1e4;

int n, m, q, x0, y0;
int opt[N][M][2], color[N][M], level[N][M];//opt[i][j][0]横向 opt[i][j][1]纵向 
bool vis[N][M], end[N][M];

int moves(int x, int y, int r, int t)	//r:道路种类 //t:(r=1)t=0未走(r=2)t=0未确定方向t=1横向t=2纵向(t=3)无意义 
{	
	vis[x][y] = 1;
	
	int ans = end[x][y] ? 0 : 1;
	
	end[x][y] = 1;
	
	if(y<m){
		if(opt[x][y][0]==r && !vis[x][y+1]){
			if(color[x][y+1]==-1){
				if(r==1 && !t)
					ans += moves(x, y+1, 1, 1);
				else if(r==2 && (t==1 || t==0))
					ans += moves(x, y+1, 2, 1);
				else if(r==3)
					ans += moves(x, y+1, 3, t);
			}
			else if(color[x][y+1]!=color[x0][y0] && level[x][y+1]<=level[x0][y0]){
				ans += (!end[x][y+1]);
				end[x][y+1] = 1;
			}
		}
	}
	
	if(x<n){
		if(opt[x][y][1]==r && !vis[x+1][y]){
			if(color[x+1][y]==-1){
				if(r==1 && !t)
					ans += moves(x+1, y, 1, 1);
				else if(r==2 && (t==2 || t==0))
					ans += moves(x+1, y, 2, 2);
				else if(r==3)
					ans += moves(x+1, y, 3, t);
			}
			else if(color[x+1][y]!=color[x0][y0] && level[x+1][y]<=level[x0][y0]){
				ans +=1;
				end[x+1][y] = 1;
			}
		}
	}
	
	if(y>1){
		if(opt[x][y-1][0]==r && !vis[x][y-1]){
			if(color[x][y-1]==-1){
				if(r==1 && !t)
					ans += moves(x, y-1, 1, 1);
				else if(r==2 && (t==1 || t==0))
					ans += moves(x, y-1, 2, 1);
				else if(r==3)
					ans += moves(x, y-1, 3, t);
			}
			else if(color[x][y-1]!=color[x0][y0] && level[x][y-1]<=level[x0][y0]){
				ans +=1;
				end[x][y-1] = 1;
			}
		}
	}
	
	if(x>1){
		if(opt[x-1][y][1]==r && !vis[x-1][y]){
			if(color[x-1][y]==-1){
				if(r==1 && !t)
					ans += moves(x-1, y, 1, 1);
				else if(r==2 && (t==2 || t==0))
					ans += moves(x-1, y, 2, 2);
				else if(r==3)
					ans += moves(x-1, y, 3, t);
			}
			else if(color[x-1][y]!=color[x0][y0] && level[x-1][y]<=level[x0][y0]){
				ans +=1;
				end[x-1][y] = 1;
			}
		}
	}
	
	return ans;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T = readInt();
	
	while(T--){
		memset(color, 0xff, sizeof(color));
		memset(level, 0xff, sizeof(level));
		
		n = readInt(),	m = readInt(),	q = readInt();
		for(int i=1; i<=n; ++i){
			char str[500]={0};
			gets(str);
			for(int j=1; j<m; ++j)
				opt[i][j][0] = str[j-1]-'0';
		}
		for(int i=1; i<n; ++i){
			char str[500]={0};
			gets(str);
			for(int j=1; j<=m; ++j)
				opt[i][j][1] = str[j-1]-'0';
		}
		while(q--){
			memset(end, 0, sizeof(end));
			
			int col = readInt(), lv = readInt();
			x0 = readInt(), y0 = readInt();
			color[x0][y0] = col;
			level[x0][y0] = lv;
			end[x0][y0] = 1;
			
			int ans = 0;
			for(int i=1; i<=3; ++i){
				memset(vis, 0, sizeof(vis));
				ans += moves(x0, y0, i, 0);
			}
			
			printf("%d\n", ans);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
