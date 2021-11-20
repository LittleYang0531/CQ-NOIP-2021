#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,k,mar;
long long v[107],num[31],ans=0,dpc[107][107];
int now[107];
bool check()
{
	long long size=0;
	memset(now,0,sizeof(now));
	for(int i=0;i<=m;i++) now[i]=num[i];
	for(int i=0;i<=mar;i++)
	{	
		now[i+1]+=(now[i]/2);
		now[i]=now[i]%2;
	}
	for(int i=0;i<=mar;i++)
	{
		size+=now[i];
		if(size>k) return 0;
	} 
	 return 1;
}
void dfs(int id,int y)
{
	if(id>m)
	{
		if(y==0&&check())
		{
			long long tmp=1,times=1,w=n;
			for(int i=0;i<=m;i++)	
			{
				if(num[i]>0)
				{
					for(int j=1;j<=num[i];j++) tmp=tmp*v[i]%mod;
					times=times*dpc[w][num[i]]%mod;
					w-=num[i];
				}
			}
			ans=(ans+times*tmp%mod)%mod;
		}
		return;
	}
	for(int i=0;i<=y;i++)
	{
		num[id]=i;
		dfs(id+1,y-i);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
		v[i]=v[i]%mod;
	}	
	dpc[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		dpc[i][1]=i;
		for(int j=2;j<i;j++)	dpc[i][j]=(dpc[i-1][j]+dpc[i-1][j-1])%mod;
		dpc[i][i]=1;
	}
	mar=log2(n*(1<<m))+1;
	dfs(0,n);
	printf("%lld",ans);
	return 0;
}
