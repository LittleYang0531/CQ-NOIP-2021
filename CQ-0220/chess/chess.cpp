#include<bits/stdc++.h>
using namespace std;

const int Maxn=2e5+10;
int T,N,M,Q,col[Maxn],lv[Maxn],x[Maxn],y[Maxn],hed[Maxn],ans,cnt;
int Vis[Maxn],num[Maxn];
char ch;
struct node{
	int nxt,to;
}G[Maxn<<1];

void Addedge(int x,int y){
	G[++cnt].nxt=hed[x]; G[cnt].to=y; hed[x]=cnt;
}

void DFS(int x,int y,int c,int l){
	if(x>N||y>M||x<1||y<1) return;
	if(Vis[x*M+y]==c||num[x*M+y]>l) return;
	int u=x*M+y; ans++;
	for(int v,i=hed[u];i;i=G[i].nxt){
		v=G[i].to;
		DFS(v/M,v%M,c,l);
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0;
		memset(Vis,-1,sizeof Vis);
		memset(col,0,sizeof col);
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(lv,0,sizeof lv);
		memset(num,0,sizeof num);
		scanf("%d %d %d",&N,&M,&Q);
		for(int i=1;i<=N;i++) {
			for(int j=1;j<M;j++){
				cin>>ch;
				if(ch!='0') Addedge(i*M+j,i*M+j+1),Addedge(i*M+j+1,i*M+j);
			}
		}
		for(int i=1;i<N;i++){
			for(int j=1;j<=M;j++){
				cin>>ch;
				if(ch!='0') Addedge((i+1)*M+j,i*M+j),Addedge(i*M+j,(i+1)*M+j);
			}
		}
		for(int i=1;i<=Q;i++){
			scanf("%d %d %d %d",&col[i],&lv[i],&x[i],&y[i]);
			Vis[x[i]*M+y[i]]=col[i]; num[x[i]*M+y[i]]=lv[i];
			DFS(x[i],y[i],col[i],lv[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*Hope I can get more point!!
RP++!!!
And, Fuck CCF!!!*/
