#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35,M=105;
const ll MOD=998244353;
ll a[M][N],dp[M][N][N][N],fac[N],inv[N];
ll qpow(ll x,ll y){
	if(!y)	return 1;
	ll t=qpow(x,y>>1);
	if(y&1)	return t*t%MOD*x%MOD;
	return t*t%MOD;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,P;
	scanf("%d %d %d",&n,&m,&P),++m;
	fac[0]=1;
	for(int i=1;i<=n;++i)	fac[i]=fac[i-1]*i%MOD;
	inv[n]=qpow(fac[n],MOD-2);
	for(int i=n-1;i>=0;--i)	inv[i]=inv[i+1]*(i+1)%MOD;
	for(int i=1;i<=m;++i)	a[i][0]=1;
	for(int i=1;i<=m;++i)	scanf("%lld",&a[i][1]);
	for(int i=1;i<=m;++i)
		for(int j=2;j<=n;++j)
			a[i][j]=a[i][j-1]*a[i][1]%MOD;
	dp[0][0][0][0]=1;
	for(int i=0;i<m;++i)
		for(int j=0;j<=n;++j)
			for(int k=0;k<=i&&k<=P;++k)
				for(int l=0;l<=j;++l)
					for(int q=0;j+q<=n;++q)
						dp[i+1][j+q][k+((l+q)&1)][(l+q)>>1]=
						(dp[i+1][j+q][k+((l+q)&1)][(l+q)>>1]+
						dp[i][j][k][l]*a[i+1][q]%MOD*inv[q])%MOD;
	ll ans=0;
	for(int k=0;k<=P;++k)
		for(int l=0;l<=n;++l){
			int u=l,sum=k;
			while(u)	sum+=u&1,u>>=1;
			if(sum>P)	continue;
			ans=(ans+dp[m][n][k][l])%MOD;
		}
	printf("%lld",(ans*fac[n]%MOD+MOD)%MOD);
	return 0;
}
