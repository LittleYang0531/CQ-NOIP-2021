#include<bits/stdc++.h>
#define par pair<int,int>
using namespace std;
inline int read(){
	int sss=0;
	char chh=getchar();
	while(chh<'0'||chh>'9') chh=getchar();
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T,n,m,q;
string r[1005],d[1005];
int color[1005][1005],lev[1005][1005];
bool vis[1005][1005];
void bfs(int x,int y){
	memset(vis,0,sizeof vis);
	queue<par> q;
	q.push(make_pair(x,y));
	vis[x][y]=1;
	int ans=-1;
	while(!q.empty()){
		int tx=q.front().first,ty=q.front().second;
		vis[tx][ty]=1;
		ans++;
		if(d[tx][ty]>'0'){
			//vis[tx][ty+1]=true;
			if(!vis[tx][ty+1]&&(color[x][y]!=color[tx][ty+1])&&(lev[x][y]>lev[tx][ty+1]))q.push(make_pair(tx,ty+1));
		}
		if(r[tx][ty]>'0'){
			if(!vis[tx+1][ty]&&(color[x][y]!=color[tx+1][ty])&&(lev[x][y]>lev[tx+1][ty]))q.push(make_pair(tx+1,ty));
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),q=read();
		for(register int i=1;i<=n;i++){
			cin>>r[i];
		}
		for(register int i=1;i<n;i++)
			cin>>d[i];
		int col,level,x,y;
		memset(color,0,sizeof color);
		memset(lev,0,sizeof lev);
		while(q--){
			col=read(),level=read(),x=read(),y=read();
			color[x][y]=col;
			lev[x][y]=level;
			bfs(x,y);
		}
	}
	return 0;
}
/*
I love zlj forever!!! 
*/
