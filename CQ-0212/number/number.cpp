#include<bits/stdc++.h>
using namespace std;
int t;
int x[2000005];
bool st[10000005];
int last,primes[10000005],cnt;
int ans[10000005];
bool getnum(int x)
{
	while(x)
	{
		if(x%10==7)
		return 0;
		x/=10;
	}
	return 1;
}
int maxn;
void init()
{
	for(int i=1;i<=maxn;++i)
	{
		st[i]=1;
	}
	for(int i=1;i<=maxn;++i)
	{
		if(!getnum(i))
		{
			primes[++cnt]=i;
			st[i]=0;
		}
	}
	for(int i=1;i<=maxn;++i)
	{
		for(int j=1;j<=cnt&&primes[j]*i<=maxn;++j)
		{
			st[i*primes[j]]=0;
		}
	}
	for(int i=1;i<=maxn;++i)
	{
		if(st[i])
		{
			ans[last]=i;
			last=i;
		}
		else
		{
			ans[i]=-1;
		}
	}
	for(int i=maxn+1;i;i++)
	{
		bool flg=0;
		if(!getnum(i))
		continue;
		for(int j=1;j<=cnt;++j)
		{
			if(i%primes[j]==0)
			{
				flg=1;
				break;
			}
		}
		if(!flg)
		{
			ans[last]=i;
			break;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&x[i]);
		maxn=max(maxn,x[i]);
	}
	init();
	for(int i=1;i<=t;++i)
	{
		printf("%d\n",ans[x[i]]);
	}
	return 0;
}
