#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
const int N = 2e2 + 10;
const ll Mod = 998244353;
ll dp[N][200002],val[N];
ll Pow[N];
int n,m,k;


int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0;i <= m;i++) cin >> val[i];
	if(m <= 12) {
		Pow[0] = 1;
		for(int i = 1;i <= m;i++) Pow[i] = Pow[i - 1] * 2 % Mod;
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= Pow[m] * i;j++) {
				for(int t = 0;t <= min(j,m) && Pow[t] <= j;t++) {
					(dp[i][j] += dp[i - 1][j - Pow[t]] * val[t] % Mod) %= Mod; 
				}
			}
		}
		ll ans = 0;
		for(int i = n;i <= Pow[m] * n;i++) {
			int s = i,tot = 0;
			while(s) {
				if(s & 1) tot++;
				s >>= 1;
			}
			if(tot <= k) (ans += dp[n][i]) %= Mod;
		}
		cout << ans << '\n';
	} else cout << "0\n";
	return 0;
}
