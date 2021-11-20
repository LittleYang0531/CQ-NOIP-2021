#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	int f=1;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}
const int MAXN=1e7+5;
bool vis[MAXN];
int v[MAXN];
int t;
int x;
int last;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	last=1;
	for(int i=2;i<=MAXN-5;i++)
	{
		bool f=0;
		int now=i;
		while(now)
		{
			int d=now%10;
			if(d==7)
			{
				f=1;
				break;
			}
			now/=10;
		}
		if(f)
		{
			for(int j=i;j<=MAXN-5;j+=i)
			{
				vis[j]=1;
			}
		}
		if(!vis[i])
		{
			v[last]=i;
			last=i;
		}
	}
	v[last]=10000001;
	scanf("%d",&t);
	while(t--)
	{
		read(x);
		if(vis[x])
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",v[x]);
		}
	}
	
	return 0;
}
