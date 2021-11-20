#include<bits/stdc++.h>
#define ll long long
//#define getchar gc
using namespace std;
const int Mxdt=1e5;
inline char gc() {
	static char buf[Mxdt+5],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}

inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=5005;

int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};

int n,m,Q;
int col[N][N],row[N][N],vit[N][N];

int iro[N],lv[N],p[N][N],ans,times,nowid;

inline int Get(int x,int y,int dir) {
	if(dir==0) return row[x][y-1];
	if(dir==1) return row[x][y];
	if(dir==2) return col[x][y];
	return col[x-1][y];
}

void DFS(int x,int y,int now,int dir,int eat) {
	vit[x][y]=times,++ans; //printf("(%d,%d) %d %d\n",x,y,now,dir);
	if(now==1||eat) return;
	
	for(int i=0; i<4; ++i) {
		int px=x+dx[i],py=y+dy[i];
		if(px<1||px>n||py<1||py>m||vit[px][py]==times) continue;
		int peo=p[px][py];
		if(peo&&(iro[peo]==iro[nowid]||lv[peo]>lv[nowid])) continue;
		int nxteat=(peo!=0);
		
		if(now==-1) {
			int typ=Get(x,y,i);
			if(typ==0) continue;
			DFS(px,py,typ,i,nxteat);
		}
		else if(now==2) {
			if(i^dir) continue;
			int typ=Get(x,y,i);
			if(typ==now) DFS(px,py,now,i,nxteat);
		}
		else if(now==3) {
			int typ=Get(x,y,i);
			if(typ==now) DFS(px,py,now,i,nxteat);
		}
	}
}

char c[N];

inline void Solve() {
	n=Rd(),m=Rd(),Q=Rd();
	memset(vit,0,sizeof(vit)); times=0;
	memset(p,0,sizeof(p));
	
	for(int i=1; i<=n; ++i) {
		scanf("%s",c+1);
		for(int j=1; j<m; ++j) row[i][j]=c[j]-'0';		
	}
	for(int i=1; i<n; ++i) {
		scanf("%s",c+1);
		for(int j=1; j<=m; ++j) col[i][j]=c[j]-'0';
	}
	for(int i=1; i<=Q; ++i) {
		nowid=i,iro[i]=Rd(),lv[i]=Rd(); int x=Rd(),y=Rd();
		++times,ans=0; DFS(x,y,-1,-1,0); p[x][y]=i;
		printf("%d\n",ans-1);
	}
}

int main() {
//	system("fc chess.out chess2.ans");
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=Rd();
	while(T--) Solve();
	return 0;
}


