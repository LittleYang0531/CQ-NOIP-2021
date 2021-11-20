#include<bits/stdc++.h>
#define N ((int)1e2+2)
using namespace std;
inline void io(){cin.tie(nullptr),cout.tie(nullptr);}
int T;
int n,m,q,h[N][N],l[N][N];
bool vis[N][N];
inline void pre_vis(){for(int i=0;i<N;++i) for(int j=0;j<N;++j) vis[i][j]=false;}
struct Node{
	int col,lv;
	inline void pre(){col=lv=0;}
}mp[N][N];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int ans=0;
inline void dfs(int x,int y,int lx,int ly,int opt,int col,int lv){
	//cout<<x<<" "<<y<<'\n';
	++ans;
	vis[x][y]=true;
	if(opt==1||(mp[x][y].lv&&lx&&ly)) return;
	if(!lx&&!ly){
		for(int i=0;i<4;++i){
			int tx=x+dx[i],ty=y+dy[i],op;
			if(tx==x&&ty>y) op=h[x][y];
			else if(tx==x&&ty<y) op=h[tx][ty];
			else if(ty==y&&tx<x) op=l[tx][ty];
			else op=l[x][y];
			if(!op||vis[tx][ty]||tx<1||ty<1||tx>n||ty>m||mp[tx][ty].lv>lv||(mp[tx][ty].col==col&&mp[tx][ty].lv)) continue;
			dfs(tx,ty,x,y,op,col,lv);
		}
	}
	else{
		for(int i=0;i<4;++i){
			int tx=x+dx[i],ty=y+dy[i],op;
			if(opt==2) if(tx-x!=x-lx||ty-y!=y-ly) continue;
			if(tx==x&&ty>y) op=h[x][y];
			else if(tx==x&&ty<y) op=h[tx][ty];
			else if(ty==y&&tx<x) op=l[tx][ty];
			else op=l[x][y];
			if(opt!=op||vis[tx][ty]||tx<1||ty<1||tx>n||ty>m||mp[tx][ty].lv>lv||(mp[tx][ty].col==col&&mp[tx][ty].lv)) continue;
			dfs(tx,ty,x,y,op,col,lv);
		}
	}
}
inline void freo(){freopen("chess.in","r",stdin),freopen("chess.out","w",stdout);}
signed main(){
	freo();
	io();
	cin>>T;
	while(T--){
		for(int i=0;i<N;++i) for(int j=0;j<N;++j) mp[i][j].pre();
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i)
			for(int j=1;j<m;++j)
				scanf("%1d",&h[i][j]);
		for(int i=1;i<n;++i)
			for(int j=1;j<=m;++j)
				scanf("%1d",&l[i][j]);
		int col,lv,x,y;
		while(q--){
			cin>>col>>lv>>x>>y;
			mp[x][y]=(Node){col,lv};
			pre_vis(),ans=0;
			dfs(x,y,0,0,-1,col,lv);
			cout<<ans-1<<'\n';
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
/*
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
