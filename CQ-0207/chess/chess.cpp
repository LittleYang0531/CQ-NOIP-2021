#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define db double
using namespace std;
const int N=2e5+5;
int n,m,q,a[N][4],lv[N],ans,col[N],vis[N][4],pass[N],tot;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char s[N];
int has(int i,int j) {
	return (i-1)*m+j;
}
bool outside(int x,int y) {
	if(x<1||x>n||y<1||y>m) return 1;
	return 0;
}
bool chk(int x,int y,int tx,int ty) {
	int u=has(x,y),v=has(tx,ty);
	if(col[u]!=col[v]&&lv[u]>=lv[v]) {
		return 1;
	}
	return 0;
}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar(); 
	}
	return x*f;
}
void dfs(int X,int Y,int x,int y,int dir1,int dir2,int step) {
	//dir1 : 当前经过的路线类型
	//dir2 : 当前的方向
//	printf("%d %d %d %d\n",x,y,dir1,dir2);
	int now=has(x,y); 
	for(int k=0;k<4;k++) {
		int tx=x+dx[k],ty=y+dy[k];
		int nxt=has(tx,ty);
		//如果出界或者不匹配 
		if(outside(tx,ty)||a[now][k]==0||(dir1!=-1&&a[now][k]!=dir1)||vis[nxt][a[now][k]]==tot||(dir1==2&&dir2!=k)||(dir1==1&&step==1)) continue;
		if(~col[nxt]) {
			if(pass[nxt]==tot) {
				continue;
			} 
			if(chk(X,Y,tx,ty)) {
				pass[nxt]=tot;
				ans++;
			}
			continue;
		}
		vis[nxt][a[now][k]]=tot; 
		if(pass[nxt]!=tot) {
			pass[nxt]=tot;
			ans++;
		}
		dfs(X,Y,tx,ty,a[now][k],k,step+1);
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	T=read();
	while(T--) {
		n=read(),m=read(),q=read();
		memset(col,-1,sizeof col);
		memset(lv,0,sizeof lv);
		int flg=1;
		for(int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for(int j=1;j<m;j++) {
				int x=has(i,j),y=has(i,j+1);
				a[x][1]=a[y][3]=s[j]-'0';
				if(a[x][1]!=1) {
					flg=0;
				}
			}
		}
		for(int i=1;i<n;i++) {
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) {
				int x=has(i,j),y=has(i+1,j);
				a[x][2]=a[y][0]=s[j]-'0';
				if(a[x][2]!=1) {
					flg=0;
				}
			}
		}
		while(q--) {
			int c=read(),le=read(),x=read(),y=read();
			int now=has(x,y);
			lv[now]=le;
			col[now]=c;
			ans=0;
			tot++; //询问编号 
			pass[now]=tot; //不能吃自己 
			for(int i=0;i<4;i++) vis[now][i]=tot;
			dfs(x,y,x,y,-1,-1,0); //搜索 找到所有可以到达的点 
			printf("%d\n",ans);
		}
	}
}
