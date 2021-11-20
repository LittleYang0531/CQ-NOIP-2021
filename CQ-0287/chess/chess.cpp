#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,q,ans;
struct node
{
	int l,r,u,d,lv,col=-1;
}Map[2005][2005];
bool mark[2005][2005];
int dfs2(int x,int y,int des,int C,int L)
{
	if(des==1)
	{
		if(x>1&&Map[x-1][y].d==2&&(Map[x-1][y].col=-1||(Map[x-1][y].col!=C&&L>Map[x-1][y].lv)))
			ans++,dfs2(x-1,y,des,C,L);
		else return ans;
	}
	if(des==2)
	{
		if(x<n&&Map[x+1][y].u==2&&(Map[x+1][y].col=-1||(Map[x+1][y].col!=C&&L>Map[x+1][y].lv)))
			ans++,dfs2(x+1,y,des,C,L);
		else return ans;
	}
	if(des==3)
	{
		if(y>1&&Map[x][y-1].r==2&&(Map[x][y-1].col=-1||(Map[x][y-1].col!=C&&L>Map[x][y-1].lv)))
			ans++,dfs2(x,y-1,des,C,L);
		else return ans;
	}
	if(des==4)
	{
		if(x<m&&Map[x][y+1].l==2&&(Map[x][y+1].col=-1||(Map[x][y+1].col!=C&&L>Map[x][y+1].lv)))
			ans++,dfs2(x,y+1,des,C,L);
		else return ans;
	}
}
struct p
{
	int x,y;
};
queue<p>Q;
int dfs3(int x,int y,int C,int L)
{
	if(mark[x+1][y]==0&&x<n&&Map[x+1][y].u==3&&(Map[x+1][y].col=-1||(Map[x+1][y].col!=C&&L>Map[x+1][y].lv)))
	{
		ans++,mark[x+1][y]=1;
		Q.push({x+1,y});
		dfs3(x+1,y,C,L);
	}
	if(mark[x-1][y]==0&&x>1&&Map[x-1][y].d==3&&(Map[x-1][y].col=-1||(Map[x-1][y].col!=C&&L>Map[x-1][y].lv)))
	{
		ans++,mark[x-1][y]=1;
		Q.push({x-1,y});
		dfs3(x-1,y,C,L);
	}
	if(mark[x][y+1]==0&&y<m&&Map[x][y+1].l==3&&(Map[x][y+1].col=-1||(Map[x][y+1].col!=C&&L>Map[x][y+1].lv)))
	{
		ans++,mark[x][y+1]=1;
		Q.push({x,y+1});
		dfs3(x,y+1,C,L);
	}
	if(mark[x][y-1]==0&&y>1&&Map[x][y-1].l==3&&(Map[x][y-1].col=-1||(Map[x][y-1].col!=C&&L>Map[x][y+1].lv)))
	{
		ans++,mark[x][y+1]=1;
		Q.push({x,y-1});
		dfs3(x,y-1,C,L);
	}
	while(!Q.empty())
	{
		int X=Q.front().x,Y=Q.front().y;
		Q.pop();
		mark[X][Y]=0;
	}
	return ans;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			int len=s.length();
			for(int j=0;j<len;j++)
			{
				Map[i][j+1].r=s[j]-'0';
				Map[i][j+2].l=s[j]-'0';
			}
		}
		for(int i=1;i<n;i++)
		{
			string s;
			cin>>s;
			int len=s.length();
			for(int j=0;j<len;j++)
			{
				Map[i][j+1].d=s[j]-'0';
				Map[i+1][j+1].u=s[j]-'0';
			}
		}
		for(int i=1;i<=q;i++)
		{
			int c,lV,x,y;
			scanf("%d%d%d%d",&c,&lV,&x,&y);
			Map[x][y].col=c,Map[x][y].lv=lV;
			int Ans=0;
			Ans+=dfs2(x,y,1,c,lV),ans=0;
			Ans+=dfs2(x,y,2,c,lV),ans=0;
			Ans+=dfs2(x,y,3,c,lV),ans=0;
			Ans+=dfs2(x,y,4,c,lV),ans=0;
			mark[x][y]=1;
			Ans+=dfs3(x,y,c,lV);
			mark[x][y]=0;
			printf("%d\n",Ans);
		}
	}
	return 0;
}
