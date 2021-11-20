#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int mod = 998244353;
int n,m,K,mc[35],f[110][35][35][35],v[110],ans,C[35][35],bt[35];
int MOD(int x) {return x>=mod?x-mod:x;}
void Add(int&x,int y) {(x+=y)>=mod?x-=mod:x;}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=m+1;i++) v[i]=read();
	for(int i=0;i<=n;C[i][0]=1,i++)
		for(int j=1;j<=i;j++) C[i][j]=MOD(C[i-1][j]+C[i-1][j-1]);
	f[0][0][0][0]=1;
	for(int i=0;i<=m;i++) {
		mc[0]=1;for(int j=1;j<=n;j++) mc[j]=1ll*mc[j-1]*v[i+1]%mod;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=K;k++)
				for(int S=0;S<16;S++) if(f[i][j][k][S])
					for(int l=0;j+l<=n;l++) {
						Add(f[i+1][j+l][k+((S+l)&1)][(S+l)>>1],1ll*f[i][j][k][S]*mc[l]%mod*C[j+l][l]%mod);
					}
	}
	for(int S=0;S<16;S++) {
		bt[S]=bt[S>>1]+(S&1);
		for(int i=0;i+bt[S]<=K;i++) Add(ans,f[m+1][n][i][S]);
	}
	cout<<ans<<'\n';
	return 0;
}
