#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
int v[10005];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int maxx=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&v[i]);
		maxx=max(maxx,v[i]);
	}
	printf("%d",n*(m+1)*maxx*maxx);
}
