#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int n, a[105], value, sum, ans = 2147483647, u[105];
bool book[10000005];
void dfs()
{
	if (book[value-sum*sum])
	{
		return ;
	}
	book[value-sum*sum] = 1;
	ans = (ans)>(value-sum*sum)?(value-sum*sum):(ans);
	for (int p=2;p<n;p++)
	{
		int temp = u[p-1]+u[p+1]-u[p], oil;
		value-=u[p]*u[p]*n;
		value+=temp*temp*n;
		sum-=u[p];
		sum+=temp;
		oil = u[p];
		u[p] = temp;
		dfs();
		u[p] = oil;
		value+=u[p]*u[p]*n;
		value-=temp*temp*n;
		sum+=u[p];
		sum-=temp;
	}
	return ;
}
int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int p=1;p<=n;p++)
	{
		scanf("%d", &a[p]);
		u[p] = a[p];
		value+=a[p]*a[p]*n;
		sum+=a[p];
	}
	dfs();
	cout<<ans;
	return 0;
}
