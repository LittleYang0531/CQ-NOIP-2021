#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define db double
using namespace std;
const int mod=998244353;
//算法； Dp
//设 dp[i][j][k][dj] 表示考虑前 i 个选了 j 个数，二进制为 1 有 k 位 ，当前进位为 dj 的答案 
//其中 i=1~m, j=1~n, k=1~K
//预处理组合数
//假设第 i 次选了 x 个数
// C(j+x,x) * v[i]^x 
int n,m,K;
ll c[105][105],v[105],dp[105][35][35][35],res;
void Mod(ll &x,ll y) {
	x=(x+y)%mod;
}
ll fpow(ll x,ll y) {
	ll mul(1);
	for(;y;y>>=1) {
		if(y&1) {
			mul=mul*x%mod;
		}
		x=x*x%mod;
	}
	return mul;
}
void init(int n) {
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init(100);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;i++) {
		scanf("%lld",&v[i]); 
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<=K;k++) {
				for(int l=0;l<=j;l++) {
					if(dp[i][j][k][l]) {
						for(int x=0;x<=n-j;x++) {
							Mod(dp[i+1][j+x][k+(l+x)%2][(l+x)/2],dp[i][j][k][l]*fpow(v[i],x)%mod*c[j+x][x]%mod);
						}
					}
				}
			}
		}
	}
//	printf("%lld",dp[m+1][n][0][2]);
    for(int i=1;i<=K;i++) {
    	for(int l=0;l<=n;l++) {
			int tot=0,tmp=l;
			while(tmp) {
				tot+=tmp%2;
				tmp/=2;
			}
			if(tot<=i) {
				res=(res+dp[m+1][n][i-tot][l])%mod;
			}
		}
	}
	
	printf("%lld",res);
}
