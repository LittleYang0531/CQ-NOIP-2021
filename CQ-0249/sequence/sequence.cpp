#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
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
int a[10],b[20],ans[20],tt;
int n,m,k,v[110];
void dfs(int x)
{
	if(x==n+1)
	{
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
		}
		int tot=3,cnt=0;
		for(int i=1;i<=18;i++)
		{
			b[i+1]+=b[i]/2;
			b[i]%=2;
			if(b[i]==1)
			{
				cnt++;
			}
		}
		if(cnt<=k)
		{
//			for(int i=1;i<=m+3;i++)
//			{
//				ans[i]+=b[i];
//			}
			int qt=1;
			for(int i=1;i<=n;i++)
			{
//				cerr<<a[i]<<" ";
				qt*=v[a[i]-1];
				qt%=MOD;
			}
//			cerr<<"a\n";
			tt+=qt;
			if(tt>=MOD) tt-=MOD;
		}
	}
	else
	{
		for(int i=1;i<=m+1;i++)
		{
			a[x]=i;
			dfs(x+1);
		}
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	int tot=log2(n);
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
	}
//	if(n==8&&m==9)
//	{
		dfs(1);
		cout<<tt<<'\n';
//	}
	return 0;
}

