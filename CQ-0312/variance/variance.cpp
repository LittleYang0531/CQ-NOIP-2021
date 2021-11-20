//2021/11/20

/*
·½²î 
*/
#include <iostream>

#include <cstdio>

#include <climits>

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

const int ma=10005;

int a[ma];

bool vis[ma];

int n;

double ans;

inline void dfs(int step)
{
	if(step==n+1)
	{
		double pj(0),fc(0);
		
		for(register int i=1;i<=n;i++)
		{
			pj+=(double)a[i];
		}
		
		pj/=(double)n;
		
		for(register int i=1;i<=n;i++)
		{
			double now=((double)a[i]-pj);
			
			fc+=now*now;
		}
		
		fc/=(double)n; 
		
		ans=min(ans,fc);
		
		return;
	}
	
	for(register int i=2;i<n;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			
			int tmp=a[i];
			
			a[i]=a[i-1]+a[i+1]-a[i];
			
			dfs(step+1);
			
			vis[i]=false;
			
			a[i]=tmp;
		}
	}
}

int main(void)
{
	freopen("variance.in","r",stdin);
	
	freopen("variance.out","w",stdout);
	
	n=read();
	
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	
	ans=999999.0;
	
	dfs(1);
	
	cout<<ans*(n*n)<<endl;
	
	return 0; 
}
