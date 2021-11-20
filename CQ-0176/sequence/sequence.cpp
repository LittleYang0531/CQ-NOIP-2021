#include<bits/stdc++.h>
using namespace std;
const int N=35;
const int M=105;
typedef long long ll;
ll mod=998244353,dp[M][N][1<<4][N],v[M],pw[M][M],jc[M],C[M][M];

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,K;
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m+1;i++) {
		scanf("%lld",&v[i]);
		pw[i][0]=1; for(int j=1;j<=n;j++) pw[i][j]=pw[i][j-1]*v[i]%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=n;i++) {
		C[i][0]=1;
		for(int j=1;j<=i;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			for(int t=0;t<=min(n,K);t++) {
				for(int s=0;s<(1<<4);s++) {
					for(int k=0;j+k<=n;k++) {
						dp[i+1][j+k][(s+k)>>1][((s+k)&1)+t]+=dp[i][j][s][t]*pw[i+1][k]%mod*C[j+k][k]%mod;
						dp[i+1][j+k][(s+k)>>1][((s+k)&1)+t]%=mod;
//						if(dp[i][j][s][t])printf("(%d)%d %d %d %d: %lld\n",k,i+1,j+k,(s+k)>>1,((s+k)&1)+t,dp[i+1][j+k][(s+k)>>1][((s+k)&1)+t]);
					}
				}
			}
		}
	}
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	ll ans=0;
	for(int t=0;t<=K;t++) {
		for(int s=0;s<(1<<4);s++) {
			int cc=t;
			for(int j=0;j<4;j++)if((1<<j)&s) cc++;
			if(cc<=K) ans=(ans+dp[m+1][n][s][t])%mod;
		}
	}
	printf("%lld",ans%mod);
	return 0;
}

