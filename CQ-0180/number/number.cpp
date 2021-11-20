#include<bits/stdc++.h>
using namespace std;
int n,t,prime[10000005],m,enext[10000005],l,x,h;
bool isprime[10000005];
bool is7(int h)
{
	while(h>0)
	{
		if(h%10==7) return true;
		h/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int a=1;a<=1e7;a++)
	{
		if(isprime[a]==0&&is7(a)==1)
		{
			prime[++m]=a;
			for(int b=1;a*b<=1e7;b++) isprime[a*b]=1;
		}
		else
		{
		    for(int b=1;b<=m&&a*prime[b]<=1e7;b++) isprime[a*prime[b]]=1;	
		}
	}
	for(int a=1e7+1;a>=1;a--)
	{
		enext[a]=l;
		if(isprime[a]==0) l=a;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		if(isprime[x]==1) printf("-1\n");
		else  printf("%d\n",enext[x]);
	}
	return 0;
}
