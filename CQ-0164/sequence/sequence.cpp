#include <stdio.h>

typedef long long ll;

const int mod = 998244353;
int n, m, k;
int v[107];
ll power[107]; 

inline ll lowbit(ll x){
	return x & (-x);
}

inline int popcount(ll n){
	int ans = 0;
	while (n){
		ans++;
		n -= lowbit(n);
	}
	return ans;
}

int dfs(int cur, ll val){
	if (cur > n) return popcount(val) <= k;
	int cur_i = cur + 1, ans = 0;
	for (register int i = 0; i <= m; i++){
		ans += 1ll * v[i] * dfs(cur_i, val + power[i]) % mod;;
		if (ans >= mod) ans -= mod;
	}
	return ans;
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (register int i = 0; i <= m; i++){
		scanf("%d", &v[i]);
		power[i] = 1ll << i;
	}
	printf("%d", dfs(1, 0));
	return 0;
}
