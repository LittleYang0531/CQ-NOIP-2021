#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

int n, m, K, res, fac, tim; 
int a[M];
int Inv[M]; 
int opt[M], g[M]; 

inline int read()
{
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f * s;
}

inline int qpow(int a, int b, int p) {  
    int s = 1; 
    for(int bas = a; b; b >>= 1, bas = 1ll * bas * bas % p) 
        if(b & 1) s = 1ll * s * bas % p; 
    return s; 
} 

inline void get() {  
    tim ++; 
    int val = 1; 
    for(int i = 0; i <= m; ++i) val = 1ll * val * Inv[opt[i]] % mod * qpow(a[i], opt[i], mod) % mod; 
    for(int i = 0; i <= m + 10; ++i) g[i] = opt[i]; 
    for(int i = 0; i <= m + 10; ++i) g[i + 1] += g[i] / 2, g[i] %= 2; 
    int pd = 0; 
    for(int i = 0; i <= m + 10; ++i) pd += g[i]; 
    if(pd <= K) res = (res + 1ll * val * fac % mod) % mod; 
}

inline void dfs(int x, int sum) {
    if(sum == 0 && x == m + 1) {
	    get(); 
	    return ; 
    }
	if(x > m || sum < 0) return ; 
	for(int i = 0; i <= sum; ++i)
	    opt[x] = i, dfs(x + 1, sum - i), opt[x] = 0;
}

int f[250005], ff[250005]; 
inline void Solve1() {
	ff[0] = 1; 
    int S = (1 << m) * n; 
    for(int i = 1; i <= n; ++i) {
    	for(int j = 0, ts = (1 << m) * i; j <= m; ++j)   
    	    for(int k = (1 << j); k <= ts; ++k) {
    	    	f[k] = (f[k] + 1ll * ff[k - (1 << j)] * a[j] % mod) % mod; 
			}
		for(int j = 0, ts = (1 << m) * i; j <= ts; ++j) ff[j] = f[j], f[j] = 0; 
	}
	for(int i = 0; i <= S; ++i) {
		int s = 0, t = i; 
		while(t) s ++, t -= t & (-t); 
		if(s <= K) res = (res + ff[i]) % mod; 
	}
	std :: cout << res; 
}

int main()
{
	freopen("sequence.in", "r", stdin); 
	freopen("sequence.out", "w", stdout); 
    n = read(), m = read(), K = read(); 
    for(int i = 0; i <= m; ++i) a[i] = read(); 
    if(m <= 12) {
    	Solve1(); 
    	return 0; 
	}
    Inv[0] = Inv[1] = 1; fac = 1; 
    for(int i = 2; i <= n; ++i) Inv[i] = 1ll * (mod - mod / i) * Inv[mod % i] % mod, fac = 1ll * fac * i % mod; 
    for(int i = 2; i <= n; ++i) Inv[i] = 1ll * Inv[i] * Inv[i - 1] % mod; 
    dfs(0, n);   
    std :: cout << res;  
	return 0;
}

