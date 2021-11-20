#include<bits/stdc++.h>
using namespace std;
int t,x;
bool check1(int a)
{
	while(a>0)
	{
		int y=a%10;
		if(y==7) return 0;
		a/=10;
	}
	return 1;
}
int check2(int a)
{
	for(int i=1;i<sqrt(a);i++)
	{
		if(a%i==0){
			if(!check1(i)) return 0;
			if(!check1(a/i)) return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>x;
		if(!check1(x)||!check2(x)){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=x+1;i;i++)
		{
			if(check1(i)&&check2(i)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
