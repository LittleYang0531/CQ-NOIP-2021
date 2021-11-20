#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, a[10005], b[10005], tot[10005], ans = 1145141919, pre[10005];
bool visit[10005];
void DFS(int i, int l, int r){
	if(i == 1){
		int t = 0, tt = 0;
		for(int i = 1; i <= n; i++){
			tot[i] += tot[i - 1];
			t += tot[i];
			tt += tot[i] * tot[i]; 
		}
		for(int i = n; i >= 1; i--){
			tot[i] -= tot[i - 1];
		}
		if(ans > n * tt - t * t){
			ans = n * tt - t * t;
			for(int i = 1; i <= n; i++) pre[i] = tot[i];
		}
		return;
	}
	tot[l] = b[i];
	DFS(i - 1, l + 1, r);
	tot[r] = b[i];
	DFS(i - 1, l, r - 1);
	return;
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		b[i] = a[i] - a[i - 1];
	}
	tot[1] = b[1];
	sort(b + 2, b + n + 1);
	DFS(n, 2, n);
	printf("%d\n", ans);
//	for(int i = 1; i <= n; i++) printf("%d ", pre[i]);
	return 0;
}
