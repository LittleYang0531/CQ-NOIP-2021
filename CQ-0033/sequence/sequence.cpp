#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;bool vis=0;
	char k;
	do (k=getchar())=='-'&&(vis=1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
# define mod 998244353
int n,m,k;
ll f[105][35][35][35],inv[155],v[105][35];
ll qkpow(ll n,ll m){
	ll t=1;
	for(;m;m>>=1,n=n*n%mod)
		if(m&1)t=t*n%mod;
	return t;
}int Bx(int x){return x?Bx(x&x-1)+1:0;}
int main(){fre("sequence");
	n=read,m=read,k=read;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i)inv[i]=inv[i-1]*inv[i]%mod;
	for(int i=0;i<=m;++i){
		v[i][0]=1;
		v[i][1]=read;
		for(int j=2;j<=n;++j)v[i][j]=v[i][j-1]*v[i][1]%mod;
	}
	f[0][0][0][0]=1;
	for(int i=0;i<=m;++i){
		for(int j=0;j<=k;++j)
			for(int w=0;w<=n;++w)
				for(int x=0;x<32;++x)
					for(int y=0;w+y<=n;++y){
						if((x+y&1)&&j==k)continue;
						f[i+1][j+(x+y&1)][x+y>>1][w+y]=(f[i+1][j+(x+y&1)][x+y>>1][w+y]+f[i][j][x][w]*v[i][y]%mod*inv[y])%mod;
					}
	}
	ll t=0;
	for(int i=0;i<=k;++i)
		for(int j=0;j<32;++j)if(Bx(j)+i<=k)t=(t+f[m+1][i][j][n])%mod;
	for(int i=2;i<=n;++i)t=t*i%mod;
	cout<<t;
	return 0;
}
/*
5 1 1
2 1	
*/
