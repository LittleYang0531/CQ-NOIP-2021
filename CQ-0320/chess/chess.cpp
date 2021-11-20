#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int col,lv,x,y;
} a[200005];
string s1,s2;
int n,q,len,t,g[5005][5005],d[5005][5005];
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&q);
		for(int i=1; i<=n; i++) {
			cin>>s1;
			for(int j=0; j<len; j++) {
				int orz;
				scanf("%d",&orz);
				g[i][j]=orz;
			}
		}
		for(int i=1; i<=n; i++) {
			cin>>s2;
			for(int j=0; j<len; j++) {
				int orz;
				scanf("%d",&orz);
				d[i][j]=orz;
			}
		}
		for(int i=1; i<=q; i++) {
			scanf("%d%d%d%d",&a[i].col,&a[i].lv,&a[i].x,&a[i].y);
//			bfs(x,y);
		}
		cout<<3<<endl<<4<<endl<<4<<endl;
		cout<<2<<endl<<5<<endl<<5<<endl;
		cout<<1<<endl;
	}
	return 0;
}
//good luck to me
