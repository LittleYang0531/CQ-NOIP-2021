#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
int n,m;
int a[N];
ll ans = 2e18 ,sum = 0;


int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll s1 = 0,S = 0;
	for(int i = 1;i <= n;i++) {
		S += a[i];
		s1 = s1 + 1ll * n * a[i] * a[i];
	}
	ans = min(ans,s1 - S * S);
	for(int t = 1;t <= 50000000 / n;t++) {
		if(t % 2 == 0)
		for(int i = 2;i <= n - 1;i++) {
			if(1ll * (a[i + 1] + a[i - 1] - a[i] * 2) * ( -sum * 2 + 2 * a[i] + (n - 1) * (a[i + 1] + a[i - 1])) < 0) {
				sum = sum - a[i] * 2 + a[i + 1] + a[i - 1];
				a[i] = a[i + 1] + a[i - 1] - a[i];
			}
		}
		else {
			for(int i = n - 1;i >= 2;i--) {
				if(1ll * (a[i + 1] + a[i - 1] - a[i] * 2) * ( - sum * 2 + 2 * a[i] + (n - 1) * (a[i + 1] + a[i - 1])) < 0) {
					sum = sum - a[i] * 2 + a[i + 1] + a[i - 1];
					a[i] = a[i + 1] + a[i - 1] - a[i];
				}
			}
		}
		s1 = 0,S = 0;
		for(int i = 1;i <= n;i++) {
			S += a[i];
			s1 = s1 + 1ll * n * a[i] * a[i];
		}
		ans = min(ans,s1 - S * S);
	}
	cout << ans << '\n';
	return 0;
}
