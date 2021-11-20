#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 2e5+5;

void file(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int read(){
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

struct Edge{int op;pii to;};
vector<Edge>edge[505*505];
struct Node{int col,lv;}mp[505][505];
int T,n,m,q,cnt,ans;
bool vis[505][505][4];

void addedge(int x,int y,int xx,int yy,int op){
	if(!op)return ;
	edge[x*m+y].push_back((Edge){op,pii(xx,yy)});
	edge[xx*m+yy].push_back((Edge){op,pii(x,y)});
}
void dfs(int x,int y,int lv,int col,int op){
	if(vis[x][y][op])return ; 
	vis[x][y][op]=1,ans++;
	for(int i=0;i<(int)edge[x*m+y].size();++i){
		Edge v=edge[x*m+y][i];
		int xx=v.to.fi,yy=v.to.se;
		if(!op||v.op==op){
			if(mp[xx][yy].col==col)continue;
			if(mp[xx][yy].col&&mp[xx][yy].lv<=lv)
				ans+=!vis[xx][yy][v.op];
			else if(!mp[xx][yy].col)dfs(xx,yy,lv,col,v.op);
		}
	}
}

signed main(){
	file(),T=read();
	while(T--){
		for(int i=0;i<=500*500;++i)edge[i].clear();
		for(int i=0;i<=500;++i)
			for(int j=0;j<=500;++j)
				mp[i][j]=(Node){0,0};
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i)
			for(int j=1,x;j<m;++j)
				scanf("%1lld",&x),addedge(i,j,i,j+1,x);
		for(int i=1;i<n;++i)
			for(int j=1,x;j<=m;++j)
				scanf("%1lld",&x),addedge(i,j,i+1,j,x);
		while(q--){
			int col,lv,x,y;
			col=read(),lv=read(),x=read(),y=read(),col++;
			mp[x][y].col=col,mp[x][y].lv=lv,ans=0;
			memset(vis,0,sizeof(vis));
			dfs(x,y,lv,col,0);
			printf("%lld\n",ans);
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
*/
