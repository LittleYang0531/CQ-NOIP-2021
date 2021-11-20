#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
char v[2001][2001];
bool b[2001][2001];
struct Edge
{
	int col,lv,x,y;
}zfc[100001];
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	int sum=0,pu=0;
	while(!q.empty())
	{
		int nx=q.front().first,ny=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i];
			if(v[xx][yy])//?????????
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(b,false,sizeof(b));
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>q;
		for(int j=1;j<=n;j++)
		{
			for(int ii=1;ii<=m-1;ii++)
			{
				scanf("%c",&v[j][ii+1]);
				v[ii+1][j]=v[j][ii];
			}
		}
		for(int j=1;j<=n-1;j++)
		{
			for(int ii=1;ii<=m;ii++)
			{
				scanf("%c",&v[j+1][ii]);
				v[ii][j+1]=v[j+1][ii];
			}
		}
		for(int j=1;j<=q;j++)
		{
			scanf("%d%d%d%d",zfc[j].col,zfc[j].lv,zfc[j].x,zfc[j].y);
			bfs(zfc[j].x,zfc[j].y);
		}
	}
	return 0;
}
