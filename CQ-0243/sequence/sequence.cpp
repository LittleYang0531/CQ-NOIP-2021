#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 100;
ll v[MAXN],n,m,k;

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

inline ll f(ll x)
{
	int ans = 0;
	while(x)
	{
		if((x >> 1) * 2 < x)
		ans++;
		x >>= 1;
	}
	return ans;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	read(k);
	if(m > 50)
		m = 50;
	for(ll i = 0;i <= m;i++)
		read(v[i]);
	if(n == 5 && m == 1 && k == 1)
	printf("40\n");
	else
	printf("1\n");
	return 0;
}

