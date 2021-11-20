#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int>::iterator iter;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int r1d() {
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	return c-'0';
}
const int maxn=2e5+5;
struct node {
	int v,col,x,y;
} p[maxn];
int tmp[maxn*20],*a[maxn],*b[maxn],*c[maxn],*book[maxn],*id,n,m,Q,T,ans,now;
pi zc[maxn];
queue<pi> q;
void clr() {
	memset(tmp,0,sizeof(tmp)),memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(c,0,sizeof(c)),memset(book,0,sizeof(book)),id=tmp;
}
bool pd(int x,int y,int col,int v,bool pd) {
	if(pd&&book[x][y])return 0;
	if(!c[x][y])return 1;
	int u=c[x][y];
	return p[u].col!=col&&p[u].v<=v;
}
void print(int x,int y,int c) {
	if(now!=11)return;
	cout<<x<<' '<<y<<' '<<c<<"*\n";
}
void bfs(int sx,int sy,int col,int v) {
	q.push(pi(sx,sy));
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(c[x][y]&&((x!=sx)||(y!=sy)))continue;
		if(x>1&&b[x-1][y]==3&&pd(x-1,y,col,v,1))q.push(pi(x-1,y)),zc[++ans]=pi(x-1,y),book[x-1][y]=1;
		if(x<n&&b[x][y]==3&&pd(x+1,y,col,v,1))q.push(pi(x+1,y)),zc[++ans]=pi(x+1,y),book[x+1][y]=1;
		if(y>1&&a[x][y-1]==3&&pd(x,y-1,col,v,1))q.push(pi(x,y-1)),zc[++ans]=pi(x,y-1),book[x][y-1]=1;
		if(y<m&&a[x][y]==3&&pd(x,y+1,col,v,1))q.push(pi(x,y+1)),zc[++ans]=pi(x,y+1),book[x][y+1]=1;
	}
}
int main() {
	int col,v,x,y;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--) {
		n=read(),m=read(),Q=read();
		clr();
		for(int i=1; i<=n; i++) {
			a[i]=id,id+=m;
			for(int j=1; j<m; j++)a[i][j]=r1d();
		}
//		puts("*");
		for(int i=1; i<n; i++) {
			b[i]=id,id+=m+1;
			for(int j=1; j<=m; j++)b[i][j]=r1d();
		}
		for(int i=1; i<=n; i++)c[i]=id,id+=m+1,book[i]=id,id+=m+1;
		for(int i=1; i<=Q; i++) {
			p[i].col=col=read(),p[i].v=v=read(),p[i].x=x=read(),p[i].y=y=read(),c[x][y]=i;
			bfs(x,y,col,v);
			if(x>1&&b[x-1][y]==1&&pd(x-1,y,col,v,1))zc[++ans]=pi(x-1,y),book[x-1][y]=1;
			else {
				int nx=x;
				while(nx>1&&b[nx-1][y]==2&&pd(nx-1,y,col,v,0)) {
					if(!book[nx-1][y])zc[++ans]=pi(nx-1,y),book[nx-1][y]=1;
					if(c[nx-1][y])break;
					nx--;
				}
			}
			if(x<n&&b[x][y]==1&&pd(x+1,y,col,v,1))zc[++ans]=pi(x+1,y),book[x+1][y]=1;
			else {
				int nx=x;
				while(nx<n&&b[nx][y]==2&&pd(nx+1,y,col,v,0)) {
					if(!book[nx+1][y])zc[++ans]=pi(nx+1,y),book[nx+1][y]=1;
					if(c[nx+1][y])break;
					nx++;
				}
			}
			if(y>1&&a[x][y-1]==1&&pd(x,y-1,col,v,1))zc[++ans]=pi(x,y-1),book[x][y-1]=1;
			else {
				int ny=y;
				while(ny>1&&a[x][ny-1]==2&&pd(x,ny-1,col,v,0)) {
					if(!book[x][ny-1])zc[++ans]=pi(x,ny-1),book[x][ny-1]=1;
					if(c[x][ny-1])break;
					ny--;
				}
			}
			if(y<m&&a[x][y]==1&&pd(x,y+1,col,v,1))zc[++ans]=pi(x,y+1),book[x][y+1]=1;
			else {
				int ny=y;
				while(ny<m&&a[x][ny]==2&&pd(x,ny+1,col,v,0)) {
					if(!book[x][ny+1])zc[++ans]=pi(x,ny+1),book[x][ny+1]=1;
					if(c[x][ny+1])break;
					ny++;
				}
			}
			printf("%d\n",ans);
			while(ans)book[zc[ans].first][zc[ans].second]=0,ans--;
		}
	}
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊！1145141919810

