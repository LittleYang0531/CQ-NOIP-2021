#include<bits/stdc++.h>
using namespace std;
const int N=30,M=100,P=998244353;
int n,m,lim,dp[3][N+5][N+5][N+5],v[M+5],pw[M+5][N+5],ans;
int fac[N+5],inv[N+5];
void upd(int &x,int y) {x=(x+y)%P;}
int getv(int x) {int ret=0;while(x) ret+=(x&1),x/=2;return ret;}
int KSM(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=ret*1ll*a%P;
		b>>=1ll;a=1ll*a*a%P;
	}
	return ret;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fac[0]=inv[0]=1;for(int i=1; i<=N; i++) fac[i]=1ll*fac[i-1]*i%P;
	inv[N]=KSM(fac[N],P-2);
	for(int i=N-1; i>=1; i--) inv[i]=1ll*inv[i+1]*(i+1)%P;
	scanf("%d%d%d",&n,&m,&lim);
	for(int i=0; i<=m; i++)
	{
		scanf("%d",&v[i]);pw[i][0]=1;
		for(int j=1; j<=n; j++)	pw[i][j]=1ll*pw[i][j-1]*v[i]%P;
	}
	int z=0;
	for(int i=0; i<=n; i++) dp[z][i][0][i]=1ll*pw[0][i]*fac[n]%P*inv[i]%P;
	for(int i=0; i<m; i++,z^=1)
	{
		memset(dp[z^1],0,sizeof dp[z^1]);
		for(int l=0; l<=n; l++)
			for(int k=0; k<=lim; k++)
				for(int x=0; x<=l; x++)
					for(int r=l; r<=n; r++)
						upd(dp[z^1][r][k+(x&1)][x/2+r-l],1ll*dp[z][l][k][x]*pw[i+1][r-l]%P*inv[r-l]%P);
	}
	for(int i=0; i<=lim; i++)
		for(int k=0; k<=n; k++)
			if(i+getv(k)<=lim) upd(ans,dp[z][n][i][k]);
	printf("%d",ans);
	return 0;
}
/*
5 1 1
2 1
*/
