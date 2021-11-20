#include <bits/stdc++.h>
#define LL long long
#define MAXX 10000010
using namespace std;
int nxt[10000015];
bool visit[10000015];
bool ok(int x){
	while(x){
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 1; i <= MAXX; i++){
		if(!visit[i]){
			if(ok(i)){
				for(int j = i; j <= MAXX; j += i) visit[j] = 1;
			}
		}
	}
	int lst;
	for(int i = MAXX; i >= 1; i--){
		if(!visit[i]){
			nxt[i] = lst;
			lst = i;
		}
	}
	int t, x;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &x);
		if(visit[x]) printf("-1\n");
		else printf("%d\n", nxt[x]);
	}
	return 0;
}
