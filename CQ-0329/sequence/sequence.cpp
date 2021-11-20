#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define inf 1e9
#define mem(a,b) memset(a,b,sizeof(a))
#define enter putchar('\n')
#define int long long
#define M 998244353
using namespace std;
int n,m,k,ans,v[205],r[205],b[205];
int getblock()
{
	int block=0,now=-1,st=0;
	while(1)
	{
		int ifind=0;
		for(st=now+1;st<=m*log2(n)+1;st++)
			if(r[st]==1)
			{
				ifind=1;
				break;
			}
		if(!ifind) break;
		for(now=st+1;now<=m*log2(n)+1;now++)
			if(r[now]!=1)
			{
				block++;
				break;
			}
	}
	return block;
}
void up()
{
	for(int i=0;i<=m*log2(n)+1;i++)
		if(r[i]==2) r[i]=0,r[i+1]++;
}
void down()
{
	for(int i=0;i<=m*log2(n)+1;i++)
		if(r[i]==-1) r[i]=1,r[i+1]--;
}
void dfs(int step)
{
	if(step==n+1)
	{
		int num=0;
		for(int i=0;i<=m*log2(n)+1;i++)
			if(r[i]) num++;
		if(num<=k)
		{
			int tmp=1;
			for(int i=1;i<=n;i++) tmp=tmp*v[b[i]]%M;
			ans=(ans+tmp)%M;
		}
		return ;
	}
	if(getblock()>n-step+1) return ;
	for(int i=0;i<=m;i++)
	{
		b[step]=i;
		r[i]++;
		up();
		dfs(step+1);
		r[i]--;
		down();
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	dfs(1);
	cout<<ans;
	return 0;
}
