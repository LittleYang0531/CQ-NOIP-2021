#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4e5 + 10;

int val[N], col[N];
char ch[N], s1[N], s2[N];

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int Case, n, m, q;
	scanf("%d", &Case);
	while(Case -- ) {
		scanf("%d %d %d", &n, &m, &q);
		int pos, cnt1 = 0, cnt2 = 0, End = 0, a, b, c, d;
		End = n * m;
		for(int i = 1; i <= End; ++i) {
			col[i] = -1;
		}
		bool fl = false;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", ch + 1);
			for(int j = 1; j < m; ++j) {
				s1[++cnt1] = ch[j];
				if(ch[j] - '0' > 1) {
					fl = true;
				}
			}
		}
		for(int i = 1; i < n; ++i) {
			scanf("%s", ch + 1);
			for(int j = 1; j <= m; ++j) {
				s2[++cnt2] = ch[j];
				if(ch[j] - '0' > 1) {
					fl = true;
				}
			}
		}
		for(int i = 1; i <= q; ++i) {
			int ans = 0, x;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			pos = (c - 1) * m + d;
			col[pos] = a;
			val[pos] = b;
			x = (c - 1) * (m - 1) + d - 1;
			if(d > 1 && s1[x] != '0' && col[pos - 1] != col[pos] && val[pos - 1] <= val[pos]) {
				++ans;
			}
			if(d < m && s1[x + 1] != '0' && col[pos + 1] != col[pos] && val[pos + 1] <= val[pos]) {
				++ans;
			}
			x = (c - 2) * m + d;
			if(c > 1 && s2[x] != '0' && col[pos - m] != col[pos] && val[pos - m] <= val[pos]) {
				++ans;
			}
			if(c < n && s2[x + m] != '0' && col[pos + m] != col[pos] && val[pos + m] <= val[pos]) {
				++ans;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
1
3 3 5
01
10
11
010
111
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
