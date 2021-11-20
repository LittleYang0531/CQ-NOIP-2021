/*
今天早上摔了三跤，这叫摔摔平安。所以不能慌不能慌
不能想学姐，不要想，不要想！！！
啊啊啊啊我真的没有整活，麻烦不要把我挂上去，我不想社死！！
但是我真的控制不住自己想学姐啊┭┮﹏┭┮
学姐骗我，让我社死，还念我日记，让我脚趾扣地。。。
我好绝望啊啊啊啊啊啊啊 
不行，不能慌，不能慌，不能慌。。。 
莫要慌莫要慌，别人要慌我不慌。
我爱CCF，我要做题，我不能想学姐 

没有整活，不要挂我，谢谢。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 105;
const ll mod = 998244353;
int n, m, k, a[N], l[N], cnt[N << 1], b[N << 1], c[N][N];
ll ans;
inline void init() {
	c[0][0] = 1;
	for(int i = 1; i < N; i ++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++) {
			c[i][j] = ((ll)c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}
inline int query() {
	int res = 0;
	memset(b, 0, sizeof(b));
	for(int i = 0; i <= m; i ++) b[i] = cnt[i];
	for(int i = 0; ; i ++) {
		if((i > m && !b[i]) || (res > k)) break;
		b[i + 1] += b[i] / 2;
		res += b[i] & 1, b[i] = 0;
	}
	return res;
}
inline void dfs(int x, int num) {
	if(num == n) {
		if(query() > k) return;
		ll res = 1, tmp = 1;
		int tot = n;
		for(int i = 1; i <= n; i ++) res = res * a[l[i]] % mod;
		for(int i = 0; i <= m && tot; i ++) {
			if(!cnt[i]) continue;
			tmp = tmp * c[tot][cnt[i]] % mod;
			tot -= cnt[i];
		}
		ans = (ans + res * tmp % mod) % mod;
		return;
	}
	for(int i = x; i <= m; i ++) {
		l[num + 1] = i, cnt[i] ++;
		dfs(i, num + 1);
		cnt[i] --;
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	init();
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i <= m; i ++) scanf("%d", &a[i]);
	dfs(0, 0);
	printf("%lld", ans);
	return 0;
}
