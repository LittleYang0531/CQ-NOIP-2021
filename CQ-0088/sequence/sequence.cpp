#include<bits/stdc++.h>
using namespace std;
#define re register int
#define int long long
#define gc() getchar()
inline int rd()
{
	int x=0,f=1;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc())if(c=='-')f=0;
	for(; '0'<=c&&c<='9'; c=gc())x=(x<<1)+(x<<3)+c-'0';
	return f?x:-x;
}
const int mo=998244353;
int shu(int x)
{
	int ret=0;
	while(x)ret++,x-=(x&-x);
	return ret;
}
int ans, b[105], val[105], n, m, k;
int C[105][105];
inline void DFS(int x, int t)
{
	if(x==n+1)
	{
		int tmp=0, ret=1, cnt=1, lst=-1, num=0;
		for(re i=1;i<=n;++i)
		{
			if(b[i]!=lst)
			{
				lst=b[i];
				cnt=cnt*C[i-1][num]%mo;
				num=0;
			}
			num++;
			tmp+=(1<<b[i]);
			ret=ret*val[b[i]]%mo;
		}
		if(shu(tmp)<=k)
		{
			ans+=ret*cnt%mo*C[n][num]%mo;
			ans%=mo;
		}
		return;
	}
	for(re i=t;i<=m;++i)
	{
		b[x]=i;
		DFS(x+1,i);
	}
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	C[0][0]=1;
	for(re i=1;i<=100;++i)
	{
		C[i][0]=1;
		for(re j=1;j<=i;++j)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
		}
	}
	n=rd(),m=rd(),k=rd();
	for(re i=0;i<=m;++i)val[i]=rd();
	DFS(1,0);
	printf("%lld\n", ans);
}
