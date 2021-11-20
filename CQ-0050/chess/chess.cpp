#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
int n,m,q;
const int N=2e5+10;
vector<int> col[N],lv[N],vis[N],ok[N];
string h1[N],h2[N];
//ban,pt,zx,ht
#define ok(i,j) (1<=i&&i<=n&&0<=j&&j<m)
bool win(int c1,int l1,int c2,int l2){return c1!=c2&&l1>=l2;}
namespace _32pts{
	int res,tag,c,l;
	void mark(int x,int y){res+=(ok[x][y]!=tag),ok[x][y]=tag;}
	void dfs(int x,int y){
		mark(x,y),vis[x][y]=tag;
		if(ok(x,y-1)&&vis[x][y-1]!=tag&&h1[x][y-1]=='3'&&!lv[x][y-1])dfs(x,y-1);
		if(ok(x,y-1)&&lv[x][y-1]&&h1[x][y-1]=='3'&&win(c,l,col[x][y-1],lv[x][y-1]))mark(x,y-1);
		
		if(ok(x-1,y)&&vis[x-1][y]!=tag&&h2[x-1][y]=='3'&&!lv[x-1][y])dfs(x-1,y);
		if(ok(x-1,y)&&lv[x-1][y]&&h2[x-1][y]=='3'&&win(c,l,col[x-1][y],lv[x-1][y]))mark(x-1,y);
		
		if(ok(x,y+1)&&vis[x][y+1]!=tag&&h1[x][y]=='3'&&!lv[x][y+1])dfs(x,y+1);
		if(ok(x,y+1)&&lv[x][y+1]&&h1[x][y]=='3'&&win(c,l,col[x][y+1],lv[x][y+1]))mark(x,y+1);
		
		if(ok(x+1,y)&&vis[x+1][y]!=tag&&h2[x][y]=='3'&&!lv[x+1][y])dfs(x+1,y);
		if(ok(x+1,y)&&lv[x+1][y]&&h2[x][y]=='3'&&win(c,l,col[x+1][y],lv[x+1][y]))mark(x+1,y) ;
	}
	void solve(){
		while(q--){
			c=read(),l=read(),tag=q+1;
			int i=read(),j=read()-1,x,y;res=0;
			assert(ok(i,j));
			col[i][j]=c,lv[i][j]=l;			
			if(j&&h1[i][j-1]=='1'&&(!lv[i][j-1]||win(c,l,col[i][j-1],lv[i][j-1])))mark(i,j-1);//left
			
			if(i>1&&h2[i-1][j]=='1'&&(!lv[i-1][j]||win(c,l,col[i-1][j],lv[i-1][j])))mark(i-1,j);//up
			
			if(j<m-1&&h1[i][j]=='1'&&(!lv[i][j+1]||win(c,l,col[i][j+1],lv[i][j+1])))mark(i,j+1);//right
			
			if(i<n&&h2[i][j]=='1'&&(!lv[i+1][j]||win(c,l,col[i+1][j],lv[i+1][j])))mark(i+1,j);//down
			
			
			x=i,y=j;while(ok(x,y-1)&&h1[x][y-1]=='2'&&!lv[x][y-1])y--,res++,ok[x][y]=tag;
			if(ok(x,y-1)&&lv[x][y-1]&&h1[x][y-1]=='2'&&win(c,l,col[x][y-1],lv[x][y-1]))mark(x,y-1);
			
			x=i,y=j;while(ok(x-1,y)&&h2[x-1][y]=='2'&&!lv[x-1][y])x--,res++,ok[x][y]=tag;
			if(ok(x-1,y)&&lv[x-1][y]&&h2[x-1][y]=='2'&&win(c,l,col[x-1][y],lv[x-1][y]))mark(x-1,y);
			
			x=i,y=j;while(ok(x,y+1)&&h1[x][y]=='2'&&!lv[x][y+1])y++,res++,ok[x][y]=tag;
			if(ok(x,y+1)&&lv[x][y+1]&&h1[x][y]=='2'&&win(c,l,col[x][y+1],lv[x][y+1]))mark(x,y+1);
			
			x=i,y=j;while(ok(x+1,y)&&h2[x][y]=='2'&&!lv[x+1][y])x++,res++,ok[x][y]=tag;
			if(ok(x+1,y)&&lv[x+1][y]&&h2[x][y]=='2'&&win(c,l,col[x+1][y],lv[x+1][y]))mark(x+1,y);
			
			
			dfs(i,j);
			printf("%d\n",res-1);
		}
	}
}

signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;cin>>T;while(T--){
		n=read(),m=read(),q=read();
		For(i,1,n)col[i].resize(m+1),lv[i].resize(m+1),vis[i].resize(m+1),ok[i].resize(m+1);
		For(i,1,n)For(j,0,m-1)ok[i][j]=vis[i][j]=col[i][j]=lv[i][j]=0;
		For(i,1,n)cin>>h1[i];For(i,1,n-1)cin>>h2[i];
		_32pts::solve();
	}
	return 0;
}

