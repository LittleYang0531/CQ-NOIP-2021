#include<bits/stdc++.h>
using namespace std;
int q[10000000];
int t,n;
int fenjie(int y)
{
	if(q[y]==1)return 0;
	int s=y;
	while(s>0)
	{
		int u=s%10;
		if(u==7)
		{
			q[s]=1;
		return 0;
		}
		s/=10;
	}
	return 1;
}
int check_2(int u)
{
	if(q[u]==1)return 0;
	int p=2;
	while(p<=sqrt(u))
	{
		if(u%p==0)
		{
			if(fenjie(p)==0)
			{
				q[p]=1;
				return 0;
			}
			else if(fenjie(u/p)==0)
			{
				q[u/p]=1;
				return 0;
			}
		}
		p++;
	}
	return 1;
}
int check_1(int x)
{
	if(x%7==0)return 0;
	else if(q[x]==1||fenjie(x)==0)return 0;
	else if(check_2(x)==0)return 0;
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(check_1(n)==0)
		{
			printf("-1\n");
			continue;
		}
		else 
		{
			int o=n+1;
			while(check_1(o)==0)
			o++;
			printf("%d\n",o);
		}
	}
	return 0;
}
