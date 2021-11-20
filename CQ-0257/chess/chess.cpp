#include <bits/stdc++.h>
using namespace std;
int n,m,q,t;
int rd[5001][5001];
char s[5001][5001];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		memset(rd,0,sizeof (rd));
		scanf("%d %d %d",&n,&m,&q);
		while (q--)
		{
			printf("%d\n",abs(rand())%(n*m));
		}
	}
	return 0;
}
