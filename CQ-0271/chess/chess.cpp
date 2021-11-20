#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[100001],lv[100001],sum;
int T,n,m,q,a[2001][2001],b[2001][2001],v[2001][2001];
bool eat(int a,int b) {
	if(c[a]==c[b]) return 0;
	if(lv[a]>=lv[b]) return 1;
	return 0;
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		memset(v,0,sizeof(v));
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=n; i++) {
			getchar();
			for(int j=1; j<=m-1; j++)
				a[i][j]=getchar()-48;
		}
		for(int i=1; i<=n-1; i++) {
			getchar();
			for(int j=1; j<=m; j++)
				b[i][j]=getchar()-48;
		}
		for(int i=1; i<=q; i++) {
			int x,y;
			sum=0;
			scanf("%d%d%d%d",c+i,lv+i,&x,&y);
			v[x][y]=i;
			if(y>1) if(!v[x][y-1]||eat(i,v[x][y-1]))
					if(a[x][y-1]) sum++;
			if(x>1) if(!v[x-1][y]||eat(i,v[x-1][y]))
					if(b[x-1][y]) sum++;
			if(y<m) if(!v[x][y+1]||eat(i,v[x][y+1]))
					if(a[x][y]) sum++;
			if(x<n) if(!v[x+1][y]||eat(i,v[x+1][y]))
					if(b[x][y]) sum++;
			printf("%d\n",sum);
		}
	}
	return 0;
}
