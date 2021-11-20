#include<bits/stdc++.h>
using namespace std;
int N;
bool num[1000001];
bool check1(int n)
{
	while(n!=0)
	{
		int x=n%10;
		if(x==7)
		return false;
		else 
		n/=10;
	}
	return true;
}
bool check2(int n)
{
	if(n%7==0) return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i%7==0||check1(i)==false) return false;
			else 
			{
				while(n%i==0)
				{
					n/=i;
					if(check1(n)==false)
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		int t=x;
		if(check1(t)==false||check2(t)==false)
		{
			printf("-1\n");
			continue;
		}
		x++;
		while(check1(x)==false||check2(x)==false)
		x++;
		printf("%d\n",x);
	}
	return 0;
}
