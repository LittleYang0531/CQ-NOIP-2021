#include<bits/stdc++.h>
#define ll long long
#define getchar gc
using namespace std;
const int Mxdt=1e5;
inline char gc() {
	static char buf[Mxdt+5],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}

inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=55,M=105,mod=998244353;
inline void cadd(int &x,int y) {x=((x+=y)>=mod?x-mod:x); }
inline int qpow(int x,int y) {
	int res=1;
	for(; y; y>>=1) {
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
	}
	return res;
}

int n,m,K,v[M],pw[M][N],fac[N],ifac[N];
int f[M][N][N][N],cnt[N];

inline void Init(int lim) {
	for(int i=fac[0]=1; i<=lim; ++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[lim]=qpow(fac[lim],mod-2);
	for(int i=lim; i; --i) ifac[i-1]=1ll*ifac[i]*i%mod;
}

int main() {
//	system("fc sequence.out sequence2.ans");
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=Rd(),m=Rd()+1,K=Rd(); Init(n);
	for(int i=1; i<=m; ++i) {
		int v=Rd();
		for(int j=pw[i][0]=1; j<=n; ++j) pw[i][j]=1ll*pw[i][j-1]*v%mod;
	}
	for(int k=1; k<=n; ++k) cnt[k]=cnt[k>>1]+(k&1);
	f[0][0][0][0]=fac[n];
	for(int i=1; i<=m; ++i) 
	for(int j=0; j<=K; ++j)
	for(int k=0; k<=n; ++k) 
	for(int u=0,lst; u<=k; ++u) if(lst=f[i-1][j][k][u]){
		for(int t=0; k+t<=n&&j+(u+t&1)<=K; ++t) 
			cadd(f[i][j+(u+t&1)][k+t][u+t>>1],1ll*lst*pw[i][t]%mod*ifac[t]%mod);
	}
	int ans=0;
	for(int j=0; j<=K; ++j)
	for(int u=0; j+cnt[u]<=K; ++u)
		cadd(ans,f[m][j][n][u]);
	
	printf("%d\n",ans);
	return 0;
}

