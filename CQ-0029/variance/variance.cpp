/*
我再也不在日记里乱花痴学姐了，我再也不乱叫老婆了
社死太痛苦了。
啊啊啊不能慌，不能慌，不能慌。
我现在稳如老狗，就是肚皮有点饿。
我稳如老狗，我稳如老狗，我稳如老狗，我淡定得一批。 
我爱暴力，我爱CCF
我只是在自我疏导，没有整活 

没有整活，不要挂我，谢谢。 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
int n, a[N], b[N], c[N], l[N], cnt;
ll ans = 1e12;
bool vis[N];
inline void dfs(int x) {
	if(x == cnt) {
		ll sum = 0, res = 0;
		for(int i = 1; i <= n; i ++) b[i] = a[i];
		for(int i = 1; i <= cnt; i ++) {
			b[l[i]] = b[l[i] - 1] + b[l[i] + 1] - b[l[i]];
		}
		for(int i = 1; i <= n; i ++) sum += b[i];
		for(int i = 1; i <= n; i ++) {
			res += (b[i] * n - sum) * (b[i] * n - sum);
		}
		res /= n;
		ans = min(ans, res);
		return;
	}
	for(int i = 1; i <= cnt; i ++) {
		if(vis[i]) continue;
		vis[i] = 1, l[x + 1] = c[i];
		dfs(x  + 1);
		vis[i] = 0; 
	}
} 
inline void solve(int x) {
	cnt = 0;
	for(int i = 0; i < n; i ++) {
		if(x & (1 << i)) {
			c[++cnt] = i + 1;
			if(i == 0 || i == n - 1) return;
		}
	}
	memset(vis, 0, sizeof(vis));
	dfs(0);
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 0; i < (1 << n); i ++) solve(i);
	printf("%lld", ans);
	return 0;
}
