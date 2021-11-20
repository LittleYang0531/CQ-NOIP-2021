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
int n;
int a[10001];
long long sum=0;
long long dsum=0;
const int mod=998244353;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum=(sum+a[i])%mod;
	}
	while(1)
	{
		bool bj=1;
		for(int i=2;i<n;i++)
		{
			long long delta=a[i-1]+a[i+1]-2*a[i];
			if(delta>0)
			{
				if((n-1)*delta<=2*(sum-(long long)n*a[i]))
				{
					a[i]+=delta;
					sum+=delta;
					bj=0;
					//cout<<(n-1)*delta<<endl;
					//cout<<i<<" "<<a[i]<<endl;
				}
			}
			else if(delta<0)
			{
				if((n-1)*delta>=2*(sum-(long long)n*a[i]))
				{
					a[i]+=delta;
					sum+=delta;
					bj=0;
					//cout<<(n-1)*delta<<endl;
					//cout<<i<<" "<<a[i]<<endl;
				}
			}
		}
		if(bj)
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dsum=(dsum+(long long)a[i]*a[i]%mod)%mod;
	}
	printf("%lld",(n*dsum%mod-sum*sum%mod+mod)%mod);
	return 0;
}
