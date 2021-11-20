#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> dint;
#define mp make_pair 

int t = 0, n = 0, m = 0, q = 0, ans = 0, lc = 0;
int tot = 0, head[1000001] = {}, vis[1000001] = {}, tb[1000001] = {};
char z;

struct Chess{
	int col, lv;
	dint xy;
}a[1000001] = {};

struct Edge{
	int val, next;
	dint to;
}c[1000001] = {};

int wnum(dint xy){
	return xy.first + n * xy.second;
}

void add(dint u, dint v, int w){
	c[tot++].next = head[wnum(u)];
	c[tot].to = v;
	c[tot].val = w;
	head[wnum(u)] = tot;
	return;
}

int find(dint zb){
	for(int i = 0; i < lc; i++){
		if(a[i].xy == zb){
			return i;
		}
	}
	return 0;
}

void bfs(int x){
	ans = 0;
	memset(vis, 0, sizeof(vis));
	queue<pair<dint, int> > dl;
	dl.push(mp(a[x].xy, 0));
	while(!dl.empty()){
		dint point = dl.front().first;
		int nval = dl.front().second;
		vis[wnum(point)] = 1;
		dl.pop();
		for(int i = head[wnum(point)]; i; i = c[i].next){
			if(c[i].val != 0 && vis[wnum(point)] == 0){
				if(nval == 0){
					if(tb[wnum(c[i].to)] == 0){
						dl.push(mp(c[i].to, c[i].val));
						ans++;
						continue;
					}
					int y = find(c[i].to);
					if(a[y].col != a[x].col){
						if(a[x].lv >= a[y].lv){
							ans++;
							vis[wnum(c[i].to)] = 1;
						}
					}
					continue;
				}
				if(nval == c[i].val){
					if(tb[wnum(c[i].to)] == 0){
						dl.push(mp(c[i].to, c[i].val));
						ans++;
						continue;
					}
					int y = find(c[i].to);
					if(a[y].col != a[x].col){
						if(a[x].lv >= a[y].lv){
							ans++;
							vis[wnum(c[i].to)] = 1;
						}
					}
					continue;
				}
			}
		}
	}
}

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &q);
		for(int i = 1; i <= n; i++){
			scanf("%s", s)
			for(int j = 0; j <= m - 1; j++){
				add(mp(i, j), mp(i, j + 1), s[j] - '0');
				add(mp(i, j + 1), mp(i, j), s[j] - '0');
			}
		}
		for(int i = 1; i <= n - 1; i++){
			scanf("%s", s);
			for(int j = 0; j <= m - 1; j++){
				add(mp(i, j), mp(i + 1, j), s[j] - '0');
				add(mp(i + 1, j), mp(i, j), s[j] - '0');
			}
		}
		for(int i = 1; i <= q; i++){
			scanf("%d %d %d %d", &a[i].col, &a[i].lv, &a[i].xy.first, &a[i].xy.second);
			tb[wnum(a[i].xy)] = 1;
			lc++;
			bfs(i);
			printf("%d\n", ans);
		}
	}
	return 0;
}
