#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pii pair <int , int>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(x<0) {putchar('-');x=-x;}
	if(!x) {putchar('0');putchar(s);return;}
	T tmp[25] , t = 0;
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t -- > 0) putchar(tmp[t] + '0');
	putchar(s);
}

int n , m , Q , vis[5005][5005];
pii tag[5005][5005];
char dw[5005][5005] , ri[5005][5005];

int ans , col , lv;
void dfs(int x , int y , int c) {
	if(vis[x][y] || !c) return;
	vis[x][y] = 1;
	if(tag[x][y].sc) {
		if(tag[x][y].sc <= lv && tag[x][y].fs != col) ans ++;
		return;
	}
	ans ++;
	if(x > 1 && (dw[x - 1][y] - '0' == c)) dfs(x - 1 , y , dw[x - 1][y] - '0'); 
	if(x < n && ((dw[x][y] - '0' == c))) dfs(x + 1 , y , dw[x + 1][y] - '0');
	if(y > 1 && (ri[x][y - 1] - '0' == c)) dfs(x , y - 1 , ri[x][y - 1] - '0');
	if(y < m && (ri[x][y] - '0' == c)) dfs(x , y + 1 , ri[x][y] - '0');
} 

void calc_Row(int x , int y) {
	int tx = x , ty = y;
	while(y < n && ri[x][y] - '0' == 2) {
		y ++;
		if(tag[x][y].sc) {
			if(tag[x][y].sc <= lv && tag[x][y].fs != col) ans ++;
			break;
		}
		ans ++;
	}
	x = tx , y = ty;
	while(y > 1 && ri[x][y - 1] - '0' == 2) {
		y --;
		if(tag[x][y].sc) {
			if(tag[x][y].sc <= lv && tag[x][y].fs != col) ans ++;
			break;
		}
		ans ++;
	}
	x = tx , y = ty;
	while(x > 1 && dw[x - 1][y] - '0' == 2) {
		x --;
		if(tag[x][y].sc) {
			if(tag[x][y].sc <= lv && tag[x][y].fs != col) ans ++;
			break;
		}
		ans ++;
	}
	x = tx , y = ty;
	while(x < n && dw[x][y] - '0' == 2) {
		x ++;
		if(tag[x][y].sc) {
			if(tag[x][y].sc <= lv && tag[x][y].fs != col) ans ++;
			break;
		}
		ans ++;
	}
}

int main() {
	freopen("chess.in" , "r" , stdin);
	freopen("chess.out" , "w" , stdout);
	int T;
	read(T);
	while(T -- > 0) {
		read(n),read(m),read(Q);
		for (int i = 1; i <= n; ++i) scanf("%s" , ri[i] + 1);
		for (int i = 1; i < m; ++i) scanf("%s" , dw[i] + 1);
		while(Q -- > 0) {
			int x , y;
			read(col),read(lv),read(x),read(y);
			dfs(x , y , 3);
//			ans --;
			calc_Row(x , y);
			write(ans);
			tag[x][y] = mp(col , lv);
			for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) vis[i][j] = 0;
		}  
		memset(tag , 0 , sizeof tag);
	}
	return 0;
}
