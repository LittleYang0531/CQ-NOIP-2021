#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005,mod=998244353;
int n,m,Q,val[N],pos[N][N],tg[N][N],vis[N][N],U[N][N],D[N][N],L[N][N],R[N][N],T;
struct Itm{int c,lv,x,y;}a[500005];
struct node{int x,y;}q[N<<4];char str[N];
int In(int x,int y){return (x>=1&&x<=n&&y>=1&&y<=m);}
int Is(int x,int y,int lv,int cl){
	if(!pos[x][y])return 1;
	return (a[pos[x][y]].lv<=lv&&a[pos[x][y]].c!=cl);
}
void BFS(int u,int v,int lv,int cl){
	int l=1,r=0;q[++r]=(node){u,v};int x=u,y=v,i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)vis[i][j]=tg[i][j]=0;
	}vis[u][v]=1;
	x=u,y=v;if(D[x][y]==1&&In(x+1,y)){if(!pos[x+1][y])tg[x+1][y]=1;else if(Is(x+1,y,lv,cl))tg[x+1][y]=1;}
	x=u,y=v;if(U[x][y]==1&&In(x-1,y)){if(!pos[x-1][y])tg[x-1][y]=1;else if(Is(x-1,y,lv,cl))tg[x-1][y]=1;}
	x=u,y=v;if(L[x][y]==1&&In(x,y-1)){if(!pos[x][y-1])tg[x][y-1]=1;else if(Is(x,y-1,lv,cl))tg[x][y-1]=1;}
	x=u,y=v;if(R[x][y]==1&&In(x,y+1)){if(!pos[x][y+1])tg[x][y+1]=1;else if(Is(x,y+1,lv,cl))tg[x][y+1]=1;}
	
	x=u,y=v;while(D[x][y]==2&&In(x+1,y)){
		if(!pos[x+1][y]){x++,tg[x][y]=1;}
		else {if(Is(x+1,y,lv,cl))x++,tg[x][y]=1;break;}
	}
	x=u,y=v;while(U[x][y]==2&&In(x-1,y)){
		if(!pos[x-1][y]){x--,tg[x][y]=1;}
		else {if(Is(x-1,y,lv,cl))x--,tg[x][y]=1;break;}
	}
	x=u,y=v;while(L[x][y]==2&&In(x,y-1)){
		if(!pos[x][y-1]){y--,tg[x][y]=1;}
		else {if(Is(x,y-1,lv,cl))y--,tg[x][y]=1;break;}
	}
	x=u,y=v;while(R[x][y]==2&&In(x,y+1)){
		if(!pos[x][y+1]){y++,tg[x][y]=1;}
		else {if(Is(x,y+1,lv,cl))y++,tg[x][y]=1;break;}
	}
	
	while(l<=r){
		node it=q[l];l++;
		int sx=it.x,sy=it.y;
		if(In(sx-1,sy)&&(U[sx][sy]==3)&&!vis[sx-1][sy]){
			if(!pos[sx-1][sy]){q[++r]=(node){sx-1,sy};vis[sx-1][sy]=1;}
			else if(Is(sx-1,sy,lv,cl))vis[sx-1][sy]=1;
		}
		if(In(sx+1,sy)&&(D[sx][sy]==3)&&!vis[sx+1][sy]){
			if(!pos[sx+1][sy]){q[++r]=(node){sx+1,sy};vis[sx+1][sy]=1;}
			else if(Is(sx+1,sy,lv,cl))vis[sx+1][sy]=1;
		}
		if(In(sx,sy-1)&&(L[sx][sy]==3)&&!vis[sx][sy-1]){
			if(!pos[sx][sy-1]){q[++r]=(node){sx,sy-1};vis[sx][sy-1]=1;}
			else if(Is(sx,sy-1,lv,cl))vis[sx][sy-1]=1;
		}
		if(In(sx,sy+1)&&(R[sx][sy]==3)&&!vis[sx][sy+1]){
			if(!pos[sx][sy+1]){q[++r]=(node){sx,sy+1};vis[sx][sy+1]=1;}
			else if(Is(sx,sy+1,lv,cl))vis[sx][sy+1]=1;
		}
	}
	int res=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(vis[i][j]||tg[i][j]){
				if((i!=u)||(j!=v))res++;
			};
		}
	}
	printf("%d\n",res);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	//printf("%d\n",sizeof(tg)*10+sizeof(a));
	int i,j,cl,lv,x,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&Q);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)pos[i][j]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%s",str+1);
			for(j=1;j<=m-1;j++){
				R[i][j]=str[j]-'0';
				L[i][j+1]=str[j]-'0';
			}
		}
		for(i=1;i<=n-1;i++){
			scanf("%s",str+1);
			for(j=1;j<=m;j++){
				D[i][j]=str[j]-'0';
				U[i+1][j]=str[j]-'0';
			}
		}
		for(i=1;i<=Q;i++){
			scanf("%d%d%d%d",&cl,&lv,&x,&y);
			a[i]=(Itm){cl,lv,x,y};BFS(x,y,lv,cl);pos[x][y]=i;
		}
	}
	
}
