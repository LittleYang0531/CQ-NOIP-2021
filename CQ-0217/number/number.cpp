#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#define pii pair<int, int>
#define make make_pair
#define ll long long
using namespace std;
const int lim = 10000000;

int T;
bool mark[lim + 5];
int nxt[lim + 5];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= lim; i++) {
		if (mark[i]) continue;
		bool flag = false;
		int temp = i;
		while (temp) {
			if (temp % 10 == 7) {
				flag = true;
				break;
			} else temp /= 10;
		}
		if (flag) 
			for (int j = i; j <= lim; j += i) 
				mark[j] = true;
	}
	for (int i = 1; i <= lim;) {
		int temp = i;
		if (mark[i]) continue;
		i++;
		while (mark[i] && i <= lim) i++;
		nxt[temp] = i;
	}
	while (T--) {
		int x;
		scanf("%d", &x);
		if (mark[x]) puts("-1");
		else printf("%d\n", nxt[x]);
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
