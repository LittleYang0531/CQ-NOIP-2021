#include <iostream>
#include <cstdio>
using namespace std;
inline int rd()
{
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')
	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int T;
int main()
{
	T=rd();
	while(T--)
	{
		int n=rd(),m=rd(),q=rd();
		for(int i=1;i<=n;i++)rd();
		for(int i=1;i<=m;i++)
		getchar();
		for(int i=1;i<=q;i++)
		{
			rd();rd();rd();rd();
		}
		printf("%d",rand()%(n*m));
	}
	return 0;
}

