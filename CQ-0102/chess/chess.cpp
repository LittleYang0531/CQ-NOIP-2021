#include<bits/stdc++.h>
using namespace std;
const unsigned int classroom=4274906972ll;
struct nodgd
{
	int x0,y0,op;
	nodgd (int _x,int _y,int _op)
	{
		x0=_x;
		y0=_y;
		op=_op;
	}
};
struct chess
{
	int col,lv,o;
};
chess hve[3240][3240];
char u_d[3240][3240];
char l_r[3240][3240];
int n,m,q,col,lv,x,y,t,ans;
deque <nodgd> pq;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&m,&q);
		memset(l_r,0,sizeof(l_r));
		memset(u_d,0,sizeof(u_d));
		for (int i=1;i<=n;i++)
		{
			cin>>l_r[i];
		}
		for (int i=1;i<=m;i++)
		{
			cin>>u_d[i];
		}
		for (int i=1;i<=q;i++)
		{
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			hve[x][y].col=col;
			hve[x][y].lv=lv;
			hve[x][y].o=1;
			//查上 
			int op=u_d[x-2][y-1]-48;
			if (op==1 && ((hve[x-1][y].lv<(hve[x][y].lv && col!=hve[x-1][y].col) || hve[x-1][y].o==0)))
			{
				ans++;
			}
			else if (op==2) 
			{
				for (int o=x-1;o>=1;o--)
				{
					if (u_d[o-1][y-1]==2) 
					{
						ans++;
						if (hve[o][y].o==1)
						{
							if (lv>hve[o][y].lv && hve[o][y].col!=col)
							{
								ans++;
							}
							break;
						}
					}
				}
			}
			else if (op==3) //bfs
			{
				pq.push_back(nodgd(x,y,3));
				while (!pq.empty())
				{
					nodgd d=pq.front();
					pq.pop_front();
					for (int i=0;i<=3;i++) //dx1 u dx2 d dx3 l dx4 r
					{
						if (d.x0+dx[i]<=n && d.x0+dx[i]>=1 && d.y0+dy[i]<=m && d.y0-dy[i]>=1) 
						{
							if (i==0 && d.op==u_d[d.x0-2][d.y0-1])
							{
								ans++;
								pq.push_back(nodgd(d.x0+dx[i],d.y0+dy[i],3));
								if (hve[d.x0+dx[i]][d.y0+dy[i]].o==1)
								{
									if (lv>hve[d.x0+dx[i]][d.y0+dy[i]].lv) ans++;
									i++;
								}
							}
							if (i==1 && d.op==u_d[d.x0][d.y0])
							{
								ans++;
								pq.push_back(nodgd(d.x0+dx[i],d.y0+dy[i],3));
								if (hve[d.x0+dx[i]][d.y0+dy[i]].o==1)
								{
									if (lv>hve[d.x0+dx[i]][d.y0+dy[i]].lv) ans++;
									i++;
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	//写不完了... 0pts 
}
