#include<bits/stdc++.h>
#define maxn 500
#define maxm 500
#define maxq 500
using namespace std;
int t,n,m,q,opt[maxn+5][maxm+5][3],stay[maxn+5][maxm+5];
bool vis[maxn+5][maxm+5];
struct star{
	int col,lv,x,y,nor,dir,l;
}chess[maxq+5];
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){
		if(ch=='-')w=-1;ch=getchar();
	}
	while(isdigit(ch)&&ch!=EOF){
		n=(n<<1)+(n<<3)+(ch&15);ch=getchar();
	}
	n*=w;
}
inline int bfs(int id){
	int cnt=0;
	queue<star>q;q.push(chess[id]);memset(vis,0,sizeof(vis));vis[chess[id].x][chess[id].y]=1;
	while(!q.empty()){
		int sx=q.front().x,sy=q.front().y,tx,ty,ts;star h=q.front();q.pop();
		if(sx>1){
			tx=sx-1,ty=sy;ts=opt[tx][ty][2];if(vis[tx][ty]||!ts||(ts!=h.l&&h.l!=0))goto nxt1;
			if(h.nor&&ts==1)goto nxt1;if(chess[stay[tx][ty]].lv>chess[id].lv||chess[stay[tx][ty]].col==chess[id].col)goto nxt1;
			if(ts==2&&h.dir==1)goto nxt1;cnt++,vis[tx][ty]=1,q.push((star){0,0,sx,sy,(ts==1),2,ts});
		}
		nxt1:if(sx<n){
			tx=sx+1,ty=sy;ts=opt[tx][ty][2];if(vis[tx][ty]||!ts||(ts!=h.l&&h.l!=0))goto nxt2;
			if(h.nor&&ts==1)goto nxt2;if(chess[stay[tx][ty]].lv>chess[id].lv||chess[stay[tx][ty]].col==chess[id].col)goto nxt2;
			if(ts==2&&h.dir==1)goto nxt2;cnt++,vis[tx][ty]=1,q.push((star){0,0,sx,sy,(ts==1),2,ts});
		}
		nxt2:if(sy>1){
			tx=sx,ty=sy-1;ts=opt[tx][ty][1];if(vis[tx][ty]||!ts||(ts!=h.l&&h.l!=0))goto nxt3;
			if(h.nor&&ts==1)goto nxt3;if(chess[stay[tx][ty]].lv>chess[id].lv||chess[stay[tx][ty]].col==chess[id].col)goto nxt3;
			if(ts==2&&h.dir==2)goto nxt3;cnt++,vis[tx][ty]=1,q.push((star){0,0,sx,sy,(ts==1),1,ts});
		}
		nxt3:if(sy<m){
			tx=sx,ty=sy+1;ts=opt[tx][ty][1];if(vis[tx][ty]||!ts||(ts!=h.l&&h.l!=0))goto nxt4;
			if(h.nor&&ts==1)goto nxt4;if(chess[stay[tx][ty]].lv>chess[id].lv||chess[stay[tx][ty]].col==chess[id].col)goto nxt4;
			if(ts==2&&h.dir==2)goto nxt4;cnt++,vis[tx][ty]=1,q.push((star){0,0,sx,sy,(ts==1),1,ts});
		}
		nxt4:;
	}
	return cnt;
}
int main(){
	freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
	read(t);
	while(t--){
		read(n);read(m);read(q);char tmp[max(maxn,maxm)+5];
		for(int i=1;i<=n;i++){
			scanf("%s",tmp+1);for(int j=1;j<=m;j++)opt[i][j][1]=tmp[j-1]-'0';
		}
		for(int i=1;i<n;i++){
			scanf("%s",tmp+1);for(int j=1;j<=n;j++)opt[i][j][2]=tmp[j-1]-'0';
		}
		for(int i=1;i<=q;i++){
			read(chess[i].col);chess[i].col++;read(chess[i].lv);read(chess[i].x);read(chess[i].y);
			stay[chess[i].x][chess[i].y]=i;printf("%d\n",bfs(i));
		}
	}
	return 0;
}
