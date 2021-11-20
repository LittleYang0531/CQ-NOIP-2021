#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int n;
int a[100005], b[100005], lst[100005];

void up (int x) {
	if (x <= 1) return ;
	up (x - 1);
	if (b[x] < (b[x-1] + b[x+1] - b[x])) b[x] = b[x-1] + b[x+1] - b[x];
	return ;
}
void down (int x) {
	if (x >= n) return ;
	down (x + 1);
	if (b[x] > (b[x-1] + b[x+1] - b[x])) b[x] = b[x-1] + b[x+1] - b[x];
	return ;
}
double Te = 1e-15, P = 0.996;
int Ans = 1e9;
void SA () {
	double T = 3000;
	while (T > Te) {
		int x = rand () % n + 1;
		if (x == 1) x++;
		if (x == n) x--;
		for (int j = 1; j <= n; j++) b[j] = a[j];
		b[x] = b[x+1] + b[x-1] - b[x];
		int S = 0, S2 = 0;
		for (int j = 1; j <= n; j++) S += b[j], S2 += b[j] * b[j];
		int nowans = n * S2 - S * S;
		int cha = nowans - Ans;
		if (cha < 0) {
			Ans = nowans;
			for (int j = 1; j <= n; j++) a[j] = b[j];
		}
		else if (exp (1.0 * cha / T) * RAND_MAX > rand ()) {
			for (int j = 1; j <= n; j++) a[j] = b[j];
		}
		T *= P;
	}
}
int main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	srand (time(0));
	n = read ();
	int sum = 0;
	for (int i = 1; i <= n; i++) a[i] = read ();
	for (int i = 1; i <= 300; i++) SA ();
	printf ("%d\n", Ans);
	return 0;
}
/*
15 
6 19 34 35 56 63 82 82 83 99 6 19 34 35 56
一眼看过去就是贪心，先考虑贪心测量，再去看大样例水不水
数据范围给得有点奇怪，可能时间复杂度和值域有关
认真看样例解释，因为它多半在演你

猜结论吧
1.最靠近两边的棋子永远不变（废话） 
2.如果一个操作操作了之后更优，马上操作（猜的）
3.每一个数只会被操作一次 
tmd，a 原来是排序的
题目中 a_i = a_{i+1} 的个数永远的不会变
大家都往平均值上凑 
选一个中间值，让大家都往上面凑，让前面都尽量变大，让后面都尽量变小
操作顺序就成了一个技术活
先考虑前面的 
一个中心原则，从中间点从大到小，一次让他们变到最大
一个递归问题，f(i) 让 i 尽量大 
md，又爆炸了，这次考炸了。。。。
fuckfuckfuckfuckfuck
nmdsb出题人 
*/
