#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll v[105], cnt[25], C[105][105], res, n, m, k, p[25], rp[2200005];
bool mk[31][1230005], vis[2200005];

inline ll KSM(ll a, ll b)
{
	ll ans = 1;
	while (b >= 1)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	} return ans;
}

ll cal()
{
	ll tmp = n, anss = 1;
	for (ll i = 0; i <= m; i++)
	{
        if (!tmp) return anss;
		anss = anss * C[tmp][cnt[i]] % mod * KSM(v[i], cnt[i]) % mod;
		tmp -= cnt[i];
	} return anss;
}

void dfs(ll x, ll y, ll num)
{
	if (y * p[num] < x) return;
	if (!x || !y)
	{
		if (!x && !y) res = (res + cal()) % mod;
		return;
	} 
	for (ll i = 0; i <= num; i++) if (x >= p[i]) ++cnt[i], dfs(x - p[i], y - 1, i), --cnt[i];
}

ll check(ll x)
{
	ll ans = 0;
	while (x >= 1) ans += (x & 1), x >>= 1;
	return ans;  
}

inline void solve1()
{
	for (ll i = 1; i <= p[m] * n; i++) 
	{
		if (vis[i] == 1) mk[1][i] = 1;
		for (ll j = 2; j <= n; j++) for (ll l = 0; p[l] <= i && l <= m; l++)
			if (mk[j - 1][i - p[l]]) mk[j][i] = 1;
	} 
	ll ans = 0;
	for (ll i = n; i <= p[m] * n; i++)
	{
		if (mk[n][i] && check(i) <= k) 
		{
			res = 0, dfs(i, n, m);
			ans = (ans + res) % mod;
		}
	} printf("%lld\n", ans);
}

ll q[105], anss, ct[105];

ll judge()
{
	memset(ct, 0, sizeof ct);
	ll tmp = 0, res = 1, lst = 0;
	for (ll i = 1; i <= n; i++)
	{
		++ct[q[i]];
		if (q[i] != q[i + 1] || i == n) res = res * C[n - lst][i - lst] % mod * KSM(v[q[i]], i - lst) % mod, lst = i;
	} 
	for (ll i = 0; i <= 60; i++) 
	{
		if (!ct[i]) continue;
		ct[i + 1] += ct[i] / 2;
		if (ct[i] & 1) ++tmp;
	} if (tmp > k) return 0;
	return res;
}

void dfss(ll pos, ll lim)
{
	if (!pos) return void(anss = (anss + judge()) % mod);
	for (ll i = 0; i <= lim; i++) q[pos] = i, dfss(pos - 1, i);
}

void solve3()
{
	dfss(n, m);
	printf("%lld\n", anss);
}

signed main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	p[0] = 1, vis[1] = 1;
	for (ll i = 1; i <= 21; i++) p[i] = p[i - 1] * 2, vis[p[i]] = 1, rp[p[i]] = i;
	for (ll i = 0; i <= m; i++) scanf("%lld", &v[i]);
	for (ll i = 1; i <= 100; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (ll j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	} 
	if (m <= 12) return solve1(), 0;
	solve3();
}
