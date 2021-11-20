#include<bits/stdc++.h>
using namespace std;

int t = 0, x = 0, st[10000001] = {};

bool chebs(int num2){
	if(st[num2] != -1){
		return st[num2];
	}
	int k = num2;
	while(k >= 1){
		if(k % 10 == 7){
			st[num2] = 1;
			return 1;
		}
		k /= 10;
	}
	return 0;
}

void chets(int num1){
	for(int i2 = 1; i2 <= sqrt(num1); i2++){
		if(num1 % i2 == 0){
			if(chebs(i2) || chebs(num1 / i2)){
				st[num1] = 1;
				return;
			}
		}
	}
	st[num1] = 0;
	return;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &t);
	memset(st, -1, sizeof(st));
	st[0] = 0;
	while(t--){
		scanf("%d", &x);
		if(st[x] == -1){
			chets(x);
		}
		if(st[x] == 0){
			for(int i1 = x + 1; 1; i1++){
				if(st[i1] == -1){
					chets(i1);
				}
				if(st[i1] == 0){
					printf("%d\n", i1);
					break;
				}
			}
		}
		if(st[x] == 1){
			printf("-1\n");
		}
	}
	return 0;
}
