#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[102][33][33][33],a[103],Pow[102][33],C[103][103];
int n,m,Maxk;
int getcnt(int x){
	int ans=0;
	while(x){
		if(x&1)++ans;
		x>>=1;
	}
	return ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    cin>>n>>m>>Maxk;
    for(int i=1;i<=m+1;i++)scanf("%lld",&a[i]);
    for(int i=0;i<=100;i++)C[i][0]=1;
	for(int i=1;i<=100;i++){
    	for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    	C[i][i]=1ll;
	}
    for(int i=1;i<=m+1;i++){
    	Pow[i][0]=1ll;
    	for(int j=1;j<=n;j++)Pow[i][j]=Pow[i][j-1]*a[i]%mod;
	}
    dp[0][0][0][0]=1ll;
    for(int i=0;i<=m;i++){
    	for(int j=0;j<=n;j++){
    		for(int k=0;k<=Maxk;k++){
    			for(int l=0;l<=n;l++){
    				for(int l1=0;l1<=n;l1++){
    					int now1=((l1>>1)+l);
    					if(j+l>n)continue;
    					if(now1&1){
    						if(k+1>Maxk)continue;
    						dp[i+1][j+l][k+1][now1]=(dp[i+1][j+l][k+1][now1]+dp[i][j][k][l1]%mod*Pow[i+1][l]%mod*C[j+l][l]%mod)%mod;
						}
    					else dp[i+1][j+l][k][now1]=(dp[i+1][j+l][k][now1]+dp[i][j][k][l1]%mod*Pow[i+1][l]%mod*C[j+l][l]%mod)%mod;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=Maxk;i++)
	 for(int j=0;j<=n;j++)
	  if(getcnt(j)+i-(j&1)<=Maxk){
	  	ans=(ans+dp[m+1][n][i][j])%mod;
	  }
	cout<<ans;
	return 0;
}
