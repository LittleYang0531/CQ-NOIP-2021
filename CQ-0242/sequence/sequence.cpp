#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

typedef long long ll;
const int MAXN=35;
const int MAXM=12;
const int MAXS=2e5+5;
const ll MOD=998244353;
int n,m,k;
ll v[MAXN];

ll power(ll a,ll b){
	ll ret=1;
	for (;b;b>>=1){
		if (b&1) ret=(ret*a)%MOD;
		a=(a*a)%MOD;
	}
	return ret;
}

namespace subtask1{
	ll dp[MAXN][MAXS];
	bool judge(){
		return n<=30&&m<=12;
	}
	bool vaild(int S){
		int tot=0;
		for (int i=0;i<=20;i++){
			if (S&(1<<i)) tot++;
		}
		return tot<=k;
	}
	void solve(){
		const int up=n*(1<<m);
		dp[0][0]=1;
		for (int i=0;i<n;i++){
			for (int S=0;S<=up;S++){
				for (int k=0;k<=m;k++){
					int nxt=S+(1<<k);
					if (nxt>up) continue;
					dp[i+1][nxt]=(dp[i+1][nxt]+(dp[i][S]*v[k]%MOD))%MOD;
				}
			}
		}
		ll ret=0;
		for (int S=0;S<=up;S++){
			if (vaild(S)) ret=(ret+dp[n][S])%MOD;
		}
		printf("%lld\n",ret);
		exit(0);
	}
}


int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);	
	for (int i=0;i<=m;i++) scanf("%lld",&v[i]);
	if (subtask1::judge()) subtask1::solve();
	cout<<0;
	return 0;
}

// Sto Orz %%% CJG ÉúÈÕ¿ìÀÖ CJG AK NOIP
