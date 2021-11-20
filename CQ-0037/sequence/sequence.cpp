#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buf_size=1<<20;
	char buf[buf_size],*S,*T;
	inline char read_char()
	{
		if(S==T)
			T=(S=buf)+fread(buf,1,buf_size,stdin);
		return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
		char c=read_char();
		bool neg=false;
		while(c<'0'||c>'9')
		{
			neg=(c=='-');
			c=read_char();
		}
		int x=0;
		while(c>='0'&&c<='9')
		{
			x=x*10+(c^'0');
			c=read_char();
		}
		return neg?-x:x;
	}
}
const int mod=998244353;
const int max_n=30+5;
const int max_m=100+5;
const int max_k=30+5;
int v[max_m],dp[max_m][max_n][max_n][max_k],C[max_n][max_n],Pow[max_m][max_n];
inline int calc(int x)
{
	int res=0;
	while(x)
	{
		res+=x&1;
		x>>=1;
	}
	return res;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n=IO::read_int(),m=IO::read_int(),k=IO::read_int();
	for(int i=0;i<=m;++i)
	{
		v[i]=IO::read_int();
//		fprintf(stderr,"i=%d v[i]=%d\n",i,v[i]);
	}
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]-=C[i][j]>=mod?mod:0;
		}
	}
	for(int i=0;i<=m;++i)
	{
		Pow[i][0]=1;
		for(int j=1;j<=n;++j)
		{
			Pow[i][j]=1ll*Pow[i][j-1]*v[i]%mod;
//			fprintf(stderr,"i=%d j=%d Pow[i][j]=%d\n",i,j,Pow[i][j]);
		}
	}
	for(int x=0;x<=n;++x)
		dp[0][x][x][x&1]=1ll*Pow[0][x]*C[n][x]%mod;
	for(int i=0;i<=m-1;++i)
		for(int j=0;j<=n;++j)
			for(int w=0;w<=j;++w)
				for(int t=0;t<=min(j,k);++t)
				{
					int v=dp[i][j][w][t];
					if(v)
					{
						for(int p=0;p<=n-j;++p)
						{
							int W=(w>>1)+p,cnt=t+(W&1);
							if(cnt<=k)
								dp[i+1][j+p][W][cnt]=(dp[i+1][j+p][W][cnt]+1ll*v*Pow[i+1][p]%mod*C[n-j][p])%mod;
						}
					}
				}
	int ans=0;
	for(int i=0;i<=n;++i)
	{
		int cnt=calc(i>>1);
		for(int j=0;j<=k-cnt;++j)
		{
			ans+=dp[m][n][i][j];
			ans-=ans>=mod?mod:0;
		}
	}
	printf("%d\n",ans);
	return 0;
}

