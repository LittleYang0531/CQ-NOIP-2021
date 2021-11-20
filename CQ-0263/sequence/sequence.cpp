#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,k,bs[20];
bool vis[50005];
ll v[105],ans,s,tot,mul=1; 
bool check(int x)
{
	int num=0;
	while(x)
	{
		int y=x%2;
		if(y==1) num++;
		if(num>k) return 0;
		x/=2;
	}
	return 1;
}
void dfs(int st)
{
	if(st==n)
	{
		if(vis[s]) ans=(ans+mul)%mod;
		return;
	}
	for(int i=0;i<=m;i++)
	{
		s+=bs[i];//,cout<<"step"<<st<<",get:"<<s<<endl;
		ll tmp=mul;
		mul=(mul*v[i])%mod;
		dfs(st+1);
		s-=bs[i],mul=tmp;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	bs[0]=1;
	for(int i=1;i<=10;i++) bs[i]=bs[i-1]*2;
	for(int i=0;i<=50000;i++) 
		if(check(i)) vis[i]=1;
		
	for(int i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	dfs(0);
	printf("%lld",ans);
	return 0;
}
