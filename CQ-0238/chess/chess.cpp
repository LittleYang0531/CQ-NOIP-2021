#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,q,opt1[8005][8005],opt2[8005][8005],col[8005][8005],lv[8005][8005];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
bool flag[8005][8005];
int putong(int x,int y)
{
//	cout<<x<<' '<<y<<' '<<(opt1[x][y-1]==1&&col[x][y-1]!=col[x][y]&&lv[x][y]>=lv[x][y-1])<<'\n';
	return (opt1[x][y]==1&&col[x][y+1]!=col[x][y]&&lv[x][y]>=lv[x][y+1])
		  +(opt1[x][y-1]==1&&col[x][y-1]!=col[x][y]&&lv[x][y]>=lv[x][y-1])
		  +(opt2[x][y]==1&&col[x+1][y]!=col[x][y]&&lv[x][y]>=lv[x+1][y])
		  +(opt2[x-1][y]==1&&col[x-1][y]!=col[x][y]&&lv[x][y]>=lv[x-1][y]);
}
int zhixing(int x,int y)
{
	int sum=0,tx=x,ty=y;
	while(opt1[tx][ty]==2&&col[tx][ty+1]!=col[x][y]&&lv[x][y]>=lv[tx][ty+1])
	{
		sum++; ty++;
		if(col[tx][ty]!=-1) break;
	}
	ty=y;
	while(opt1[tx][ty-1]==2&&col[tx][ty-1]!=col[x][y]&&lv[x][y]>=lv[tx][ty-1])
	{
		sum++,ty--;
//		if(x==2&&y==3) cout<<tx<<' '<<ty<<' '<<opt1[tx][ty-1]<<'\n';
		if(col[tx][ty]!=-1) break;
	}
//	cout<<x<<' '<<y<<' '<<sum<<'\n';
	ty=y;
	while(opt2[tx][ty]==2&&col[tx+1][ty]!=col[x][y]&&lv[x][y]>=lv[tx+1][ty])
	{
		sum++,tx++;
		if(col[tx][ty]!=-1) break;
	}
	tx=x;
	while(opt2[tx-1][ty]==2&&col[tx-1][ty]!=col[x][y]&&lv[x][y]>=lv[tx-1][ty])
	{
		sum++,tx--;
		if(col[tx][ty]!=-1) break;
	}
	return sum;
}
int dfs(int x,int y,int sx,int sy)
{
	int sum=0;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if((dx[i]==1&&opt2[tx-1][ty]!=3)||(dx[i]==-1&&opt2[tx][ty]!=3)||(dy[i]==1&&opt1[tx][ty-1]!=3)||(dy[i]==-1&&opt1[tx][ty]!=3)||flag[tx][ty]||tx<1||tx>n||ty<1||ty>m)
			continue;
		if(col[sx][sy]!=col[tx][ty]&&lv[sx][sy]>=lv[tx][ty])
		{
			flag[tx][ty]=1;
			if(col[x][y]==-1) sum++;
			else sum+=dfs(tx,ty,sx,sy)+1;
			flag[tx][ty]=0;
		}
	}
	return sum;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(col,-1,sizeof(col));
		memset(lv,-1,sizeof(lv));
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++) scanf("%1d",&opt1[i][j]);
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++) scanf("%1d",&opt2[i][j]);
		for(int Col,Lv,x,y,i=1;i<=q;i++)
		{
			scanf("%d %d %d %d",&Col,&Lv,&x,&y);
			col[x][y]=Col;
			lv[x][y]=Lv;
			flag[x][y]=1;
			printf("%d\n",putong(x,y)+zhixing(x,y)+dfs(x,y,x,y));
			flag[x][y]=0;
		}
	}
	return 0;
}
