//2021/11/20

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

/*
const int ma=1e7;

int pri[ma];

bool is_pri[ma];
*/

int T,n;

int idx;

inline bool solv(int x)
{
	while(x!=0)
	{
		if(x%10==7)
		{
			return false;
		}
		
		x/=10;
	}
	
	return true;
}

/*
inline void init(int x)
{
	for(register int i=2;i<=x;i++)
	{
		if(is_pri[i]==false)
		{
			pri[++idx]=i;
		}
		
		for(register int j=1;j<=idx && pri[j]*i<=x;j++)
		{
			is_pri[pri[j]*i]=true;
			
			if(i%pri[j]==0)
			{
				break;
			}
		}
	}
}
*/

inline bool chk(int x)
{
	for(register int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(solv(i)==false || solv(x/i)==false)
			{
				return false;
			}
		}
	}
	
	return solv(x);
}

int main(void)
{
	freopen("number.in","r",stdin);
	
	freopen("number.out","w",stdout);
	
	T=read();
	
	/*
	bool mark=(T>=100000);
	
	if(mark==true)
	{
		init(ma);
	}
	*/
	
	while(T--)
	{
		n=read();
		
		if(chk(n)==false)
		{
			puts("-1");
			
			continue;
		}
		
		for(n=n+1;;n++)
		{
			/*
			if(mark==true && solv(n)==true && is_pri[n]==false)
			{
				break;
			}
			*/
			
			if(chk(n)==true)
			{
				break;
			}
		}
		
		printf("%d\n",n);
	}
	
	return 0;
}
