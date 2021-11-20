//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 10000005;
int n;

LL Read()
{
	LL x = 0,f = 1;char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

bool vis[MAXN];
int nxt[MAXN];

bool check(int x)
{
	while(x)
	{
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
void sieve(int x)
{
	for(int i = 1;i <= x;++ i)
	{
		if(i % 7 == 0 || check(i))
		{
			if(!vis[i])
			{
				vis[i] = 1;
				for(int j = i;j <= x;j += i) vis[j] = 1;
			}
		}
	}
	for(int i = x;i >= 1;-- i)
		if(!vis[i]) nxt[i] = i;
		else nxt[i] = nxt[i+1];
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sieve(10000001);
	for(int T = Read(); T ;-- T)
	{
		n = Read();
		if(vis[n]) Put(-1,'\n');
		else Put(nxt[n+1],'\n');
	}
	return 0;
}
