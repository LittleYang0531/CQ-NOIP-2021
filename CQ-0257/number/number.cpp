#include <bits/stdc++.h>
using namespace std;
int t,n;
bool f[10000001];
bool check(int x)
{
	while (x)
	{
		if (x%10==7)
		{
			return true;
		}
		x/=10;
	}
	return false;
}
void find(int x)
{
	while (f[++x]);
	printf("%d\n",x);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for (int i=1; i<=10000000; i+=1)
	{
		if (!f[i])
		{
			if (check(i))
			{
				for (int j=1; j*i<=10000000; j+=1)
				{
					if (!f[i*j])
					{
						f[j*i]=1;
					}
				}
			}
		}
	}
	while (t--)
	{
		scanf("%d",&n);
		if (f[n])
		{
			printf("%d\n",-1);
		}
		else
		{
			find(n);
		}
	}
	return 0;
}
