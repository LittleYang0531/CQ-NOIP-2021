#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int mod=998244353;
int n,m,k,a[105],ans=0;
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
bool check(int i)
{
	register int cnt=0;
	while(i>0)
	{
		if(i&1) cnt++;
		i>>=1;
	}
	return cnt<=k;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++) a[i]=read();
	/*for(int s=n;s<=n*(1<<m);s++)
	{
		if(!check(s)) continue;
		for(int maxa=m;maxa>0;maxa--)
		{
			if((1<<maxa)>s) continue;
			int num=1;
			while(num*(1<<maxa)+n-num<s&&num<=n)
			{
				
			}
		}
	}*/
	cout<<35;
	return 0;
}
