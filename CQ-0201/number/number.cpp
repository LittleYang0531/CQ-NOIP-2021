#include<bits/stdc++.h>
using namespace std;
int sn[10000006],t,x,cnt=0,sf[10000006];
bool nsn[10000006];
inline int read()
{
	register int x=0,f=1;
	register char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x)
{
	if(x<0) putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline bool check(int i)
{
	if(i%7==0) return 1;
	int l;
	while(i>0)
	{
		l=i%10;
		if(l==7) return 1;
		i/=10;
	}
	return 0;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(register int i=1;i<=10000005;i++)
	{
		if(nsn[i]==0&&check(i)) nsn[i]=1,sf[i]=i;
		if(!nsn[i])
		{
			sn[++cnt]=i;
			continue;
		}
		if(nsn[i]&&sf[i]!=i) continue;
		for(register int j=2;j*i<=10000005;j++)
		{
			sf[i*j]=i;
			nsn[i*j]=1;
		}
	}
	t=read();
	while(t--)
	{
		x=read();
		if(nsn[x])
		{
			putchar('-');
			putchar('1');
			putchar('\n');
			continue;
		}
		int it=upper_bound(sn+1,sn+cnt+1,x)-sn;
		write(sn[it]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
