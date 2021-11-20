/*
ѧ����Ҽ����ˣ���ʡ���и��Ҽ����ˣ�LF ���Ҽ����ˣ�������Ҽ����ˣ��������ű���ͬѧ�����Ƕ����Ҽ����ˣ�
��֧�������ˣ��� 
�������Ϲ����������Ϲ����������Ϲ����ҵ�����һ���� 
�ҿ�ʼ������ˣ��������úóԣ�
�Ҳ�����ɽ���Һܵ����� 
�Ұ��������Ұ� CCF
�õģ��ҳ����ˣ��������˿��֡�
��ʼ���⣬���Ĳݸ�ֽ�����治��������ûʲô�������� 
�õģ����������ݰݡ� 
���������
���ް����ӷ���Ҫ�ͷű��������ˣ�ѽ�٣�  
���У��뵽ѧ���Ҿͺ���Ϣ�� 
�õģ������ܳ�ʱ��ķ�������Ҳ��֪����д�˸�ɶ555���¸�ţţ������η�塣 

û�������Ҫ���ң�лл��
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
