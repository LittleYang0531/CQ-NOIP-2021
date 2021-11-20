#include<bits/stdc++.h>
using namespace std;
struct p
{
	int x;
	int y;
};
int t,n,m,q,cnt,head[3005][3005],ans[100005],viss[3005][3005],visb[3005][3005];
struct chess
{
	int col;
	int lv;
};
vector <chess> v[100005];
struct edge
{
	int next;
	p to;
	int sta;
}e[100005],re;
void addedge(p x,p y,int z)
{
	cnt++;
	e[cnt].to=y;
	e[cnt].next=head[x.x][x.y];
	e[cnt].sta=z;
	head[x.x][x.y]=cnt;
}
void dfs(int xx,int yy,int coln,int lvn,int opt,int nq,int lx,int ly)
{
	if(viss[xx][yy]==1) return;
	viss[xx][yy]=1,visb[xx][yy]=1;
	if(opt==-1)
	{
		for(int i=head[xx][yy];i;i=e[i].next)
		{
			//cout<<e[i].to.x<<" "<<e[i].to.y<<v[e[i].to.x][e[i].to.y].col<<endl;
			if(e[i].sta!=0)
			{
				if(v[e[i].to.x][e[i].to.y].col==2)
				{
					memset(viss,0,sizeof(viss));
					//cout<<"-1: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
					if(visb[e[i].to.x][e[i].to.y]==0)
					ans[nq]++;
					dfs(e[i].to.x,e[i].to.y,coln,lvn,e[i].sta,nq,xx,yy);
				}
				else if(v[e[i].to.x][e[i].to.y].col==coln&&v[e[i].to.x][e[i].to.y].lv<=lvn)
				{
					//cout<<"-1: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
					if(visb[e[i].to.x][e[i].to.y]==0)
					ans[nq]++;
				}
			}	
		}
	}
	else if(opt==0)
	{
		return;
	}
	else if(opt==1)
	{
		return;
	}
	else if(opt==2)
	{
		if(xx==lx)
		{
			for(int i=head[xx][yy];i;i=e[i].next)
			{
				if(e[i].to.x==xx&&e[i].sta==2&&viss[e[i].to.x][e[i].to.y]==0)
				{
					if(v[e[i].to.x][e[i].to.y].col==2)
					{
						//cout<<"2: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
						if(visb[e[i].to.x][e[i].to.y]==0)
						ans[nq]++;
						dfs(e[i].to.x,e[i].to.y,coln,lvn,e[i].sta,nq,xx,yy);
					}
					else if(v[e[i].to.x][e[i].to.y].col!=coln&&v[e[i].to.x][e[i].to.y].lv<=lvn)
					{
						if(visb[e[i].to.x][e[i].to.y]==0)
						ans[nq]++;
						//cout<<"2: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
					}
				}
			}
		}
		if(yy==ly)
		{
			for(int i=head[xx][yy];i;i=e[i].next)
			{
				if(e[i].to.y==yy&&e[i].sta==2&&viss[e[i].to.x][e[i].to.y]==0)
				{
					if(v[e[i].to.x][e[i].to.y].col==2)
					{
					//	cout<<"2: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
						if(visb[e[i].to.x][e[i].to.y]==0)
						ans[nq]++;
						dfs(e[i].to.x,e[i].to.y,coln,lvn,e[i].sta,nq,xx,yy);
					}
					else if(v[e[i].to.x][e[i].to.y].col!=coln&&v[e[i].to.x][e[i].to.y].lv<=lvn)
					{
						//cout<<"2: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
						if(visb[e[i].to.x][e[i].to.y]==0)
						ans[nq]++;
					}
				}
			}
		}
	}
	else if(opt==3)
	{
		for(int i=head[xx][yy];i;i=e[i].next)
		{
			if(e[i].sta==3&&viss[e[i].to.x][e[i].to.y]==0)
			{
				if(v[e[i].to.x][e[i].to.y].col==2)
				{
				//	cout<<"3: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
					if(visb[e[i].to.x][e[i].to.y]==0)
					ans[nq]++;
					dfs(e[i].to.x,e[i].to.y,coln,lvn,e[i].sta,nq,xx,yy);
				}
				else if(v[e[i].to.x][e[i].to.y].col!=coln&&v[e[i].to.x][e[i].to.y].lv<=lvn)
				{
				//	cout<<"3: "<<e[i].to.x<<" "<<e[i].to.y<<" "<<visb[e[i].to.x][e[i].to.y]<<"// ";
					if(visb[e[i].to.x][e[i].to.y]==0)
					ans[nq]++;
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		memset(ans,0,sizeof(ans));
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			char c[m-1];
			cin>>c;
			for(int j=0;j<m-1;j++)
			{
				p a,b;
				a.x=i,a.y=j+1,b.x=i,b.y=j+2;
				addedge(a,b,c[j]-'0');
				addedge(b,a,c[j]-'0');
			}
		}
		for(int i=1;i<n;i++)
		{
			char c[m];
			cin>>c;
			for(int j=0;j<m;j++)
			{
				p a,b;
				a.x=i,a.y=j+1,b.x=i+1,b.y=j+1;
				addedge(a,b,c[j]-'0');
				addedge(b,a,c[j]-'0');
			}
		}
		for(int i=1;i<=n+1;i++)
		{
			v[i].clear();
			for(int j=1;j<=m+1;j++)
			{
				chess a;
				a.col=2,a.lv=0;
				v[i].push_back(a);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int c,l,a,b;
			cin>>c>>l>>a>>b;
			dfs(a,b,c,l,-1,i,0,0);
			v[a][b].col=c;
			v[a][b].lv=l;
			cout<<ans[i]<<endl;
			memset(visb,0,sizeof(visb));
			memset(viss,0,sizeof(viss));
		}
	}
	return 0;
}//解决不了互通道路···寄了···
//好像解决了？我1，2样例过了，听天命吧，我已经尽人事了 
