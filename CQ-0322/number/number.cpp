#include<bits/stdc++.h>
#define X 1001005
using namespace std;
int t,x,se[X],cnt;
bool p[X],vis[X];
bool judge_seh(int x)//�ж��ǲ������ߵ���
{
	while(x)
	{
		if(x%10==7)
		{
			return true;
		}
		x=x/10;
	}
	return false;
}
bool judge_seb(int x)//�ж��ǲ������ߵ����ı���
{
	for(int i=1;i<=cnt;i++)
	{
		if(x%se[i]==0)
		{
			return true;
		}
	}
	return false;
}
void cl(int x)//��һ�������д���
{
	if(!vis[x])
	{
		vis[x]=true;
		if(x%7==0)
		{
			p[x]=true;
		}
		else if(judge_seb(x)||judge_seh(x))
		{
			p[x]=true;
			se[++cnt]=x;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		for(int i=1;i<=x;i++)
		{
			cl(i);
		}
//		cout<<cnt<<endl;
//		for(int i=1;i<=cnt;i++)
//		{
//			cout<<i<<":"<<se[i]<<endl;
//		}
		if(p[x])
		{
			printf("-1\n");
			goto flag;
		}
		else do
		{
			cl(++x);
		}
		while(p[x]);
		printf("%d\n",x);
		flag:
		x++;
	}
	return 0;
}

