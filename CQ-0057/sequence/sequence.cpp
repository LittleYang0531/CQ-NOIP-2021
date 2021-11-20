#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 998244353
#define MAXM 115
#define MAXN 35

template <typename T> inline void read (T &x){x = 0;int f = 1;char c = getchar();while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar ();while (isdigit (c)) x = x * 10 + c - '0',c = getchar ();x *= f;}
template <typename T> inline void write (T x){if (x < 0) x = -x,putchar ('-');if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int N,M,K,val[MAXM];

int mul (int a,int b){return 1ll * a * b % mod;}
int dec (int a,int b){return a >= b ? a - b : a + mod - b;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
int qkpow (int a,int b){
	int res = 1;for (;b;b >>= 1,a = mul (a,a)) if (b & 1) res = mul (res,a);
	return res; 
}
void Add (int &a,int b){a = add (a,b);}
void Sub (int &a,int b){a = dec (a,b);}

int C[MAXN][MAXN],f[MAXM][MAXN][MAXN][MAXN];

signed main(){
	freopen ("sequence.in","r",stdin);
	freopen ("sequence.out","w",stdout);
	read (N),read (M),read (K);
	for (Int i = 0;i <= M;++ i) read (val[i]);
	C[0][0] = 1;
	for (Int i = 1;i <= N;++ i){
		C[i][0] = 1;
		for (Int j = 1;j <= i;++ j) C[i][j] = add (C[i - 1][j],C[i - 1][j - 1]);
	}
	int up = M + 6;
	for (Int i = 0,pw = 1;i <= N;++ i,pw = mul (pw,val[0])) f[0][i / 2][i % 2][i] = mul (pw,C[N][i]);
	for (Int i = 0;i < up;++ i){
		for (Int j = 0;j <= N;++ j)
			for (Int k = 0;k <= K;++ k)
				for (Int s = 0;s <= N;++ s) if (f[i][j][k][s]){
					int v = f[i][j][k][s],rup = (i + 1 <= M) ? N - s : 0;
					for (Int h = 0,pw = 1;h <= rup;++ h,pw = mul (pw,val[i + 1]))
						Add (f[i + 1][(j + h) >> 1][k + ((j + h) % 2)][s + h],mul (mul (v,pw),C[N - s][h]));
				} 
	}
	int ans = 0;
	for (Int k = 0;k <= K;++ k) Add (ans,f[up][0][k][N]);
	write (ans),putchar ('\n');
	return 0;
}
/*
m<=100
我们可以考虑设f[i][j][s]表示前面i位，出现了j个1，用了s个来填的权值之和
那么我们还需要处理出g[i][j]表示2^i用j个位置凑出来的权值之和
最小值的话可以取到2^{i-(j-1)}，所以用最小值考虑是不现实的
而我们的最大值取完了之后也不一定是2^i这种形式，所以也不行
我们考虑切换思路
我们考虑到了一个位置的实际上的值就是前面的进位再加上当前这位的值%2
所以我们考虑最小到大枚举一个位置选了多少个，进位多
设f[i][j][k][s]表示前面i个，进位为j，选了s个，有k个1的权值之和
做完了，我是sb
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
