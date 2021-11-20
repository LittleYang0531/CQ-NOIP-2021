/*
或许可以尝试写一个类似于线性筛的东西
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
int ban[N], num, ok[N], cnt;
int n, ans, pri[N], tot;
bool vis[N], sig[N];
inline int read() {
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch > '9') {if (ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
inline bool check(int k) {
	while (k) {
		if (k % 10 == 7) return 1;
		k /= 10;
	}
	return 0;
}
inline void prime() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) pri[++tot] = i;
		for (int j = 1; j <= tot && pri[j] * i < N; ++j) {
			vis[pri[j] * i] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 2; i < N; ++i) {
		if ((!sig[i] && check(i)) || sig[i]) {
			ban[++num] = i; sig[i] = 1;
			for (int j = 1; j <= tot && pri[j] * i < N; ++j) {
				sig[pri[j] * i] = 1;
				//if (i % pri[j] == 0) break;
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		if (!sig[i]) ok[++cnt] = i;
	}
}
inline void mian() {
	n = read();
	if (sig[n]) {printf("-1\n"); return ;}
	ans = *upper_bound(ok + 1, ok + 1 + cnt, n);
	printf("%d\n", ans);
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	prime();
	int t = read();
	while (t--) mian();
	return 0;
}
