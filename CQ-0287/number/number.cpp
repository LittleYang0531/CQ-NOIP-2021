#include<bits/stdc++.h>
using namespace std;
int t;
bool m[8000005];
bool check(int x)
{
	bool f=0;
	while(x>0)
	{
		if(x%10==7)
		{
			f=1;
			break;
		}
		x/=10;
	}
	if(f==1)
	{
		m[x]=1;
		return false;
	}
	else return true;
}
bool check1(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i!=0)continue;
		int j=x/i;
		if(m[i]==1||m[j]==1)
		{
			m[x]=1;
			return false;
		}
		if(!check(i))
		{
			m[x]=1;
			m[i]=1;
			return false;
		}
		if(!check(j))
		{
			m[x]=1;
			m[j]=1;
			return false;
		}
	}
	return true;
}
bool realcheck(int x)
{
	if(m[x]==1)return false;
	if(check(x)==0)return false;
	if(check1(x)==0)return false;
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(!realcheck(x))
		{
			printf("-1\n");
			continue;
		}
		x++;
		while(!realcheck(x))x++;
		printf("%d\n",x);
	}
	return 0;
}
