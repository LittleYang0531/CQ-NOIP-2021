/*---And in that light,I find deliverance.---*/
#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
const int maxm=105;
const int maxn=35;
int v[maxm];
int power[maxm][maxn];
int f[2][maxn][256][maxn];
int mask[256];
int fac[maxn],inv[maxn];
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=1ll*ans*a%p;
		b>>=1,a=1ll*a*a%p;
	}
	return ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,K;cin>>n>>m>>K;
	for(int i=0;i<=m;++i){
		cin>>v[i];
		power[i][0]=1;
		for(int j=1;j<=n;++j)
			power[i][j]=1ll*power[i][j-1]*v[i]%p;
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%p;
	inv[n]=ksm(fac[n],p-2,p);
	for(int i=n-1;i>=1;--i) inv[i]=1ll*(i+1)*inv[i+1]%p;
	for(int i=1;i<=128;++i) mask[i]=mask[i-(i&(-i))]+1;
	f[0][0][0][0]=1;
	for(int i=0;i<=m;++i){
		memset(f[1],0,sizeof f[1]);
		int now=-1;
		for(int j=0;j<=n;++j){
			++now;
			for(int s=0;s<64;++s){
				for(int k=n;k>=j;--k){
					for(int u=0;u<=min(k,K);++u){
						f[1][k][s+now][u]=1ll*(f[1][k][s+now][u]+1ll*f[0][k-j][s][u]*power[i][j]%p*inv[j]%p)%p;
//						cerr<<s+now<<'\n';
//						cerr<<k<<' '<<s+now<<' '<<u<<' '<<f[1][k][s+now][u]<<'\n';
					}
				}
			}
		}
		memset(f[0],0,sizeof f[0]);
		for(int nu=0;nu<=n;++nu){
			for(int j=0;j<128;++j){
				for(int k=0;k<=K;++k){
//					if(f[1][nu][j][k]) cout<<nu<<' '<<j<<' '<<k<<' '<<f[1][nu][j][k]<<'\n';
					if(j&1) f[0][nu][j>>1][k+1]=(f[0][nu][j>>1][k+1]+f[1][nu][j][k])%p;
					else f[0][nu][j>>1][k]=(f[0][nu][j>>1][k]+f[1][nu][j][k])%p;
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<128;++j){
		for(int k=0;k<=n;++k){
			if(mask[j]+k<=K){
				ans=(ans+f[1][n][j][k])%p;
			}
		}
	}
	cout<<1ll*ans*fac[n]%p<<'\n';
	return 0;
}
