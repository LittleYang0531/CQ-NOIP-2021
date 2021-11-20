#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e7 + 1000;

bool f[N];
int num[N], nxt[N], cnt;

template <typename T>
void read(T &x) {
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9') {
		s = getchar();
	}
	while(s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar();
	}
}

void dfs(int Now, int sum, bool f) {
	if(Now == 8 && f) {
		num[++cnt] = sum;
		return;
	}
	if(Now == 7 && !f) {
		dfs(Now + 1, sum * 10 + 7, 1);
	} else {
		for(int i = 0; i <= 9; ++i) {
			dfs(Now + 1, sum * 10 + i, (i == 7) || f);
		}
	}
}

void init() {
	int End = 1e7 + 500, la = 0;
	for(int i = 1; i <= End; ++i) {
		if(!f[i]) {
			nxt[la] = i;
			la = i;
		}
		for(int j = 1; j <= cnt && num[j] * i <= End; ++j) {
			f[i * num[j]] = true;
			if(i % num[j] == 0) {
				break;
			}
		}
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int Case, x;
	dfs(1, 0, 0);
	init();
	read(Case);
	while(Case -- ) {
		read(x);
		if(f[x]) {
			puts("-1");
		} else {
			printf("%d\n", nxt[x]);
		}
	}
	return 0;
}
