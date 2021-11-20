#include<bits/stdc++.h>
using namespace std;

#define re register

const long long NUM = 998244353;

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

int n,m,k;
int num[105];

long long s;

inline int BIN(long long x)
{
	long long y=x;
	int ans;
	while(y)
	{
		int m=y%2;
		if(m==1)
			++ans;
		y/=2;
	}
	return  ans;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read();
	m = read();
	k = read();
	for(re int i = 1;i <= m;++i)
		num[i] = read();
	for(re long long i = n;i <= n;++i)
	return 0;
}
