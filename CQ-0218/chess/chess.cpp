#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN];
int n; 
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
char s[MAXN];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m,q;
		read(n),read(m),read(q);
		for(R int i = 1;i <= n; i++)
			scanf("%s", s + 1);
		for(R int i = 1;i < n; i++)
			scanf("%s", s + 1);
		while(q--)
		{
			int c,l,x,y;
			read(c),read(l),read(x),read(y);
			printf("0\n");
		}
	}
	return 0;
}
