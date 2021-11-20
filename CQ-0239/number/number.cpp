#include <cstdio>

int read() {
	int x = 0, k = 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-')
			k = -1;
		s = getchar();
	}
	while('0' <= s && s <= '9') {
		x = (x << 3) + (x << 1) + (s ^ 48);
		s = getchar();
	}
	return x * k;
}

void write(int x) {
	if(x < 0) {
		x = -x;
		putchar('-');
	}
	if(x > 9) 
		write(x / 10);
	putchar(x % 10 + '0');
}

void print(int x, char s) {
	write(x);
	putchar(s);
}

const int MAXN = 1e7 + 20;

bool flag[MAXN];
int to[MAXN], len = 0;

void init() {
	int i, x;
	bool sev = false;
	for(i = 1; i < MAXN; i++) {
		if(flag[i])
			continue;
		x = i;
		sev = false;
		while(x > 0) {
			if(x % 10 == 7)  {
				sev = true;
				break;
			}
			x /= 10;
		}		
		if(sev) {
			flag[i] = true;		
			for(int j = i + i; j < MAXN; j += i) 
				flag[j] = true;			
		}			
	}	
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	int t = read(), last = 0;
	for(int i = 1; i < MAXN; i++)
		if(!flag[i]) {
			if(last)
				to[last] = i;
			last = i;
		}
	while(t--) {
		int x = read();
		if(!to[x])
			print(-1, '\n');
		else
			print(to[x], '\n');
	} 
	return 0;
} 
