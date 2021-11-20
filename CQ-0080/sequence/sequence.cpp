#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll MOD=998244353;
int v[205],a[205],S[205],Tmp[205];
ll Fac[205],Inv[205],Ans;
int n,m,k;
ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%MOD;
		b>>=1;a=a*a%MOD;
	}
	return ret;
}
void Solve(int op=1)
{
	for(int i=m+1;i<=m+7;i++) if(S[i]) return;
	for(int i=0;i<=m+7;i++) Tmp[i]=S[i];
	int cnt=0;
	for(int i=0;i<=m+7;i++) 
		S[i+1]+=S[i]/2,S[i]%=2,cnt+=S[i];
	for(int i=0;i<=m+7;i++) S[i]=Tmp[i];
	if(cnt>k) return;
	ll Val=1,Way=Fac[n];
	for(int i=0;i<=m;i++)
	{
		Val=Val*qpow(v[i],S[i])%MOD;
		Way=Way*Inv[S[i]]%MOD;	
	}
	if(op==1) Ans=(Ans+Val*Way%MOD)%MOD;
	if(op==-1) Ans=(Ans+Val)%MOD;
}
void dfs(int t)
{
	if(t==n+1)
	{
		Solve();
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[t]=i;S[i]++;
		dfs(t+1);
		a[i]=0;S[i]--;	
	} 
}
int PopCount(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
void Divide(int t,int Rest,ll Val,ll Way)
{
	if(t==0)
	{
		if(Rest==0) Ans=(Ans+Val*qpow(v[0],S[0])%MOD*Way%MOD*Inv[S[0]]%MOD)%MOD;
		return;
	}
	int From=0,Up=min(S[t],Rest);
	if(t>m) From=S[t];
	if(t==1) From=Rest;
	for(int i=From;i<=Up;i++)
	{
		S[t-1]+=i<<1; S[t]-=i;
		Divide(t-1,Rest-i,Val*qpow(v[t],S[t])%MOD,Way*Inv[S[t]]%MOD);
		S[t-1]-=i<<1; S[t]+=i;
	}
}
void dfs2(int t)
{
	if(t==n+1)
	{
		Solve(1);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		S[i]++,dfs2(t+1),S[i]--;	
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Fac[0]=1;
	for(int i=1;i<=200;i++) Fac[i]=Fac[i-1]*i%MOD;
	Inv[200]=qpow(Fac[200],MOD-2);
	for(int i=199;i>=1;i--) Inv[i]=Inv[i+1]*(i+1)%MOD;Inv[0]=1;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	if(m<=12)
	{
		ll From=n,To=n*qpow(2,m);
		for(int i=From;i<=To;i++)
		{
			int res=PopCount(i),Maxn=0;
			if(res<=k)
			{
				int x=i,cnt=0;
				while(x)
				{
					S[cnt++]=x&1;
					if(x&1) Maxn=max(Maxn,cnt-1);
					x>>=1;
				}
				Divide(Maxn,n-res,1,Fac[n]);
			}
		}
		printf("%lld",Ans);
		return 0;
	}
	if(k==1)
	{
		for(int i=0;i<=m+5;i++)
		{
			S[i]=1;
			Divide(i,n-1,1,Fac[n]);
			S[i]=0;
		}
		printf("%lld",Ans);
		return 0;
	}
	if(n<=8)
	{
		dfs2(1);
		printf("%lld",Ans);
		return 0;
	}
	return 0;
}
/*
5 1 1
2 1

40
*/
