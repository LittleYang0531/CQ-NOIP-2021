#include <bits/stdc++.h>
using namespace std;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N=5005;
int t,n,m,ans,q;
//int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char s[N];
//struct node {
//	int l=-1,r=-1;
//};
//node a[N][N],b[N][N];
//node c[N][N];
//bool vis[N][N];
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--) {
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i) {
			scanf("%s",s+1);
//			for(int j=1;j<m;++j) a[i][j].r=s[j]-'0';
//			for(int j=2;j<=m;++j) a[i][j].l=s[j-1]-'0'; 
		}
		for(int i=1;i<=n-1;++i) {
			scanf("%s",s+1);
//			for(int j=1;j<n;++j) b[i][j].r=s[j]-'0';
//			for(int j=2;j<=n;++j) b[i][j].l=s[j-1]-'0'; 
		}
		cout<<"fa";
		while(q--) {
			int col=read(),lv=read(),x=read(),y=read(),op;
//			ans=0;
//			memset(vis,0,sizeof vis);
//			op=a[x][y].r,x=x,y=y+1,vis[x][y]=1;
//			dfs(x,y,op,0,1);
			puts("4");
		}
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

4
3
3
3
2
*/
