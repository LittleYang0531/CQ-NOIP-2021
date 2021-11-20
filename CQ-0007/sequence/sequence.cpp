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

const int mod = 998244353;

LL f[105][35][35][35] , v[105] , g[105][35][35] , finv[105] , fac[105];
int n , m , K , cnt[55];

LL qpow(LL a , LL b) {
	LL res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	read(n),read(m),read(K);
	for (int i = 0; i <= m; ++i) read(v[i]);
	LL ans = 0;
	f[0][0][0][0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	finv[n] = qpow(fac[n] , mod - 2);
	for (int i = n; i >= 1; --i) finv[i - 1] = finv[i] * i % mod;
	for (LL i = 1 , cur = v[0]; i <= n; ++i , cur = cur * v[0] % mod) f[0][i][i][i & 1] = cur * finv[i] % mod , cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (LL k = 0 , cur = 1; k <= j; ++k , cur = cur * v[i] % mod) {
				for (int w = 0; w <= j - k; ++w) 
					for (int p = ((k + (w >> 1)) & 1); p <= K; ++p) {
						f[i][j][k + (w >> 1)][p] = (f[i][j][k + (w >> 1)][p] + f[i - 1][j - k][w][p - ((k + (w >> 1)) & 1)] * cur % mod * finv[k] % mod) % mod;
					}
			}
			if(j == n) {
				if(i == m) {
					for (int k = 0; k <= n; ++k) {
						for (int p = 0; p <= K; ++p) if(p + cnt[k >> 1] <= K) ans = (ans + f[i][j][k][p]) % mod;
					}
				}
			}
		}
	}
	write(ans * fac[n] % mod);
	return 0;
}
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699

642171527
*/
