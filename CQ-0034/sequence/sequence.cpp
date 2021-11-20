#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long llong;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; !isdigit(c); c=getchar())
		if(c == '-') f = -f;
	for(; isdigit(c); c=getchar())
		a = (a*10)+(c^48);
	return a*f;
}
void writeint(unsigned x){
	if(x > 9) writeint(x/10);
	putchar(char((x%10)^48));
}

const int MOD = 998244353;
inline int modAdd(int x,const int &y){
	return ((x += y) >= MOD) ? (x-MOD) : x;
}

const int MAXN = 40;
int c[MAXN][MAXN], bitcnt[MAXN];
int dp[MAXN][MAXN][MAXN], nxt[MAXN][MAXN][MAXN];

int vpow[MAXN];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	rep(i,0,MAXN-1) rep(j,c[i][0]=1,i)
		c[i][j] = modAdd(c[i-1][j-1],c[i-1][j]);
	int n = readint(), m = readint();
	int cnt_one = readint();
	dp[0][0][n] = vpow[0] = 1;
	for(int i=0; i<=m; ++i){
		const llong base = vpow[1] = readint();
		rep(j,2,n) vpow[j] = int(base*vpow[j-1]%MOD);
		rep(j,0,n) rep(k,0,cnt_one) rep(p,0,n){
			const llong now = dp[j][k][p];
			rep(t,0,p){ // how many choosing this
				int &v = nxt[(j+t)>>1][k+((j^t)&1)][p-t];
				v = int((v+now*c[p][t]%MOD*vpow[t])%MOD);
			}
		}
//		printf(">>> i = %d\n",i);
		rep(j,0,n) rep(k,0,cnt_one) rep(p,0,n){
			dp[j][k][p] = nxt[j][k][p];
//			if(dp[j][k][p]) printf("dp[%d,%d,%d] = %d\n",j,k,p,dp[j][k][p]);
			nxt[j][k][p] = 0;
		}
	}
	rep(i,1,n) bitcnt[i] = bitcnt[i>>1]+(i&1);
	int ans = 0;
	rep(j,0,n) rep(k,0,cnt_one-bitcnt[j])
		ans = modAdd(ans,dp[j][k][0]);
	printf("%d\n",ans);
	return 0;
}

/*

f(i,j,k,p): i-th digit, having j carry-over, k bit 1 allowed, p choices remained

goto f(i+1,(j+t)>>1,k-((j+t)&1),p-t) * C(p,t) * v_i^{t}

O(m*n*k*n) status, O(n) transfer, OK!

*/
