#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 1e4 + 5;

int t, x;
bool vis[MAXN];

bool p(int x) {
	while (x) {
		if (x % 10 == 7) return true;
		x /= 10; 
	}
	return false;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 7; i <= MAXN - 5; i++)
		if (!vis[i] && p(i))
			for (int j = 1; i * j <= MAXN - 5; j++)
				vis[i * j] = true;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		if (vis[x]) puts("-1");
		else {
			for (int i = x + 1; i <= MAXN - 5; i++)
				if (!vis[i]) {
					printf("%d\n", i);
					break;
				}
		}
	}
	return 0;
}

// Why this code can pass these data?
// I don't know.
// I think I can't AC.
// 求求啦！！！能 100 分吗！！！ 
