#include<bits/stdc++.h>
using namespace std;
unsigned long long v[40];
unsigned long long mod=998244353;
unsigned long long ans0=0;	
unsigned long long n,m,k;
map<unsigned long long,unsigned long long>d[200];
unsigned long long dfs(unsigned long long s,unsigned long long p)
{
	if(d[n-p][s])return d[n-p][s];
	if(p==n&&s==0)return 1;
	if(p==n||s==0)return 0;
	unsigned long long ans=0;
	unsigned long long ds=1;
	for(unsigned long long i=0;i<=m;i++)
	{
		if(ds>s)break;
		ans+=dfs(s-ds,p+1)%mod*v[i]%mod;
		ans%=mod;
		ds<<=1;
	}
	return d[n-p][s]=ans;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(unsigned long long i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	for(unsigned long long s=n*(1<<m);s>=n;s--)
	{
		unsigned long long cnt=0;
		unsigned long long x=s;
		while(x)
		{
			if(x&1)cnt++;
			if(cnt>k)break;
			x>>=1;
		}
		if(cnt>k)continue;
		ans0=dfs(s,0)+ans0;
		ans0%=mod;
	}
	printf("%lld",ans0);
	fclose(stdin);
	fclose(stdout);
}
