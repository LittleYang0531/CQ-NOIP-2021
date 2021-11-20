#include<bits/stdc++.h>
using namespace std;
const unsigned int classroom=4274906972ll;
int t,temp_p;
char a[100];
bool check_7()
{
	for (int i=0;i<=strlen(a)-1;i++)
	{
		if (a[i]=='7') return 0;
	}
	int p=0;
	int o=1;
	for (int i=strlen(a)-1;i>=0;i--)
	{
		p+=o*(a[i]-48);
		o*=10;
	}
	temp_p=p;
	int l=0;
	for (int i=2;i*i<=p;i++)
	{
		l=0;
		o=1;
		if (p%i==0) l=p/i;
		for(;i>=o;o*=10)
		{
			if (p%i==0 && (i/o)%10==7) return 0;	 
		}
		if (l!=0)
		{
			for (o=1;l>=o;o*=10)
			{
				if ((l/o)%10==7) return 0;
			}
		}
	}
	return 1;
}
bool check_7_int(int p)
{
	int l=0;
	for (int i=2;i*i<=p;i++)
	{
		l=0;
		int o=1;
		if (p%i==0) l=p/i;
		for(;i>=o;o*=10)
		{
			if (l!=0 && (i/o)%10==7) return 0;	 
		}
		if (l!=0)
		{
			for (o=1;l>=o;o*=10)
			{
				if ((l/o)%10==7) return 0;
			}
		}
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>a;
		if (check_7())
		{
			while (true)
			{
				temp_p++;
				for (int o=1;o<=temp_p;o*=10)
				{
					if ((temp_p/o)%10==7) temp_p+=o;
				}
				if (check_7_int(temp_p))
				{
					cout<<temp_p<<endl;
					break;
				}
			}
		}
		else cout<<"-1"<<endl;
	}
	return 0;
	//I love TLE so much!!! 5s 70pts
}
