#include<iostream>
#include<cstdio>
using namespace std;
#define N 102
#define mod 998244353
inline int M(int x){return (x>=mod)?(x-mod):x;}
inline void Ad(int &x,int v){x=M(x+v);}
inline int M1(int x){return (x<0)?(x+mod):x;}
inline int ksm(int p,int k){int res=1;while(k){if(k&1)res=1ll*res*p%mod;k>>=1;p=1ll*p*p%mod;}return res;}
int n,m,K,f[N][32][32][32],a[N],ans=0,fac[N],inv[N],P[N][N];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fac[0]=inv[0]=1;for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=ksm(fac[i],mod-2);
	scanf("%d%d%d",&n,&m,&K);int i,j,k,w,p,v;f[0][0][0][0]=1;
	for(i=0;i<=m;i++){scanf("%d",&a[i]);P[i][0]=1;for(j=1;j<=n;j++)P[i][j]=1ll*P[i][j-1]*a[i]%mod;}
	for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
	for(k=0;k<=j;k++)
	for(w=0;w<=K;w++)
	if(v=f[i][j][k][w])
	for(p=0;p<=n-j;p++)Ad(f[i+1][j+p][(k>>1)+p][w+(((k>>1)+p)&1)],1ll*v*P[i][p]%mod*inv[p]%mod);
	for(k=0;k<=n;k++)
	for(w=0;w<=K;w++)if((w+__builtin_popcount(k>>1))<=K)Ad(ans,f[m+1][n][k][w]);
	ans=1ll*ans*fac[n]%mod;printf("%d",ans);return 0;
}
