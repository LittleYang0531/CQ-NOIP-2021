#include<bits/stdc++.h>
const int N = 1e7 + 10;
using namespace std;
int t, bol[N];
int OK(int n) {
	int num = 1;
	while(true) {
		int flg = 0; if(bol[n]) flg = 1;
		for(int i = 1; i * i <= n && !flg; ++i) {
			if(n % i) continue;
			int x = i, y = n / i;
			if(bol[x] || bol[y]) bol[n] = 1, flg = 1;
		}
		if(flg && num == 1) return -1;
		if(!flg && num > 1) return n; ++n; ++num;
	}
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= N - 10; ++i) {
		int x = i;
		while(x && !bol[i]) {
			if(x % 10 == 7) bol[i] = 1;
			x /= 10;
		} if(bol[i]) continue;
	}
	while(t--) {
		int n; scanf("%d", &n);
		printf("%d\n", OK(n));
	}
	return 0;
}
// (o)  (o)
// ||   ||
// || _ || (±¬Áã¿ìÀÖ)
//I LOVE(F***) NOIP!!!
//I want to ac this problem, but it is only my dream.  :-(
