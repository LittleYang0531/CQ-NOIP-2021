#include<bits/stdc++.h>
using namespace std;
 
int T;
int N;
int M;
int Q;
int cnt;
int vis[1005][1005];
int ifdo[1005][1005];
int op[2][100][100][100];
int ant[2][100][100][100];
//0 ºá 
//1 Êú 
const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,-1};

struct f
{
 	int x;
 	int y;
	int val;
 	int col;
}e[1000005]; 
 
void doit(int k,int x,int y,int id,int val)
{
	if(x<1||x>N||y<1||y>M)
	{
		return ;
	}
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(vis[xx][yy])
		{
			for(int j=1;j<=k;j++)
			{
				if(e[j].x==xx&&e[j].y==yy)
				{
					if((e[k].col^e[j].col)&&e[k].val>e[j].val)
					{
						cnt++;
					}
				}
			}	
		}
		else
		{
			//0 1 -->x 1
			//2 3 -->y 0
			int ok;
			if(i/2==0)
			{
				ok=op[1][x][xx][y];
			}
			else
			{
				ok=op[0][x][y][yy];
			}
			if((val==-1)||(val==ok))
			{
				if(ok==0)
				{
					continue;
				}
				if(ok==1)
				{
					if(!ant[1][x][xx][y])
					{
						ant[1][x][xx][y]=1;	
						if(!ifdo[xx][yy])
						{
							cnt++;
							ifdo[xx][yy]=1;
							doit(k,xx,yy,id,ok);
						}
					}
				}
				if(ok==2)
				{
					int g=i/2;
					// 0 su
					// 1 heng
					if((id==-1)||(g==id))
					{
						if(!ifdo[xx][yy])
						{
							cnt++;
							ifdo[xx][yy]=1;
							doit(k,xx,yy,id,ok);
						}
					}
				}
				if(ok==3)
				{
					if(!ifdo[xx][yy])
					{
						cnt++;
						ifdo[xx][yy]=1;
						doit(k,xx,yy,id,ok);
					}
				}
			}
		}
	}
}
 
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T)
	{
		T--;
		cin>>N>>M>>Q;
		string s;
		for(int i=1;i<=N;i++)
		{
			cin>>s;
			for(int j=0;j<=M-2;j++)
			{
				op[0][i][j+1][j+2]=op[0][i][j+2][j+1]=s[j]-48;
			}
		}
		for(int i=1;i<=N-1;i++)
		{
			cin>>s;
			for(int j=0;j<=N-1;j++)
			{
				op[1][i][i+1][j+1]=op[1][i+1][i][j+1]=s[j]-48;
			}
		}
		for(int i=1;i<=Q;i++)
		{
			cin>>e[i].col>>e[i].val>>e[i].x>>e[i].y;
			vis[e[i].x][e[i].y]=1;
			cnt=0;
			memset(ant,0,sizeof ant);
			memset(ifdo,0,sizeof ifdo);
			doit(i,e[i].x,e[i].y,-1,-1);
			cout<<cnt<<endl;
		}
		
	}
	return 0;
}
