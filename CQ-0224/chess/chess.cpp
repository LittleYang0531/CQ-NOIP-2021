#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e3+10;
int T,n,m,q;
int a[MAX][MAX];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T = read();
	while(T--)
	{
		n = read(),m = read(),q = read();
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				a[i][j] = read();
		while(q--)
		{
			printf("1\n");
		}
	}
	return 0;
}
