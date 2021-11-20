#include <cstdio>

const int maxn = (int) 1e7 + 5;
const int n = maxn - 5;

int t, q, tot, g[maxn];
bool b[maxn];
// b[x] = 1 说明 x 不能被选

// 若 x中有 7，返回 1 
inline bool pan7(int x) {
	int qwq;
	while(x) {
		qwq = x % 10;
		if(qwq == 7)
			return 1;
		x /= 10;
	}
	return 0;
}

inline void prime() {
	for(int i = 1; i <= n; i++) {
		if(pan7(i)) {
			b[i] = 1;
			for(int j = 1; j <= n; j++) {
				int qwq = i * j;
				if(qwq > n)
					break;
				b[qwq] = 1;
			}
		}
	}
	return;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	prime();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &q);
		if(b[q]) 
			printf("-1\n");
		else {
			++q;
			while(b[q])
				++q;
			printf("%d\n", q);
		}
	}
	return 0;
}

// TLE 70pts qwq
// CCF 少爷机给老子冲！！！ 

/*
IronHeart@413A
5 
90
99
106
114
169
*/
