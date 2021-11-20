#include <set>
#include <map>
#include <cmath>
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
bool p[11000005];
vector <int> G;
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	for (int i = 1; i <= 11000000; i++) {
		if (p[i]) continue;
		int x = i, flag = 0;
		while (x) {
			if (x % 10 == 7) {
				flag = 1;
				break;
			}
			x /= 10;
		}
		if (flag) {
			p[i] = 1;
			for (int j = i; j <= 11000000; j += i) p[j] = 1;
		}
	} 
	for (int i = 1; i <= 11000000; i++) if (p[i] == 0) G.push_back(i);
	int T = read ();
	while (T--) {
		int n = read ();
		int q = lower_bound (G.begin(), G.end(), n) - G.begin();
		if (G[q] != n) printf ("-1\n");
		else write (G[q+1]), putchar ('\n'); 
	}
	return 0;
}
/*
好，确定了最后一道题不可做
第一题的话应该是有什么规律
首先，如何去判断一个数是否是可以选的，打表找规律
总共763407可以选的 

sb题，出题人良心， 
*/
