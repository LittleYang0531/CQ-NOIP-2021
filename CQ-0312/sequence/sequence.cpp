//2021/11/20

#include <iostream>

#include <cstdio>

#include <climits>

#define int long long

#define debug(x,que) cerr<<#x<<" = "<<x<<que

#define endl "\n"

namespace Newstd
{
	inline int read()
	{
		int x=0,k=1;
		char ch=getchar();
		while(ch<'0' || ch>'9')
		{
			if(ch=='-')
			{
				k=-1;
			}
			ch=getchar();
		}
		while(ch>='0' && ch<='9')
		{
			x=(x<<1)+(x<<3)+ch-'0';
			ch=getchar();
		}
		return x*k;
	}
	inline void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		if(x>9)
		{
			write(x/10);
		}
		putchar(x%10+'0');
	}
}

using namespace Newstd;

using namespace std;

const int mod=998244353;

const int ma=105;

int v[ma],a[ma];

int C[ma][ma];

int n,m,k;

int ans;

inline void init()
{
	C[0][0]=1;
	
	for(register int i=1;i<=ma;i++)
	{
		C[i][0]=1;
		
		for(register int j=1;j<=ma;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}

inline int calc(int x)
{
	int tp=0;
	
	if(x%2==1)
	{
		tp++;
		
		x--;
	}
	
	while(x!=0)
	{
		tp+=(x%2);
		
		x/=2;
	}
	
	return tp;
}

inline void dfs(int step,int num)
//num:S 二进制下 1 的个数,cost:当前序列的价值 
{
	if(step==n+1)
	{
		int cost(1);
		
		for(register int i=1;i<=m;i++)
		{
			cost=(cost*v[a[i]])%mod;
		}
		
		for(register int i=1;i<=n;i++){
			cout<<a[i]<<" "; 
		}puts("");
		
		ans=(ans+cost)%mod;
		
		return;
	}
	
	for(register int i=0;i<=m;i++)
	{
		a[step]=i;
		
		dfs(step+1,num+1);
		
		a[step]=0;
		
		dfs(step+1,num);
	}
}

#undef int

int main(void)
{
	freopen("sequence.in","r",stdin);
	
	freopen("sequence.out","w",stdout);
	
	#define int long long
	
	n=read(),m=read(),k=read();
	
	for(register int i=0;i<=m;i++)
	{
		v[i]=read();
	}
	
//	init();
	
	dfs(1,0);
	
	printf("%lld\n",ans%mod);
	
	return 0;
}
