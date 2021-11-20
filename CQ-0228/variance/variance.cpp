#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <cmath>
#include <map> 

typedef long long ll;
typedef unsigned long long ull;

const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n; 
int a[M];
ll res; 
struct Node {
	int a[405]; 
};
std :: map < ull, int > mp; 

std :: queue < Node > q; 

inline int read()
{
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f * s;
}

inline ll value(Node t) {
    ll s1 = 0, s2 = 0; 
    for(int i = 1; i <= n; ++i) s1 += 1ll * t.a[i] * t.a[i], s2 += t.a[i]; 
    return n * s1 - 1ll * s2 * s2; 
}

inline void bfs() {
    Node s; 
    for(int i = 1; i <= n; ++i) s.a[i] = a[i]; 
    q.push(s); 
    int tim = 0; 
    res = (1ll << 60); 
    while(!q.empty()) {
    	tim ++; Node tmp = q.front(); q.pop(); 
    	Node qe; 
    	ll t = value(tmp); 
    	if(t <= res) res = t; 
    	else if(n > 30) continue ; 
//    	std :: cout << tim << '\n'; 
    	if(tim >= 114514) break; 
    	qe = tmp; 
    	for(int i = 2; i < n; ++i) {
    		ll t = tmp.a[i - 1] + tmp.a[i + 1] - tmp.a[i]; 
    		ull h = 0; 
    		for(int j = 1; j <= n; ++j) h = h * 1145141919ull + (j == i ? t : tmp.a[j]); 
    		if(!mp[h]) {
    			mp[h] = 1; 
				for(int j = 1; j <= n; ++j) qe.a[j] = (i == j ? t : tmp.a[j]); 
				q.push(qe);
		    }
		}
	}
	std :: cout << res; 
}


int main()
{
	freopen("variance.in", "r", stdin); 
	freopen("variance.out", "w", stdout); 
    n = read(); 
    for(int i = 1; i <= n; ++i) a[i] = read(); 
    bfs(); 
	return 0;
}

