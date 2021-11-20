#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

#define LL long long
#define LB long double
#define ULL unsigned long long

int n, a[MAXN];
LL ans = LONG_LONG_MAX; 

pair<LL, ULL> get_val(int *a, int n) {
	LB sum = 0;
	ULL val = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i], val = val * 39993 + a[i];
	val += (LL)sum;
	sum /= n;
	LB ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (a[i] - sum) * (a[i] - sum);
	ans *= n;
	return make_pair((LL)ans, val);
} // 求数组方差 

map<ULL, bool> vis;

inline void dfs(int *a, int k) {
	pair<LL, ULL> g = get_val(a, n);
	if (!vis[g.second]) vis[g.second] = true;
	else return;
	ans = min(ans, g.first);
	for (int i = k + 1; i < n; i++) {
		int tmp = a[i];
		a[i] = a[i + 1] + a[i - 1] - a[i];
		dfs(a, i);
		a[i] = tmp;
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	dfs(a, 1);
	printf("%lld\n", ans);
	return 0;
}

// 哈哈，本来能过样例 2，结果加上 Hash 后 RE 了
// 还改不回去了？ 
// ***
// 撤销找不到（能过 2 的） code 呢，** 
// 5xxxx -> RE -> 8xxxx -> 67609，哈哈 
