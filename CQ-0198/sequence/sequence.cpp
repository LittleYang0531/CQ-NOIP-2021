#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 998244353

inline void read(ll &x) {
	x=0;
	int f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1;
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	c*=f;
}
int now=0, use[105];
ll n, m, k, ANS=0;
ll dp[105][140000];
ll v[105];
void dpp() {
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int j=1; j<=n*(1<<m); ++j) {
		for(int k=1; k<=n; ++k) {
			for(int i=0; i<=m; ++i){
				if(j>=(1<<i))dp[k][j]=(dp[k][j]+dp[k-1][j-(1<<i)]*v[i]%mod)%mod;
//				if(dp[k][j]<0) puts("ER");
			} 
		}
	}
	/*
	for(int j=1; j<=20; ++j) {
		printf("%-2d:", j);
		for(int k=1; k<=n; ++k) {
			printf("%-2d ", dp[k][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	putchar('\n');
	/**/

}
int count(ll x){
	int aa=0;
	while(x){
		if(x&1) ++aa;
		x>>=1;
	}
	return aa;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	read(n), read(m), read(k);
	for(int i=0; i<=m; ++i) {
		read(v[i]);
	}
	dpp();
//	cout << n*(1<<m) << endl;
	for(int i=n; i<=n*(1<<m); ++i){
		if(count(i)<=k){
			ANS=(ANS+dp[n][i])%mod;
		}
	}
	printf("%lld", ANS);
	return 0;
}

