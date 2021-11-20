#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll dp[105][33][33][33];
int n,m,K;
ll v[105],fac[105],nd[105];
ll qp(ll b,ll p){
	ll ans=1;
	while(p){
		if(p&1)ans=ans*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return ans;
} 
/*
5 1 1
2 1
*/
ll C[105][105]; 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++){ 
		int now=i;
		while(now){ 
			if(now%2)nd[i]++;
			now/=2;  
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=100;i++){
		C[i][0]=1;
		for(int j=1;j<=100;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod; 
		}
	}  
	m++;
	for(int i=1;i<=m;i++){
		scanf("%lld",&v[i]);
	} 
	dp[0][0][0][0]=1; 
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int now=0;now<=min(i,K);now++){
				for(int lst=0;lst<=j/2;lst++){
					for(int k=0;k<=j;k++){
						int w=k+lst;
						int nw=w%2;
						if(nw&&now==0)continue;
						dp[i][j][now][w/2]=(dp[i][j][now][w/2]+dp[i-1][j-k][now-nw][lst]*qp(v[i],k)%mod*C[n-(j-k)][k]%mod)%mod;
 					} 
				} 
			}
		}
	}  
	ll ans=0;
	for(int i=0;i<=K;i++){
		for(int w=0;w<=n;w++){ 
			if(i+nd[w]>K)continue;
			ans=(ans+dp[m][n][i][w])%mod;
//			ans=(ans+dp[m][n][i][w])%mod;		
		}
	}
	printf("%lld\n",ans);
	return 0;
}
