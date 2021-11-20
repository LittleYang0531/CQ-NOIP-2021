#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e7+5;
int t,x;
bool vis[MAXN];

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

inline bool check(int x)
{
	while(x > 1)
	{
		if(x % 10 == 7)
		return true;
		x /= 10;
	}
	return false;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 7;i <= 1e7;i++)
	{
		if(!vis[i] && check(i) == true)
		{
			for(int j = 1;j <= (int)((1e7)/i);j++)
			{
				vis[j * i] = true;
			}
		}
	}
	read(t);
	while(t--)
	{
		read(x);
		if(vis[x] == true)
		{
			printf("-1\n");
			continue;
		}
		for(int i = x + 1;i <= 1e7+1;i++)
		{
			if(vis[i] == false)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
