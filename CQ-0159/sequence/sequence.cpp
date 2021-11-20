#include <bits/stdc++.h>

namespace Solve {
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	int const N = 40;
	int const K = N;
	int const M = 110;
	int const MOD = 998244353;

	int val[M + 1];
	int n, m, k;
	
	namespace BF {
		int const N = 30;
		int const M = 18;
		
		int dp[N + 1][1 << M];
		
		void main() {
			int t = n * (1 << m);
			int smax = ((t & (-t)) << 1) - 1;
			t -= t & (-t);
			
			while (t) {
				smax = std::max(smax, ((t & (-t)) << 1) - 1);
				t -= t & (-t);
			}
			
			for (int i = 1; i <= m + 1; i++) {
				dp[1][1 << (i - 1)] = val[i];
			}
			
			for (int i = 2; i <= n; i++) {
				for (int j = 1; j <= m + 1; j++) {
					for (int s = 0; s <= smax; s++) {
						dp[i][s + (1 << (j - 1))] = (dp[i][s + (1 << (j - 1))] + 1ll * dp[i - 1][s] * val[j] % MOD) % MOD;
					}
				}
			}
			
			int ans = 0;
			for (int s = 0; s <= smax; s++) {
				int t = s;
				int cnt = 0;
				while (t) {
					cnt++;
					t -= t & (-t);
				}
				
				if (cnt <= k) {
					ans = (ans + dp[n][s]) % MOD;
				}
			}
			
			std::cout << ans << '\n';
		}
	}
	
	void main() {
		std::cin >> n >> m >> k;
				
		for (int i = 1; i <= m + 1; i++) {
			std::cin >> val[i];
		}
		
		BF::main();
	}
}

signed main() {
	std::cerr << (sizeof (Solve::BF::dp)) / 1024 / 1024 << "\n\n";
	
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	Solve::main();
	
	return 0;
}
