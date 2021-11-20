#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
const int MAXN = 10005;
ll n,a[MAXN],sum,sq,ans,cnt,del[MAXN];
map <string,bool> mp;

template <typename T>
inline void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0'||ch > '9')
	{
		if(ch == '-')
		w = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

bool check()
{
	ll now,d;
	string k;
	char cl;
	for(int i = 2;i < n;i++)
	{
		now = a[i];
		while(now >= 10)
		{
			d = now % 10;
			cl = d ^ 48;
			k += cl;
			now /= 10;
		}
		d = now % 10;
		cl = d ^ 48;
		k += cl;
	}
	if(mp[k] == true)
	return true;
	mp[k] = true;
	return false;
}

void dfs()
{
	int now;
	for(int i = 2;i < n;i++)
	{
		now = a[i-1] + a[i+1] - a[i];
		if(a[i] != now)
		{
			sq += now * now - a[i] * a[i];
			sum += now - a[i];
			int hy = a[i];
			a[i] = now;
			if(check() == false)	
			{
				ans = min(ans,n * sq - (sum * sum));
				dfs();
			}
			sq += hy * hy - a[i] * a[i];
			sum += hy - a[i];
			a[i] = hy;
		}
	}
	return;
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i = 1;i <= n;i++)
	{
		read(a[i]);
		sum += a[i];
		sq += a[i] * a[i];
		if(i >= 2)
		del[i] = a[i] - a[i-1];
	}
	ans = n * sq - sum * sum;
	if(n < 10)
	{
		bool q = check();
		dfs();
		printf("%lld\n",ans);
	}
	else
		printf("%lld\n",ans);
	return 0;
}

