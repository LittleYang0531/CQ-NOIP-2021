#include<bits/stdc++.h>
#define N 20000005
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T,x[200005],n,pd[N],now,v[N],vis[N],cnt;
int p(int x)
{
	if(x%7==0) return 1;
	while(x)
	{
		int tmp=x%10;
		x=x/10;
		if(tmp==7) return 1;
	}
	return 0;
}
void pre(int x)
{
	now=1;
	for(int i=2;i<=x;i++)
	{
		if(i%7==0||vis[i]) continue;
		if(pd[i])
		{
		    int lt=x/i;
			for(int j=1;j<=lt;)
			{	
				pd[i*j]=1;
				vis[i*j]=1;
				if(v[j]) j=v[j];
			    else j++;
			}
		}
		else 
		{
			v[now]=i;
			now=i;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++)
	{
		x[i]=read();
		n=max(n,x[i]);
	}
	for(int i=1;i<=n+10000;i++)
	{
		if(p(i)==1) pd[i]=1;
	}
	pre(n+10000);
	for(int i=1;i<=T;i++)
	{
		n=x[i];
		if(pd[n])
		{
			write(-1);
			putchar('\n');
		}
		else
		{
			write(v[n]);
			putchar('\n');
		}
	}
	return 0;
}
