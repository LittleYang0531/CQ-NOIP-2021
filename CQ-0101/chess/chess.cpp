#include<bits/stdc++.h>
using namespace std;
const int M=5002;
int v[M][M],vis[M][M],co[M][M],d[M][M],r[M][M];
inline int che(int x,int y,int lv,int col){
	if(co[x][y]==col||lv<v[x][y]||vis[x][y])return 0;
	vis[x][y]=1;return 1;
}
int bfs1(int x,int y,int lv,int col){
	int ans=0;
	if(d[x-1][y]==1&&che(x-1,y,lv,col))ans++;
	if(r[x][y-1]==1&&che(x,y-1,lv,col))ans++;
	if(d[x][y]==1&&che(x+1,y,lv,col))ans++;
	if(r[x][y]==1&&che(x,y+1,lv,col))ans++;
	return ans;
}
int bfs2(int x,int y,int lv,int col){
	int ans=0;
	int x1=x,x2=x,y1=y,y2=y;
	while(d[x1-1][y]==2&&che(x1-1,y,lv,col)){ans++,x1--;if(co[x1][y])break;
	}
	while(r[x][y1-1]==2&&che(x,y1-1,lv,col)){ans++,y1--;if(co[x][y1])break;
	}
	while(d[x2][y]==2&&che(x2+1,y,lv,col)){
		ans++,x2++;if(co[x2][y])break;
	}
	while(r[x][y2]==2&&che(x,y2+1,lv,col)){
	ans++,y2++;if(co[x][y2])break;	
	}
	return ans;
}
struct o{
	int x,y;
};
queue<o> q;
int bfs3(int x,int y,int lv,int col){
	int ans=0;
	q.push({x,y});
	while(!q.empty()){
		int s=q.front().x,t=q.front().y;q.pop();
		if(d[s-1][t]==3&&che(s-1,t,lv,col)){
		ans++;if(!co[s-1][t])q.push({s-1,t});	
		}
	    if(r[s][t-1]==3&&che(s,t-1,lv,col)){
	    	ans++;if(!co[s][t-1])q.push({s,t-1});
		}
	    if(d[s][t]==3&&che(s+1,t,lv,col)){
	    	ans++;if(!co[s+1][t])q.push({s+1,t});
		}
	    if(r[s][t]==3&&che(s,t+1,lv,col)){
	    ans++;if(!co[s][t+1])q.push({s,t+1});	
		}
	}
	return ans;
}
int suan(int x,int y,int lv,int col){
	int ans=0;vis[x][y]=1;
	ans+=bfs1(x,y,lv,col);
	ans+=bfs2(x,y,lv,col);
	ans+=bfs3(x,y,lv,col);
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,q,t,col,lv,x,y;
	char c;
	cin>>t;
	while(t--){
	memset(d,0,sizeof d);
	memset(r,0,sizeof r);	
	memset(co,0,sizeof co);
	memset(v,0,sizeof v);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)
		cin>>c,r[i][j+1]=c-'0';
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++)
		cin>>c,d[i][j]=c-'0';
	}
	for(int i=1;i<=q;i++){
	    memset(vis,0,sizeof vis);
		cin>>col>>lv>>x>>y;
		cout<<suan(x,y,lv,col+1)<<endl;
		co[x][y]=col+1,v[x][y]=lv;
	   }
	}
	return 0;
}
