#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k,s,t,ans,cnt,tot;
int d[10001005],bj[10001005];
bool pd(int u)
{
	while(u)
	{
		if(u%10==7) return 1;
		u/=10;
	}
	return 0;
}
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
void print(int u)
{
	if(u/10) print(u/10);
	putchar(u%10+48);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	tot=0;
	for(int i=1;;i++)
	{
		if(bj[i]) continue;
		if(pd(i))
		{
			for(int j=1;i*j<=10000000;j++)
			bj[i*j]=1;
			continue;
		}
		if(!bj[i]) d[tot]=i,tot=i;
		if(i>10000000&&!bj[i]) break;
	}
	for(int i=1,x;i<=n;i++)
	{
		x=read();
		if(bj[x]) puts("-1");
		else print(d[x]),puts("");
	}
}
