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
���ǿ��Կ�����f[i][j][s]��ʾǰ��iλ��������j��1������s�������Ȩֵ֮��
��ô���ǻ���Ҫ�����g[i][j]��ʾ2^i��j��λ�ôճ�����Ȩֵ֮��
��Сֵ�Ļ�����ȡ��2^{i-(j-1)}����������Сֵ�����ǲ���ʵ��
�����ǵ����ֵȡ����֮��Ҳ��һ����2^i������ʽ������Ҳ����
���ǿ����л�˼·
���ǿ��ǵ���һ��λ�õ�ʵ���ϵ�ֵ����ǰ��Ľ�λ�ټ��ϵ�ǰ��λ��ֵ%2
�������ǿ�����С����ö��һ��λ��ѡ�˶��ٸ�����λ��
��f[i][j][k][s]��ʾǰ��i������λΪj��ѡ��s������k��1��Ȩֵ֮��
�����ˣ�����sb
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
