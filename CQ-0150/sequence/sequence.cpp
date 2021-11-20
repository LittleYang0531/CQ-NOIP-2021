#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m, q, print, dp[35][35];
vector<int> keg(25);
long long int v[25];
const int mod = 998244353;
set<vector<int> > s;
int C(int x, int y)
{
	if (dp[x][y]!=-1)
	{
		return dp[x][y];
	}
	long long int ans = 1, last = 2;
	for (int p=y+1;p<=x;p++)
	{
		ans*=p;
		if (last<=x-y&&ans%last==0)
		{
			ans/=last;
			last++;
		}
	}
	return dp[x][y]=ans%mod;
}
void dfs(int i)
{
	if (s.count(keg))
	{
		return ;
	}
	s.insert(keg);
	if (i==n)
	{
		long long int sum = 1, place = n;
		for (int p=0;p<20;p++)
		{
			for (int k=1;k<=keg[p];k++)
			{
				sum*=v[p];
				sum%=mod;
			}
		}
		for (int p=0;p<20;p++)
		{
			if (keg[p])
			{
				sum*=C(place, keg[p]);
				sum%=mod;
				place-=keg[p];
			}
		}
		print+=sum;
		print%=mod;
		return ;
	}
	for (int p=20;p>0;p--)
	{
		if (keg[p])
		{
			keg[p]--;
			keg[p-1]+=2;
			dfs(i+1);
			keg[p]++;
			keg[p-1]-=2;
		}
	}
	return ;
}
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &m, &q);
	for (int p=0;p<=m;p++)
	{
		scanf("%lld", &v[p]);
	}
	for (int p=n;p<=n*(1<<m);p++)
	{
		int u = 0;
		for (int k=0;k<20;k++)
		{
			keg[k] = 0;
			if (((p>>k)&1))
			{
				u++;
				keg[k] = 1;
			}
		}
		if (u<=q)
		{
			s.clear();
			dfs(u);
		}
	}
	cout<<print;
	return 0;
}
