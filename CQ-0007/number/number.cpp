#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define pii pair <int , int>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long LL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(x<0) {putchar('-');x=-x;}
	if(!x) {putchar('0');putchar(s);return;}
	T tmp[25] , t = 0;
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t -- > 0) putchar(tmp[t] + '0');
	putchar(s);
}

const int MAXN = 1e7 + 5;
const int N = 1e7 + 1;

bool pr[MAXN];
int nxt[MAXN];

void pre() {
	for (int i = 1; i <= N; ++i) {
		int x = i , fl = 0;
		while(x) {
			if(x % 10 == 7) fl = 1;
			x /= 10;
			if(fl) break;
		}
		if(!fl) continue;
		pr[i] = 1;
		for (int j = i * 2; j <= N; j += i) pr[j] = 1;
	}
	for (int i = N - 1; i >= 1; --i) {
		if(!pr[i + 1]) nxt[i] = i + 1;
		else nxt[i] = nxt[i + 1];
	}
}

int main() {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	pre();
	int T;
	read(T);
	while(T -- > 0) {
		int x;read(x);
		if(pr[x]) write(-1);
		else write(nxt[x]);
	}
	return 0;
}
