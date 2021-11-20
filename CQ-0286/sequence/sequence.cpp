#include<bits/stdc++.h>
using namespace std;

int n = 0, m = 0, k = 0, v[100] = {};

int ran(int x){
	srand(time(NULL) + x * x);
	return rand();
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m + 1; i++){
		scanf("%d", &v[i]);
	}
	printf("%d", ran(n + m + v[2]) * ran(k + v[1] + v[2]) % 998244353);
	return 0;
}
