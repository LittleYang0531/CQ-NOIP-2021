#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long llong;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; !isdigit(c); c=getchar())
		if(c == '-') f = -f;
	for(; isdigit(c); c=getchar())
		a = (a*10)+(c^48);
	return a*f;
}
void writeint(unsigned x){
	if(x > 9) writeint(x/10);
	putchar(char((x%10)^48));
}

const int MAXN = 200005;
char dstr[MAXN], rstr[MAXN];
int col[MAXN], level[MAXN], n, m;

const int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int now_col, now_level;
bool vis[MAXN][2]; int now_cnt;
/// @param zhi -1 if swaper, [0,4) if on straight road, 4 if normal
void bfs(int x,int y,int zhi){
	const int id = x*m+y, typ = (zhi == -1);
	if(vis[id][typ]) return ;
	if(vis[id][typ] = true, col[id] != -1){
		if(col[id] == now_col || level[id] > now_level)
			return ; // defeated
		if(!vis[id][typ^1]) ++ now_cnt;
		return ; // cannot move
	}
	if(!vis[id][typ^1]) ++ now_cnt; // reach this grid
	for(int i=0,tx,ty,c; i!=4; ++i){
		if((~zhi) && i != zhi) continue;
		tx = x+dir[i][0], ty = y+dir[i][1];
		if((~tx) && tx != n && (~ty) && ty != m){
			if(!dir[i][1]) c = dstr[min(tx,x)*m+y];
			else c = rstr[x*m+min(ty,y)];
			if(c == '2' && zhi == i) bfs(tx,ty,i);
			if(c == '0' || c == '1') continue;
			if(c == '3' && zhi == -1) bfs(tx,ty,zhi);
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int T=readint(); T; --T){
		n = readint(), m = readint();
		int q = readint();
		rep(i,0,n-1) scanf("%s",rstr+i*m);
		rep(i,0,n-2) scanf("%s",dstr+i*m);
		memset(col,-1,(n*m)<<2);
		for(int x,y; q; --q){
			now_col = readint(), now_level = readint();
			x = readint()-1, y = readint()-1;
			memset(vis,false,n*m<<1); now_cnt = 0;
			for(int i=0,tx,ty,c; i!=4; ++i){
				tx = x+dir[i][0], ty = y+dir[i][1];
				if((~tx) && tx != n && (~ty) && ty != m){
					if(!dir[i][1]) c = dstr[min(tx,x)*m+y];
					else c = rstr[x*m+min(ty,y)];
					if(c == '3') bfs(tx,ty,-1);
				}
			}
			for(int i=0,tx,ty,c; i!=4; ++i){
				tx = x+dir[i][0], ty = y+dir[i][1];
				if((~tx) && tx != n && (~ty) && ty != m){
					if(!dir[i][1]) c = dstr[min(tx,x)*m+y];
					else c = rstr[x*m+min(ty,y)];
					if(c == '1') bfs(tx,ty,4);
					else if(c == '2') bfs(tx,ty,i);
				}
			}
			if(vis[x*m+y][0] || vis[x*m+y][1])
				-- now_cnt; // cannot stay
			writeint(now_cnt), putchar('\n');
			col[x*m+y] = now_col;
			level[x*m+y] = now_level;
		}
	}
	return 0;
}

