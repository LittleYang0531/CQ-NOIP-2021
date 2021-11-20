#include<bits/stdc++.h>
#define ll long long
#define Re register
using namespace std;

const int N = 35, M = 105;
const ll mod = 998244353;

int n, m, k, a[M*2];
ll v[M], fac[N*2], inv_f[N*2], ans = 0 ;

ll ksm(ll x,ll y){
	ll ret=1, nown=x;
	while(y){
		if(y&1) ret = ret * nown % mod;
		nown = nown * nown % mod;
		y >>= 1;
	}
	return ret;
}

void init(int maxn){
	fac[0] = 1;
	for(int i=1;i<=maxn;i++)
		fac[i] = fac[i-1] * i % mod;
	inv_f[maxn] = ksm(fac[maxn], mod-2);
	
	inv_f[0] = 1;
	
	for(int i=maxn-1;i>=1;i--) 
		inv_f[i] = inv_f[i+1] * (i+1) % mod;
}

void dfs(int step, int lim){
	if(step > n){
		int jw = 0, las = 0;
		for(Re int i=0;las || i <= m;++i){
			las = (a[i] + las) / 2;
			jw += las;
		}
		if(n - jw > k) return ;
		ll nans = fac[n];
		for(Re int i=0;i<=m;++i){
			nans = nans * ksm(v[i], a[i]) % mod;
			nans = nans * inv_f[ a[i] ] % mod;
		}
		ans = (ans + nans) % mod;
		return ;
	}
	for(Re int i=lim;i<=m;++i){
		++a[i] ;
		dfs(step+1, i);
		--a[i] ;
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	
	for(int i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	
	init(50);
	
	dfs(1, 0);
	
	printf("%lld",ans);
	
	return 0;
}
