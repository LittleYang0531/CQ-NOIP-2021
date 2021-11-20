#include<bits/stdc++.h>
using namespace std;
long long q_pow(long long a,long long b,long long mod){
	long long ans=1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
long long n,m,k,dp[115][35][45][35],mod=998244353,a[1005],ans,jc[100005],inv[100005];
struct st{
	long long a,b;
	st(){}
	st(long long A,long long B){
		a=A;
		b=B;
	}
};
vector<st>rp[105];
void rppppppp(long long x){
	long long rpp=0,rpppp=0,rppp=1;
	for(int lzmnb=0;lzmnb<=n;lzmnb++){
		rpp=lzmnb;
		rpppp=lzmnb;
		for(long long i=0;i<=n;i++){
			for(long long j=0;j<=40;j++){
				for(long long l=0;l<=k;l++){
					long long kk=j+rpppp;
					if(i+rpp>n)break;
					if(kk&1){
						if(l+1>k)continue;
						dp[x+1][i+rpp][kk>>1][l+1]+=dp[x][i][j][l]*rppp%mod*jc[i+rpp]%mod*inv[i]%mod*inv[lzmnb]%mod;
						dp[x+1][i+rpp][kk>>1][l+1]%=mod;
					}else{
						dp[x+1][i+rpp][kk>>1][l]+=dp[x][i][j][l]*rppp%mod*jc[i+rpp]%mod*inv[i]%mod*inv[lzmnb]%mod;
						dp[x+1][i+rpp][kk>>1][l]%=mod;
					}
				}
			}
		}
		rppp*=a[x];
		rppp%=mod;
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	jc[0]=1;
	for(long long i=1;i<=100000;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	inv[0]=1;
	inv[100000]=q_pow(jc[100000],mod-2,mod);
	for(long long i=99999;i>=1;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<=m;i++){
		dp[i][0][0][0]=1;
		rppppppp(i);
	}
	for(long long i=0;i<=k;i++){
		for(int j=0;j<=40;j++){
			int op=j,rppp=0;
			while(op){
				rppp+=(op&1);
				op>>=1;
			}
			if(rppp+i<=k){
				ans+=dp[m+1][n][j][i];
				ans%=mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
