//_zzi_ orz jzm ppl xez xyx xjx dym zxy wxk llsw they are yyds!!!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
string a[maxn],b[maxn];
char T[maxn];
vector<bool> vis2[maxn],vis[4][maxn];
vector<int> used[maxn];
struct zz{
	int col,lev;
}s[maxn];
int nowx,nowy,n,m,now;
int cnt=0;
void check(int x,int y,int from){
	if(now==used[x][y])
		return;
	if(s[now].col==s[used[x][y]].col)
		return;
	if(s[now].lev<s[used[x][y]].lev)
		return;
	if(!vis2[x][y])
		cnt++;
	vis2[x][y]=1;
	vis[from][x][y]=1;
	return;
}
void dfs1(int x,int y,char type,int from){
	if(x<1||x>n||y<1||y>m||vis[from][x][y])
		return ;
	if(used[x][y]){
		check(x,y,from);
		return;
	}
	if(!vis2[x][y])
		cnt++;
	vis2[x][y]=1;
	vis[from][x][y]=1;
	if(type==1)
		return;
	if(type==2){
		if(b[x-1][y]==type){
			dfs1(x-1,y,type,2);
		}
		if(b[x][y]==type){
			dfs1(x+1,y,type,0);
		}
	}
	if(type==3){
		if(b[x][y-1]==type){
			dfs1(x-1,y,type,2);
		}
		if(b[x][y]==type){
			dfs1(x+1,y,type,0);
		}
		if(a[x][y-1]==type){
			dfs1(x,y-1,type,3);
		}
		if(a[x][y]==type){
			dfs1(x,y+1,type,1);
		}
	}
}
void dfs2(int x,int y,char type,int from){
	if(x<1||x>n||y<1||y>m)
		return ;
	if(used[x][y]){
		check(x,y,from);
		return;
	}
	if(vis[from][x][y])
		return;
	bool flag=0;
	if(!vis2[x][y])
		cnt++;
	vis2[x][y]=1;
	vis[from][x][y]=1;
	if(type==1)	
		return;
	if(type==2){
		if(b[x][y-1]==type){
			dfs1(x,y-1,type,3);
		}
		if(b[x][y]==type){
			dfs1(x,y+1,type,1);
		}
	}
	if(type==3){
		if(b[x][y-1]==type){
			dfs1(x,y-1,type,3);
		}
		if(b[x][y]==type){
			dfs1(x,y+1,type,1);
		}
		if(a[x-1][y]==type){
			dfs1(x-1,y,type,2);
		}
		if(a[x][y]==type){
			dfs1(x+1,y,type,0);
		}
	}
}
int main (){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=readint();
	while(t--){
		n=readint(),m=readint();
		int q=readint();
		for(int i=1;i<=n;i++){
			a[i]="";
			scanf("%s",T+1);
			vis2[i].resize(m+5);
			used[i].resize(m+5);
			for(int j=0;j<4;j++)
				vis[j][i].resize(m+5);
			for(int j=1;j<m;j++){
				a[i]+=T[j];
			}
//			cout<<a[i]<<endl;
		}
		for(int i=1;i<n;i++){
			b[i]="";
			scanf("%s",T+1);
			for(int i=1;i<m;i++){
				b[i]+=T[i];
			}
		}
//		cout<<"fuck"<<endl;
		for(int i=1;i<=q;i++){
			now=i;
			cnt=0;
			s[i].col=readint(),s[i].lev=readint();
			int nowx=readint(),nowy=readint();
			used[nowx][nowy]=i;
			cnt=0;
			for(int j=1;j<=n;j++)
				vis2[j].clear(),vis[1][j].clear(),vis[0][j].clear(),vis[2][j].clear(),vis[3][j].clear();
			vis2[nowx][nowy]=1;
			if(b[nowx-1][nowy]!='0')
				dfs1(nowx-1,nowy,b[nowx-1][nowy],2);
			if(b[nowx][nowy]!='0')
				dfs1(nowx+1,nowy,b[nowx][nowy],0);
			if(a[nowx][nowy-1]!='0')
				dfs2(nowx,nowy-1,a[nowx-1][nowy],3);
			if(a[nowx][nowy]!='0')
				dfs2(nowx,nowy+1,a[nowx][nowy],1);
			printf("%d\n",cnt);
		}
	}
	return 0;
}
