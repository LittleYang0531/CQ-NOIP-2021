#include "bits/stdc++.h"
using namespace std;
int n,m;
inline int read()
{
	char ch = getchar();
	int x = 0 , f = 1;
	while(ch < '0' || ch > '9') 
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
inline void wrote(int x)
{
	if(x < 0) putchar('-') , x = -x;
	if(x > 9) wrote(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	return 0;
}
