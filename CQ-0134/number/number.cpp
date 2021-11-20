#include<bits/stdc++.h>
using namespace std;
int t,n;
bool check(int x)
{
	while(1)
	{
		if(x%10==7)
		return 1;
		else
		x/=10;
		if(x<10)
		{
			if(x==7)
			return 1;
			else
			return 0;
		}
	}
}
bool confirm(int x)
{
	if(x%7==0)
	return 1;
	if(check(x))
	return 1;
	for(int i=1;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			int yy=x/i;
			if(check(i)||check(yy))
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(confirm(n))
		{
			cout<<-1<<endl;
		}
		else
		{
			for(int j=n+1;j<=10000000;j++)
			{
				if(!confirm(j))
				{
					cout<<j<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
