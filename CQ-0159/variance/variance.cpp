#include <bits/stdc++.h>
#define int long long

namespace Solve {
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	int const N = 1e4;
	
	struct State {
		int id;
		int val;
		
		bool operator>(const State &rhs) const {
			if (val == rhs.val) {
				return id > rhs.id;
			}
			else {
				return val > rhs.val;
			}
		}
	};
	
	int n;
	int a[N + 1];
	int change[N + 1];
	int cnt[N + 1];
	int sum;
	int ans;
	
	namespace BF {
		std::map<std::vector<int>, bool> vis;
		int ans = INF;
		
		void dfs(std::vector<int> t) {
			int cur = 0;
			int sum = 0;
			vis[t] = true;
			
			for (auto v : t) {
				sum += v;
				cur += v * v;
			}
			
			cur = n * cur - sum * sum;
			ans = std::min(ans, cur);
			
			for (int i = 1; i + 1 < n; i++) {
				int p = t[i];
				t[i] = t[i - 1] + t[i + 1] - t[i];
				if (!vis.count(t)) {
					dfs(t);
				}
				
				t[i] = p;
			}
		}
		
		void main() {
			std::vector<int> t(n);
			for (int i = 0; i < n; i++) {
				t[i] = a[i + 1];
			}
			
			dfs(t);
			std::cout << ans << '\n';
		}
	}
	
	void main() {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			sum += a[i];
			
			ans += a[i] * a[i];
		}
		
		ans = n * ans - sum * sum;
		
		if (n <= 20) {
			BF::main();
			return;
		}
		
//		std::priority_queue<State> heap;
//		for (int i = 2; i < n; i++) {
//			int d = a[i - 1] + a[i + 1] - a[i] - a[i];
//			
//			if (d) {
//				change[i] = n * 2 * a[i] * d + (n - 1) * d * d;
//				heap.push({ i, change[i] });
//			}
//		}
//		
//		int res = ans;
//		while (!heap.empty()) {
//			auto top = heap.top();
//			heap.pop();
//			
//			if (change[top.id] == top.val && (top.val <= 0 || (top.val > 0 && cnt[top.id] <= n))) {
//				if (top.val > 0) {
//					cnt[top.id]++;
//				}
//				
//				int i = top.id;
//				ans += change[i];
//				sum -= a[i];
//				a[i] = a[i - 1] + a[i + 1] - a[i];
//				sum += a[i];
//				
//				res = std::min(res, ans);
//				
//				if (i - 1 != 1) {
//					int d = a[i - 2] + a[i] - a[i - 1] - a[i - 1];
//			
//					if (d) {
//						change[i - 1] = -2 * sum * d + n * 2 * a[i - 1] * d + (n - 1) * d * d;
//						heap.push({ i - 1, change[i - 1] });	
//					}
//				}
//				
//				if (i + 1 != n) {
//					int d = a[i] + a[i + 2] - a[i + 1] - a[i + 1];
//			
//					if (d) {
//						change[i + 1] = -2 * sum * d + n * 2 * a[i + 1] * d + (n - 1) * d * d;
//						heap.push({ i + 1, change[i + 1] });	
//					}
//				}
//				
//				int d = a[i - 1] + a[i + 1] - a[i] - a[i];
//				
//				if (d) {
//					change[i] = -2 * sum * d + n * 2 * a[i] * d + (n - 1) * d * d;
//					heap.push({ i, change[i] });
//				}
//			}
//		}
//		
//		std::cout << ans << '\n';
	}
}

signed main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	Solve::main();
	
	return 0;
}
