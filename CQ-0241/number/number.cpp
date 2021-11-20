#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

#define maxn 10000010
#define rc() getchar()

using namespace std;

int pr[maxn],pd[maxn],bj[maxn],nxt[maxn];
const int maxk=2e5+10;

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

inline bool check(int x)
{
	while(x)
	{
		int now=x%10;
		if(now==7) return 1;
		x/=10;
	}
	return  0;
}

inline void check2(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			if(pd[i]==1||pd[x/i]==1) 
			{
				pd[x]=1;
				return;
			}
		}
	}
	
}

int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=2;i<=maxk;++i)
	{
		if(!pd[i]) pd[i]=check(i);
		if(!bj[i]) pr[++pr[0]]=i;
		for(int j=1;j<=pr[0]&&i*pr[j]<=maxk;++j)
		{
			bj[i*pr[j]]=1;
			pd[i*pr[j]]=pd[i]+pd[pr[j]];
			if(i%pr[j]==0) break;
		}
	}
	for(int i=maxk,l=0;i;--i)
	{
		if(!pd[i]) check2(i);
		if(!pd[i])
		{
			nxt[i]=l;
			l=i;
		}
	}
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		if(pd[x]) printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
