#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
const int MAXN = 1e7 + 20;
bool ans[MAXN];
int k,num[MAXN];
inline bool check(int x)
{
	while(x)
	{
		if(x % 10 == 7)return false;
		x /= 10;
	}
	return true;
}
void sai(int x)
{
	for(R int i = 1;i <= x; i++)
	{
		if(ans[i])continue;
		if(check(i) == false)
			for(R int j = i;j <= x; j += i)
				ans[j] = true;
	}
}
inline int read(int &x)
{
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')ch = getchar();
	while('0' <= ch && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
int Stack[1005],cnt = 0;
inline void print(int x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x == 0)putchar('0');
	else
	{
		while(x)
		{
			Stack[++cnt] = x % 10;
			x /= 10;
		}
		for(R int i = cnt;i >= 1; i--)
			putchar(Stack[i] + '0');
		cnt = 0;
	}
	putchar(10);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sai(10000010);
	int Last = 0;
	for(R int i = 10000010;i >= 0; i--)
	{
		if(ans[i] == false)
		{
			num[i] = Last;
			Last = i;
		}
	}
	int t;
	read(t);
	while(t--)
	{
		int n;
		read(n);
		if(ans[n] == true)print(-1);
		else
			print(num[n]);
//			printf("%d\n", num[n]);
	}
	return 0;
}
//1
//85300

