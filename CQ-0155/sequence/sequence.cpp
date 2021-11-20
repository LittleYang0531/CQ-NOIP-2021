#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int N = 35,mod = 998244353;
int v[N],num[N],inv[N];
int n,m,K;

inline int cntone(int num){
	int ans = 0;
	while(num){
		ans++;
		num &= num-1;
	}
	return ans;
}

inline int C(int a,int b){
	return num[a]*inv[a-b]%mod*inv[b]%mod;
}

inline int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)
			ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

namespace stb1{
	int ans = 0;
	int d[N];
	inline void dfs(int num,int dep=0,int nlas=n){
		if(!num&&!nlas){
			int geshu = 1;
			int las = n;
			for(int k=0;las;k++){
				geshu *= C(las,d[k]);
				geshu %= mod;
				las -= d[k];
			}
			int tmpnum = 1;
			for(int k=0;k<dep;k++)
				tmpnum = tmpnum*ksm(v[k],d[k])%mod;
			ans = (ans+tmpnum*geshu%mod)%mod;
			return;
		}
		if(dep>m)
			return;
		if((1<<dep)>num||!nlas)
			return;
		for(d[dep]=min(nlas,num/(1<<dep));~d[dep];d[dep]--)
			dfs(num-d[dep]*(1<<dep),dep+1,nlas-d[dep]);
	}
	signed main(){
		for(int k=n;k<=n*(1<<m);k++){
			if(cntone(k)>K)
				continue;
			dfs(k);
		}
		printf("%lld",ans);
		return 0;
	}
}

signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int k=0;k<=m;k++)
		scanf("%lld",v+k);
	inv[0] = num[0] = 1;
	for(int k=1;k<=n;k++)
		num[k] = num[k-1]*k%mod;
	inv[n] = ksm(num[n],mod-2);
	for(int k=n-1;k;k--)
		inv[k] = inv[k+1]*(k+1)%mod;
	if(n<=12){
		stb1::main();
		return 0;
	}
	return 0;
}
/*
5 1 1
2 1
*/
