#include <bits/stdc++.h>
using namespace std;
int t,a,n = 11000000;
bool b[11000001];
bool check(int x) {
	while (x > 0) {
		int a = x % 10;
		if (a == 7) return 1;
		x /= 10;
	}
	return 0;
}
void solve() {
	for (int i = 1; i <= n; i ++) {
		if (b[i]) continue;
		if (check(i))
			for (int j = 1; j * i <= n; j ++)
				b[i * j] = 1;
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	solve();
	for (int i = 1; i <= t; i ++) {
		scanf("%d",&a);
		if (b[a]) printf("-1\n");
		else {
			int k = a + 1;
			while (b[k]) k ++;
			printf("%d\n",k);
		}
	}
	return 0;
}
