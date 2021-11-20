#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#define inf 1e9
#define mem(a,b) memset(a,b,sizeof(a))
#define enter putchar('\n')
#define N 10000000
using namespace std;
int t;
int ok[N];
bool vst1[N],vst2[N];
inline int re()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
priority_queue<int>q;
void csh()
{
	q.push(7);
	while(!q.empty())
	{
		int x=q.top();
		q.pop();
		ok[x]=-1;
		for(int i=x+x;i<=200000;i+=x)
		{
			ok[i]=-1;
			if(!vst1[i]) q.push(i);
			vst1[i]=1;
		}
	}
}
void dfs(int x)
{
	if(x>200000) return ;
	if(vst2[x]) return ;
	vst2[x]=1;
	ok[x]=-1;
	q.push(x);
	for(int i=0;i<=9;i++)
		dfs(x*10+i);
	for(int i=1;i<=9;i++)
	{
		dfs(x+i*pow(10,int(log10(x)+1)));
		dfs(x+i*10*pow(10,int(log10(x)+1)));
		dfs(x+i*100*pow(10,int(log10(x)+1)));
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	dfs(7);
	for(int i=10007;i<=90007;i+=10000)
		dfs(i);
	ok[100007]=-1;
	csh();
	t=re();
	while(t--)
	{
		int x=re();
		if(ok[x]==-1)
		{
			cout<<"-1\n";
			continue;
		}
		x++;
		int xc=x,k=0;
		while(x)
		{
			if(x%10==7) xc+=pow(10,k);
			k++;
			x/=10;
		}
		while(ok[xc]==-1) xc++;
		cout<<xc<<'\n';
	}
	return 0;
}
