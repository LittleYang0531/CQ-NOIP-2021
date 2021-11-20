#include<bits/stdc++.h>
#define mod 998244353
#define N 35
#define ll long long
#define M 130000
using namespace std;
inline ll read(){
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(ll x){
	char f[50];ll cnt=0;
	if(!x)
		putchar('0');
	while(x){
		f[cnt++]=x%10+'0';
		x/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
}
ll dp[N][M],n,m,k,lg[N],ans=0,v[N],maxn;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	lg[0]=1;
	for(ll i=1;i<=20;++i)
		lg[i]=lg[i-1]<<1;
	for(ll i=0;i<=m;++i)
		v[i]=read();
	dp[0][0]=1;
	maxn=lg[m]*n;
	for(ll i=1;i<=n;++i)
		for(ll j=0;j<=m;++j)
			for(ll h=i-1;h+lg[j]<=maxn;++h)
dp[i][h+lg[j]]=(dp[i][h+lg[j]]+dp[i-1][h]*v[j]%mod)%mod;
	for(ll i=n;i<=maxn;++i)
		{
			ll tot=0;
			for(ll j=0;j<=16;++j)
				if(i&lg[j])
					++tot;
			if(tot<=k)
				ans=(ans+dp[n][i])%mod;
		}
	write(ans);
	return 0;
}
