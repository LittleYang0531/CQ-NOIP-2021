#include<bits/stdc++.h>
using namespace std;
int n,m,t,p,a,s,d,f,k,dd[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char xi[1002][1002],yi[1002][1002];
bool b[1002][1002];
struct node{int col,lv;}mp[1002][1002];
int r()
{
	register int q=0,w=1;register char e=getchar();
	while(e<'0'||e>'9'){if(e=='-')w=-1;e=getchar();}
	while(e>='0'&&e<='9')q=(q<<3)+(q<<1)+e-'0',e=getchar();
	return q*w;
}
void dfs(int x,int y,int h,bool xz,bool j1,bool cr)
{
	if(!b[x][y])k++;
	b[x][y]=1;
	if(cr)return;
	for(int i=0;i<4;i++)
	{
		cr=0;
		int xx=x+dd[i][0],yy=y+dd[i][1];
		if(xx>0&&yy>0&&xx<=n&&yy<=m)
		{
			if(mp[xx][yy].lv)
			{
				if(mp[xx][yy].lv<s&&mp[xx][yy].col!=a)cr=1;
				else continue;
			}
			if(i==0&&xi[xx][yy]=='1'&&!j1&&(h==0||h==1))dfs(xx,yy,0,0,1,cr);
			if(i==1&&xi[x][y]=='1'&&!j1&&(h==0||h==1))dfs(xx,yy,0,0,1,cr);
			if(i==2&&yi[xx][yy]=='1'&&!j1&&(h==0||h==1))dfs(xx,yy,0,0,1,cr);
			if(i==3&&yi[x][y]=='1'&&!j1&&(h==0||h==1))dfs(xx,yy,0,0,1,cr);
			
			if(i==0&&xi[xx][yy]=='2'&&(h==0||h==1))dfs(xx,yy,1,0,j1,cr);
			if(i==1&&xi[x][y]=='2'&&(h==0||h==2))dfs(xx,yy,2,0,j1,cr);
			if(i==2&&yi[xx][yy]=='2'&&(h==0||h==3))dfs(xx,yy,3,0,j1,cr);
			if(i==3&&yi[x][y]=='2'&&(h==0||h==4))dfs(xx,yy,4,0,j1,cr);
			
			if(i==0&&xi[xx][yy]=='3'&&(h==0||h==3)&&!b[xx][yy])dfs(xx,yy,0,1,j1,cr);
			if(i==1&&xi[x][y]=='3'&&(h==0||h==3)&&!b[xx][yy])dfs(xx,yy,0,1,j1,cr);
			if(i==2&&yi[xx][yy]=='3'&&(h==0||h==3)&&!b[xx][yy])dfs(xx,yy,0,1,j1,cr);
			if(i==3&&yi[x][y]=='3'&&(h==0||h==3)&&!b[xx][yy])dfs(xx,yy,0,1,j1,cr);
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=r();
	while(t--)
	{
		n=r();m=r();p=r();
		for(int i=1;i<=n;i++)scanf("%s",yi[i]+1);
		for(int i=1;i<n;i++)scanf("%s",xi[i]+1);
		while(p--)
		{
			a=r(),s=r(),d=r(),f=r();k=0;
			mp[d][f].col=a;
			mp[d][f].lv=s;
			dfs(d,f,0,0,0,0);
			memset(b,0,sizeof(b));
			printf("%d\n",k-1);
		}
		memset(mp,0,sizeof(mp));
	}
	return 0;
}
