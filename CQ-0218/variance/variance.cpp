#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 5;
int a[MAXN],n;
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
ull Seed = 133;
ll minn = 1e18;
map <ull,int> M;
void dfs()
{
	ll ans1 = 0,ans2 = 0;
	ull Hash = 0;
	for(R int i = 1;i <= n; i++)
	{
		ans1 = (ans1 + a[i] * a[i]);
		ans2 = (ans2 + a[i]);
		Hash = (Hash * Seed + a[i]);
	}
	if(M[Hash] != 0)return;
	M[Hash] = 1;
	minn = min(minn,n * ans1 - ans2 * ans2);
	for(R int i = 2;i < n; i++)
	{
		int p = a[i];
		a[i] = a[i + 1] + a[i - 1] - a[i];
		dfs();
		a[i] = p;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d", &n);
	for(R int i = 1;i <= n; i++)
		read(a[i]);
	dfs();
	printf("%lld\n", minn);
	return 0;
}
