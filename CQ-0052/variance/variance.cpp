#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
typedef unsigned long long ull;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct node{ int a[16]; };
int n, ans = INF;
int arr[16];
map<ull, bool> mp;
queue<node> q;
//20 ~ 32 ·Ö²»µÈ 
signed main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	n = read();
	node add;
	for(register int i = 1; i <= n; i++) add.a[i] = read();
	ull val = 0;
	for(register int i = 1; i <= n; i++) val = val * 131 + add.a[i];
	mp[val] = true, q.push(add);
	int tim = 0;
	while(!q.empty()){
		node x = q.front(); q.pop();
		tim++;
		double res = 0, sum = 0;
		for(register int i = 1; i <= n; i++) res = res + x.a[i];
		res /= n;
		for(register int i = 1; i <= n; i++) sum = sum + (x.a[i] - res) * (x.a[i] - res);
		sum *= n;
		ans = min(ans, (int)sum);
		if(tim >= 2e6) break;
		for(register int i = 2; i <= n - 1; i++){
			add = x, val = 0;
			add.a[i] = add.a[i - 1] + add.a[i + 1] - add.a[i];
			for(register int i = 1; i <= n; i++) val = val * 131 + add.a[i];
			if(mp.find(val) != mp.end()) continue;
			mp[val] = true, q.push(add);
		}
	}
//	cout << tim << "\n";
	printf("%lld\n", ans);
	return 0;
}
