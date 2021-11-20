#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
#define RP 0x7fffffffffffffff
using namespace std;
int T;
int n,m,q;
int ans;
int h[2005][2005],z[2005][2005];
int book[2005][2005],check[2005][2005];
char ch;
struct road {
	int col;
	int lv;
}a[2005][2005];
void dfs(int x,int y,int f,int r,int c,int l) {//x坐标,y坐标,方向,路,颜色,等级 
	//1:rignt,2:down,3:left,4:up
	if(y<m) {//右 
		if(h[x][y]==1&&r==-1&&(a[x][y+1].col==-1||(a[x][y+1].col!=c&&a[x][y+1].lv<=l))&&!book[x][y+1]) {
			if(!check[x][y+1])
				++ans,check[x][y+1]=1;
		}
		else if(h[x][y]==2&&(f==1||f==0)&&(r==2||r==-1)&&(a[x][y+1].col==-1||(a[x][y+1].col!=c&&a[x][y+1].lv<=l))&&!book[x][y+1]) {
			if(!check[x][y+1])
				++ans,check[x][y+1]=1;
			if(a[x][y+1].col==-1) {
				book[x][y+1]=1;
				dfs(x,y+1,1,2,c,l);
				book[x][y+1]=0;
			}
		}
		else if(h[x][y]==3&&(r==3||r==-1)&&(a[x][y+1].col==-1||(a[x][y+1].col!=c&&a[x][y+1].lv<=l))&&!book[x][y+1]) {
			if(!check[x][y+1])
				++ans,check[x][y+1]=1;
			if(a[x][y+1].col==-1) {
				book[x][y+1]=1;
				dfs(x,y+1,0,3,c,l);
				book[x][y+1]=0;
			}
		}
	}
	if(x<n) {//下 
		if(z[x][y]==1&&r==-1&&(a[x+1][y].col==-1||(a[x+1][y].col!=c&&a[x+1][y].lv<=l))&&!book[x+1][y]) {
			if(!check[x+1][y])
				++ans,check[x+1][y]=1;
		}
		else if(z[x][y]==2&&(f==2||f==0)&&(r==2||r==-1)&&(a[x+1][y].col==-1||(a[x+1][y].col!=c&&a[x+1][y].lv<=l))&&!book[x+1][y]) {
			if(!check[x+1][y])
				++ans,check[x+1][y]=1;
			if(a[x+1][y].col==-1) {
				book[x+1][y]=1;
				dfs(x+1,y,2,2,c,l);
				book[x+1][y]=0;
			}
		}
		else if(z[x][y]==3&&(r==3||r==-1)&&(a[x+1][y].col==-1||(a[x+1][y].col!=c&&a[x+1][y].lv<=l))&&!book[x+1][y]) {
			if(!check[x+1][y])
				++ans,check[x+1][y]=1;
			if(a[x+1][y].col==-1) {
				book[x+1][y]=1;
				dfs(x+1,y,0,3,c,l);
				book[x+1][y]=0;
			}
		}
	}
	if(y>1) {//左 
		if(h[x][y-1]==1&&r==-1&&(a[x][y-1].col==-1||(a[x][y-1].col!=c&&a[x][y-1].lv<=l))&&!book[x][y-1]) {
			if(!check[x][y-1])
				++ans,check[x][y-1]=1;
		}
		else if(h[x][y-1]==2&&(f==3||f==0)&&(r==2||r==-1)&&(a[x][y-1].col==-1||(a[x][y-1].col!=c&&a[x][y-1].lv<=l))&&!book[x][y-1]) {
			if(!check[x][y-1])
				++ans,check[x][y-1]=1;
			if(a[x][y-1].col==-1) {
				book[x][y-1]=1;
				dfs(x,y-1,3,2,c,l);
				book[x][y-1]=0;
			}
		}
		else if(h[x][y-1]==3&&(r==3||r==-1)&&(a[x][y-1].col==-1||(a[x][y-1].col!=c&&a[x][y-1].lv<=l))&&!book[x][y-1]) {
			if(!check[x][y-1])
				++ans,check[x][y-1]=1;
			if(a[x][y-1].col==-1) {
				book[x][y-1]=1;
				dfs(x,y-1,0,3,c,l);
				book[x][y-1]=0;
			}
		}
	}
	if(x>1) {//上 
		if(z[x-1][y]==1&&r==-1&&(a[x-1][y].col==-1||(a[x-1][y].col!=c&&a[x-1][y].lv<=l))&&!book[x-1][y]) {
			if(!check[x-1][y])
				++ans,check[x-1][y]=1;
		}
		else if(z[x-1][y]==2&&(f==4||f==0)&&(r==2||r==-1)&&(a[x-1][y].col==-1||(a[x-1][y].col!=c&&a[x-1][y].lv<=l))&&!book[x-1][y]) {
			if(!check[x-1][y])
				++ans,check[x-1][y]=1;
			if(a[x-1][y].col==-1) {
				book[x-1][y]=1;
				dfs(x-1,y,4,2,c,l);
				book[x-1][y]=0;
			}
		}
		else if(z[x-1][y]==3&&(r==3||r==-1)&&(a[x-1][y].col==-1||(a[x-1][y].col!=c&&a[x-1][y].lv<=l))&&!book[x-1][y]) {
			if(!check[x-1][y])
				++ans,check[x-1][y]=1;
			if(a[x-1][y].col==-1) {
				book[x-1][y]=1;
				dfs(x-1,y,0,3,c,l);
				book[x-1][y]=0;
			}
		}
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	for(int I_Love_LXY=1;I_Love_LXY<=T;++I_Love_LXY) {
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				a[i][j].col=-1;
				a[i][j].lv=0;
				if(j==m) continue;
				cin>>ch;
				h[i][j]=(ch^48);
			}
		}
		for(int i=1;i<n;++i) {
			for(int j=1;j<=m;++j) {
				cin>>ch;
				z[i][j]=(ch^48);
			}
		}
		int c,l,xx,yy;
		while(q--) {
			ans=0;
			memset(book,0,sizeof book);
			memset(check,0,sizeof check);
			scanf("%d %d %d %d",&c,&l,&xx,&yy);
			a[xx][yy].col=c,a[xx][yy].lv=l;
			dfs(xx,yy,0,-1,c,l);
			printf("%d\n",ans);
		}
	}
	return 0;
}
//sto CRN、GYH、did、xinyue、jzp1025、HCQ、MZH orz
//I want to fuck CCF, but I love LXY, so I can't fuck CCF.
