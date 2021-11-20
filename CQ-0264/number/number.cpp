#include<bits/stdc++.h>
using namespace std;
int T;
int x;
bool p(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
bool check(int x)
{
	if(x%7==0)
		return false;
	for(int i=1;i<=x/i;i++)
		if( x%i==0 && (p(i) || p(x/i)) )
			return false;
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		if(!check(x))
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=x+1;;i++)
			if(check(i))
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
