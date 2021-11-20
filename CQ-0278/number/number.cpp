#include<bits/stdc++.h>
using namespace std;
int t,a,ans,cnt,to,num,p;
int pr[6000101],se[6000101],tmd[10000001];
bool vis[10000001],v[10000001];
bool ckp(int x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void primes()
{
	for(int i=2;i<=10000000;i++)
	{
		if(ckp(i)) {se[++num]=i;vis[i]=1;}
		if(!v[i]) pr[++cnt]=i,v[i]=1;
		to=10000000/i;
		for(int j=1;j<=cnt;j++)
		{
			if(pr[j]>to) break;
			v[pr[j]*i]=1;
		}
	}
}
void sevens()
{
	for(int i=1;i<=num;i++)
	{
		vis[se[i]]=1;to=10000000/se[i];
		for(int j=1;j<=cnt;j++)
		{
			if(pr[j]>to) break;
			if(!vis[se[i]*pr[j]]) se[++num]=se[i]*pr[j];
			vis[se[i]*pr[j]]=1;
		}
	}
}
void fxxks()
{
	for(int i=10000000;i;i--)
	{
		if(vis[i]) p++;
		else {tmd[i]=p;p=0;}
	}
}
void _primes()
{
	for(int i=2;i<=500000;i++)
	{
		if(ckp(i)) {se[++num]=i;vis[i]=1;}
		if(!v[i]) pr[++cnt]=i,v[i]=1;
		to=500000/i;
		for(int j=1;j<=cnt;j++)
		{
			if(pr[j]>to) break;
			v[pr[j]*i]=1;
		}
	}
}
void _sevens()
{
	for(int i=1;i<=num;i++)
	{
		vis[se[i]]=1;to=500000/se[i];
		for(int j=1;j<=cnt;j++)
		{
			if(pr[j]>to) break;
			if(!vis[se[i]*pr[j]]) se[++num]=se[i]*pr[j];
			vis[se[i]*pr[j]]=1;
		}
	}
}
void _fxxks()
{
	for(int i=500000;i;i--)
	{
		if(vis[i]) p++;
		else {tmd[i]=p;p=0;}
	}
}
inline int read()
{
	int x(0);char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	if(t<=10000) 
	{
		_primes();
		_sevens();
		_fxxks();
	}
	else
	{
		primes();
		sevens();
		fxxks();
	}
	while(t--)
	{
		a=read();
		if(vis[a]) {puts("-1");continue;}
		ans=a+tmd[a]+1;
		printf("%d\n",ans);
	}
	return 0;
}
