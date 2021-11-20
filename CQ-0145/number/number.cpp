#include<bits/stdc++.h>
using namespace std;
bool f1(int x)
{
	int total=0;
	if(x%7==0)
	{
		return 1;
	}
	int y=x;
	while(y>0)
	{
		if(y%10==7)
		{
			return 1;
		}
		y/=10;
		total++;
	}
	for(int i=2;i<=sqrt(x);i++)
	{
		for(int j=0;j<=total;j++)
		{
			y=x;
			y-=7*i*pow(10,j);
			if(y<=0 || y%i!=0)
			{
				break;
			}
			y/=i;
			y/=pow(10,j);
			if(y%10==0)
			{
				return 1;
			}
		}
	}
	return 0;
}
bool f2(int x)
{
	if(f1(x))
	{
		return 1;
	}
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			if(f1(i))
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,x;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>x;
		int ans=-1;
		if(f2(x)==1)
		{
			cout<<ans<<endl;
			continue;
		}
		ans=x+1;
		while(f2(ans))
		{
			ans=ans+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
