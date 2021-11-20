#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#define maxn 5002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int dis[4][2]={1,0,0,1,-1,0,0,-1};
struct str{
	int op;
	int i;
	int x,y;
};
short a[maxn][maxn],b[maxn][maxn];
int c[maxn][maxn];
int cl[maxn],lv[maxn];
int cnt;
int n,m,Q;
bool vis[maxn][maxn],cc[maxn][maxn];
int rc()
{
	char c=getchar();
	while(c!='0'&&c!='1'&&c!='2'&&c!='3')c=getchar();
	return c-'0';
}
void Clear()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			vis[i][j]=0;
			cc[i][j]=0;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		m=read();
		Q=read();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				a[i][j]=rc();
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=rc();
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) c[i][j]=0;
		}
		while(Q--)
		{
			int sum=0;
			cnt++;
			Clear();
			cl[cnt]=read();
			lv[cnt]=read();
			int x=read(),y=read();
			vis[x][y]=1;
			c[x][y]=cnt;
			cc[x][y]=1;
			queue<str>q;
			for(int i=0;i<4;i++)
			{
				int xx=x+dis[i][0],yy=y+dis[i][1];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
				{
					if(!c[xx][yy])
					{
						int sx=0,sy=0,sz=0;
						if(i==0)
						{
							sx=x;
							sy=y;
							sz=0;
						}else if(i==1)
						{
							sx=x,sy=y;
							sz=1;
						}else if(i==2)
						{
							sx=xx;
							sy=yy;
							sz=0;
						}else
						{
							sx=xx;
							sy=yy;
							sz=1;
						}
						if(sz==0)
						{
							if(b[sx][sy]==1)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!1!%d %d\n",xx,yy);
							}else if(b[sx][sy]==2)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!2!%d %d\n",xx,yy);
								str w;
								w.op=2;
								w.i=i;
								w.x=xx;
								w.y=yy;
								q.push(w); 
							}else if(b[sx][sy]==3)
							{
								cc[xx][yy]=1;
								vis[xx][yy]=1;
								sum++;
//								printf("!3!%d %d\n",xx,yy);
								str w;
								w.op=3;
								w.x=xx;
								w.y=yy;
								q.push(w); 
							}
						}else
						{
							if(a[sx][sy]==1)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!4!%d %d\n",xx,yy);
							}else if(a[sx][sy]==2)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!5!%d %d\n",xx,yy);
								str w;
								w.op=2;
								w.i=i;
								w.x=xx;
								w.y=yy;
								q.push(w); 
							}else if(a[sx][sy]==3)
							{
								cc[xx][yy]=1;
								vis[xx][yy]=1;
								sum++;
//								printf("!6!%d %d\n",xx,yy);
								str w;
								w.op=3;
								w.x=xx;
								w.y=yy;
								q.push(w); 
							}
						}
					}else if(cl[cnt]!=cl[c[xx][yy]]&&lv[cnt]>=lv[c[xx][yy]])
					{
						int sx=0,sy=0,sz=0;
						if(i==0)
						{
							sx=x;
							sy=y;
							sz=0;
						}else if(i==1)
						{
							sx=x,sy=y;
							sz=1;
						}else if(i==2)
						{
							sx=xx;
							sy=yy;
							sz=0;
						}else
						{
							sx=xx;
							sy=yy;
							sz=1;
						}
						if(sz==0)
						{
							if(b[sx][sy]==1)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!7!%d %d\n",xx,yy);
							}else if(b[sx][sy]==2)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!8!%d %d\n",xx,yy);
							}else if(b[sx][sy]==3)
							{
								cc[xx][yy]=1;
								vis[xx][yy]=1;
								sum++;
//								printf("!9!%d %d\n",xx,yy);
							}
						}else
						{
							if(a[sx][sy]==1)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!10!%d %d\n",xx,yy);
							}else if(a[sx][sy]==2)
							{
								vis[xx][yy]=1;
								sum++;
//								printf("!11!%d %d\n",xx,yy);
							}else if(a[sx][sy]==3)
							{
								cc[xx][yy]=1;
								vis[xx][yy]=1;
								sum++;
//								printf("!12!%d %d\n",xx,yy);
							}
						}
					}
				}
			}
			while(!q.empty() )
			{
				str w=q.front() ;
				q.pop() ;
				if(w.op ==2)
				{
					str t=w;
					t.x+=dis[w.i][0];
					t.y+=dis[w.i][1];
					if(t.x>=1&&t.x<=n&&t.y>=1&&t.y<=m)
					{
						if(c[t.x][t.y])
						{
							if(cl[cnt]!=cl[c[t.x][t.y]]&&lv[cnt]>=lv[c[t.x][t.y]]);
							else continue;
						}
						int xx=t.x,yy=t.y,i=w.i;
						int x=w.x,y=w.y;
						int sx=0,sy=0,sz=0;
						if(i==0)
						{
							sx=x;
							sy=y;
							sz=0;
						}else if(i==1)
						{
							sx=x,sy=y;
							sz=1;
						}else if(i==2)
						{
							sx=xx;
							sy=yy;
							sz=0;
						}else
						{
							sx=xx;
							sy=yy;
							sz=1;
						}
						if(sz==0)
						{
							if(b[sx][sy]==2)
							{
								if(!vis[xx][yy])
								{
									vis[t.x][t.y]=1;
									sum++;
//								printf("!13!%d %d\n",xx,yy);
								}
							}
						}else
						{
							if(a[sx][sy]==2)
							{
								if(!vis[xx][yy])
								{
									vis[t.x][t.y]=1;
									sum++;
//								printf("!14!%d %d\n",xx,yy);
								}
							}
						}
						if(!c[xx][yy])
						{
							q.push(t); 
						}
					}
				}
				else
				{
					if(w.x==1&&w.y==1)
					{
//						printf("------------\n");
					}
					for(int i=0;i<4;i++)
					{
						str t=w;
						t.x+=dis[i][0];
						t.y+=dis[i][1];
						if(t.x>=1&&t.x<=n&&t.y>=1&&t.y<=m&&!cc[t.x][t.y])
						{
//							if(w.x==1&&w.y==1)puts("YES");
							int xx=t.x,yy=t.y;
							int x=w.x,y=w.y;
//							printf("!!!!%d %d!!!\n",xx,yy);
//							printf("!!!!%d\n",c[xx][yy]);
							if(!c[xx][yy])
							{
								int sx=0,sy=0,sz=0;
								if(i==0)
								{
									sx=x;
									sy=y;
									sz=0;
								}else if(i==1)
								{
									sx=x,sy=y;
									sz=1;
								}else if(i==2)
								{
									sx=xx;
									sy=yy;
									sz=0;
								}else
								{
									sx=xx;
									sy=yy;
									sz=1;
								}
//								printf("%d %d %d\n",sx,sy,sz);
								if(sz==0)
								{
									if(b[sx][sy]==3)
									{
										if(!vis[xx][yy])
										{
											vis[xx][yy]=1;
											sum++;
//								printf("!15!%d %d\n",xx,yy);
										}
										cc[xx][yy]=1;
										q.push(t); 
									}
								}else
								{
									if(a[sx][sy]==3)
									{
										if(!vis[xx][yy])
										{
											vis[xx][yy]=1;
											sum++;
//								printf("!16!%d %d\n",xx,yy);
										}
										cc[xx][yy]=1;
										q.push(t);
									}
								}
							}else if(cl[cnt]!=cl[c[xx][yy]]&&lv[cnt]>=lv[c[xx][yy]])
							{
								int sx=0,sy=0,sz=0;
								if(i==0)
								{
									sx=x;
									sy=y;
									sz=0;
								}else if(i==1)
								{
									sx=x,sy=y;
									sz=1;
								}else if(i==2)
								{
									sx=xx;
									sy=yy;
									sz=0;
								}else
								{
									sx=xx;
									sy=yy;
									sz=1;
								}
								if(sz==0)
								{
									if(b[sx][sy]==3)
									{
										if(!vis[xx][yy])
										{
											vis[xx][yy]=1;
											sum++;				
//								printf("!17!%d %d\n",xx,yy);							
										}
									}
									cc[xx][yy]=1;
								}else
								{
									if(a[sx][sy]==3)
									{
										if(!vis[xx][yy])
										{
											vis[xx][yy]=1;
											sum++;
//									printf("!18!%d %d\n",xx,yy);											
										}
									}
									cc[xx][yy]=1;
								}
							}
						}
					}
					if(w.x==1&&w.y==1)
					{
//						printf("------------\n");
					}
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}


