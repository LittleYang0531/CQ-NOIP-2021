#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q,ans;
char c[200005];
int ca[200005][4];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool out(int x,int y){return (x<1||x>n||y<1||y>m);}

struct node{int col,lev;};
node p[200005];
bool hav[200005];

inline int read(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-'0',c=getchar();
	return s;
}

bool cmp(node x,node y){
	return (x.col!=y.col)&&(x.lev>=y.lev);
}

bool legal[200005];
void sch(int x,int y,int cas,int org){
	int now=(x-1)*m+y;
	if(out(x,y)) return;
	if(!hav[now]) {
		legal[now]=1;
		if(ca[now][cas]!=2) return;
		sch(x+dir[cas][0],y+dir[cas][1],cas,org);
		return;
	}
	if(cmp(p[org],p[now])) legal[now]=1;
	return;
}

bool vis[200005];
void dfs(int x,int y,int org){
	int now=(x-1)*m+y;
	if(out(x,y)) return;
	vis[now]=1;
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0],dy=y+dir[i][1];
		if(out(dx,dy)||ca[now][i]!=3) continue;
		int nxt=(dx-1)*m+dy;
		if(vis[nxt]) continue;
		if(!hav[nxt]) legal[nxt]=1,dfs(dx,dy,org);
		else if(cmp(p[org],p[nxt])) legal[nxt]=1;
	}
	vis[now]=0;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),q=read();
		memset(ca,0,sizeof(ca));
		memset(hav,0,sizeof(hav));
		
		for(int i=1;i<=n;i++) {
			scanf("%s",c+1);
			for(int j=1;j<m;j++)
			ca[(i-1)*m+j][0]=c[j]-'0',
			ca[(i-1)*m+j+1][1]=c[j]-'0';
		}
		
		for(int i=1;i<n;i++){
			scanf("%s",c+1);
			for(int j=1;j<=m;j++)
			ca[(i-1)*m+j][2]=c[j]-'0',
			ca[i*m+j][3]=c[j]-'0';
		}
		
		for(int i=1;i<=q;i++){
			int col=read(),lv=read(),x=read(),y=read();
			int now=(x-1)*m+y;
			ans=0;
			p[now]=(node){col,lv},hav[now]=1;
			for(int j=1;j<=n*m;j++) legal[j]=0;
			
			for(int j=0;j<4;j++){
				int dx=x+dir[j][0],dy=y+dir[j][1];
				int nxt=(dx-1)*m+dy;
				if(!ca[now][j]) continue;
				if(ca[now][j]==1){
					if(!hav[nxt]) legal[nxt]=1;
					else if(cmp(p[now],p[nxt])) legal[nxt]=1;
				}
				else if(ca[now][j]==2) sch(x+dir[j][0],y+dir[j][1],j,now);
			}
			
			dfs(x,y,now);
			for(int j=1;j<=n*m;j++) ans+=legal[j];
			
			printf("%d\n",ans);
		}
		
	}
	return 0;
}

