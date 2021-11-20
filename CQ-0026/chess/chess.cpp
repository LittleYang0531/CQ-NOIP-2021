#include <bits/stdc++.h>
using namespace std;
const int N=5005;
char a[N][N],b[N][N];
int d[4][2]={0,1,1,0,0,-1,-1,0};
bool vis[N][N],tag[N][N];
bool col[N][N];int lvl[N][N];
int n,m;
void dfs(int x,int y,int p,int q){
	vis[x][y]=1;
	if(lvl[x][y])	return ;
	for(int i=0;i<4;++i){
		int xn=x+d[i][0],yn=y+d[i][1];
		if(xn<1||xn>n||yn<1||yn>m)	continue;
		if(vis[xn][yn])	continue;
		if(lvl[xn][yn]&&(col[xn][yn]==p||lvl[xn][yn]>q))
			continue;
		if(i==0&&a[x][y]!='3')	continue;
		if(i==1&&b[x][y]!='3')	continue;
		if(i==2&&a[x][y-1]!='3')	continue;
		if(i==3&&b[x-1][y]!='3')	continue;
		dfs(xn,yn,p,q);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int Q;
		scanf("%d %d %d",&n,&m,&Q);
		for(int i=1;i<=n;++i)
			scanf("%s",a[i]+1);
		for(int i=1;i<n;++i)
			scanf("%s",b[i]+1);
		while(Q--){
			int p,q,x,y;
			scanf("%d %d %d %d",&p,&q,&x,&y);
			for(int i=0;i<4;++i){
				int xn=x+d[i][0],yn=y+d[i][1],knd=0;
				if(xn<1||xn>n||yn<1||yn>m)	continue;
				if(i==0)	knd=a[x][y];
				if(i==1)	knd=b[x][y];
				if(i==2)	knd=a[x][y-1];
				if(i==3)	knd=b[x-1][y];
				knd-='0';
				if(knd==0)	continue;
				if(knd==1){
					if(lvl[xn][yn]&&(col[xn][yn]==p||lvl[xn][yn]>q))
						continue;
					tag[xn][yn]=1;
				}
				if(knd==2){
					int X=xn,Y=yn;
					while(1){
						if(X<1||X>n||Y<1||Y>m)	break;
						if(lvl[X][Y]){
							if(col[X][Y]!=p&&lvl[X][Y]<=q)
								tag[X][Y]=1;
							break;
						}
						tag[X][Y]=1;
						if(i==0)	knd=a[X][Y];
						if(i==1)	knd=b[X][Y];
						if(i==2)	knd=a[X][Y-1];
						if(i==3)	knd=b[X-1][Y];
						if(knd!='2')	break;
						X+=d[i][0],Y+=d[i][1];
					}
				}
				if(knd==3){
					if(lvl[xn][yn]&&(col[xn][yn]==p||lvl[xn][yn]>q))	continue;
					vis[x][y]=1,dfs(xn,yn,p,q);
					for(int i=1;i<=n;++i)
						for(int j=1;j<=m;++j)
							if(vis[i][j])
								tag[i][j]=1,vis[i][j]=0;
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if((i!=x||j!=y)&&tag[i][j])
						++ans;
			printf("%d\n",ans);
			col[x][y]=p,lvl[x][y]=q;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					tag[i][j]=0;
		}
		memset(col,0,sizeof(col)),memset(lvl,0,sizeof(lvl));
		memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	}
	return 0;
}
