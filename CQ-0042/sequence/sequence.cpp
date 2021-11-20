#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=105;
int n,m,k,now,ans,lim;
int v[N],f[2][30*(1<<12)+5];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int x,cnt;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",&v[i]);
	f[now][0]=1;
	for(int i=1;i<=n;i++)
	{
		lim+=(1<<m);now^=1;
		for(int w=0;w<=lim;w++)
		{
			f[now][w]=0;
			for(int j=0;j<=m;j++)
			{
				if(w<(1<<j))break;
				f[now][w]=(f[now][w]+1ll*f[now^1][w-(1<<j)]*v[j])%mod;
			}
		}
	}
	for(int w=0;w<=lim;w++)
	{
		x=w;cnt=0;while(x)x-=(x&(-x)),cnt++;
		if(cnt<=k)ans=(ans+f[now][w])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
