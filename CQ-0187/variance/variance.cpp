#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;
int n, a[N], vst[N];
long long ans;
void dfs() {
	
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += n * a[i] * a[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) ans -= a[i] * a[j];
	}
//	dfs();
	printf("%lld", ans);
	return 0;
}
