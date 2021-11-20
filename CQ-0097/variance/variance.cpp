#include <bits/stdc++.h>

using namespace std;

int ans = 1e9, n;

struct node {
	int a[16];
};
bool operator< (node x, node y) 
{
	for (int i = 1; i < n; i++) if (x.a[i] != y.a[i]) return x.a[i] < y.a[i];
	return x.a[n] < y.a[n];
}

queue <node> Q;
map <node, bool> mp;

int cal(node tmp)
{
	int sum = 0, res = 0;
	for (int i = 1; i <= n; i++) sum += tmp.a[i];
	sum /= n;
	for (int i = 1; i <= n; i++) res += (tmp.a[i] - sum) * (tmp.a[i] - sum);
	return res;
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	node st;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &st.a[i]), st.a[i] *= n;
	mp[st] = 1, Q.push(st);
	while (!Q.empty())
	{
		node now = Q.front(); Q.pop();
		ans = min(ans, cal(now));
		for (int i = 2; i < n; i++)
		{
			node tmp = now;
			tmp.a[i] = tmp.a[i - 1] + tmp.a[i + 1] - tmp.a[i];
			if (mp.count(tmp)) continue;
			mp[tmp] = 1, Q.push(tmp);
		}
	} printf("%d\n", ans / n);
}
