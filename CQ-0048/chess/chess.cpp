//R.I.P.
#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
#define rloop(i,from,to) for(int i=(from);i>=(to);--i)
#define reset(a,x) memset(a,x,sizeof a)
using namespace std;
const int maxn=2e5;
int T,n,m,q,ans,color[maxn+1],level[maxn+1],x[maxn+1],y[maxn+1],d[maxn+1],r[maxn+1],vis[maxn+1][4],count_ans[maxn+1],erased[maxn+1];
char board[maxn+1];
void read(int &x){
	x=0;
	char t=getchar();
	while(!isdigit(t))t=getchar();
	while(isdigit(t))x=x*10+t-'0',t=getchar();
	return;
}
inline int no(int x,int y){return (x-1)*m+y;}
inline bool check(int x,int y,int lastdir,int nowdir){return y?(y!=1&&x==y&&(y==3||lastdir==nowdir)):x;}
void dfs(int x,int y,int path,int dir){
	if(vis[no(x,y)][dir]==q)return;
	vis[no(x,y)][dir]=q;
	if(erased[no(x,y)]&&erased[no(x,y)]!=q){
		if(color[erased[no(x,y)]]!=color[q]&&level[erased[no(x,y)]]<=level[q]&&count_ans[no(x,y)]!=q)++ans,count_ans[no(x,y)]=q;
		return;
	}
	if(count_ans[no(x,y)]!=q)++ans,count_ans[no(x,y)]=q;
	if(y>1&&check(r[no(x,y-1)],path,dir,0))dfs(x,y-1,r[no(x,y-1)],0);
	if(x>1&&check(d[no(x-1,y)],path,dir,1))dfs(x-1,y,d[no(x-1,y)],1);
	if(y<m&&check(r[no(x,y)],path,dir,2))dfs(x,y+1,r[no(x,y)],2);
	if(x<n&&check(d[no(x,y)],path,dir,3))dfs(x+1,y,d[no(x,y)],3);
	return;
}
int main(){
	freopen("chess.in","r",stdin),freopen("chess.out","w",stdout);
	read(T);
	while(T--){
		read(n),read(m),read(q),reset(erased,0),reset(vis,0),reset(count_ans,0);
		loop(i,1,n){
			scanf("%s",board+1);
			loop(j,1,m-1)r[no(i,j)]=board[j]-'0';
		}
		loop(i,1,n-1){
			scanf("%s",board+1);
			loop(j,1,m)d[no(i,j)]=board[j]-'0';
		}
		do read(color[q]),read(level[q]),read(x[q]),read(y[q]),erased[no(x[q],y[q])]=q,ans=0,dfs(x[q],y[q],0,-1),printf("%d\n",ans-1);while(--q);
	}
	return 0;
}
