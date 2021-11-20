#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define uint unsigned int
using namespace std;
const int MAXN = 1e7 + 1e6 + 5;
int T, n, t, f, F[MAXN];
bool vis[MAXN];
bool Check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 0; i <= 9; i ++) {
		for(int j = 0; j <= 9; j ++) {
			for(int k = 0; k <= 9; k ++) {
				for(int u = 0; u <= 9; u ++) {
					for(int v = 0; v <= 9; v ++) {
						for(int w = 0; w <= 9; w ++) { 
							for(int qwq = 0; qwq <= 9; qwq ++) {
								if(i == 7 || j == 7 || k == 7 || u == 7 || v == 7 || w == 7 || qwq == 7) vis[i * 1000000 + j * 100000 + k * 10000 + u * 1000 + v * 100 + w * 10 + qwq] = 1;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 10000000; i >= 1; i --) {
		if(vis[i]) {
			for(int j = i; j <= 10000200; j += i) vis[j] = 1;
		}
	}
	for(int i = 10000200; i >= 1; i --) {
		if(vis[i + 1]) F[i] = F[i + 1];
		else F[i] = i + 1;
	}
	while(T --) {
		scanf("%d", &n);
		if(vis[n]) printf("-1\n");
		else printf("%d\n", F[n]);
	}
	return 0;
}

