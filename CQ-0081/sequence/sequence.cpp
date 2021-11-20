#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,K,c[35][35],v[35];
int f[105][35][35][35],num[35];//·½°¸ºÍ 
int Mod(int x) {return x<mod?x:x-mod;}
void Add(int&x,int y) {x=Mod(x+y);}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=0; i<=n; ++i)c[i][0]=1;
	for(int i=1; i<=n; ++i)for(int j=1; j<=i; ++j)c[i][j]=Mod(c[i-1][j]+c[i-1][j-1]);
	for(int i=0; i<=m; ++i)cin>>v[i];
	for(int i=0,vb=1; i<=n; ++i)f[0][i][i&1][i>>1]=vb,vb=1ll*vb*v[0]%mod;
	for(int i=0,tmp; i<m; ++i)
		for(int j=0; j<=n; ++j)
			for(int k=0; k<=K; ++k)
				for(int l=0; l<31; ++l)if(tmp=f[i][j][k][l])
					for(int o=0,vb=1; j+o<=n; ++o,vb=1ll*vb*v[i+1]%mod)
						Add(f[i+1][j+o][k+((o+l)&1)][o+l>>1],1ll*c[j+o][o]*vb%mod*tmp%mod);
	int ans=0;
	for(int j=0; j<31; ++j)num[j]=num[j>>1]+(j&1);
	for(int i=0; i<=K; ++i)
		for(int j=0; j<31; ++j)if(i+num[j]<=K)Add(ans,f[m][n][i][j]);
	cout<<ans;
	return 0;
}
