#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
const int maxn=105,mod=998244353;
ll f[2][maxn][maxn][maxn],fac[maxn],inv[maxn],pw[maxn][maxn],ans;
int n,m,K,v[maxn];
ll qpow(ll x,int y) {
	ll w=1;
	while(y) {
		if(y&1)w=w*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return w;
}
ll C(int x,int y) {
	if(y>x)return 0;
	return fac[x]*inv[x-y]%mod*inv[y]%mod;
}
int bitcount(int x) {
	int cnt=0;
	while(x)cnt++,x-=x&(-x);
	return cnt;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequene.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=0; i<=m; i++)v[i]=read();
	fac[0]=1;
	for(int i=1; i<=n; i++)fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n; i; i--)inv[i-1]=inv[i]*i%mod;
	for(int i=0; i<=m; i++) {
		pw[i][0]=1;
		for(int j=1; j<=n; j++)pw[i][j]=pw[i][j-1]*v[i]%mod;
	}
	f[1][0][0][0]=1;
	for(int i=0; i<=m; i++) {
		int now=i&1,lst=now^1;
		memset(f[now],0,sizeof(f[now]));
		for(int j=0; j<=n; j++)
			for(int k=0; k<=min(j,K); k++)
				for(int w=0; w<=j; w++) {
					if(!f[lst][j][k][w])continue;
					for(int x=0; x<=n-j; x++)
						f[now][j+x][k+((w+x)&1)][(w+x)/2]=(f[now][j+x][k+((w+x)&1)][(w+x)/2]+f[lst][j][k][w]*pw[i][x]%mod*C(n-j,x))%mod;
				}
	}
	for(int i=0; i<=K; i++)
		for(int j=0; j<=n; j++)
			if(i+bitcount(j)<=K)ans=(ans+f[m&1][n][i][j])%mod;
	printf("%lld",ans);
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊！1145141919810

