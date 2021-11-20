#include<cstdio>
#include<map>
#include<algorithm>
const int P = 99991, mod = 3e8 + 9;
using namespace std;
typedef long long ll;
int n, a[10005], sum1, sum2, ans = INT_MAX;
bool vis[mod + 5];
int H(int *a){
	ll sum = 0, mul = 1;
	for (int i = 1; i <= n; i++){
		sum = (sum + a[i]) % mod;
		mul = (a[i] * mul) % mod;
	}
	return (sum + mul) % mod;
}
void dfs(int sum1, int sum2){
//	printf("%d %d\n", sum1, sum2);
	if (vis[H(a)]) return;
	vis[H(a)] = 1;
	ans = min(ans, sum2 * n - sum1 * sum1);
	for (int i = 2; i < n; i++){
		int t = a[i];
		a[i] = a[i + 1] + a[i - 1] - a[i];
		if (a[i] != t) 
			dfs(sum1 - t + a[i], sum2 - t * t + a[i] * a[i]);
		a[i] = t;
	}
	return;
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum1 += a[i], sum2 += a[i] * a[i];
	dfs(sum1, sum2);
	printf("%d", ans);
	return 0;
}
