#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
int a[N];
int sum;
double p;
double c[N];
double ans = 1e9;
pair<int,double> zb[N];
int read(){
	int x = 0, p = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')
			p = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}
void change(int x, int t){
	int y;
	y = a[x - 1] + a[x + 1] - a[x];
	if(y == a[x])
	{
		change(zb[t + 1].first, t + 1);
		return;
	}
	a[x] = y;
}
void pj(){
	sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += a[i];
	p = sum / (n * 1.0);
}
double fc(){
	double sum2 = 0;
	for(int i = 1; i <= n; i ++)
		sum2 += (a[i] - p) * (a[i] - p);
	return sum2 / (n * 1.0);
}
bool cmp(pair<int,double> a, pair<int,double> b)
{
	return a.second > b.second;
}
void solve(){
	pj();
	if(ans < fc())
		return;
	else ans = fc();
	for(int i = 2; i < n; i ++)
		zb[i].first = i, zb[i].second = abs(a[i] - p);
	sort(zb + 2, zb + n, cmp);
	change(zb[2].first, 2);
	solve();
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	solve();
	cout << ans * n * n << endl;
	return 0;
}
