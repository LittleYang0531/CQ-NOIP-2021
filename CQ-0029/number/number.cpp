/*
ĪҪ��ĪҪ�ţ�����Ҫ���Ҳ��š�
��Ҫ������������Ҫ�Ų�Ҫ�Ų�Ҫ��
�����������������˲�Ҫ�� 
������⣬ʱ����պã���Ҫ�ţ��� 
�����Ҹ������أ����ܻŲ��ܻ�
��Ҫ��ѧ���ˣ�����
�ҿ����ȥ��Ҫʹ��ѧ��Ĳ��������Ϊ������ 

û�������Ҫ���ң�лл��
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5, M = 1e7 + 5;
int T, q[N], mx, id[M], ans[M], tot, res;
bool tag[M];
inline bool check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
inline void solve() {
	for(int i = 1; i < M; i ++) {
		if(tag[i]) continue;
		if(i % 7 == 0 || check(i)) {
			tag[i] = 1;
			for(int j = 1; ; j ++) {
				if(i * j < M)tag[i * j] = 1;
				if(i * j > mx) break;
			}
		}
		if(!tag[i] && i > mx) break;
	}
}
inline void read(int &x) {
	x = 0;
	char s= getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
}
inline void write(int x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10), x %= 10;
	putchar(x + '0');
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	read(T);
	for(int i = 1; i <= T; i ++) {
		read(q[i]), mx = max(q[i], mx);
	}
	solve();
	for(int i = 1; i < M; i ++) {
		if(!tag[i]) ans[++tot] = i, id[i] = tot;
		if(ans[tot] > mx) break;
	}
	for(int i = 1; i <= T; i ++) {
		if(tag[q[i]]) puts("-1");
		else write(ans[id[q[i]] + 1]), puts("");
	}
	return 0;
} 

/*

4
6
33
69
300

*/
