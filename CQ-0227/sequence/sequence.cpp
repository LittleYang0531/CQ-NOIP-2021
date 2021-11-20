#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=30;
const int Maxm=100;
const int Mod=998244353;
int v[Maxm+5];
int dp[Maxm+5][Maxn+5][Maxm+5][Maxn+5];
int f[35][130000];
int fac[Maxn+5],inv[Maxn+5];
int n,m,K;
inline bool check(int x) {
	int cnt=0;
	while(x) {
		cnt+=x&1;
		x>>=1;
	}
	return cnt<=K;
}
inline int c(int x,int y) {
	return 1ll*fac[x]*inv[x-y]%Mod*inv[y]%Mod;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(ri i=1;i<=m+1;i++)scanf("%d",&v[i]);
	if(m<=12) {
		int S=n*(1<<m);
		f[0][0]=1;
		for(ri i=1;i<=n;i++) {
			for(ri j=1;j<=S;j++) {
				for(ri k=1;k<=m+1;k++) {
					if(j>=(1<<(k-1))) {
						f[i][j]=(f[i][j]+1ll*f[i-1][j-(1<<(k-1))]*v[k]%Mod)%Mod;
					}
				}
			}
		}
		int ans=0;
		for(ri i=0;i<=S;i++)
			if(check(i))ans=(ans+f[n][i])%Mod;
		printf("%d\n",ans);
		return 0;
	}
	fac[0]=1;
	for(ri i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	inv[0]=inv[1]=1;
	for(ri i=2;i<=n;i++)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(ri i=1;i<=n;i++)inv[i]=1ll*inv[i]*inv[i-1]%Mod;
	dp[0][0][0][0]=1;
	for(ri i=1;i<=m+1;i++)
		for(ri j=0;j<=n;j++)
			for(ri k=j&1;k<=K;k++)
				for(ri l=0;l<=n;l++) {
					int val=1;
					for(ri x=0;x<=min(l,j);x++) {
						int lst=(j-x)*2;
						if(lst<=n) {
							dp[i][j][k][l]+=1ll*dp[i-1][lst][k-(j&1)][l-x]*val%Mod*c(l,x)%Mod;
							dp[i][j][k][l]%=Mod;
							if(lst<n) {
								dp[i][j][k][l]+=1ll*dp[i-1][lst+1][k-(j&1)][l-x]*val%Mod*c(l,x)%Mod;
								dp[i][j][k][l]%=Mod;
							}
						}
						val=1ll*val*v[i]%Mod;
					}
				}
	int ans=0;
	for(ri i=0;i<=K;i++)
		for(ri j=0;j<=n;j++) {
			int x=i,y=j;
			while(y) {
				y/=2;
				x+=y&1;
			}
			if(x<=K)ans+=dp[m+1][j][i][n],ans%=Mod;
		}
	printf("%d\n",ans);
	return 0;
}
