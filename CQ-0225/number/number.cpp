#include<bits/stdc++.h>
using namespace std;
const int N = 10000010;
int t, a[N], r[N], now;
bool flag[N];
bool check(int x)
{
	while(x)
	{
		if(x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= 10000001; i++)
	{
		if(flag[i])
			continue;
		if(check(i))
			for(int j = 1; i * j <= 10000001; j++)
				flag[i * j] = 1;
		else
			now = r[now] = i;
	}
	for(int i = 1; i <= t; i++)
	{
		if(flag[a[i]])
			printf("-1\n");
		else
			printf("%d\n", r[a[i]]);
	}
	return 0;
}

