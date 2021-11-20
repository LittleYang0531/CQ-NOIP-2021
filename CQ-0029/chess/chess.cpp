/*
学姐给我加油了，外省大佬给我加油了，LF 给我加油了，爸妈给我加油了，神奇张张便宜同学室友们都给我加油了，
我支棱起来了！！ 
我稳如老狗，我稳如老狗，我稳如老狗，我淡定得一批。 
我开始吃面包了，玉米粒好好吃，
我不动如山，我很淡定。 
我爱暴力，我爱 CCF
好的，我吃完了，并戴上了口罩。
开始看题，发的草稿纸质量真不戳，但是没什么用诶。。 
好的，看不懂，拜拜。 
阴间玩意儿
南无阿弥陀佛，我要释放暴力大招了！呀嘿！  
不行，想到学姐我就好窒息。 
好的，经过很长时间的发功，我也不知道我写了个啥555。勇敢牛牛，无所畏惧。 

没有整活，不要挂我，谢谢。
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5005, M = 2e5 + 5;
int T, n, m, q, cnt, col, lv, xx, yy, rel[M], rel2[M], C[M], V[M];
char s[N][N], maap[M];
int pos(int x, int y) {
	return (x - 1) * m + y;
}
bool tag[5];
inline void read(int &x) {
	x = 0;
	char s= getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
}
inline void query() {
	int res = 0, x = pos(xx, yy), tx;
	tx = x + 1;
	if(rel[x] && xx < m && V[tx] <= lv && C[tx] != col) res ++;
	tx = x + m;
	if(rel2[x] && yy < n && V[tx] <= lv && C[tx] != col) res ++;
	tx = x - 1;
	if(rel[tx] && xx && V[tx] <= lv && C[tx] != col) res ++;
	tx = x - m;
	if(rel2[tx] && yy && V[tx] <= lv && C[tx] != col) res ++;
	printf("%d\n", res);
	V[x] = lv, C[x] = col;
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	read(T);
	while(T --) {
		cnt = 0;
		memset(tag, 0, sizeof(tag));
		memset(C, -1, sizeof(C));
		memset(V, -1, sizeof(V));
		read(n), read(m), read(q);
		if(n <= 5000 && m <= 5000) {
			for(int i = 1; i <= n; i ++) {
				scanf("%s", s[i] + 1);
			}
			while(q --) {
				read(col), read(lv), read(col), read(q);
				 
			}
		}
		else {
			for(int i = 1; i <= n; i ++) {
				scanf("%s", maap + 1);
				for(int j = 1; j < m; j ++) {
					rel[pos(i, j)] = maap[j] - '0';
					tag[rel[pos(i, j)]] = 1;
				}
			}
			for(int i = 1; i < n; i ++) {
				scanf("%s", maap + 1);
				for(int j = 1; j <= m; j ++) {
					rel2[pos(i, j)] = maap[j] - '0';
					tag[rel2[pos(i, j)]] = 1;
				}
			}
			if(!tag[2] && !tag[3]) {
				while(q --) {
					read(col), read(lv), read(col), read(q);
					query();
				}
			}
		}
	} 
	return 0;
}
