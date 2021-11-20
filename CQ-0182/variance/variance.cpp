#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define uint unsigned int
using namespace std;
const int MAXN = 1e4 + 5;
int n, a[MAXN], t, tmp[MAXN], maxx, qwq;
bool vis[10000005];
LL res = 9e18, ans, c;
LL Min(LL x, LL y) { return x < y ? x : y; }
void dfs() {
	t = 0; ans = 0; c = 0; qwq ++;
//	if(qwq >= 2e7) printf("%d}", qwq);
	if(qwq >= 1e7 / n) return;
	for(int i = 1; i <= n; i ++) {
//		printf("%d ", tmp[i]);
		t = t * (maxx + 1) + tmp[i]; ans += tmp[i]; c += tmp[i] * tmp[i];
	}
//	printf("\n");
	if(n <= 7 && vis[t]) return;
	res = Min(res, n * c - ans * ans);
	if(n <= 7) vis[t] = 1;
	for(int i = 2; i < n; i ++) {
		if(n <= 5) {
			int cc[7];
			for(int j = 1; j <= n; j ++) cc[j] = tmp[j];
			tmp[i] = tmp[i - 1] + tmp[i + 1] - tmp[i];
			dfs();
			for(int j = 1; j <= n; j ++) tmp[j] = cc[j];
		}
		if(n <= 10) {
			int cc[12];
			for(int j = 1; j <= n; j ++) cc[j] = tmp[j];
			tmp[i] = tmp[i - 1] + tmp[i + 1] - tmp[i];
			dfs();
			for(int j = 1; j <= n; j ++) tmp[j] = cc[j];
		}
		if(n <= 15) {
			int cc[17];
			for(int j = 1; j <= n; j ++) cc[j] = tmp[j];
			tmp[i] = tmp[i - 1] + tmp[i + 1] - tmp[i];
			dfs();
			for(int j = 1; j <= n; j ++) tmp[j] = cc[j];
		}
		if(n <= 20) {
			int cc[22];
			for(int j = 1; j <= n; j ++) cc[j] = tmp[j];
			tmp[i] = tmp[i - 1] + tmp[i + 1] - tmp[i];
			dfs();
			for(int j = 1; j <= n; j ++) tmp[j] = cc[j];
		}
		else {
			int cc[55];
			for(int j = 1; j <= n; j ++) cc[j] = tmp[j];
			tmp[i] = tmp[i - 1] + tmp[i + 1] - tmp[i];
			dfs();
			for(int j = 1; j <= n; j ++) tmp[j] = cc[j];
		}
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), maxx = max(maxx, a[i]);
	if(n == 1) {
		printf("%d", 0); return 0;
	}
	if(n == 2) {
		printf("%d", n * (a[1] * a[1] + a[2] * a[2]) - (a[1] + a[2]) * (a[1] + a[2]));
		return 0;
	}
	//if(n <= 6) {
		for(int i = 1; i <= n; i ++) tmp[i] = a[i];
		dfs(); printf("%lld", res);
	//}
	return 0;
}

