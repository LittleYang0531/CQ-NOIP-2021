//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 105;
const int MOD = 998244353;
int n,m,k,ans;
int v[MAXN];

LL Read()
{
	LL x = 0,f = 1;char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

int dp[35][1<<18];
int cnt[1<<18];
void solve1()
{
	for(int S = 1;S < (1<<17);++ S) cnt[S] = cnt[S^(S & -S)] + 1;
	dp[0][0] = 1;
	for(int i = 0;i < n;++ i)
		for(int S = 0;S < (1<<17);++ S)
			for(int j = 0;j <= m;++ j)
				dp[i+1][S+(1<<j)] = (dp[i+1][S+(1<<j)] + 1ll * dp[i][S] * v[j]) % MOD;
	for(int S = 0;S < (1<<17);++ S)
		if(cnt[S] <= k) ans = (ans + dp[n][S]) % MOD;
}
void solve2()
{
	
}
void ck(LL mul,LL c)
{
	if(__builtin_popcount(c) <= k) ans = (ans + mul) % MOD;
}
void dfs3(int x,LL mul,LL c)
{
	if(x == n+1){ck(mul,c);return;}
	for(int i = 0;i <= m;++ i)
		dfs3(x+1,mul * v[i] % MOD,c+(1ll<<i));
}
void solve3()
{
	dfs3(1,1,0);
	Put(ans,'\n');
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = Read(); m = Read(); k = Read();
	for(int i = 0;i <= m;++ i) v[i] = Read();
	if(m <= 12) {solve1();return 0;}
	else if(n <= 5) {solve3();return 0;}
	else if(k == 1) {solve2();return 0;}
	return 0;
}
