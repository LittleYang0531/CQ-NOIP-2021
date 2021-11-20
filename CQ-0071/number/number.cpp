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
int T;
bool b[10000001];
int nxt[10000001];
int p[10]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int maxs=0;
	for(int k=1;k<=7;k++)
	{
		int x=7*p[k];
		for(int i=0;i<p[8-k];i++)
		{
			x+=i*p[k+1];
			for(int j=0;j<p[k];j++)
			{
				//cout<<x+j+i*p[k+1]<<endl;
				b[x+j]=1;
				//maxs=max(maxs,x+j+i*p[k+1]);
			}
			x-=i*p[k+1];
		}
	}
	//cout<<maxs<<endl;
	//cout<<b[1]<<endl;
	int last=0;
	for(int i=1;i<=10000000;i++)
	{
		if(b[i])
		{
			for(int j=i;j<=10000000;j+=i)
			{
				nxt[j]=-1;
			}
		}
		else
		{
			if(~nxt[i])
			{
				//cout<<i<<endl;
				nxt[last]=i;
				last=i;
			}
		}
	}
	//cout<<nxt[1]<<endl;
	T=read();
	while(T--)
	{
		int x=read();
		printf("%d\n",nxt[x]);
	}
	return 0;
}
/*
4
6
33
69
300
*/
/*
5
90
99
106
114
169
*/
