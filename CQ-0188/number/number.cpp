#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){bool f=0;int sum=0;char ch=getchar();while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();ret=sum;}

const int N=1e7,M=2e5+5;
bool d[10000005],pri[10000005];
int m,p[1000005],ans[10000005];
bool check_7(int num)
{
	while(num)
	{
		if(num%10==7)
			return 1;
		num/=10;
	}
	return 0;
}
void lucky_7()
{
	int i,j;
	for(i=2;i<=N;i++)
	{
		if(pri[i]==0)
			p[++m]=i;
		for(j=1;j<=m&&(long long)p[j]*i<=N;j++)
		{
			pri[p[j]*i]=1;
			if(i%p[j]==0)
				break;
		}
	}
	for(i=2;i<=N;i++)
	{
		d[i]|=(i%7==0)|check_7(i);
		if(d[i])
		{
			for(j=1;j<=m&&(long long)p[j]*i<=N&&p[j]*i>0;j++)
				d[p[j]*i]=1;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(d[i])
			ans[i]=-1;
		else
		{
			int x=i;
			i++;
			while(d[i])
				ans[i++]=-1;
			ans[x]=i;
			i--;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,i,j,x;
	d[0]=1;
	qr(t);
	lucky_7();
	while(t--)
	{
		qr(x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
