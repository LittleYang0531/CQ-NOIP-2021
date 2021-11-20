#include<bits/stdc++.h>
using namespace std;
const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k,cntid,cnt,typ[200020][4],col[200020],lev[200020];
char s[200020];
vector<int>id[200020];
bool mark[5050],vis[5050];
void dfs(int x,int y,int c,int l)
{
	int u=id[x][y];
	if(vis[u]) return;
	vis[u]=1;
	if(col[u]!=-1)
	{
		if(!mark[u]&&col[u]!=c&&lev[u]<=l) ++cnt,mark[u]=1;
		return;
	}
	if(!mark[u]) ++cnt,mark[u]=1;
	for(int t=0;t<4;t++)
		if(typ[u][t]==3) dfs(x+d[t][0],y+d[t][1],c,l);
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
int T;
scanf("%d",&T);
while(T--)
{
	memset(col,-1,sizeof(col));
	memset(lev,0,sizeof(lev));
	memset(typ,0,sizeof(typ));
	cntid=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) id[i].resize(m+5);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			id[i][j]=++cntid;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<m;j++)
			typ[id[i][j]][3]=typ[id[i][j+1]][2]=s[j]-'0';
	}
	for(int i=1;i<n;i++)
	{
		scanf("%s",s+1);
		for(int j=1,x;j<=m;j++)
		{
			x=s[j]-'0';
			if(x) typ[id[i][j]][1]=typ[id[i+1][j]][0]=x;
		}
	}
	for(int i=1,c,l,x,y;i<=k;i++)
	{
		scanf("%d%d%d%d",&c,&l,&x,&y);
		cnt=0;
		if(cntid<=5000)
		{
			memset(mark,0,sizeof(mark));
			memset(vis,0,sizeof(vis));
		}
		int u=id[x][y];
		mark[u]=1;
		for(int t=0;t<4;t++)
		{
			int tx=x+d[t][0],ty=y+d[t][1];
			if(typ[u][t]==1)
			{
				int tt=id[tx][ty];
				if(col[tt]!=c&&lev[tt]<=l)
				{
					if(cntid<=5000)
					{
						if(!mark[tt]) mark[tt]=1,++cnt;
					}
					else ++cnt;
				}
			}
			else if(typ[u][t]==2)
			{
				int tt=id[tx][ty];
				while(col[tt]==-1)
				{
					if(cntid<=5000)
					{
						if(!mark[tt]) ++cnt,mark[tt]=1;
					}
					else ++cnt;
					if(typ[tt][t]!=2) break;
					tx+=d[t][0];ty+=d[t][1];
					tt=id[tx][ty];
				}
				if(col[tt]!=-1)
				{
					if(!mark[tt]&&col[tt]!=c&&lev[tt]<=l) ++cnt,mark[tt]=1;
				}
			}
			else if(typ[u][t]==3)
				dfs(x,y,c,l);
		}
		col[u]=c;
		lev[u]=l;
		printf("%d\n",cnt);
	}
}
	return 0;
}
/*
3
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
