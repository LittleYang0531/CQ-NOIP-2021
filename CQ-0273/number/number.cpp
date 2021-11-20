#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
const int M=1e6;
int T,cnt,x;
int t[N],a[N];

bool check(int x)
{
	int y=x;
	while(y>=10)
	{
		int z=y%10;
		if(z==7) return true;
		y/=10;
	}
	if(y==7) return true;
	return false;
}

bool check1(int x)
{
	if(check(x)) return true;
	for(int i=1;i<=cnt;i++)
	{
		if(x%a[i]==0) return true;
		if(a[i]>x) break;
	}
	return false;
}

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	int maxn=-1;
	for(int i=1;i<=T;i++)
	{
		t[i]=read();
		maxn=max(maxn,t[i]);
	}
	for(int i=7;i<=maxn;i++)
	{
		if(check(i))
			a[++cnt]=i;
	}
	for(int i=1;i<=T;i++)
	{
		if(check1(t[i]))
		{
			printf("-1\n");
			continue;
		}
		else
		{
			for(int j=t[i]+1;j<=N;j++)
			{
				if(!check1(j))
				{
					printf("%lld\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
