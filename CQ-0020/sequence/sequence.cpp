/*
考虑每次加入一个数a
枚举其选了o个。
dp[i][j][k][l]表示当前在第i个v，选了j个a，当前的和二进制下有k个1，当前第i位向i+1位进了l的方案目前乘积之和 
dp[i][j][k][l]->dp[i+1][j+o][k+((l+o)&1)][(l+o)>>1]
转移的权值为v[i+1]^o
所有的可能方案都要乘上这个，所以是对的。
错了还得搞个组合数算下放在哪儿。 
转移的权值为v[i+1]^o*C(n-j,o)
所有的可能方案都有n-j个空位，所以还是对的。 
看下复杂度：m*n*k*k*n
100*30^4
81000000?
dp[i-1][j][k][l]->dp[i][j+o][k+((l+o)&1)][(l+o)>>1]
转移的权值为v[i]^o
答案在dp[m][n][0~k][x]

**会做pdf样例吗 
5 1 1
2 1

40

过大样例了，先滚了。 
*/
#include<cstdio>
const long long mod=998244353;
long long n,m,K,dp[110][35][35][35],C[35][35],v[110],ans;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&K);
	C[0][0]=1;
	for(long long i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(long long j=1;j<=i;++j)	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(long long i=0;i<=m;++i)	scanf("%lld",&v[i]);
	for(long long i=0,vls=1;i<=n;++i,vls=(vls*v[0])%mod)	dp[0][i][i&1][i>>1]=vls*C[n][i]%mod;
	for(long long i=1;i<=m;++i)
	{
		for(long long j=0;j<=n;++j)
		{
			for(long long k=0;k<=K;++k)
			{
				for(long long l=0;l<=n;++l)
				{
					if(!dp[i-1][j][k][l])	continue;
					for(long long o=0,vls=1;o+j<=n;++o,vls=(vls*v[i])%mod)
					{
						if(k+((l+o)&1)<=K)	dp[i][j+o][k+((l+o)&1)][(l+o)>>1]=(dp[i][j+o][k+((l+o)&1)][(l+o)>>1]+dp[i-1][j][k][l]*vls%mod*C[n-j][o])%mod;
					}
				}
			}
		}
	}
	for(long long i=0;i<=K;++i)
	{
		for(long long j=0;j<=n;++j)
		{
			if(!dp[m][n][i][j])	continue;
			long long cnt=i,now=j;
			while(now)
			{
				if(now&1)	++cnt;
				now>>=1;
			}
			if(cnt<=K)	ans=(ans+dp[m][n][i][j])%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
