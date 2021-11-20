#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
const int mod=998244353;
int n,m,k;
int val[105];
int dp[31],dp2[31];
int C[31][31];
int main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	rd(n),rd(m),rd(k);
	for(int i=0;i<=m;++i)rd(val[i]);
	int _m=1<<m+4;
	for(int i=0;i<_m;++i)
	{
		int cnt=0;
		int tmp=i;
		while(tmp)
		{
			tmp-=tmp&-tmp;
			++cnt;
		}
		if(cnt>k)continue;
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		dp2[0]=1;
		int tst=i>m?0:i-m;
		for(int j=0;j<=_m;++j)
		{
			for(int k=n;k>=1;--k)
			{
				for(int t=tst;;++t)
				{
					int tp=1<<t;
					if(tp>k)break;
					dp[k]=(dp[k]+(long long)dp[k-tp]*C[n-k+tp][tp])%mod;
					
				}
			}
		}
	}
	return 0;
}
