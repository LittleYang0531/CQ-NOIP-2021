#include <cstdio>
const int maxn = 35,maxm = 105,maxk = 35,mod = 998244353;
const int ppc[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
inline int min(int a,int b){return a<b?a:b;}
inline void plus(int &x,int v){(x+=v),(x>=mod?x-=mod:0);}
inline int ksm(int a,int x){
	int ans = 1,bas = a;
	while(x){
		if(x&1)ans = 1ll*ans*bas%mod;
		bas = 1ll*bas*bas%mod,x >>= 1;
	}return ans;
}
int n,m,K,v[maxm],jc[maxn],iv[maxn];
void init(){
	jc[0] = iv[0] = 1;
	for(int i=1;i<=n;++i)jc[i] = 1ll*jc[i-1]*i%mod;
	iv[n] = ksm(jc[n],mod-2);
	for(int i=n;i>=2;--i)iv[i-1] = 1ll*iv[i]*i%mod;
}
int pw[maxn],dp[maxm][maxk][maxn][16];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&K),init(),++m;
	for(int i=1;i<=m;++i)scanf("%d",&v[i]);
	pw[0] = dp[0][0][0][0] = 1;
	for(int i=0;i<m;++i){
		for(int j=1;j<=n;++j)pw[j] = 1ll*pw[j-1]*v[i+1]%mod;
		for(int j=0;j<=min(i,K);++j){
			for(int k=0;k<=n;++k)
				for(int s=0;s<16;++s){
					int v = dp[i][j][k][s];
					if(!v)continue;
					for(int l=0;l<=n-k;++l){
						int t = (s+l)>>1,p = (s+l)&1;
						plus(dp[i+1][j+p][k+l][t],1ll*v*pw[l]%mod*iv[l]%mod);
					}
				}
		}
	}
	int ans = 0;
	for(int j=0;j<=K;++j)
		for(int s=0;s<16;++s)
			if(j+ppc[s]<=K)plus(ans,dp[m][j][n][s]);
	return printf("%lld\n",1ll*ans*jc[n]%mod),0;
}
