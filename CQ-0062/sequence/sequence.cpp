#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar('0'+x%10);
}
const LL MOD=998244353;
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
LL C[111][111],n,m,K,v[111],dp[111][32][32][(1<<8)+2],fac[111],pct[(1<<8)+2];
LL lowbit(LL x){return x&(-x);}
LL Converge(LL S,LL p){return S+p;}
int main(){
	freopen("sequence.in","r",stdin);
//	freopen("sequence2.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read();
	for(LL i=0;i<=m;++i)	v[i]=read();
	C[0][0]=1;
	for(LL i=1;i<=100;++i)
	{
		C[i][0]=1;
		for(LL j=1;j<=i;++j)	C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	for(LL S=1;S<(1<<8);++S)	pct[S]=pct[S^lowbit(S)]+1;
	fac[0]=1;
	for(LL i=1;i<=100;++i)	fac[i]=fac[i-1]*i%MOD;
	dp[0][0][0][0]=1;
	for(LL i=0;i<=m+8;++i)
	{
		for(LL j=0;j<=K;++j)
		{
			for(LL k=0;k<=n;++k)
			{
				for(LL S=0;S<(1<<8);++S)
				{
					if(!dp[i][j][k][S])	continue;
					LL val=1;
					for(LL l=0;l+k<=n;++l)
					{
						LL T=Converge(S,l);
						dp[i+1][j+(T&1)][k+l][T>>1]=(dp[i+1][j+(T&1)][k+l][T>>1]+dp[i][j][k][S]*val%MOD*C[n-k][l]%MOD)%MOD;
						val=val*v[i]%MOD;
					}
				}
			}
		}
	}
	LL ans=0;
	for(LL j=0;j<=K;++j)	for(LL S=0;S<(1<<8);++S)	if(j+pct[S]<=K)	ans=(ans+dp[m+8][j][n][S])%MOD;
	write(ans);
	return 0;
}
/*
Faint Glow...
*/
