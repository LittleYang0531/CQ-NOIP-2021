#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
#define R_ register
using namespace std;

const ll mod=998244353;
ll n,m,k,v[105],f[35][130005],ans,a[35];
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll check(ll S)
{
	ll tot=0;
	while(S){
		if(S&1)++tot;
		S>>=1;
		if(tot>k)return 0;
	}
	return 1;
}
void solve()
{
	ll s=0;
	for(R_ int i=1;i<=n;++i)s+=1<<a[i];
	if(!check(s))return;s=1;
	for(R_ int i=1;i<=n;++i)s=s*v[a[i]]%mod;
	ans=(ans+s)%mod;
}
void dfs(int x)
{
	if(x==n+1){solve();return;}
	for(R_ int i=0;i<=m;++i){
		a[x]=i;dfs(x+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++)v[i]=read();
	if(m<=12)
	{
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i*(1<<m);j++){
				for(int x=0;x<=m;x++){
					if((1<<x)>j)break;
					f[i][j]=(f[i][j]+f[i-1][j-(1<<x)]*v[x]%mod)%mod;
//					cout<<i<<" "<<j<<" "<<x<<"^\n";
				}
			}
		}
		for(int i=n;i<=n*(1<<m);i++){
			if(check(i)){
//				cout<<f[n][i]<<"  ";
				ans=(ans+f[n][i])%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=5){
		dfs(1);
		cout<<ans;
		return 0;
	}
	ll sss=1,ttt=0;
	for(int i=0;i<=m;i++)ttt=(ttt+v[i])%mod;
	for(int i=0;i<=m;i++)sss=(sss+v[i]%mod*(i)%mod)%mod;
	cout<<1ll*n*k%mod*sss%mod*(ttt+1)%mod;
	return 0;
}
