#include <cstdio>
const int M = 10000010;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<=9)
	{
		putchar(x+'0');
		return ;
	}
	write(x/10);
	putchar(x%10+'0');
}
int T,n,f[M],nx[M];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		int upd=0;
		if(!f[i])
		{
			int x=i;
			while(x>0)
			{
				int t=x%10;
				if(t==7)
				{
					f[i]=upd=1;
					break;
				}
				x/=10;
			}
		}
		if(upd)
		{
			for(int j=i;j<=n;j+=i)
				f[j]=1;
		}
	}
	for(int i=n,ls=0;i>=1;i--)
	{
		if(!f[i]) ls=i;
		nx[i]=ls;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(1e7+5);T=read();
	while(T--)
	{
		n=read();
		if(f[n]) puts("-1");
		else write(nx[n+1]),puts("");
	}
	return 0;
}
