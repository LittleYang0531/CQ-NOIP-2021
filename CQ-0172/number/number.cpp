#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char buf[1<<23],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
int fpow[10];
bool g[10000005];
int seq[10000005],seq_total;
int nex[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	fpow[0]=1;
	for(int i=1;i<=8;++i)fpow[i]=fpow[i-1]*10;
	int cnt=1;
	for(int i=1;i<=7;++i)
	{
		int a=fpow[i-1]*fpow[7-i+1];
		int b=fpow[7-i];
		int c=fpow[7-i+1];
		int d=7*fpow[7-i];
		for(int j=0;j<a;j+=c)
		{
			for(int k=0;k<b;++k)
			{
				if(!g[j+d+k])
				{
					seq[++seq_total]=j+d+k;
					g[j+d+k]=true;
				}
			}
		}
	}
	for(int i=1;i<=seq_total;++i)
	{
		for(int j=seq[i];j<=10000000;j+=seq[i])
			g[j]=true;	
	}
	int last=0;
	for(int i=1;i<=10000000;++i)
	{
		if(!g[i])
		{
			if(last!=0)nex[last]=i;
			last=i;
		}
	}
	nex[last]=10000001;
	int m;
	rd(m);
	while(m--)
	{
		int x;
		rd(x);
		if(g[x])cout<<"-1\n";
		else
		{
			cout<<nex[x]<<'\n';
		}
	}
	return 0;
}
