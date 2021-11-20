#include<bits/stdc++.h>
using namespace std;

const int N=10005000;
int low[N],p7[N],cnt,prim[N],i7[N],cnt1;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while( ch < '0' or ch > '9' ) f *= ch=='-' ? -1 : 1, ch=getchar();
	while( ch >= '0' and ch <= '9' ) x=x*10+ch-'0', ch=getchar();
	return x*f;
}

inline bool is7(int x)
{
	while( x )
	{
		if( x%10==7 ) return true;
		x/=10;
	}
	return false;
}

inline void shai()
{
	cnt=0; p7[++cnt1]=1;
	for(int i=2;i<=10004000;i++)
	{
		if( (!i7[i]) && is7(i) )
		{
			i7[i]=1;
			for(int j=1;j*i<=10004000;j++) i7[i*j]=1;
		}
		else if( !i7[i] ) p7[++cnt1]=i;
	}
}

inline int find(int x)
{
	int l=1,r=cnt1,ans=-1;
	if( i7[x] ) return ans;
	while( l <= r )
	{
		int mid=l+r>>1;
		if( p7[mid] <= x ) l=mid+1;
		else ans=p7[mid],r=mid-1;
	}
	return ans;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	shai();
	int T=read();
	while( T-- )
	{
		int x=read();
		printf("%d\n",find(x));
	}
	return 0;
}
