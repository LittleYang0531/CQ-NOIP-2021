#include <bits/stdc++.h>
using namespace std;
long long n;
//long long tot, kk[100005], book[100005][57];
long long a[10007], cnt, ans = 1e9 + 7, ans1 = 1e9 + 7;
void dfs(long long k, long long step) {
////			cout << step << "! ";
//			if(step > 100000) return; 
//			tot++;
//			kk[tot] = step;
//			for(long long i = 1; i <= n; i++) {
//				book[tot][i] = a[i];
//			}
//			for(long long i = 1; i < tot; i++) {
//				bool flag = 1;
//				for(long long j = 1; j <= n; j++) {
//					if(book[i][j] != a[i]) {
//						flag = 0;
//						break;
//					}
//				}
//				if(flag) {
//					cout << kk[i] << "!!!!!!!!!!" << endl;
//					return;
//				}
//			}
//			for(int i = 1; i < tot; i++) {
//				for(int j = 1; j <= n; j++) {cout << book[i][j] << " @";
//				}
//				cout << endl;
//			}
//			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	if(step > n) return;
	cnt = ans1 = 0;
	for(long long i = 1; i <= n; i++) {
		cnt += a[i];
	}
//	cout << cnt << endl;
	for(long long i = 1; i <= n; i++) {
		ans1 += (n * a[i] - cnt) * (n * a[i] - cnt);
	}
//		cout << ans << " " << ans1 << endl;
	if(ans > ans1) ans = ans1;
//		cout << step << "  ";
//		for(int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
//	if(ans == 59865) {
//		cout << step << "  ";
//		for(int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
//		return;
//	} 
//	if(step >= 2 * n) {
//		return;
//	}
	for(long long i = 2; i < n; i++) {
		if(i != k && a[i - 1] + a[i + 1] != 2 * a[i]) {
			long long t = a[i];
			a[i] = a[i - 1] + a[i + 1] - a[i]; 
			dfs(i, step + 1);
			a[i] = t;
		} 
	}
//	if(k == 2) {
//		a[3] = a[2] + a[4] - a[3];
//		dfs(3, step + 1);
//	}
//	else if(k == n - 1) {
//		a[n - 2] = a[n - 1] + a[n - 3] - a[n - 2];
//		dfs(n - 2, step + 1);
//	}
//	else {
//		
//		long long t = a[k + 1];
//		a[k + 1] = a[k] + a[k + 2] - t;
//		dfs(k + 1, step + 1);
//		a[k + 1] = t;
//		t = a[k - 1];
//		a[k - 1] = a[k] + a[k - 2] - t;
//		dfs(k - 1, step + 1);
//		a[k - 1] = t;
//	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
//		cin >> a[i];
//		cout << a[i] << " ";
	}
//	for(long long i = 2; i < n; i++) {
//		long long t = a[i];
//		a[i] = a[i - 1] + a[i + 1] - t;
//		dfs(i, 1);
//		a[i] = t;
//	}
	dfs(1, 0);
	cout << ans / n;
	return 0;
}
