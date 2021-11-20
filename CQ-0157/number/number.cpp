#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e7 + 10;

int t, n, cnt, pr[MAXN], ind[MAXN];
bool vis[MAXN];

bool check(int x) {
	
	while (x) {
		int tmp = x % 10;
		x /= 10;
		if (tmp == 7) return 1;
	}
	
	return 0;
	
}

void init() {
	
	for (int i = 1; i <= 1e7 + 5; i++) {
		
		if (vis[i]) continue;
		if (!check(i)) {
			pr[++cnt] = i;
			ind[i] = cnt;
			continue;
		}
		
		for (int j = 1; j * i <= 1e7 + 5; j++) {
				
			vis[i * j] = 1;
			
		}
		
	}
	
}

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	init();
//	for (int i = 1; i <= 100; i++) {
//		printf("%d ", pr[i]);
//	}
//	printf("\n");
//	printf("%d\n", cnt);
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &n);
		
		if (vis[n]) {
			printf("-1\n");
		} else {
			printf("%d\n", pr[ind[n] + 1]);
		}
		
	}
	
	return 0;
}
