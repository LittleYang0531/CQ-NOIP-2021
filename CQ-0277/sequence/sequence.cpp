#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m, k, v[105], ans, mem[35][150005];
ll count(int x){
	ll res = 0;
	while(x != 0){
		res += x & 1;
		x >>= 1;
	}
	return res;
}
ll dfs(ll id, ll cnt){
//	printf("%d %d\n", id, cnt);
	if (id == 0){
		if (cnt == 0) return 1;
		else return 0;
	}
	if (mem[id][cnt] != -1) return mem[id][cnt];
	ll res = 0;
	for (int i = 0; i <= m && cnt - (1 << i) >= 0; i++)
		res = (res + (dfs(id - 1, cnt - (1 << i)) * v[i]) % mod) % mod;
	return mem[id][cnt] = res;
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	memset(mem, -1, sizeof(mem));
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%lld", &v[i]);
	for (int i = n; i <= (1 << m) * n; i++)
		if (count(i) <= k)
			ans = (ans + dfs(n, i)) % mod;
	printf("%lld", ans);
	return 0;
}
