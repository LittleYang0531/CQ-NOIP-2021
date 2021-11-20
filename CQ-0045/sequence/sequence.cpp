#include<bits/stdc++.h>
#define purge AK
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;++i)
#define Rof(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int mod=998244353;
int n,m,k,v[101],a[31],c[31][31],ans;
bitset<200>f[101];
void dfs(int x,int lim,bitset<200>sta)
{
	if((sta&f[lim]).count()>k)
		return;
	if(x>n)
	{
		if(sta.count()>k)
			return;
		int val=1;
		For(i,1,n)
			val=1ll*val*v[a[i]]%mod;
		for(int i=1,j=upper_bound(a+1,a+n+1,a[i])-a;j<=n;i=j,j=upper_bound(a+1,a+n+1,a[i])-a)
			val=1ll*val*c[n-i+1][j-i]%mod;
		ans=(ans+val)%mod;
		return;
	}
	For(i,lim,m)
	{
		bitset<200>t=sta;
		int j=i;
		while(t[j])
		{
			t[j]=0;
			++j;
		}
		t[j]=1;
		a[x]=i;
		dfs(x+1,i,t);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	For(i,0,m)
	{
		cin>>v[i];
		For(j,0,i-1)
			f[i][j]=1;
	}
	For(i,0,n)
		c[i][0]=1;
	For(i,1,n)
		For(j,1,i)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
