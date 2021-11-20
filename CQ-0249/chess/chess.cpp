#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c)){if(c=='-') f=1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return f==0?x:-x;
}
void out(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}
struct qz
{
	int clr,lv,x,y;
	void init()
	{
		clr=read(),lv=read(),x=read(),y=read();
	}
	void out()
	{
		cerr<<clr<<" "<<lv<<' '<<x<<" "<<y<<"\n";
	}
//	bool operator < (const qz a) const
//	{
//		return a.x<x;
//	}
}a[100010];
int T,n,m,q,ans;
char c;
vector<int> hen[200010],zng[200010],qp[200010],tj[200010];
vector<bool> vis[200010];
vector<pair<int,int> > jyh[200010];
bool ok(int x,int y)
{
	return (1<=x&&x<=n&&1<=y&&y<=m);
}
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//0上 1左 2下 3右 
int ttt;
//map<qz,bool> mp;
void dfs(int x,int y,int qz_clr,int qz_lv,int lu,int cx)
{
//	if(mp[(qz){qz_clr,qz_lv,x,y}]==1) return;
//	mp[(qz){qz_clr,qz_lv,x,y}]=1;
	if(tj[x][y]!=ttt)
	{
//		cerr<<"ans++\n";
		tj[x][y]=ttt;
		ans++;	
	}
//	cerr<<x<<' '<<y<<" "<<qz_clr<<" "<<qz_lv<<' '<<lu<<" "<<cx<<"f"<<'\n';
	if(lu==1)
	{
//		cerr<<"hh\n";
		return;
	}
	if(lu==2)
	{
		int zx=x+dir[cx][0],zy=y+dir[cx][1];
//		cerr<<zx<<" "<<zy<<"z\n";
		if(ok(zx,zy))
		{
//			cerr<<zx<<' '<<zy<<" "<<vis[zx][zy]<<"ok\n";
			if(!vis[zx][zy])
			{
//				cerr<<zx<<' '<<zy<<"ok\n";
				if(cx==3)
				{
//					cerr<<hen[x][y]<<" "<<lu<<"qiao\n";
					if(hen[x][y]!=0&&lu==hen[x][y])
					{
						int tmp=qp[zx][zy];
						if(!tmp)
						{
							vis[zx][zy]=1;
//							if(zx==1&&zy==1)
//							{
//								cerr<<x<<' '<<y<<"Error1\n"; 
//							}
//							cerr<<zx<<" "<<zy<<"emm\n";
							dfs(zx,zy,qz_clr,qz_lv,hen[zx][zy],cx);
							vis[zx][zy]=0;
						}
						else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)
						{
							dfs(zx,zy,qz_clr,qz_lv,1,cx);
						}
//						cerr<<qz_clr<<"pp\n";
					}
				}
				if(cx==2)
				{
//					cerr<<zng[x][y]<<" "<<lu<<"qiao3\n";
					if(zng[x][y]!=0&&lu==zng[x][y])
					{
						int tmp=qp[zx][zy];
						if(!tmp)
						{
							vis[zx][zy]=1;
//							if(zx==1&&zy==1)
//							{
//								cerr<<x<<' '<<y<<"Error1\n"; 
//							}
//							cerr<<zx<<" "<<zy<<"emm\n";
							dfs(zx,zy,qz_clr,qz_lv,zng[zx][zy],cx);
							vis[zx][zy]=0;
						}
						else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)
						{
							dfs(zx,zy,qz_clr,qz_lv,1,cx);
						}
//						cerr<<qz_clr<<"pp\n";
					}
				}
				if(cx==0)
				{
					if(zng[zx][zy]!=0&&lu==zng[zx][zy])
					{
						int tmp=qp[zx][zy];
						if(!tmp)
						{
							vis[zx][zy]=1;
//							if(zx==1&&zy==1)
//							{
//								cerr<<x<<' '<<y<<"Error2\n"; 
//							}
//							cerr<<zx<<" "<<zy<<"emm2\n";
							dfs(zx,zy,qz_clr,qz_lv,zng[zx][zy],cx);
							vis[zx][zy]=0;
							return;
						}
						else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(zx,zy,qz_clr,qz_lv,1,cx);
//						cerr<<qz_clr<<"p\n";
					}
				}
				if(cx==1)
				{
					if(hen[zx][zy]!=0&&lu==hen[zx][zy])
					{
						int tmp=qp[zx][zy];
						if(!tmp)
						{
							vis[zx][zy]=1;
//							if(zx==1&&zy==1)
//							{
//								cerr<<x<<' '<<y<<"Error2\n"; 
//							}
//							cerr<<zx<<" "<<zy<<"emm2\n";
							dfs(zx,zy,qz_clr,qz_lv,hen[zx][zy],cx);
							vis[zx][zy]=0;
							return;
						}
						else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(zx,zy,qz_clr,qz_lv,1,cx);
//						cerr<<qz_clr<<"p\n";
					}
				}
			}
		}
		return;
	}
	if(ok(x-1,y))
	{
		if(!vis[x-1][y])
			if(zng[x-1][y]&&(lu==-1||lu==zng[x-1][y]))
			{
				int tmp=qp[x-1][y];
				if(!tmp)
				{
					vis[x-1][y]=1;
//					if(x-1==3&&y==1)
//					{
//						cerr<<x<<' '<<y<<"Error3\n"; 
//					}
					dfs(x-1,y,qz_clr,qz_lv,zng[x-1][y],0);
					vis[x-1][y]=0;
				}
				else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(x-1,y,qz_clr,qz_lv,1,0);
			} 
	}
	if(ok(x+1,y))
	{
		if(!vis[x+1][y])
			if(zng[x][y]&&(lu==-1||lu==zng[x][y]))
			{
				int tmp=qp[x+1][y];
				if(!tmp)
				{
					vis[x+1][y]=1;
//					if(x+1==3&&y==1)
//					{
//						cerr<<x<<' '<<y<<"Error4\n"; 
//					}
					dfs(x+1,y,qz_clr,qz_lv,zng[x][y],2);
					vis[x+1][y]=0;
				}
				else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(x+1,y,qz_clr,qz_lv,1,2);
			} 
	}
	if(ok(x,y-1))
	{
		if(!vis[x][y-1])
			if(hen[x][y-1]&&(lu==-1||lu==hen[x][y-1]))
			{
				int tmp=qp[x][y-1];
				if(!tmp)
				{
					vis[x][y-1]=1;
//					if(x==3&&y-1==1)
//					{
//						cerr<<x<<' '<<y<<"Error5\n"; 
//					}
					dfs(x,y-1,qz_clr,qz_lv,hen[x][y-1],1);
					vis[x][y-1]=0;
				}
				else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(x,y-1,qz_clr,qz_lv,1,1);
			} 
	}
	if(ok(x,y+1))
	{
		if(!vis[x][y+1])
			if(hen[x][y]&&(lu==-1||lu==hen[x][y]))
			{
				int tmp=qp[x][y+1];
				if(!tmp)
				{
					vis[x][y+1]=1;
//					cerr<<x<<' '<<y<<" "<<hen[x].size()<<"hen\n";
//					if(x==3&&y+1==1)
//					{
//						cerr<<x<<' '<<y<<"Error6\n"; 
//					}
					dfs(x,y+1,qz_clr,qz_lv,hen[x][y],3);
					vis[x][y+1]=0;
				}
				else if(qz_clr!=a[tmp].clr&&qz_lv>=a[tmp].lv)dfs(x,y+1,qz_clr,qz_lv,1,3);
			} 
	}
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
//		cerr<<n<<" "<<m<<" "<<q<<"nmq\n";
	//	bool vis[n+1][m+1],hen[n+1][m+1],zng[n+1][m+1];
		for(int i=0;i<=n;i++)
		{
			qp[i].clear();
			vis[i].clear();
			hen[i].clear();
			zng[i].clear();
			tj[i].clear();
			hen[i].push_back(0);
			zng[i].push_back(0);
			for(int j=0;j<=m;j++)
			{
				qp[i].push_back(0);
				vis[i].push_back(0);
				tj[i].push_back(0);
			}
		}	
		for(int i=1;i<=n;i++)
		{
//			cerr<<c<<" ";
			for(int j=1;j<m;j++)
			{
				c=getchar();
	//			hen[i][j]=c-'0';
//				cerr<<c<<"c\n";
				hen[i].push_back(c-'0');
			}
			c=getchar();
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				c=getchar();
	//			zng[i][j]=c-'0';
//				cerr<<c<<"cc\n";
				zng[i].push_back(c-'0');
			}
			c=getchar();
		}
	//	queue<qz> qu;
		for(int i=1;i<=q;i++)
		{
//			mp.clear();
			ttt=i;
			ans=0;
			a[i].init();
			vis[a[i].x][a[i].y]=1;
			dfs(a[i].x,a[i].y,a[i].clr,a[i].lv,-1,-1);
			vis[a[i].x][a[i].y]=0;
			qp[a[i].x][a[i].y]=i;
			out(ans-1);
			putchar('\n');
		}
	}
	
	return 0;
}
/*
花三小时怒码312行，希望有点分=-=
sto 摸鱼酱 orz
sto 华恋~韵 orz
sto B神 orz 
*/
