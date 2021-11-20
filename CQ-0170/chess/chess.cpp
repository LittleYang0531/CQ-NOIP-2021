// 归去来兮，田园将芜胡不归！（无端 
// 小舟从此逝，江海寄余生。
// 寒蝉凄切。
// 但去莫复问，白云无尽时。
// 日暮乡关何处是，烟波江上使人愁。
// 烦君最相警，我亦举家清。
// 昨夜西风凋碧树，独上高楼，望尽天涯路。
// 荷尽已无擎雨盖，菊残犹有傲霜枝。 
// 江畔何人初见月，江月何年初照人。 
// 三山半落青天外，二水中分白鹭洲。
// 滟滟随波千万里，何处春江无月明。
// 轮台九月风夜吼，一川碎石大如斗，随风满地石乱走。
// 燕子来时新社，梨花落后清明。
// 锦瑟无端五十弦，一弦一柱思华年。 
// 来如春梦几多时，去似朝云无觅处。
// 出师未捷身先死，长使英雄泪满襟。 
// 晴空一鹤排云上，便引诗情到碧霄。 
// 河流大野犹嫌束，山入潼关不解平。 

#include<cstdio>
#include<cstring>
const int maxn=5005;
const int fangx[]={-1,1,0,0};
const int fangy[]={0,0,-1,1};
int T,n,m,q,c,l,t,x,y,ans,now;
int a[maxn][maxn],b[maxn][maxn];
int vis[maxn][maxn],vis2[maxn][maxn];
struct _{ int c,l; bool f; } p[maxn][maxn];
inline int GetType(int x,int y,int u){
	if(u==1) return b[x-1][y];
	if(u==2) return b[x][y];
	if(u==3) return a[x][y-1];
	return a[x][y];
} 
void Search(int x,int y,int u,int r){
	if(++vis[x][y]>1) return;
	if(vis2[x][y]!=now) vis2[x][y]=now, ++ans;
	if(u==1) return;
//	printf("%d, %d, %d, %d\n",x,y,u,r);
	for(int i=0;i<4;++i){
		int nx=x+fangx[i], ny=y+fangy[i];
		if(nx<1||ny<1||nx>n||ny>m) continue;
		if((t=GetType(x,y,i+1))!=u&&(~u)) continue;
		if(!t) continue;
		if(t==2&&(i<2&&r==2||i>1&&r==1)&&(~r)) continue;
//		printf("(%d, %d) => (%d, %d): %d (I = %d)\n",
//		x,y,nx,ny,t,i+1);
		if(p[nx][ny].f){
			if(p[nx][ny].c!=c&&p[nx][ny].l<=l)
				if(vis2[nx][ny]!=now) vis2[nx][ny]=now, ++ans;
			continue;
		}
		Search(nx,ny,t,t==2?(i<2?1:2):-1); --vis[nx][ny];
	}
	return;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				scanf("%1d",&a[i][j]);
				p[i][j].f=0;
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
				scanf("%1d",&b[i][j]);
				p[i][j].f=0;
			}
		}
		while(q--){
			scanf("%d%d%d%d",&c,&l,&x,&y);
			p[x][y].c=c; p[x][y].l=l;
			p[x][y].f=1; ans=0;
			if(n*m<=5000){
				vis2[x][y]=++now;
				Search(x,y,-1,-1);
				--vis[x][y];
				printf("%d\n",ans);
			} else{
				for(int i=0;i<4;++i){
					int nx=x+fangx[i], ny=y+fangy[i];
					if(nx<1||ny<1||nx>n||ny>n) continue;
					if(GetType(x,y,i+1)==1&&(!p[nx][ny].f||
					p[nx][ny].c!=c&&p[nx][ny].l<=l)) ++ans;
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

// You watch me bleed until I can't breathe shaking
// Falling onto my knees
// And now that I'm without your kisses
// I'll be needing stiches
// Tripping over myself aching
// Begging you to come help
// And now that I'm without your kisses
// I'll be needing stiches

// 小 z 和小 c
// （要素察觉）小小 zc！ 
// 草 活动是不是要关了啊，我好像还没碰 
