#include <bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
int T,n,m,q,ans,rd[mxn][4],lv[mxn],col[mxn];
int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int _() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int check(int x,int y) {
	if(x>1&&y>1&&x<=n&&y<=m) return 1;
	return 0;
}
void find(int x,int y,int r,int f) {
	int X=x+fx[f][0],Y=y+fx[f][1];
	int a=x*n+y,b=X*n+Y;
	if(r==0||lv[b]>lv[a]||col[b]==col[a]||(!check(X,Y))) 
	return ;
	ans++;
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=_();
	while(T--) {
		n=_(),m=_(),q=_();
		memset(lv,-1,sizeof(lv));
		memset(col,-1,sizeof(col));
		for(int i=1;i<=n;++i) {
			for(int j=1;j<m;++j) {
				char ch=getchar();
				while(ch<'0'||ch>'9') ch=getchar();
				rd[i*n+j][3]=ch^48;
				rd[i*n+j+1][2]=ch^48;
			}
		}
		for(int i=1;i<n;++i) {
			for(int j=1;j<=m;++j) {
				char ch=getchar();
				while(ch<'0'||ch>'9') ch=getchar();
				rd[i*n+j][1]=ch^48;
				rd[(i+1)*n+j][0]=ch^48;
			}
		}
		for(int i=1;i<=q;++i) {
			int a=_(),b=_(),x=_(),y=_();ans=0;
			col[x*n+y]=a,lv[x*n+y]=b;
			for(int j=0;j<4;++j) {
				find(x,y,rd[x*n+y][j],i);
			}
			printf("%d ",ans);
		}
	}
}
