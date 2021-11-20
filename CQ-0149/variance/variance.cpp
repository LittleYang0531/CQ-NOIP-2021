#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, a[N], b[N], ans = 0x3f3f3f3f;
map<string, int>mp;
void update(int d[N])
{
	int s = 0, res = 0;
	for (int i = 1;i <= n;i ++)
	{
		s += d[i];res += n * d[i] * d[i];
	}
	res -= s * s;
	ans = min(ans, res);
}
string ccc(int d[N])
{
	string s;
	for (int i = 1;i <= n;i ++) s += (char)d[i];
	return s; 
}
void dfs(int c[N])
{
	int d[N];
	for (int i = 2;i < n;i ++){
		memcpy(d, c, sizeof d);
		d[i] = d[i - 1] + d[i + 1] - d[i];
		string s = ccc(d);
		if (mp.find(s) == mp.end()){
			update(d);
			mp[s] = 1;
			dfs(d);
		} 
	}
}
int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	dfs(a);
	cout << ans;
	return 0;
}
