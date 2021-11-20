#include <bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,m,k;
int v[101],lt,rt;
int num[101],id;
int hs[100];
int vl[100],ct[100],idx;
int p;
int ans;
int C(int a,int b)
{
	int p=a,q=b;
	for(int i=1;i<b;i++)
	{
		p=p*(a-i);
		q=q*(b-i);
	}
	return p/q;
}
int qm(int x,int y)
{
	int base=x,ans=1;
	while(y)
	{
		if(y&1) ans*=base;
		base*=base;
		y>>=1;
	}
	return ans;
}
void dfs(int cnt,int val,int last,int x)
{
	if(cnt>n)
	{
	    if(val==x)
	    {
	    	memset(vl,0,sizeof(vl));
	    	memset(ct,0,sizeof(ct));
	    	idx=0;
	    	int t=n,sit=1,va=1;
	    	for(int i=1;i<=n;i++)
	    	{
	    		va=(va*v[num[i]])%mod;
	    		if(i==1||num[i]!=num[i-1])
	    		{
	    			vl[++idx]=num[i];
	    			ct[idx]=1;
				}
				else ct[idx]++;
			}
			for(int i=1;i<=idx;i++)
			{
				sit=(sit*C(t,ct[i]))%mod;
				t-=ct[i];
			}
			ans+=sit*va;
		}
		else return;
	}
	if(n-cnt+1>x-val) return;
	if((n-cnt+1)*hs[m]<x-val) return;
	for(int i=last;i>=0;i--)
	{
		if(val+hs[i]<=x)
		{
			num[++id]=i;
			dfs(cnt+1,val+hs[i],i,x);
			num[id]=0;
			id--;
		}
	}
	return;
}
void init()
{
	for(int i=0;i<=m;i++)
	{
		hs[i]=qm(2,i);
	}
}
void solve(int x)
{
	dfs(1,0,m,x);
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	init();
	lt=n;rt=n*hs[m];
	for(int s=lt;s<=rt;s++)
	{
		for(int o=s;o;o-=(o&(-o))) p++;
		if(p<=k)
		{
			solve(s);
		}
		p=0;
	}
	cout<<ans%mod;
	return 0;
}
