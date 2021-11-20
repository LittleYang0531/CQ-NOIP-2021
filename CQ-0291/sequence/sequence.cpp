#include <bits/stdc++.h> 

using namespace std;

int n, m, k, ans = 0;
int arr[105];
int temp[35];

void dfs(int id) {
	if (id == n + 1) {
		long long num = 0, cnt = 0, num_ = 0;
		for (int i = 1; i <= n; i ++)
			num += (1 << temp[i]);
		num_ = num;
		while (num) {
			if (num & 1) cnt ++;
			num >>= 1;
		}
		if (cnt <= k) {
			long long ans_ = 1;
			for (int i = 1; i <= n; i ++) ans_ = (ans_ * arr[temp[i]]) % 99824353;
			ans = (ans + ans_) % 99824353;
		}
	}
	else for (int i = 0; i <= m; i ++) {
		temp[id] = i;
		dfs(id + 1);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; i ++) scanf("%d", &arr[i]);
	dfs(1);
	printf("%d", ans);
	return 0;
}
