#include <bits/stdc++.h>
using namespace std;
int T, n, k, tot, len, c[200007];
char a[13], b[13];
bool check(int x) {
	int tt = -1;
	while(x) {
		tt++;
		a[tt] = x % 10 + '0';
		x /= 10;
	}	
	len = strlen(a);
//	for(int i = 0; i < len; i++) {
//		a[i] = b[len - i - 1];
//	}
//	cout << a << endl;
	for(int i = 0; i < len; i++) {
		if(a[i] == '7') {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 7; i <= 200007; i++) {
		if(!check(i) && !c[i]) {
			for(int j = i; j <= 200007; j += i) {
				c[j] = 1;
			}
		}
	}
	while(T--) {
		scanf("%d", &n);
		if(c[n]) {
			printf("-1\n");
		}
		else {
			for(int i = n + 1; i <= 200007; i++) {
				if(!c[i]) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
