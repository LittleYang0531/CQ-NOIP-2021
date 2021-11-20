#include<bits/stdc++.h>
using namespace std;
int t,vis[10000123],num,nxt[10000001];
int mar;
bool check(int x)
{
	int tmp;
	while(x>0)
	{
		tmp=x%10;
		if(tmp==7) return 1;
		x=x/10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	if(t<=100) mar=1000;
	else if(t<=1000) mar=10000;
	else if(t<=10000) mar=200000;
	else mar=10000000;
	for(int i=1;i<=mar+120;i++)
	{
		if(vis[i]==1) continue;
		if(check(i)==0) continue;
		for(int j=i;j<=mar+120;j+=i)	vis[j]=1;
	}
	int tmp=1;
	for(int i=2;i<=mar+120;i++)
	{
		if(vis[i]==0)	nxt[tmp]=i,tmp=i;
		if(tmp>mar) break;	
	}
	while(t--)
	{
		scanf("%d",&num);
		if(vis[num]==1) 
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",nxt[num]);
	}
	return 0;
}
