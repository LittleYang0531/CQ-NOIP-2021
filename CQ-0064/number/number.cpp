#include<bits/stdc++.h>
using namespace std;
inline int r()
{
	int s=0,k=1;char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')k=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s*k;
}
int T,n,b[20000005],a[20000005],cnt;
inline void check(int x)
{
//	cout<<"check"<<x<<endl;
	int tmp=x;
	int ok=0;
	while(tmp)
	{
		if(tmp%10==7)
		{
			ok=1;
			break;
		}
		tmp/=10;
	}
	if(ok)
	{
		int tmp=x;
		while(tmp<=15000000)
		{
			b[tmp]=1;
			tmp+=x;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=15000000;i++)
	{
		if(b[i])continue;
		check(i);
	}
	for(int i=1;i<=15000000;i++)
	if(!b[i])a[++cnt]=i;
	T=r();
	while(T--)
	{
		n=r();
		if(b[n])cout<<"-1\n";
		else
		{
			int now=upper_bound(a+1,a+cnt+1,n)-a;
			cout<<a[now]<<'\n';
		}
	}
}
