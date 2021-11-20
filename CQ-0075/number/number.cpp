#include "bits/stdc++.h"
using namespace std;
const int Len = 2e5 + 5 , M = 1.2e7 + 5;
int n,m,x,maxn,Prt[Len];
int nxt[M],llen,ps[M];
bool flag[M],flaw[M];
void Init()
{
	bool Ist = 0;
	for(int i = 1 ; i <= maxn ; i ++)
	{
		x = i;
		Ist = 0;
		while(x)
		{
			if(x % 10 == 7){Ist = 1;break;}
			x = x / 10;
		}
		if(Ist) 
		{
			flag[i] = flaw[i] = 1;
			for(int j = 2 ; j * i <= maxn ; j ++) flaw[j * i] = 1;
		}
		if(!flaw[i]) 
		{
			nxt[++ llen] = i;
			ps[i] = llen;
		}
	}
}
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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;T = read();
	for(int i = 1 ; i <= T ; i ++) 
	{
		Prt[i] = read();
		maxn = max(maxn , Prt[i]);
	}
	maxn = maxn + 1000002;
	Init();//注意最后一个数的nxt等会儿要特殊处理
	for(int i = 1 ; i <= T ; i ++)
	{
		if(flaw[Prt[i]]) puts("-1");
		else
		{
			wrote(nxt[ps[Prt[i]] + 1]);
			putchar('\n');
		}
	}
	return 0;
}
