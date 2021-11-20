/*
wpcakioi
*/
#include<bits/stdc++.h>
#define N 105
#define ll long long
#define p 998244353
using namespace std;
ll ans,n,m,k,v[N],f[40][62000],cf[31];
ll read()
{
	ll x=0,f=1;char ch=getchar();
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
ll pd(ll x)
{
	ll t=0;
	while(x)
	{
		if(x&1) t++;
		x=(x>>1);
		if(t>k) return 0;
	}
	return 1;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
	}
	cf[0]=1;
	for(int i=1;i<=m;i++)
	{
		cf[i]=cf[i-1]*2;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i*cf[m];j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(j>=cf[k]) f[i][j]=(f[i][j]+f[i-1][j-cf[k]]*v[k]%p)%p;
			}
			if(i==n&&pd(j)) ans=(ans+f[n][j])%p;
		}
	}
	cout<<ans;
	return 0;
}
