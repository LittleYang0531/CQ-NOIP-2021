#include<bits/stdc++.h>
using namespace std;

#define re register

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

int n;
int num[10005],times;

double ave;

double res[10005];

inline double variance()
{
	double x=0;
	for(re int i = 1;i <= n;++i)
	{
		x+=pow((double)num[i]-ave,2);
	}
	return x/(double)n;
}

inline void gg()
{
	ave=0;
	for(re int i = 1;i <= n;++i)
	{
		ave+=num[i];
	}
	ave/=(double)n;
}

inline bool cmp(double x,double y)
{
	return x<y;
}

int main()
{
	freopen("variance.out","w",stdout);
	freopen("variance.in","r",stdin);
	n = read();
	for(re int i = 1;i <= n;++i)
	{
		num[i] = read();
		ave+=(double)num[i];
	}
	ave/=(double)n;
	res[++times] = variance();
	for(re int i = 2;i <= n-1;++i)
	{
		num[i] = num[i-1]+num[i+1]-num[i];
		gg();
		res[++times] = variance();
	}
	sort(res+1,res+times+1,cmp);
	printf("%lld",(long long)(res[1]*n*n));
	return 0;
}
