#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
const LL mod=998244353;
LL n,m,k,l,r,ans;//l,r:S的范围 
LL v[N];
LL c[N][N];//c[n][m]:n个数中含有m个1的组合数量 
LL w[N];//w[i]:1的数量为i的权值
LL a[N];
bool check(LL x)//暴力判断x是否为合法数字(<20) 
{
	LL res=0;
	while(x)
	{
		if(x%2==1)
			res++;
		x/=2;
	}
	if(res<=k)
		return true;
	return false;
}
LL qwq(LL x)
{
	LL res=1;
	while(x)
	{
		res*=2;
		x--;	
	} 
	return res;
}
void dfs(int x,LL w)//一分都骗不了 
{
	if(w>r)
		return;
	if(x>n)
	{
		if(w>=l&&check(w)==true)
		{
			LL res=1;
			for(int i=1;i<=n;i++)
				res=res*v[a[i]]%mod;
			ans=(ans+res)%mod;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1,w+qwq(i));
		a[x]=m+1;
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	l=n,r=n*qwq(m);
	for(int i=0;i<=m;i++)
		scanf("%lld",&v[i]);
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<=i;j++)
//		{
//			if(j==0)
//				c[i][j]=1;
//			else
//				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
//		}
//	if(k==1)
//	{
//		return 0;
//	}
	if(n<=8)
	{
		for(int i=1;i<=n;i++)
			a[i]=m+1;
		dfs(1,0);
		printf("%lld\n",ans);
		return 0;
	}
//	if(n==30)
//	{
//		return 0;
//	}
	return 0;
}
