#include <cstdio>
#include <vector>
const int maxn = 2e5+5;
struct pair{
	int x,y;~pair(){};
	pair(int X=-1,int Y=0):x(X),y(Y){};
};
int T,n,m,q;char s[maxn];
std :: vector <pair> chs[maxn];
std :: vector <int> dn[maxn],rg[maxn];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;++i)rg[i].clear(),rg[i].shrink_to_fit(),rg[i].resize(m+1);
		for(int i=1;i<=m;++i)dn[i].clear(),dn[i].shrink_to_fit(),dn[i].resize(n+1);
		for(int i=1;i<=n;++i)chs[i].clear(),chs[i].shrink_to_fit(),chs[i].resize(m+1);
		for(int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(int j=1;j<m;++j)dn[j][i] = s[j]-'0';
		}
		for(int i=1;i<n;++i){
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)rg[i][j] = s[j]-'0';
		}
		for(int i=1,x,y,r,c;i<=q;++i){
			scanf("%d %d %d %d",&x,&y,&r,&c);
			int ans = 0;
			if(r != 1 && rg[r-1][c] && chs[r-1][c].x != -1 && chs[r-1][c].x != x && chs[r-1][c].y <= y)
				++ans;
			if(r != n && rg[r][c] && chs[r+1][c].x != -1 && chs[r+1][c].x != x && chs[r+1][c].y <= y)
				++ans;
			if(c != 1 && dn[c-1][r] && chs[r][c-1].x != -1 && chs[r][c-1].x != x && chs[r][c-1].y <= y)
				++ans;
			if(c != m && dn[c][r] && chs[r][c+1].x != -1 && chs[r][c+1].x != x && chs[r][c+1].y <= y)
				++ans;
			printf("%d\n",ans);
			chs[r][c] = pair(x,y);
		}
	}
	return 0;
}
