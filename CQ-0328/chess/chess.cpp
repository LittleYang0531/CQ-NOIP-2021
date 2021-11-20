#include<bits/stdc++.h>
using namespace std;
int v[1009][1009],n,m,T,con;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	srand(time(0));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				scanf("%1d",&con);
				v[i][j]=con;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%1d",&con);
				v[j][i]=con;
			}
		}
		printf("%d\n",rand()%100+1);
	}
	return 0;	
}
