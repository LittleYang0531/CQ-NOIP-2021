#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define popcount __builtin_popcount
using namespace std;

const int maxn=200005;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int v[115];
int inv[35];
int fact[35];
int val[115][35];
int f[35][115][20][115];
int g[35][115][20][115];

int qpow(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) {
			ans=1ll*ans*x%mod;
		}
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ans;
}

signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,K;
	cin>>n>>m>>K;
	for(int i=0; i<=m; i++) {
		cin>>v[i];
		for(int j=0; j<=n; j++) {
			val[i][j]=qpow(v[i],j);
		}
	}
	fact[0]=inv[0]=1;
	for(int i=1; i<=n; i++) {
		fact[i]=1ll*fact[i-1]*i%mod;
	}
	inv[n]=qpow(fact[n],mod-2);
	for(int i=n-1; i>=1; i--) {
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
	for(int i=0; i<=n; i++) {
		g[i][0][i>>1][i&1]=f[i][0][i>>1][i&1]=1ll*fact[n]*inv[i]%mod*val[0][i]%mod;
	}
	//k or K !!!
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			for(int k=0; k<=K; k++) {
//				for(int w=5; w<=j; w++) {
				if(j>=5) {
					for(int p=1; p<=i; p++) {
						for(int ABCD=0; ABCD<=15; ABCD++) {
							int abcd=p>>1;
							if(k-popcount(ABCD)-(p&1)<0) {
								continue;
							}
//							ll sum=0;
//							for(int w=5; w<=j; w++) {
//								sum+=f[i-p][j-w][ABCD][k-popcount(ABCD)-(p&1)];
//								sum%=mod;
//							}
//							if(g[i-p][j-5][ABCD][k-popcount(ABCD)-(p&1)]!=sum) {
//								for(int w=5; w<=j; w++) {
//									cout<<f[i-p][j-w][ABCD][k-popcount(ABCD)-(p&1)]<<"\n";
//								}
//								cout<<i<<" "<<j<<" "<<ABCD<<" "<<k-popcount(ABCD)-(p&1)<<"\n";
//								cout<<g[i-p][j-5][ABCD][k-popcount(ABCD)-(p&1)]<<" "<<sum<<"\n";
//							}
							f[i][j][abcd][k]=(f[i][j][abcd][k]+1ll*inv[p]*g[i-p][j-5][ABCD][k-popcount(ABCD)-(p&1)]%mod*val[j][p])%mod;
						}
					}
				}
//				}
				if(j>=4) {
					int w=4;
					for(int p=1; p<=i; p++) {
						for(int ABCD=0; ABCD<=15; ABCD++) {
							int A=ABCD>>3,BCD=ABCD&7,abcd=((p+A)>>1);
							if(k-popcount(BCD)-((A+p)&1)<0) {
								continue;
							}
							f[i][j][abcd][k]=(f[i][j][abcd][k]+1ll*inv[p]*f[i-p][j-w][ABCD][k-popcount(BCD)-((A+p)&1)]%mod*val[j][p])%mod;
						}
					}
				}
				if(j>=3) {
					int w=3;
					for(int p=1; p<=i; p++) {
						for(int ABCD=0; ABCD<=15; ABCD++) {
							int CD=ABCD&3,B=(ABCD>>2)&1,AB=ABCD>>2,abcd=((p+AB)>>1);
							if(k-popcount(CD)-((B+p)&1)<0) {
								continue;
							}
							f[i][j][abcd][k]=(f[i][j][abcd][k]+1ll*inv[p]*f[i-p][j-w][ABCD][k-popcount(CD)-((B+p)&1)]%mod*val[j][p])%mod;
						}
					}
				}
				if(j>=2) {
					int w=2;
					for(int p=1; p<=i; p++) {
						for(int ABCD=0; ABCD<=15; ABCD++) {
							int D=ABCD&1,C=(ABCD>>1)&1,ABC=ABCD>>1,abcd=((p+ABC)>>1);
							if(k-popcount(D)-((C+p)&1)<0) {
								continue;
							}
							f[i][j][abcd][k]=(f[i][j][abcd][k]+1ll*inv[p]*f[i-p][j-w][ABCD][k-popcount(D)-((C+p)&1)]%mod*val[j][p])%mod;
						}
					}
				}
				if(j>=1) {
					int w=1;
					for(int p=1; p<=i; p++) {
						for(int ABCD=0; ABCD<=15; ABCD++) {
							int D=ABCD&1,abcd=((p+ABCD)>>1);
							if(k-((D+p)&1)<0) {
								continue;
							}
							f[i][j][abcd][k]=(f[i][j][abcd][k]+1ll*inv[p]*f[i-p][j-w][ABCD][k-((D+p)&1)]%mod*val[j][p])%mod;
						}
					}
				}
			}
		}
		for(int i=0; i<=n; i++) {
			for(int k=0; k<=K; k++) {
				for(int abcd=0; abcd<=15; abcd++) {
					g[i][j][abcd][k]=(g[i][j-1][abcd][k]+f[i][j][abcd][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int j=0; j<=m; j++) {
		for(int k=0; k<=K; k++) {
			for(int abcd=0; abcd<=15; abcd++) {
				if(k+popcount(abcd)<=K) {
//					if(f[n][j][abcd][k])cout<<n<<" "<<j<<" "<<abcd<<" "<<k<<": "<<f[n][j][abcd][k]<<"\n";
					ans=(ans+f[n][j][abcd][k])%mod;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
