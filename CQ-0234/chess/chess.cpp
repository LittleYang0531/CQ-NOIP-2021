#include<bits/stdc++.h>
using namespace std;
int T;
char u[105][105],r[105][105];
int n,m,q;
int cl[105][105],l[105][105];
bool vis[105][105];
void dfs(int x,int y,char S,int C,int lv,int lst){
	if(S=='0')return ;
	if(vis[x][y])return ; 
	if(x<=0||x>n||y<=0||y>m){
		return ;
	}
	if(cl[x][y]!=C&&cl[x][y]){
		if(l[x][y]<=lv)vis[x][y]=1;
		return ;
	}
	if(cl[x][y]==C)return ;  
	vis[x][y]=1;
	if(S=='1')return ;
	if(u[x-1][y]==S&&(lst==1||S!='2'))dfs(x+1,y,u[x-1][y],C,lv,lst);
	if(u[x][y]==S&&(lst==2||S!='2'))dfs(x-1,y,u[x][y],C,lv,lst);
	if(r[x][y-1]==S&&(lst==3||S!='2'))dfs(x,y-1,r[x][y-1],C,lv,lst);
	if(r[x][y]==S&&(lst==4||S!='2'))dfs(x,y+1,r[x][y],C,lv,lst);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		memset(cl,0,sizeof(cl));
		memset(l,0,sizeof(l));
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				cin>>r[i][j];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				cin>>u[i][j];
			}
		}
//		cout<<"dsadas"<<endl;
		while(q--){
			memset(vis,0,sizeof(vis));
			int col,lv,x,y;
			cin>>col>>lv>>x>>y;
			col++;
			dfs(x+1,y,u[x-1][y],col,lv,1);
			dfs(x-1,y,u[x][y],col,lv,2);
			dfs(x,y-1,r[x][y-1],col,lv,3);
			dfs(x,y+1,r[x][y],col,lv,4);
			cl[x][y]=col;
			l[x][y]=lv;
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(vis[i][j])cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
