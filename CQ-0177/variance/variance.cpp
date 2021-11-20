#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, sum, x, pos, a[10005];
priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll> > > q;
bool flag[10005];
ll clac(ll p) {
	ll yzh = a[p - 1] + a[p + 1], zqr = a[p - 1] + a[p + 1] - 2 * a[p];
	return n * yzh * (yzh - 2 * a[p]) - zqr * (zqr + 2 * sum);
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i], ans += a[i] * a[i];
	}
	ans = n * ans - sum * sum;
	for(int i = 2; i < n; ++i) q.push(make_pair(clac(i), i));
	flag[1] = flag[n] = true;
	while(!q.empty() && q.top().first < 0) {
		x = q.top().first, pos = q.top().second;
		q.pop();
		if(flag[pos]) continue;
		flag[pos - 1] = flag[pos + 1] = true;
		ans += x;
		if(pos > 2 && pos < n - 1) q.push(make_pair(min(clac(pos - 1), 0ll) + min(clac(pos + 1), 0ll) - x, pos));
	}
	printf("%lld", ans);
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	//QAQ
	return 0;
}
//a[p]->a[p-1]+a[p+1]-a[p]
//n*sum2-sum1^2
//n*(sum2-a[p]^2+(a[p-1]+a[p+1]-a[p])^2)-(sum1-2*a[p]+a[p-1]+a[p+1])^2
//
//n*sum2-sum1^2
//
//n*(a[p-1]^2+a[p+1]^2-2*a[p]*(a[p-1]+a[p+1])+2*a[p-1]*a[p+1])-(a[p-1]+a[p+1]-2*a[p])^2-2*sum1*(a[p-1]+a[p+1]-2*a[p])
