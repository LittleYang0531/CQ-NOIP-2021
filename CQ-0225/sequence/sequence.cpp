#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 110, mod = 998244353;
LL n, m, k, a[N], t[N], ans;
bool geshu(LL x)
{
	LL cnt = 0;
	while(x)
	{
		cnt++;
		x -= x & -x;
	}
	return cnt <= k;
}
LL pow_(int x)
{
	LL s = 1;
	for(int i = 1; i <= x; i++)
		s *= 2;
	return s;
}
int pailie()
{
	LL s = 1, now = 0;
	for(int i = 1; i <= n; i++)
	{
		s *= (n - i + 1);
		if(t[i] == t[i - 1])
		{
			now++;
			s /= now;
		}
		else
			now = 1;
		s %= mod;
	}
	return s;
}
void dfs(int x)
{
	if(x > n)
	{
		LL s = 0;
		for(int i = 1; i <= n; i++)
			s += pow_(t[i]);
		if(geshu(s))
		{
			s = 1;
			for(int i = 1; i <= n; i++)
				s = s * a[t[i]] % mod;
			s = s * pailie() % mod;
			ans = (ans + s) % mod;
		}
		return;
	}
	for(int i = t[x - 1]; i <= m; i++)
	{
		t[x] = i;
		dfs(x + 1);
	}
}
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i <= m; i++)
		cin >> a[i];
	t[0] = -1;
	dfs(1);
	cout << ans << endl;
	return 0;
}

