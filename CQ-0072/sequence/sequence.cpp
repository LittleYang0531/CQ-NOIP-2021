#include<cstdio>
const int N=1<<13,M=998244353,V=35;
int dp[V][V*N],n,m,k,a[V];
int po(int b){
	int ans=0;
	while(b){
		ans++;
		b-=(b&(-b));
	}
	return ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=i*(1<<m);j++){
			for(int z=0;z<=m;z++)
				dp[i+1][j+(1<<z)]=(dp[i+1][j+(1<<z)]+1ll*dp[i][j]*a[z]%M)%M;
		}
	}
	int ans=0;
	for(int j=n;j<=n*(1<<m);j++){
		if(po(j)<=k) ans=(ans+dp[n][j])%M;
	}
	printf("%d",ans);
	return 0;
}
