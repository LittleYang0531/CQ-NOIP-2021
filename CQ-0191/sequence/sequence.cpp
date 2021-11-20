#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAXN=35;
const int MAXM=105;
int n,m,K;
long long v[505];
long long C[505][505];
long long dp[MAXM][MAXN][MAXN][MAXN/2+1];
long long Pow[MAXM][MAXN];
int o(int x)
{
	int tot=0;
	while(x)
	{
		tot+=(x&1);
		x>>=1;
	}
	return tot;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	C[0][0]=1;
	for(int i=1;i<=500;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	//		printf("%d ",C[i][j]);
		}
	//	printf("\n");
	}
	scanf("%d %d %d",&n,&m,&K);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
	}
	for(int i=0;i<=m;i++)
	{
		Pow[i][0]=1;
		for(int j=1;j<=n;j++)
		{
			Pow[i][j]=(Pow[i][j-1]*v[i])%MOD;
		}
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i%2][i][i/2]=Pow[0][i];	
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=K;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int l=0;l<=k;l++)
				{
					for(int p=0;p<=n/2;p++)
					{
						int f=(p+l)%2;
						if(j<f)
						{
							continue;
						}
						dp[i][j][k][(p+l)/2]+=((dp[i-1][j-f][k-l][p]*Pow[i][l]%MOD)*C[k][l])%MOD;
						dp[i][j][k][(p+l)/2]%=MOD;	
						
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=K;i++)
	{
		for(int p=0;p<=n/2;p++)
		{
			if(i+o(p)<=K)
			{
				ans+=dp[m][i][n][p];
				ans%=MOD;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
