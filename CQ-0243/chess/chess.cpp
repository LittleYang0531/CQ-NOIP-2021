#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t,m,p,q;

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

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(t);
	while(t--)
	{
		read(m);
		read(p);
		read(q);
		for(int i = 1;i <= q;i++)
		{
			printf("1\n");
		}
	}
	return 0;
}

