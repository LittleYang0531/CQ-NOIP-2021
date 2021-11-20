#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,v[103],a[102],sum,mo=998244353;
int r()
{
	register int q=0,w=1;register char e=getchar();
	while(e<'0'||e>'9'){if(e=='-')w=-1;e=getchar();}
	while(e>='0'&&e<='9')q=(q<<3)+(q<<1)+e-'0',e=getchar();
	return q*w;
}
bool h2(int x)
{
	int t=0;
	while(x)
	{
		if(x&1)t++;
		x>>=1;
	}
	return t<=k?1:0;
}
void js()
{
	int p=1;
	for(int i=0;i<n;i++)p=(p*v[a[i]])%mo;
	sum=(sum+p)%mo;
}
void dfs(int S,int ds,int x)
{
	if(x>n)return;
	if(x==n&&ds==S)js();
	if((n-x)*pow(2,m)+ds<S)return;
	for(int i=0;i<=m;i++)
	{
		if(pow(2,i)+ds>S)return;
		a[x]=i;
		dfs(S,pow(2,i)+ds,x+1);
	}
	return;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=r();m=r();k=r();
	for(int i=0;i<=m;i++)v[i]=r();
	for(int i=n;i<=n*pow(2,m);i++)
	if(h2(i))dfs(i,0,0);
	printf("%lld",sum);
	return 0;
}
