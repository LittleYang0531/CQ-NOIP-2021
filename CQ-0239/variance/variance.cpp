#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
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

void write(LL x) {
	if(x < 0) {
		x = -x;
		putchar('-');
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

void print(LL x, char s) {
	write(x);
	putchar(s);
}

const int MAXN = 1e4 + 5;
const int MAXM = 6e2 + 5;
const double eps = 1e-11;

double Abs(double x) { return x < eps ? -x : x; }
int a[MAXN], num[MAXN], len = 0;

bool cmp(int x, int y) {
	return x > y;
}

double calc(int l, int r) {
	double sum = 0;
	for(int i = l; i <= r; i++)
		sum += a[i];
	sum /= (r - l + 1);
	double ans = 0;
	for(int i = l; i <= r; i++)
		ans += (a[i] * 1.0 - sum) * (a[i] * 1.0 - sum);
	return ans;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();	
		if(i > 1) 
			num[++len] = a[i] - a[i - 1];	
	}
	sort(num + 1, num + len + 1, cmp);
	
	int l = 1, r = n, pos = 0, suml = a[1], sumr = a[n];
	while(l < r) {
		if(calc(1, l) < calc(r, n)) {
			a[l + 1] = a[l] + num[++pos];
			l++;
			if(r - 1 != l + 1) {
				a[r - 1] = a[r] - num[++pos];
				r--;				
			}
		}
		else {
			a[r - 1] = a[r] - num[++pos];	
			r--;	
			if(r - 1 != l + 1) {
				a[l + 1] = a[l] + num[++pos];	
				l++;					
			}		
		}
		suml += a[l];
		sumr += a[r];
	}			
	double S = 0;
	for(int i = 1; i <= n; i++)
		S += a[i];
	S /= n;
	double ans = 0;
	for(int i = 1; i <= n; i++)
		ans += (a[i] * 1.0 - S) * (a[i] * 1.0 - S);
	print((LL)(ans * n), '\n');
	return 0;
}
