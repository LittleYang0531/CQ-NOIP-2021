#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#define maxn 10000002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
char wr[20];
void WRite(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	int cnt=0;
	while(x)
	{
		wr[++cnt]=x%10+'0';
		x/=10;
	}
	while(cnt)
	{
		putchar(wr[cnt]);
		cnt--;
	}
}
bool vis[maxn];
int p[6000002];
int ans[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=maxn-2;i++)
	{
		int ii=i;
		while(ii)
		{
			if(ii%10==7)
			{
				p[++p[0]]=i;
				break;
			}
			ii/=10;
		}
	}
	for(int i=1;i<=p[0];++i)
	{
		for(int j=1;p[i]*j<=maxn-2;++j)
		{
			vis[p[i]*j]=1;
		}
	}
	for(int i=maxn-2;i>=1;i--)
	{
		if(!vis[i+1]) ans[i]=i+1;
		else ans[i]=ans[i+1];
	}
	int T=read();
	while(T--)
	{
		int x=read();
		if(vis[x])
		{
			putchar('-');
			putchar('1');
			putchar('\n');
			continue;
		}
		WRite(ans[x]);
		putchar('\n');
	}
	return 0;
}


