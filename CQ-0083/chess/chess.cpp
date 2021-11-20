#include<bits/stdc++.h>
using namespace std;
const int N=2e6+101;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int n,m,q;
int co[5010][5010],pos[5010][5010],e[5010][5010],p[5010][5010];
int h[5010][5010],s[5010][5010];

int r[]={1,-1,0,0},o[]={0,0,1,-1},ans,vis[5010][5010];
void bfs(int c,int LV,int a,int b,int opt,int zhi) {
	
	p[a][b]=1;
	vis[a][b]=1;
	for(int i=0;i<=3;++i) {
		int u=a+r[i],v=b+o[i];
		if(u<0||u>n||v<0||v>m) continue;
		//cout<<u<<" "<<v<<'\n';
		if(vis[u][b]) continue;
		if(e[u][v]==c) continue;
		if(i==0) {	// об
			if(opt==0&&s[v][u]==1) {
				if(e[u][v]==2) p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(s[v][u]==2&&(opt==0||zhi==1)) {
				if(e[u][v]==2) bfs(c,LV,u,v,2,1),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(s[v][u]==3&&(opt==0||opt==3)) {
				if(e[u][v]==2) bfs(c,LV,u,v,3,4),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
		}
		if(i==1) {	// ио 
			if(opt==0&&s[v][a]==1) {
				if(e[u][v]==2) p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(s[v][a]==2&&(opt==0||zhi==1)) {
				if(e[u][v]==2) bfs(c,LV,u,v,2,1),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(s[v][a]==3&&(opt==0||opt==3)) {
				if(e[u][v]==2) bfs(c,LV,u,v,3,4),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
		}
		if(i==2) {	// ср 
			if(opt==0&&h[u][v]==1) {
				if(e[u][v]==2) p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(h[u][v]==2&&(opt==0||zhi==2)) {
				if(e[u][v]==2) bfs(c,LV,u,v,2,2),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(h[u][v]==3&&(opt==0||opt==3)) {
				if(e[u][v]==2) bfs(c,LV,u,v,3,4),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
		}
		if(i==3) {	// вС 
			if(opt==0&&h[u][b]==1) {
				if(e[u][v]==2) p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(h[u][b]==2&&(opt==0||zhi==2)) {
				if(e[u][v]==2) bfs(c,LV,u,v,2,2),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
			if(h[u][b]==3&&(opt==0||opt==3)) {
				if(e[u][v]==2) bfs(c,LV,u,v,3,4),p[u][v]=1;
				else if(LV>=pos[u][v]) p[u][v]=1;
			}
		}
	}
}
char ch[N];
signed main() {
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T=read();
	while(T--) {
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i) {
			scanf("%s",ch+1);
			for(int j=1;j<=m-1;++j) {
				h[i][j+1]=ch[j]-'0';
			}
		}
		for(int i=1;i<=n-1;++i) {
			scanf("%s",ch+1);
			for(int j=1;j<=m;++j) {
				s[j][i+1]=ch[j]-'0';
			}
		}
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) e[i][j]=2;
		for(int i=1;i<=q;++i) {
			for(int u=1;u<=n;++u) for(int v=1;v<=m;++v) p[u][v]=2,vis[u][v]=0;
			int c=read(),lv=read(),x=read(),y=read();
			e[x][y]=c;
			pos[x][y]=lv;
			
			bfs(c,lv,x,y,0,0);
			
			int ans=0;
			for(int u=1;u<=n;++u) for(int v=1;v<=m;++v) if(p[u][v]==1) ++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
