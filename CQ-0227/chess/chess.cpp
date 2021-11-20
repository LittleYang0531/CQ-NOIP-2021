#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=1e2;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
string a[Maxn+5],b[Maxn+5];
int s[Maxn+5][Maxn+5][4];
int vis[Maxn+5][Maxn+5],mark[Maxn+5][Maxn+5],c[Maxn+5][Maxn+5],l[Maxn+5][Maxn+5];
int T,n,m,q,ans,vt;
void dfs(int x,int y,int sta,int col,int lv,int d) {
	//printf("%d %d %d %d\n",x,y,sta,d);
	if(vis[x][y]==vt)return ;
	if(c[x][y]) {
		if(c[x][y]!=col&&l[x][y]<=lv) {
			if(!mark[x][y])++ans;
			mark[x][y]=1;vis[x][y]=vt;
		}
		return ;
	}
	if(!mark[x][y])++ans;
	vis[x][y]=vt;mark[x][y]=1;
	if(sta==1)return ;
	if(sta==2) {
		if(s[x][y][d]==sta)dfs(x+dx[d],y+dy[d],sta,col,lv,d);
		return ;
	}
	for(ri d=0;d<4;d++) {
		int xx=x+dx[d],yy=y+dy[d];
		//printf("Ex: %d %d %d %d\n",xx,yy,d,s[x][y][d]);
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[x][y][d]==sta) {
			dfs(xx,yy,sta,col,lv,d);
		}
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&q);
		for(ri i=1;i<=n;i++)cin>>a[i];
		for(ri i=1;i<n;i++)cin>>b[i];
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++) {
				for(ri d=0;d<4;d++)s[i][j][d]=-1;
				if(i>1)s[i][j][0]=b[i-1][j-1]-48;
				if(i<n)s[i][j][2]=b[i][j-1]-48;
				if(j>1)s[i][j][3]=a[i][j-2]-48;
				if(j<m)s[i][j][1]=a[i][j-1]-48;
				c[i][j]=l[i][j]=0;
			}
		for(ri i=1;i<=q;i++) {
			for(ri j=1;j<=n;j++)
				for(ri k=1;k<=m;k++)vis[j][k]=mark[j][k]=0;
			ans=0;
			int col,lv,x,y;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			++col;
			c[x][y]=col,l[x][y]=lv;mark[x][y]=1;
			for(ri d=0;d<4;d++) {
				int xx=x+dx[d],yy=y+dy[d];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&s[x][y][d]) {
					++vt;vis[x][y]=vt;
					dfs(xx,yy,s[x][y][d],col,lv,d);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

