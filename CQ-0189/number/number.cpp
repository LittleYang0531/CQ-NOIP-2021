#include<bits/stdc++.h>
using namespace std;
bool a[10000010];
int t,x,cnt;
int belong[10000010];
struct abc
{
	int l,r;
}b[2000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=10000005;i++)
	{
		if(a[i])continue;
		bool flag=0;
		int temp=i;
		while(temp)
		{
			if(temp%10==7)
			{
				flag=1;
				break;
			}
			temp/=10;
		}
		if(flag==1)
		{
			for(int j=1;i*j<=10000005;j++)
			{
				a[i*j]=1;
			}
		}
	}
	for(int i=1;i<=10000005;i++)
	{
		if(a[i]!=a[i-1])
		{
			b[++cnt].l=i;
			b[cnt-1].r=i-1;
		}
		belong[i]=cnt;
	}
	b[cnt].r=10000005;
	while(t--)
	{
		scanf("%d",&x);
		if(a[x])
		{
			printf("-1\n");
			continue;
		}
		if(a[x+1]==1)
		{
			printf("%d\n",b[belong[x+1]+1].l);
		}
		else printf("%d\n",x+1);
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
