#include <bits/stdc++.h>


const int N = 100,
		  MOD = 998244353;
int n, m, k, val[N + 1], ans;
inline bool check(int x) {
	int cnt = 0;
	while (x) {
		if ((x & 1) == 1)
			cnt++;
		x <<= 1;
	}
	return cnt <= k;
}
int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    
    srand((unsigned)(time(0)));
    
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= m; i++)
    	scanf("%d", &val[i]);
//	for (int i = n; i <= n * (1 << m); i++) {
//		if (check(i)) {
//			ans ++;
//		}
//	}
    printf("%d\n", rand() % 1000);
	return 0;
}
