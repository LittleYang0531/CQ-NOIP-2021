#include <cstdio>
#include <algorithm>
const int N = 1e7 + 1;
int n, t, i, j, cnt, l, r, mid, p[2000000];
bool vis[N + 10];
bool check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0; 
}
int read() {
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
void write(int x) {
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(i = 1; i <= N; ++i) {
		if(check(i)) vis[i] = 1;
		if(!vis[i]) p[++cnt] = i;
		else for(j = i * 2; j <= N; j += i) vis[j] = 1;
	}
	t = read();
	while(t--) {
		n = read();
		if(*(std::lower_bound(p + 1, p + 1 + cnt, n)) != n) puts("-1");
		else write(*(std::lower_bound(p + 1, p + 1 + cnt, n) + 1)), putchar('\n');
	}
	return 0;
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
}
