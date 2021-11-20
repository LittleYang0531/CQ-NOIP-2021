#include <algorithm>
#include <iostream> 
#include <cstring> 
#include <cstdio>
#include <vector>
#include <ctime> 
#include <cmath>

typedef long long ll; 
typedef unsigned long long ull; 

const int M = 2e7 + 5;  
const int INF = 0x3f3f3f3f; 

int n, cnt;  
int pre[M], prime[M];
bool vis[M], vt[M]; 

inline bool pd(int x) {
	if(x % 7 == 0) return 1; 
	while(x) {
		if(x % 10 == 7) return 1; 
		x /= 10; 
	}
	return 0; 
} 

inline void Sieve() {
    for(int i = 2; i < M; ++i) {
    	if(!vis[i] && pd(i)) {
    		vis[i] = 1; 
    		for(int j = i + i; j < M; j += i) vis[j] = 1; 
		}
	}
	int lst = 0; 
	for(int i = M - 1; i >= 1; --i) {
	    if(i <= M / 2 && !vis[i]) pre[i] = lst; 
		if(!vis[i]) lst = i; 
	}
}

inline int read() 
{
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();  
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); 
	return f * s; 
}

int main() 
{
    freopen("number.in", "r", stdin);  
    freopen("number.out", "w", stdout);
    Sieve(); 
    int q = read();
    while(q --) {
    	int x = read(); 
    	printf("%d\n", vis[x] ? -1 : pre[x]);
	}
	return 0;  	
}
