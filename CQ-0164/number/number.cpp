#include <stdio.h>

const int N = 1e7 + 7;
int nxt[N];
bool mark[N];

inline bool check(int n){
	while (n > 0){
		if (n % 10 == 7) return false;
		n /= 10;
	}
	return true;
	
}
inline void init(){
	for (int i = 1, j = 0; i < N; i++){
		if (mark[i]) continue;
		if (check(i)){
			nxt[j] = i;
			j = i;
		} else {
			for (int j = i; j < N; j += i){
				mark[j] = true;
			}
		}
	}
}

int main(){
	int t;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &t);
	init();
	for (int i = 1; i <= t; i++){
		int x;
		scanf("%d", &x);
		if (mark[x]){
			printf("-1\n");
		} else {
			printf("%d\n", nxt[x]);
		}
	}
	return 0;
}
