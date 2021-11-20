#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e2 + 5;
const ll Mod = 998244353;
int v[MAXN],n,m,k;
inline int read(int &x)
{
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')ch = getchar();
	while('0' <= ch && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
ll f[MAXN],d[MAXN],inv[MAXN],dp[MAXN][MAXN][MAXN];
ll C(int x,int y)
{
	if(x < y)return 0;
	return (f[x] * d[y] % Mod) * d[x - y] % Mod;
}
ll ksm(ll x,ll y)
{
	ll ans = 1;
	while(y)
	{
		if(y & 1)ans = (ans * x) % Mod;
		x = (x * x) % Mod;
		y >>= 1;
	}
	return ans;
}
inline int popcnt(int x)
{
	int ans = 0;
	while(x)
	{
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}
ll ans = 0;
void dfs(int x,ll sum,int now)
{
	if(popcnt(now) > k)return;
	if(x > n)
	{
		ans = (ans + sum) % Mod;
		return;
	}
	for(R int i = 0;i <= m; i++)
		dfs(x + 1,sum * v[i] % Mod,now + (1 << i));
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m),read(k);
	for(R int i = 0;i <= m; i++)
		read(v[i]);
	dfs(1,1,0);
	printf("%lld\n", ans);
	return 0;
}
