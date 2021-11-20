#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,K,val[110],f[110][35][35][35],jc[110]={1},ny[110]={1},pw[110][110],ans=0;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
void upd(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;i++)scanf("%d",&val[i]);
	for(int i=0;i<=m+6;i++){
		pw[i][0]=1;
		if(i<=m)for(int j=1;j<=n;j++)pw[i][j]=1ll*pw[i][j-1]*val[i]%mod;
	}
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	for(int i=0;i<=n;i++)f[0][i][i][0]=1ll*pw[0][i]*ny[i]%mod;
	for(int i=0;i<m+6;i++){
		int A=0;
		if(i<=m)A=n;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=j;k++){
				for(int p=0;p<=j;p++){
					for(int q=0;q<=n-j&&q<=A;q++){
						upd(f[i+1][j+q][q+(k>>1)][p+(k&1)],1ll*f[i][j][k][p]*pw[i+1][q]%mod*ny[q]%mod);
					}
				}
			}
		}
	}
	for(int x=0;x<=K;x++)ans=(ans+1ll*f[m+6][n][0][x]*jc[n])%mod;
	cout<<ans;
	return 0;
}
