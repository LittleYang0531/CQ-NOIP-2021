#include<bits/stdc++.h>
using namespace std;

int n = 0, a[10001] = {}, b[10001] = {}, h[10001][10001] = {}, lh = 0;
long double ans = 1e9;

void fc(){
	long double sum = 0, k = 0;
	for(int i = 0; i < n; i++){
		k += b[i];
	}
	k /= n;
	for(int i = 0; i < n; i++){
		sum += pow(b[i] - k, 2);
	}
	sum *= n;
	ans = min(ans, sum);
	return;
}

bool check(){
	for(int j = 0; j < lh; j++){
		int flag = 1;
		for(int i = 0; i < n; i++){
			if(b[i] != h[j][i]){
				flag = 0;
			}
		}
		if(flag){
			return 1;
		}
	}
	for(int i = 0; i < n; i++){
		h[lh][i] = b[i];
	}
	lh++;
	return 0;
}

void dfs(){
	fc();
	for(int i = 1; i < n - 1; i++){
		b[i] = b[i - 1] + b[i + 1] - b[i];
		if(check()){
			continue;
		}
		dfs();
	}
	return;
}

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for(int i = 0; i < n; i++){
		h[lh][i] = b[i];
	}
	lh++;
	dfs();
	long long int anss = ans;
	printf("%lld", anss); 
	return 0;
}
