#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 205
#define LL long long
#define ENDL putchar('\n')
#define DB double
#define lowbit(x) (-(x) & (x))
#define FI first
#define SE second
LL read() {
	LL f = 1,x = 0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s = getchar();}
	while(s >= '0' && s <= '9') {x = (x<<1) + (x<<3) + (s^48);s = getchar();}
	return f*x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);}
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

const int MOD = 998244353;
int n,m,s,o,k;
int a[205];
int dp[35][35][105][1<<5|5],po[105][35];
int ct[35];
int fac[35],inv[35],invf[35];
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read();m = read();
	int K = read();
	for(int i = 1;i <= (1<<5);i ++) {
		ct[i] = ct[i-lowbit(i)] + 1;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	for(int i = 2;i <= n;i ++) {
		fac[i] = fac[i-1] *1ll* i % MOD;
		inv[i] = (MOD - inv[MOD%i]) *1ll* (MOD/i) % MOD;
		invf[i] = invf[i-1] *1ll* inv[i] % MOD;
	}
	for(int i = 0;i <= m;i ++) {
		a[i] = read();
		po[i][0] = 1;
		for(int j = 1;j <= n;j ++) {
			po[i][j] = po[i][j-1] *1ll* a[i] % MOD;
		}
	}
	
	int tp = 1<<5;
	for(int i = 0;i < tp;i ++) dp[0][ct[i]][m+1][i] = 1;
	for(int j = m;j >= 0;j --) {
		for(int i = 0;i <= n;i ++) {
			for(int c = 0;c <= K;c ++) {
				for(int k = 0;k < tp;k ++) {
//					if(!(k & 1)) dp[i][c][j][k] = (dp[i][c-1][j+1][(k>>1)+(1<<4)] + dp[i][c][j+1][k>>1]) % MOD;
					for(int s = 0;s <= i;s ++) {
						int p = k + s;
						if(p&1) {
							if(c) (dp[i][c][j][k] += dp[i-s][c-1][j+1][p>>1] *1ll* po[j][s] % MOD * invf[s] % MOD) %= MOD;
						}
						else {
							(dp[i][c][j][k] += dp[i-s][c][j+1][p>>1] *1ll* po[j][s] % MOD * invf[s] % MOD) %= MOD;
						}
					}
//					if(dp[i][c][j][k]) printf("dp[%d][%d][%d][%d] = %d\n",i,c,j,k,dp[i][c][j][k]);
				}
			}
		}
	}
	int ans = 0;
	for(int c = 0;c <= K;c ++) {
		(ans += dp[n][c][0][0]) %= MOD;
	}
	ans = ans *1ll* fac[n] % MOD;
	AIput(ans,'\n');
	return 0;
}
