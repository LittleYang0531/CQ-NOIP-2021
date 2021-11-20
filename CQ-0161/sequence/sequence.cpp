#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
#define mod 998244353
long long ans;
long long n,m,kk;
long long vl[121];
long long wh[121];
long long an[121],wei=-1;
void addt(long long x)
{
	if(x>wei)wei=x,an[wei]=1;
	else if(x==wei)wei++,an[x]=0,an[wei]=1;
	else
	{
		an[x]++;
		for(long long i=x;i<=wei;i++)
		{
			if(an[i]<=1)break;
			an[i]=0;
			an[i+1]++;
		}
		if(an[wei+1]==1)wei++;
	}
}
void delt(long long x)
{
	an[x]--;
	for(long long i=x;i<=wei;i++)
	{
		if(an[i]>=0)break;
		an[i]+=2;
		an[i+1]--;
	}
	while(an[wei]==0)wei--;
}
void dfs(long long k)
{
	if(k==n+1)
	{
		long long ge=0;
		for(long long i=0;i<=wei;i++)ge+=(an[i]==1);
		if(ge>kk)return ;
		long long so=1;
		for(long long i=1;i<=n;i++)so*=vl[wh[i]],so%=mod;
		ans+=so;
		ans%=mod;
	}
	else
	{
		for(long long i=0;i<=m;i++)
		{
			addt(i);
			wh[k]=i;
			dfs(k+1);
			delt(i);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>kk;
	for(long long i=0;i<=m;i++)cin>>vl[i];
	dfs(1);
	cout<<ans;
	return 0;
}

