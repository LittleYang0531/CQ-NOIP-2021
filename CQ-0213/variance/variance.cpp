#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<map>
#define maxn 10002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int n;
struct str{
	int a[102];
	int val()
	{
		int ans=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i];
			sum+=a[i];
		}
		return n*ans-sum*sum;
	}
	ll h()
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=sum*607+a[i];
		}
		return sum;
	}
};
map<ll,bool>vis;
queue<str>q;
int minn;
int cnt;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	str w;
	for(int i=1;i<=n;i++)
	{
		w.a[i]=read();
	}
	minn=w.val() ;
	vis[w.h()]=1;
	q.push(w);
	int dx=10000000/n;
	while(!q.empty())
	{
		w=q.front() ;
		q.pop() ;
		for(int i=2;i<n;i++)
		{
			str t=w;
			t.a[i]=t.a[i-1]+t.a[i+1]-t.a[i];
			int e=t.h();
			if(!vis.count(e))
			{
				vis[e]=1;
				++cnt;
				minn=min(minn,t.val() );
				q.push(t); 
			}
		}
	}
	printf("%d\n",minn);
	return 0;
}


