#include <bits/stdc++.h>
#define ll long long
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b
#define pow(a) a * a
const int N = 10000;
int n, a[N + 1], num[N + 1];
inline int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
inline void yue(int &a, int &b) {int t = gcd(a, b);a /= t, b /= t;}
inline void yue(ll &a, int &b) {int t = gcd(a, b);a /= t, b /= t;}
inline int find() {
	int sum = 0, t = n; ll ans = 0;
	for (int i = 1; i <= n; i++) 
		sum += num[i];
	yue(sum, t);
	for (int i = 1; i <= n; i++) 
		ans += pow(t * num[i] - sum);
	t = pow(t);
	yue(ans, t);
	return ans;
}
int main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    
    srand((unsigned)(time(0)));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	int ans = 1e9;
	find();
	for (int i = 2; i < n; i++) {
		num[i] = num[i - 1]  + num[i + 1] - num[i];
		ans = min(ans, find());
	}
    printf("%d\n", ans);
    
	return 0;
}

