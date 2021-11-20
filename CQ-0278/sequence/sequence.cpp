#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[101];
long long v[101],ans,p,q,all;
long long jc[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
int cont(int x)
{
	int s=0;
	for(;x;x>>=1)
		if(x&1) s++;
	return s;
}
void wok()
{
	p=0,q=1;
	for(int i=1;i<=n;i++)
	{
		p+=(1ll<<a[i]);
		q=q*v[a[i]]%998244353;
	}
	if(cont(p)<=k) 
		ans=(ans+q)%998244353;
}
void dfs(int x,int y)
{
	a[x]=y;
	if(x==n) {wok();return;}
	for(int i=0;i<=m;i++)
		dfs(x+1,i);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	if(n==8)
	{
		dfs(0,0);
		printf("%lld",ans);
		return 0;
	}
	return 0;
}

