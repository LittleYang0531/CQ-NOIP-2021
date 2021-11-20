#include<bits/stdc++.h>
#define re register
using namespace std;
const int posx[4]={0,1,0,-1};
const int posy[4]={1,0,-1,0};
int board[5005][5005];
int way[5005][5005][4];
bool col[2005];
int lv[2005];
bool visit[5005][5005],desti[5005][5005];
int T,m,n,q,res;
void Init()
	{
		for (re int i=1;i<=5005;i++)
			for (re int j=1;j<=5005;j++)
				{
					board[i][j]=0;
					visit[i][j]=0;
					desti[i][j]=0;
					for (re int t=0;t<4;t++)
						{
							way[i][j][t]=0;
						}
				}
		for (re int i=1;i<=2005;i++)
			{
				col[i]=0;
				lv[i]=0;
			}
		
	}
void dfs(int x,int y,int id,int opt=-1,int to=-1,int step=0,int eat=0)
	{
		for (int i=0;i<4;i++)
			{
				int xx=x+posx[i];
				int yy=y+posy[i];
				if (xx>=1 and xx<=n and yy>=1 and yy<=m)
					{
						if (opt==-1 or way[x][y][i]==opt)
							{
								if (board[xx][yy]!=0)
									{
										if (col[id] == col[board[xx][yy]] or lv[id]<lv[board[xx][yy]])
											continue;
										eat=1;
									}
								if (opt==1)
									{
										if (step>1)
											break;
									}
								else if (opt==2)
									{
										if (to!=-1 and to!=i)
											continue;
									}
								if (eat==2)
									break;
								//cout<<way[x][y][i]<<endl<<endl;
								if (!visit[xx][yy] and way[x][y][i]!=0)
									{
										visit[xx][yy]=1;
										if (!desti[xx][yy])
											{
												res++;
												desti[xx][yy]=1;
											}
										//printf("(%d,%d)",xx,yy);
										dfs(xx,yy,id,way[x][y][i],i,step+1,eat*2);
										visit[xx][yy]=0;
									}
								eat=0;
							}
					}
			}
	}
inline int read()
	{
		int f=1,x=0;
		char ch=getchar();
		while (ch<'0' or ch>'9')
			{
				if (ch=='-')
					f=-1;
				ch=getchar();
			}
		while (ch>='0' and ch<='9')
			{
				x= (x<<3) + (x<<1) + (ch^48);
				ch=getchar();
			}
		return x*f;
	}
int main()
	{
		freopen("chess.in","r",stdin);
		freopen("chess.out","w",stdout);
		T=read();
		while(T)
			{
				T=T-1;
				Init();
				n=read();m=read();q=read();
				string str;
				for (int i=1;i<=n;i++)
					{
						cin>>str;
						for(int j=1;j<m;j++)
							{
								int pos=int(str[j-1]-'0');
								//cout<<pos<<endl;
								way[i][j][0]=pos;
								//printf("(%d,%d)->(%d,%d) : %d\n",i,j,i,j+1,pos);
								way[i][j+1][2]=pos;
								//printf("(%d,%d)->(%d,%d) : %d\n",i,j+1,i,j,pos);
							}
					}
				for (int i=1;i<n;i++)
					{
						cin>>str;
						for(int j=1;j<=m;j++)
							{
								int pos=int(str[j-1]-'0');
								//cout<<pos<<endl;
								way[i][j][1]=pos;
								way[i+1][j][3]=pos;
							}
					}
				/*
				for (int i=1;i<=n;i++)
					{
						for(int j=1;j<=m;j++)
							{
								for (int t=0;t<4;t++)
									{
										int xx=j+posx[t];
										int yy=i+posy[t];
										if (xx>=1 and xx<=m and yy>=1 and yy<=n)
											{
												printf ("(%d,%d)->(%d,%d) : %d\n",j,i,xx,yy,way[j][i][t]);
											}
									}
									
							}
					}
				*/
				for(int i=1;i<=q;i++)
					{
						int x,y;
						col[i]=read();
						lv[i]=read();
						x=read();y=read();
						board[x][y]=i;
						dfs(x,y,i);
						printf("%d\n",res);
						for (re int i=1;i<=n;i++)
							for (re int j=1;j<=m;j++)
								{
									desti[i][j]=0;
								}
						res=0;
					}
			}
		return 0;
	}
