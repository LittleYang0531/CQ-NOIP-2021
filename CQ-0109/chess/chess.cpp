#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int ans;
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
int Map[4000][4000][5],vis[4000][4000],vis3[4000][4000];//1:-->,2:<--,3:下,4:上 
struct NODE{
	int col,lv,pd;
}che[4000][4000];

inline int read(){
	char c=getchar();int kkk=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9'){kkk=kkk*10+c-'0';c=getchar();}
	return kkk;
}

void START(){
	n=read(),m=read(),q=read();
	memset(vis,0,sizeof(vis));
	memset(Map,0,sizeof(Map));
	memset(che,0,sizeof(che));
	char a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			a=getchar();
			while(a>'9'||a<'0') a=getchar();
			Map[i][j][1]=a-'0';
			Map[i][j+1][2]=a-'0';
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			a=getchar();
			while(a>'9'||a<'0') a=getchar();
			Map[i][j][3]=a-'0';
			Map[i+1][j][4]=a-'0';
		}
	}
}

void search2(int x,int y,int i,int col,int lv){
	if(Map[x][y][i]==2){
		if(!che[x+xx[i]][y+yy[i]].pd||(che[x+xx[i]][y+yy[i]].pd&&col!=che[x+xx[i]][y+yy[i]].col&&lv>=che[x+xx[i]][y+yy[i]].lv)){
			if(!vis[x+xx[i]][y+yy[i]]) vis[x+xx[i]][y+yy[i]]=1,ans++;
			if(che[x+xx[i]][y+yy[i]].pd) return ;
			search2(x+xx[i],y+yy[i],i,col,lv);
		}
	}
}

void search3(int x,int y,int col,int lv){
	for(int i=1;i<=4;i++){
		if(Map[x][y][i]==3&&!vis3[x+xx[i]][y+yy[i]]){
			if(!che[x+xx[i]][y+yy[i]].pd||(che[x+xx[i]][y+yy[i]].pd&&col!=che[x+xx[i]][y+yy[i]].col&&lv>=che[x+xx[i]][y+yy[i]].lv)){
				if(!vis[x+xx[i]][y+yy[i]]) vis[x+xx[i]][y+yy[i]]=1,ans++;
				if(che[x+xx[i]][y+yy[i]].pd) return ;
				vis3[x+xx[i]][y+yy[i]]=1;
				search3(x+xx[i],y+yy[i],col,lv);
				vis3[x+xx[i]][y+yy[i]]=0;
			}
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		START();
		for(int t=1;t<=q;t++){
			int c,l,x,y;
			c=read(),l=read(),x=read(),y=read();
			che[x][y].col=c,che[x][y].lv=l,che[x][y].pd=1;
			vis[x][y]=1;
			ans=0;
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=4;i++){
			memset(vis3,0,sizeof(vis3));
				if(Map[x][y][i]==1){
					if(vis[x+xx[i]][y+yy[i]]) continue;
					if(che[x+xx[i]][y+yy[i]].pd){
						if(che[x][y].col!=che[x+xx[i]][y+yy[i]].col&&che[x][y].lv>=che[x+xx[i]][y+yy[i]].lv)
							ans++,vis[x+xx[i]][y+yy[i]]=1;
					}
					else ans++;
				}
				if(Map[x][y][i]==2){
					if(!che[x+xx[i]][y+yy[i]].pd||(che[x+xx[i]][y+yy[i]].pd&&che[x][y].col!=che[x+xx[i]][y+yy[i]].col&&che[x][y].lv>=che[x+xx[i]][y+yy[i]].lv)){
						//要么没有棋子，要么符合条件 
						if(!vis[x+xx[i]][y+yy[i]]) vis[x+xx[i]][y+yy[i]]=1,ans++;
						if(che[x+xx[i]][y+yy[i]].pd) continue;
						search2(x+xx[i],y+yy[i],i,che[x][y].col,che[x][y].lv);
					}
				}
				if(Map[x][y][i]==3){
					if(!che[x+xx[i]][y+yy[i]].pd||(che[x+xx[i]][y+yy[i]].pd&&che[x][y].col!=che[x+xx[i]][y+yy[i]].col&&che[x][y].lv>=che[x+xx[i]][y+yy[i]].lv)){
						if(!vis[x+xx[i]][y+yy[i]]) vis[x+xx[i]][y+yy[i]]=1,ans++;
						vis3[x][y]=vis3[x+xx[i]][y+yy[i]]=1;
						if(che[x+xx[i]][y+yy[i]].pd) continue;
						search3(x+xx[i],y+yy[i],che[x][y].col,che[x][y].lv);
					}
				}
			}
			printf("%d\n",ans);
		}
	}
}
