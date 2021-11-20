#include<bits/stdc++.h>
#define R register
int n, m, q;
int T;
const int maxn=200005;
const int maxm=2000005;
int tot,Last[maxn],Next[maxm],End[maxm],Len[maxm];
inline void add(int x, int y, int z) {
	End[++tot]=y,Next[tot]=Last[x],Last[x]=tot,Len[tot]=z;
	return ;
}
int c[maxn],l[maxn];
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&q);
		tot=0;
		for(R int i=1; i<=n*m; ++i) {
			Last[i]=0;
		}
		for(R int i=1; i<=n; ++i) {
			for(R int j=1; j<m; ++j) {
				R int x;
				scanf("%d",&x);
				add(i*(n-1)+j,i*(n-1)+j+1,x);
				add(i*(n-1)+j+1,i*(n-1)+j,x);
			}
		}
		for(R int i=1; i<n; ++i) {
			for(R int j=1; j<=m; ++j) {
				R int x;
				scanf("%d",&x);
				add(i*(n-1)+j,(i+1)*(n-1)+j,x);
				add((i+1)*(n-1)+j,i*(n-1)+j,x);
			}
		}
		while(q--) {
			R int col,lv,x,y,nid;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			nid=x*(n-1)+y;
			c[nid]=col,l[nid]=lv;
			R int flag=0;
			for(R int i=Last[nid]; i; i=Next[i]) {
				if(Len[i]>1) {
					flag=1;
					break;
				}
			}
			if(!flag) {
				R int cnt=0;
				for(R int i=Last[nid]; i; i=Next[i]) {
					R int v=End[i];
					if(Len[i]==1) {
						if(!l[v]) {
							++cnt;
						} else {
							if(c[nid]!=c[v]&&l[nid]>=l[v]) {
								++cnt;
							}
						}
					}
				}
				printf("%d\n",cnt);
			} else {
				printf("%d\n",nid);
			}
		}
	}
	return 0;
}
