#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
//#define int long long
using namespace std;
inline int read() {
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
int n,m,q,cnt;
int nm[400001];
char hb[200001],dj[200001];
bool v[200001];
int dfs(int x,int y,int col,int lv,int dl,int fx) {
	if(x>n||x<=0||y>m||y<=0||v[x*n+y]||dl==0)return 0;
//	if(fx%2&&dl!=(nm[x*n+y]/*^48*/))return 0;
//	if(fx%2==0&&dl!=(nm[n*m-n+x*n+y])/*^48*/)return 0;
	if(v[x*n+y]&&lv>=(dj[x*n+y]^48)&&col!=(hb[x*n+y]^48))return 1;
	v[x*n+y]=1;
	if(dl==2)
		if(fx==0)return 1+dfs(x+1,y,col,lv,nm[n*m+x*n+y],0);
	else if(fx==1)return 1+dfs(x,y+1,col,lv,nm[x*n+y+1],1);
	else if(fx==3)return 1+dfs(x,y-1,col,lv,nm[x*n+y-1],3);
	else return 1+dfs(x-1,y,col,lv,nm[n*m-n+x*n+y-n],2);
	if(dl==3)return 1+dfs(x-1,y,col,lv,nm[n*m-n+x*n+y-n],2)+dfs(x,y-1,col,lv,nm[x*n+y-1],3)+dfs(x+1,y,col,lv,nm[n*m+x*n+y],0)+dfs(x,y+1,col,lv,nm[x*n+y+1],1);
}
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--) {
		int n=read(),m=read(),q=read();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<m; j++)
				nm[++cnt]=getchar();
			getchar();
		}
		for(int i=1; i<n; i++) {
			for(int j=1; j<=m; j++)
				nm[++cnt]=getchar();
			getchar();
		}
		while(q--) {
			int col=read(),lv=read(),x=read(),y=read(),ans=0;
//			hb[x*n+y]=col,dj[x*n+y]=lv,v[x*n+y]=1;
//			ans+=dfs(x,y+1,col,lv,nm[x*n+y+1],1);//ср
//			ans+=dfs(x,y-1,col,lv,nm[x*n+y-1],3);//вС
//			ans+=dfs(x+1,y,col,lv,nm[n*m+x*n+y],0);//ио
//			ans+=dfs(x-1,y,col,lv,nm[n*m-n+x*n+y-n],2);//об
			printf("%d\n",ans);
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
*/
