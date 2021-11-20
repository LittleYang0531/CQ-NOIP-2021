#include <bits/stdc++.h>

namespace Solve {
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	int const A = 1e7 + 10;
	
	bool is[A + 1];
	int next[A + 1];
	
	bool check(int x) {
		while (x) {
			if (x % 10 == 7) {
				return true;
			}
			
			x /= 10;
		}
		
		return false;
	}
	
	void main() {
		for (int i = 1; i <= A; i++) {
			if (!is[i] && check(i)) {
				is[i] = true;
				
				for (int j = 2; i * j <= A; j++) {
					is[i * j] = true;
				}
			}
		}
		
		int last = 0;
		for (int i = A; i >= 1; i--) {
			next[i] = last;
			
			if (!is[i]) {
				last = i;
			}
		}
		
		int t;
		std::cin >> t;
		
		for (int i = 1; i <= t; i++) {
			int x;
			std::cin >> x;
			
			if (is[x]) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout << next[x] << '\n';
			}
		}
	}
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	Solve::main();
	
	return 0;
}
