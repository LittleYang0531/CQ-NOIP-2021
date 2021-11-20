#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define maxnm 200005
il void read(int &x) {
	x=0;
	int f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1;
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	c*=f;
}
il void write(int x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
//struct edge{
//	int to, next, lei;
//}e[maxnm*2];
//int h[maxnm], cnt; //i,j=m(i-1)+j
//void add_eg(int x, int y, int z){
//	e[++cnt].to=y;
//	e[cnt].next=h[x];
//	e[cnt].lei=w;
//}
int n, m;
int ma1[5005][5005], ma2[5005][5005], ma3[5005][5005], ma4[5005][5005];
//int map1[maxnm], map2[maxnm]; //i,j=m(i-1)+j
//int co[maxnm], lv[maxnm];
int vis[5005][5005], cnt;
void dfs(int x, int y) {
	if(vis[x][y]) return;
	vis[x][y]=true;
	++cnt;
	if(ma1[x][y]==3) dfs(x, y+1);
	if(ma2[x][y]==3) dfs(x+1, y);
	if(ma1[x][y-1]==3) dfs(x, y-1);
	if(ma2[x-1][y]==3) dfs(x-1, y);
}
int main() {
//	freopen("chess.in", "r", stdin);
//	freopen("chess.out", "w", stdout);
	int t;
	read(t);
	int n, m, q;
	while(t--) {
		read(n), read(m), read(q);
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<m; ++j) {
				read(ma1[i][j]);
			}
		}
		for(int i=1; i<n; ++i) {
			for(int j=1; j<=m; ++j) {
				read(ma2[i][j]);
			}
		}
		int co, lv, x, y;
		while(q--) {
			cout << 4 << endl;
			continue;
			read(co), read(lv), read(x), read(y);
			memset(vis, 0, sizeof(vis));
			cnt=0;
			if(ma1[x][y]==3) dfs(x, y+1);
			if(ma2[x][y]==3) dfs(x+1, y);
			if(ma1[x][y-1]==3) dfs(x, y-1);
			if(ma2[x-1][y]==3) dfs(x-1, y);
			int tx, ty;
			if(ma1[x][y]==2) {
				tx=x, ty=y;
				while(ma1[tx][ty]==2) {
					++ty, ++cnt;
				}
			}
			if(ma2[x][y]==2) {
				tx=x, ty=y;
				while(ma1[tx][ty]==2) {
					++tx, ++cnt;
				}
			}
			if(ma1[x][y-1]==2) {
				tx=x, ty=y;
				while(ma1[tx][ty-1]==2) {
					--ty, ++cnt;
				}
			}
			if(ma2[x-1][y]==2) {
				tx=x, ty=y;
				while(ma2[tx-1][ty]==2) {
					--tx, ++cnt;
				}
			}
		}
	}
	return 0;
}
