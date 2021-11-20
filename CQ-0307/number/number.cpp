#include<bits/stdc++.h>
using namespace std;
#define N 10000005
int T;
int vis[N];
int check(int a)
{
	while(a)
	{
		if(a%10==7)return 1;
		else a/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=N;i++)
		if(!vis[i]&&check(i))
		{
			for(int j=1;j*i<=N;j++)
				vis[j*i]=1;
		}
	int x;
	while(T--)
	{
		scanf("%d",&x);
		if(vis[x])printf("-1\n");
		else 
		{
			for(int i=x+1;i<N;i++)
				if(!vis[i])
				{
					printf("%d\n",i);
					break;
				}
		}
	}
	return 0;
}
