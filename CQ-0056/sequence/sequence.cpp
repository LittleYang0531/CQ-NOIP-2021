#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
	if(b&1)s=1ll*s*a%mod;
	return s;
}
int fac[50],inv[50];
int n,m,k,v[110],dp[40][110][40][40];
int main()
{
freopen("sequence.in","r",stdin);
freopen("sequence.out","w",stdout);
fac[0]=1;
for(int i=1;i<50;i++)fac[i]=1ll*fac[i-1]*i%mod;
inv[49]=ksm(fac[49],mod-2);
for(int i=48;~i;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;

scanf("%d%d%d",&n,&m,&k);
for(int i=0;i<=m;i++)scanf("%d",&v[i+1]);

dp[0][0][0][0]=1;

for(int a=0;a<=n;a++)
	for(int b=0;b<=m;b++)
		for(int c=0;c<=k;c++)
			for(int d=0;d<=a;d++)
			if(dp[a][b][c][d])
			{
				int cc=c,dd=d;
				for(int i=b+1;i<=m+1;i++)
				{
					for(int j=a+1;j<=n;j++)
					if(cc+(((j-a)+dd)&1)<=k)
						(dp[j][i][cc+(((j-a)+dd)&1)][((j-a)+dd)>>1]+=
						1ll*dp[a][b][c][d]*ksm(v[i],j-a)%mod*inv[j-a]%mod)%=mod;
					cc+=(dd&1);
					dd>>=1;
				}
			}
int ans=0;
for(int c=0;c<=k;c++)
	for(int d=0;d<=n;d++)
	{
		int cc=c,dd=d;
		while(dd)
		{
			cc+=(dd&1);
			dd>>=1;
		}
		if(cc<=k)
		for(int b=1;b<=m+1;b++)
		(ans+=1ll*dp[n][b][c][d]*fac[n]%mod)%=mod;
	}

printf("%d",ans);

return 0;
}
