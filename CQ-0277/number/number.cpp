#include<bits/stdc++.h>
using namespace std;
int T, m, a[18000005], x;
bool can[18000005];
bool judge(int x){
	int d = x;
	while(d != 0){
		if (d % 10 == 7) return 1;
		d /= 10;
	}
	return 0;
}
void P(int n){
	for (int i = 0; i <= n; i++){
		if (can[i]) continue;
		if (judge(i)){
			for (int j = 1; j <= n / i; j++)
				can[i * j] = 1;
		}
		if (!can[i]) a[++m] = i;
	}
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	P(1.8e7);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &x);
		if (can[x]) printf("-1\n");
		else{
			int p = lower_bound(a + 1, a + m + 1, x) - a;
			printf("%d\n", a[p + 1]);
		}
	}
	return 0;
}
