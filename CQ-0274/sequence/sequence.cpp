#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1),s+=(ch-'0'),ch=getchar();
	return s*t;
}
inline void freo(){freopen("sequence.in","r",stdin),freopen("sequence.out","w",stdout);}
int n,m,K;
int v[102],f[32][100002];
inline int fast_pow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a;
		a=a*a,b>>=1;
	}
	return ret;
}
inline int calc(int x){
	int cnt=0;
	while(x) cnt+=(x&1),x>>=1;
	return cnt;
}
int tmp[12],ans;
inline void dfs(int p){
	if(p==n+1){
		int now=0;
		for(int i=1;i<=n;++i) now+=fast_pow(2,tmp[i]);
		if(calc(now)<=K){
			int cnt=1;
			for(int i=1;i<=n;++i) (cnt=cnt*v[tmp[i]]%mod)%=mod;
			(ans+=cnt)%=mod;
		}
		return;
	}
	for(int i=0;i<=m;++i){
		tmp[p]=i;
		dfs(p+1);
	}
}
inline void solve(){dfs(1);}
signed main(){
	freo();
	n=read(),m=read(),K=read();
	int mx=n*fast_pow(2,m);
	for(int i=0;i<=m;++i) v[i]=read();
	if(n<=5&&m>=20){
		solve();
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=0;i<=m;++i) f[1][fast_pow(2,i)]=v[i];
	for(int i=1;i<n;++i){
		for(int j=i;j<=mx;++j){
			if(calc(j)>i) continue;
			for(int k=0;k<=m;++k){
				(f[i+1][j+fast_pow(2,k)]+=f[i][j]*v[k]%mod)%=mod;
			}
		}
	}
	for(int i=n;i<=mx;++i){
		if(calc(i)>K) continue;
		(ans+=f[n][i]%mod)%=mod;
		//cout<<i<<" "<<f[n][i]<<'\n';
	}
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=mx;++j){
			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
		}
	}*/
	printf("%lld\n",ans);
return 0;
}
/*
5 1 1
2 1
*/
