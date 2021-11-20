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
һ�ۿ���ȥ����̰�ģ��ȿ���̰�Ĳ�������ȥ��������ˮ��ˮ
���ݷ�Χ�����е���֣�����ʱ�临�ӶȺ�ֵ���й�
���濴�������ͣ���Ϊ�����������

�½��۰�
1.������ߵ�������Զ���䣨�ϻ��� 
2.���һ������������֮����ţ����ϲ������µģ�
3.ÿһ����ֻ�ᱻ����һ�� 
tmd��a ԭ���������
��Ŀ�� a_i = a_{i+1} �ĸ�����Զ�Ĳ����
��Ҷ���ƽ��ֵ�ϴ� 
ѡһ���м�ֵ���ô�Ҷ�������գ���ǰ�涼��������ú��涼������С
����˳��ͳ���һ��������
�ȿ���ǰ��� 
һ������ԭ�򣬴��м��Ӵ�С��һ�������Ǳ䵽���
һ���ݹ����⣬f(i) �� i ������ 
md���ֱ�ը�ˣ���ο�ը�ˡ�������
fuckfuckfuckfuckfuck
nmdsb������ 
*/
