#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 105
int n,m,k;
int v[N];
int num[N];
long long ans;
long long mi[N];
int check(int a)
{
	int tot=0;
	while(a)
	{
		tot+=(a&1);
		a>>=1;
	}
	return tot<=k;
}
void bfs(int a,int ord)
{
	num[ord]=a;
	if(ord==n)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
			tot+=mi[num[i]],tot%=mod;
		if(check(tot))
		{
			long long js=1;
			for(int i=1;i<=n;i++)
				js*=v[num[i]],js%=mod;
			ans+=js,ans%=mod;
		}
	}
	else for(int i=0;i<=m;i++)
		bfs(i,ord+1);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%d",&v[i]);
	mi[0]=1;
	for(int i=1;i<=N;mi[i]=mi[i-1]*2%mod,i++);
	for(int i=0;i<=m;i++)bfs(i,1);
	printf("%d",ans);
	return 0;
}
