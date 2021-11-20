#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int T,n,m,q,C[N][N],C_[400005],L_[400005],L[N][N],col,lv;
int opt1[N][N],opt2[N][N];
bool vis[N][N][3];
vector<bool>v1[N],v2[N];
struct P{
	int x,y;
}t1,t2;
inline bool beat(int i,int j) {
	if (!C[i][j]) return true;
	if (C[i][j]==col) return false;
	if (lv>=L[i][j]) return true;
	return false;
}
inline void bfs(int x,int y) {
	vis[x][y][2]=1;
	queue<P>q;
	t1.x=x,t1.y=y;
	q.push(t1);
	while (!q.empty()) {
		t1=q.front();
		q.pop();
		if (t1.y>1&&beat(t1.x,t1.y-1)&&opt1[t1.x][t1.y-1]=='3'&&!vis[t1.x][t1.y-1][2]) {
			vis[t1.x][t1.y-1][2]=1;
			if (!C[t1.x][t1.y-1]) {
				t2.x=t1.x,t2.y=t1.y-1;
				q.push(t2);	
			}
		}
		if (t1.y<m&&beat(t1.x,t1.y+1)&&opt1[t1.x][t1.y]=='3'&&!vis[t1.x][t1.y+1][2]) {
			vis[t1.x][t1.y+1][2]=1;
			if (!C[t1.x][t1.y+1]) {
				t2.x=t1.x,t2.y=t1.y+1;
				q.push(t2);	
			}
		}
		if (t1.x>1&&beat(t1.x-1,t1.y)&&opt2[t1.x-1][t1.y]=='3'&&!vis[t1.x-1][t1.y][2]) {
			vis[t1.x-1][t1.y][2]=1;
			if (!C[t1.x-1][t1.y]) {
				t2.x=t1.x-1,t2.y=t1.y;
				q.push(t2);	
			}
		}
		if (t1.x<n&&beat(t1.x+1,t1.y)&&opt2[t1.x][t1.y]=='3'&&!vis[t1.x+1][t1.y][2]) {
			vis[t1.x+1][t1.y][2]=1;
			if (!C[t1.x+1][t1.y]) {
				t2.x=t1.x+1,t2.y=t1.y;
				q.push(t2);	
			}
		}
	}
	return;
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d %d",&n,&m,&q);
		if ((long long)n*(long long)m<=20000&&q<=3000) {
			for (int i=1;i<=n;i++) {
				scanf("\n");
				for (int j=1;j<m;j++) {
					scanf("%c",&opt1[i][j]);
				}
			}
			for (int i=1;i<n;i++) {
				scanf("\n");
				for (int j=1;j<=m;j++) {
					scanf("%c",&opt2[i][j]);
				}
			}
			for (int cgy=1;cgy<=q;cgy++) {
				int x,y;
				scanf("%d %d %d %d",&col,&lv,&x,&y);
				col++;
				if (y>1&&beat(x,y-1)&&opt1[x][y-1]=='1') vis[x][y-1][0]=1;
				if (y<m&&beat(x,y+1)&&opt1[x][y]=='1') vis[x][y+1][0]=1;
				if (x>1&&beat(x-1,y)&&opt2[x-1][y]=='1') vis[x-1][y][0]=1;
				if (x<n&&beat(x+1,y)&&opt2[x][y]=='1') vis[x+1][y][0]=1;
				int dx=x,dy=y;
				while (dy>1&&opt1[dx][dy-1]=='2'&&beat(dx,dy-1)) {
					vis[dx][dy-1][1]=1;
					if (C[dx][dy-1]) break;
					dy--;
				}
				dx=x,dy=y;
				while (dy<m&&opt1[dx][dy]=='2'&&beat(dx,dy+1)) {
					vis[dx][dy+1][1]=1;
					if (C[dx][dy+1]) break;
					dy++;
				}
				dx=x,dy=y;
				while (dx>1&&opt2[dx-1][dy]=='2'&&beat(dx-1,dy)) {
					vis[dx-1][dy][1]=1;
					if (C[dx-1][dy]) break;
					dx--;
				}
				dx=x,dy=y;
				while (dx<n&&opt2[dx][dy]=='2'&&beat(dx+1,dy)) {
					vis[dx+1][dy][1]=1;
					if (C[dx+1][dy]) break;
					dx++;
				}
				bfs(x,y);
				int ans=-1;
				for (int i=1;i<=n;i++) {
					for (int j=1;j<=m;j++) {
						ans+=vis[i][j][0]|vis[i][j][1]|vis[i][j][2];
						vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=0;
					}
				}
				printf("%d\n",ans);
				C[x][y]=col,L[x][y]=lv;
			}	
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=m;j++) {
					C[i][j]=0;
				}
			}
		} else {
			for (int i=1;i<=n;i++) {
				scanf("\n");
				for (int j=1;j<m;j++) {
					char c;
					scanf("%c",&c);
					bool b=c-'0';
					v1[i].push_back(b);
				}
			}
			for (int i=1;i<n;i++) {
				scanf("\n");
				for (int j=1;j<=m;j++) {
					char c;
					scanf("%c",&c);
					bool b=c-'0';
					v2[i].push_back(b);
				}
			}
			for (int cgy=1;cgy<=q;cgy++) {
				int i,j;
				scanf("%d %d %d %d",&col,&lv,&i,&j);
				col++;
				int ans=0;
				if (i>1&&v2[i-1][j-1]&&(!C_[(i-2)*m+j]||(C_[(i-2)*m+j]!=col&&L_[(i-2)*m+j]<=lv))) ans++;
				if (i<n&&v2[i][j-1]&&(!C_[i*m+j]||(C_[i*m+j]!=col&&L_[i*m+j]<=lv))) ans++;
				if (j>1&&v1[i][j-2]&&(!C_[(i-1)*m+j-1]||(C_[(i-1)*m+j-1]!=col&&L_[(i-1)*m+j-1]<=lv))) ans++;
				if (j<m&&v1[i][j-1]&&(!C_[(i-1)*m+j+1]||(C_[(i-1)*m+j+1]!=col&&L_[(i-1)*m+j+1]<=lv))) ans++;
				printf("%d\n",ans);
				C_[(i-1)*m+j]=col;
				L_[(i-1)*m+j]=lv;
			}
			memset(C_,0,sizeof C_);
			memset(L_,0,sizeof L_);
		}
	}
	return 0;
}
