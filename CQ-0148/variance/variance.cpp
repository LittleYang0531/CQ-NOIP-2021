//CJG生日快乐
//CJG一战成冥
//CJGYYDS 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 100000
#define MAXM 600
#define INF 0x7f7f7f7f7f7f7f7f

int s[MAXN + 5];
int snum[MAXM + 5];
int n;
int sa[MAXN + 5];

long long dfs (int l, int m) {
	if (l == 1) {
		long long ans = 0;
		long long sum = 0;
		long long num = 0;
		
		for (int i = 2; i <= n; i ++) {
			num += sa[i];
			ans += num * num;
			sum += num;
		}
		
		return ans * n - sum * sum;
	}
	
	long long smin = INF;
	
	for (int i = 0; i <= m; i ++) {
		if (snum[i]) {
			sa[l] = i;
			snum[i] --;
			smin = min (smin, dfs (l - 1, m));
			snum[i] ++;
		}
	}
	
	return smin;
}
long long dfs2 (int l, int m) {
	long long smin = INF;
	
	for (int i = 1; i < n; i ++) {
		sa[i + 1] = s[i];
	}
	for (int k = 1; k <= 50000000 / n; k ++) {
		if (k == 1) {
			sort (sa + 2, sa + 1 + n);
			for (int i = 1; i <= (n >> 1); i ++) {
				swap (sa[i + 1], sa[n - i]);
			}
		}
		else {
			for (int i = 2; i <= n; i ++) {
				swap (sa[i], sa[rand () % (i - 1) + 2]);
			}
		}
		
		long long ans = 0;
		long long sum = 0;
		long long num = 0;
		
		for (int i = 2; i <= n; i ++) {
			num += sa[i];
			ans += num * num;
			sum += num;
		}
		smin = min (smin, ans * n - sum * sum);
	}
	
	return smin;
}

int main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	
	int smax = 0;
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &s[i]);
	}
	for (int i = n; i >= 1; i --) {
		s[i] -= s[1];
	}
	for (int i = 1; i < n; i ++) {
		s[i] = s[i + 1] - s[i];
		snum[s[i]] ++;
		smax = max (smax, s[i]);
	}
	if (n <= 15) {
		printf ("%lld", dfs (n, smax));
	}
	else {
		sort (s + 1, s + 1 + n);
		
		printf ("%lld", dfs2 (n, smax));
	}
	
	return 0;
}
