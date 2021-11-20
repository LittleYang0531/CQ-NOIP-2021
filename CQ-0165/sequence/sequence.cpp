#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,m,k,s,t,ans,cnt,tot;
int a[100005],c[100005],d[100005],f[100005],h[100005];
void dfs(int step)
{
	if(step==n+1)
	{
//		for(int i=1;i<=n;i++)
//		printf("%d ",c[i]);
//		puts("");
		long long s=0;
		long long sum=0;
		for(int i=1;i<=n;i++)
		sum+=d[c[i]];
//		cout<<sum<<endl;
		while(sum)
		{
			if(sum&1) s++;
			sum>>=1;
		}
		if(s>k) return ;
		s=1;
		for(int i=1;i<=n;i++)
		{
			s*=a[c[i]];
			if(s>mod) s%=mod;
		}
		ans+=s;
		if(ans>mod) ans-=mod;
//		cout<<s<<endl;
		return ;
	}
	for(int i=0;i<=m;i++)
	{
		c[step]=i;
		dfs(step+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);d[0]=1;
	for(int i=1;i<=m;i++)
	d[i]=d[i-1]<<1;
	for(int i=0;i<=m;i++)
	scanf("%d",&a[i]),a[i]%=mod;
	if(n>10)
	{
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ans%mod);
}
