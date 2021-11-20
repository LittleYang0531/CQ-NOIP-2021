#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c)){if(c=='-') f=1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return f==0?x:-x;
}
void out(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10; 
	}
	return 0;
}
int T,x,f[10000020];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=10000010;++i)
	{
		if(f[i]) continue;
		else if(check(i))
		{
			for(int j=i;j<=10000010;j+=i)
			{
				f[j]=1;
			}
		}
	}
	while(T--)
	{
		x=read();
		if(f[x])
		{
			out(-1),putchar('\n');
			continue;
		}
		for(int i=x+1;;i++)
		{
			if(!f[i])
			{
				out(i);
				putchar('\n');
				break;
			}
		}
	}
	return 0;
}
//(p-p/i)*(p%i)
