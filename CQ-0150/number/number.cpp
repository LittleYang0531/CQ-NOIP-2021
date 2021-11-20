#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
int prime[10000005], tot, len, ans[10000005];
bitset<10000005> book;
bool check(int i)
{
	while (i>0)
	{
		if (i%10==7)
		{
			return 1;
		}
		i/=10;
	}
	return 0;
}
void Prime(int n)
{
	for (int p=1;p<=n;p++)
	{
		if (check(p))
		{
			book[p] = 1;
			prime[++tot] = p;
		}
	}
	for (int p=2;p<=n;p++)
	{
		for (int k=1;(k<=tot&&prime[k]*p<=n);k++)
		{
			book[prime[k]*p] = 1;
			if (p%prime[k]==0)
			{
				break;
			}
		}
	}
	return ;
}
int t, u;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	Prime(10000001);
	int last = 0;
	for (int p=1;p<=10000001;p++)
	{
		if (p!=1)
		{
			ans[last] = p;
		}
		if (!book[p])
		{
			last = p;
		}
	}
	scanf("%d", &t);
	for (int tl=1;tl<=t;tl++)
	{
		scanf("%d", &u);
		if (book[u])
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", ans[u]);
		}
	}
	return 0;
}
