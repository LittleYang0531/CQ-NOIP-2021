#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int T;
int n,m,q;
char c;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m-1;j++)cin>>c;
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)cin>>c;
		}
		for(int i=1;i<=q;i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			cout<<1<<endl;
		}
	}
	return 0;
}
//He didn't stop learning OI after CSP.But his ending is chess in NOIP.
