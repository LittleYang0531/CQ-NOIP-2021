#include <bits/stdc++.h>
using namespace std;
int n,m,k,K,s[101],q[110];
const long long Mod = 998244353;
long long ans,v[101];
long long Qsm(long long a,int b) {
	long long shu = a,res = 1ll;
	while (b) {
		if (b % 2) res = res * shu % Mod;
		shu = shu * shu % Mod;
		b = b / 2;
	}
	return res;
}
void dfs(int i,int kk) {
	if (i == n + 1) {
		if (kk != K) return ;
		long long res = 1;
		for (int j = 0; j <= m; j ++)
			res = (res * Qsm(v[j],s[j])) % Mod;
		ans = (ans + res) % Mod;
		return ;
	}
	for (int j = 0; j <= m; j ++) {
		int kkk = kk,ij = j;
		s[j] ++;
		while (q[ij] == 1) q[ij] = 0,kk --,ij ++;
		q[ij] = 1,kk ++;
		dfs(i + 1,kk);
		s[j] --;
		kk = kkk;
		q[ij --] = 0;
		while (q[ij] == 0 && ij >= j) q[ij] = 1,ij --;
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0; i <= m; i ++) scanf("%lld",&v[i]);
	for (K = 1; K <= k; K ++)
		for (int j = 0; j <= m; j ++) {
			s[j] = 1;
			q[j] = 1;
			dfs(2,1);
			s[j] = 0;
			q[j] = 0;
		}
	printf("%lld",ans);
	return 0;
}
