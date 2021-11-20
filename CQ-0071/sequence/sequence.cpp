#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x;
}
const long long mod=998244353;
long long p[31];
int n,m,k;
int v[101];
long long ans;
long long res;
inline void dfs(int now,long long sum,int t)
{
	//cout<<now<<" "<<sum<<" "<<t<<endl;
	if(t==n)
	{
		int cnt=0;
		while(sum)
		{
			cnt+=sum%2;
			sum/=2;
			if(cnt>k)
			{
				return ;
			}
		}
		ans=(ans+res)%mod;
		return ;
	}
	if(now>m)
	{
		return ;
	}
	for(int i=t;i<=n;i++)
	{
		res+=v[now]*(i-t);
		dfs(now+1,sum+p[now]*(i-t),i);
		res-=v[now]*(i-t);
	}
	return ;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=100;i++)
	{
		p[i]=p[i-1]*2;
	}
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
	}
	dfs(0,0,0);
	printf("%lld",ans);
	return 0;
}
