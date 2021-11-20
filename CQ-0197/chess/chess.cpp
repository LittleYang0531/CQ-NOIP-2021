#include <bits/stdc++.h>

using std :: pair;
using std :: make_pair;

const int siz_1 = 1e5 + 10;

int T,n,m,q;
int ans;

int coler,level;
bool vis[siz_1 << 1];

int e = 1;
int L[siz_1 << 1];

struct E {
	int L,R,N,O;
}edge[siz_1 << 4];

pair <int,int> node[siz_1 << 1];

inline void Add (int,int,int);
inline int I (int,int);
inline bool A (int,int,int);

void M (int,int,int);

int main () {
	freopen ("chess.in","r",stdin);	
	freopen ("chess.out","w",stdout);
    
    scanf ("%d",&T);
    
    while (T --) {
    	memset (node,0,sizeof (node));
    	memset (L,0,sizeof (L));
    	e = 1;
    	
	    scanf ("%d%d%d",&n,&m,&q);
	    for (int i = 1;i <= n; ++ i) {
			char link[siz_1];
			scanf ("%s",link + 1);
			for (int j = 1;j < m; ++ j) {
				if (link[j] - '0' == 0) continue;
				Add (I (j,i),I (j + 1,i),link[j] - '0' + 1);
				Add (I (j + 1,i),I (j,i),link[j] - '0' + 1);
			}
		}
		for (int i = 1;i < n; ++ i) {
			char link[siz_1];
			scanf ("%s",link + 1);
			for (int j = 1;j <= m; ++ j) {
				if (link[j] - '0' == 0) continue;
				Add (I (j,i),I (j,i + 1),link[j] - '0' + 1);
				Add (I (j,i + 1),I (j,i),link[j] - '0' + 1);
			}
		}
				
		for (int i = 1;i <= q;++ i) {
			int col,lv,x,y;
			scanf ("%d%d%d%d",&col,&lv,&y,&x);
			coler = col,level = lv;
			memset (vis,false,sizeof (vis));
			ans = 0;
			M (I (x,y),0,0);
			printf ("%d\n",ans - 1);
			node[I (x,y)] = make_pair (col,lv);
		}
	}
	
	return 0; 
}

inline int I (int x,int y) { return (y - 1) * m + x; }

inline void Add (int l,int r,int o) {
	edge[++ e].L = l,edge[e].R = r,edge[e].O = o;
	edge[e].N = L[l],L[l] = e;
}

void M (int now,int last,int opt) {
	vis[now] = true;
	if (node[now].second != 0) {
		if (node[now].first != coler && node[now].second <= level) ++ ans;
		return;		
	}
	++ ans;
	for (int i = L[now];i;i = edge[i].N) {
		int next = edge[i].R;
		if (vis[next]) continue;
		if (opt == 0) M (next,now,edge[i].O);
		if (opt != edge[i].O) continue;
		if (opt == 2) return;
 		if (opt == 3 && A (last,now,next)) M (next,now,opt);
		if (opt == 4) M (next,now,opt);
	}
	
	return;
}

inline bool A (int a,int b,int c) {
	int y1 = a / m,y2 = b / m,y3 = c / m;
	int x1 = a % m,x2 = b % m,x3 = c % m;
	if (x1 == x2 && x2 == x3) return true;
	if (y1 == y2 && y2 == y3) return true;
	return false;
}
