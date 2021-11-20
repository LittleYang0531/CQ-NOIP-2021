#include <stdio.h>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
const int N = 10005, MARK = 20000005;
const int seed = 107, seed2 = 998244353, inf = 0x3f3f3f3f;

int n, ans = inf;
int a[N];
bool mark1[MARK], mark2[MARK];

int square(int x) {
	return x * x;	
} 

int gethash1(int x[]) {
	unsigned int ans = 0;
	for (int i = 1; i <= n; i++) ans = seed * x[i] + ans & ((1 << 20) - 1);
	return ans;
}
int gethash2(int x[]) {
	unsigned int ans = 0;
	for (int i = 1; i <= n; i++) ans = seed2 * x[i] + ans & ((1 << 20) - 1);
	return ans;
}

int getans(int x[]) {
	int sum = 0, ans = 0, down = n;
	for (int i = 1; i <= n; i++) sum += x[i];
	for (int i = 1; i <= n; i++) ans += square(n * x[i] - sum);
	return ans / n;
}

void dfs(int x[]) {
	ans = min(ans, getans(x));
	for (int i = 2; i < n; i++) {
		int temp = x[i];
		x[i] = x[i - 1] + x[i + 1] - x[i];
		int temp1 = gethash1(x), temp2 = gethash2(x);
		if (mark1[temp1] && mark2[temp2]) {
			x[i] = temp;                                                                                                     
			continue;
		} else mark1[temp1] = true, mark2[temp2] = true, dfs(x);
		x[i] = temp;
	}
}

signed main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	mark1[gethash1(a)] = true, mark2[gethash2(a)] = true;
	dfs(a);
	printf("%lld", ans);
	return 0;
}
