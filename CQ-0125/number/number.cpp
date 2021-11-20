#include<bits/stdc++.h>
using namespace std;
int qi(long long a)
{
	int q=0;
	while(a>0)
	{
		q=a%10;
		if(q==7)return 1;
		a/=10;
	}
	return 2;
}
int bei(long long a)
{
	long long q1=0,q2=0;
	int b=sqrt(a);
	for(long long i=1;i<=b;i++)
	{
		if(a%i==0)
		{
			q1=qi(i);
			q2=qi(a/i);
		}
		if(q1==1||q2==1)return 1;
	}
	return 2;
}
long long T,tem,t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&T);
	for(long long i=0;i<T;i++)
	{
		scanf("%lld",&tem);
		t=bei(tem);
		if(t==1)printf("%d\n",-1);
		else
		{
			long long j=tem+1;
			while(bei(j)==1)
				j++;
			printf("%lld\n",j);
		}
	}
	return 0;
}
