#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector <int> G[4][200005];
char S[200005];
int vis[200005];
int col[200005],lv[200005],Ans,n,m;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
inline int ID(int x,int y){return (x-1)*m+y;}
void dfs2(int u,int lst,int Col,int Lv)
{
	if(!vis[u]) Ans++;vis[u]=2;
	if(col[u]!=-1) return;
	for(int i=0;i<G[2][u].size();i++)
	{
		int v=G[2][u][i];
		if(v-u==u-lst&&Col!=col[v]&&Lv>=lv[v]) dfs2(v,u,Col,Lv);
	}
}
void dfs3(int u,int lst,int Col,int Lv)
{
	if(!vis[u]) Ans++; vis[u]=3;
	if(col[u]!=-1&&lst!=0) return;
	for(int i=0;i<G[3][u].size();i++)
	{
		int v=G[3][u][i];
		if(v==lst||vis[v]==3)continue;
		if(Col!=col[v]&&Lv>=lv[v]) dfs3(v,u,Col,Lv);
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T,q,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n*m;i++) G[1][i].clear(),G[2][i].clear(),G[3][i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",S+1);
			for(int j=1;j<m;j++)
			{
				if(S[j]=='1') G[1][ID(i,j)].push_back(ID(i,j+1)),G[1][ID(i,j+1)].push_back(ID(i,j));
				if(S[j]=='2') G[2][ID(i,j)].push_back(ID(i,j+1)),G[2][ID(i,j+1)].push_back(ID(i,j));
				if(S[j]=='3') G[3][ID(i,j)].push_back(ID(i,j+1)),G[3][ID(i,j+1)].push_back(ID(i,j));
			}
		}
		for(int i=1;i<n;i++)
		{
			scanf("%s",S+1);
			for(int j=1;j<=m;j++)
			{
				if(S[j]=='1') G[1][ID(i,j)].push_back(ID(i+1,j)),G[1][ID(i+1,j)].push_back(ID(i,j));
				if(S[j]=='2') G[2][ID(i,j)].push_back(ID(i+1,j)),G[2][ID(i+1,j)].push_back(ID(i,j));
				if(S[j]=='3') G[3][ID(i,j)].push_back(ID(i+1,j)),G[3][ID(i+1,j)].push_back(ID(i,j));
			}
		}
		memset(lv,0,sizeof(lv));
		memset(col,-1,sizeof(col));
		while(q--)
		{
			int Col,Lv;
			scanf("%d %d %d %d",&Col,&Lv,&x,&y);
			col[ID(x,y)]=Col;lv[ID(x,y)]=Lv;
			int u=ID(x,y);Ans=0;
			for(int i=0;i<G[1][u].size();i++)
			{
				int v=G[1][u][i];
				if(col[v]!=col[u]&&lv[u]>=lv[v]) Ans++,vis[v]=true;
			}
			for(int i=0;i<G[2][u].size();i++)
			{
				int v=G[2][u][i];
				if(col[v]!=col[u]&&lv[u]>=lv[v]) dfs2(v,u,col[u],lv[u]);
			}
			dfs3(u,0,col[u],lv[u]);
			printf("%d\n",Ans-1);memset(vis,0,sizeof(vis));	
		}
	}
	return 0;
}
/*
1
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

2
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
*/
