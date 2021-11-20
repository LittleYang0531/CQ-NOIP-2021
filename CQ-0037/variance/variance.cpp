#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buf_size=1<<20;
	char buf[buf_size],*S,*T;
	inline char read_char()
	{
		if(S==T)
			T=(S=buf)+fread(buf,1,buf_size,stdin);
		return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
		char c=read_char();
		bool neg=false;
		while(c<'0'||c>'9')
		{
			neg=(c=='-');
			c=read_char();
		}
		int x=0;
		while(c>='0'&&c<='9')
		{
			x=x*10+(c^'0');
			c=read_char();
		}
		return neg?-x:x;
	}
}
int n;
const int max_n=1e4+5;
int a[max_n];
namespace Subtask1 // n<=10,a[n]<=40
{
	map<vector<int>,bool> vis;
	int ans=1e9;
	vector<int> now;
	void dfs(int S,int V)
	{
		if(vis[now])
			return;
		vis[now]=true;
		ans=min(ans,V);
		for(int i=0;i<int(now.size());++i)
		{
			int x=now[i];
			int L=i>0?now[i-1]:a[1];
			int R=i+1<n-2?now[i+1]:a[n];
			int S_new=S-x+(L+R-x);
			int V_new=V+n*((L+R-x)*(L+R-x)-x*x)+S*S-S_new*S_new;
			now[i]=L+R-x;
			dfs(S_new,V_new);
			now[i]=x;
		}
	}
	inline void solve()
	{
		for(int i=2;i<=n-1;++i)
			now.push_back(a[i]);
		int S=0,V=0;
		for(int i=1;i<=n;++i)
		{
			S+=a[i];
			V+=n*a[i]*a[i];
		}
		V-=S*S;
		dfs(S,V);
		printf("%d\n",ans);
	}
}
namespace Subtask2
{
	int b[max_n],p[max_n];
	inline void solve()
	{
		int S=0,V=0;
		for(int i=1;i<=n;++i)
		{
			S+=a[i];
			V+=n*a[i]*a[i];
			b[i]=a[i];
		}
		V-=S*S;
		int S1=S,V1=V;
		srand(time(NULL));
		for(int i=1;i<=n;++i)
			p[i]=i;
		while(1)
		{
			bool flag=false;
			for(int j=1;j<=n;++j)
			{
				int i=p[j];
				if(i==1||i==n)
					continue;
				int x=a[i];
				int L=a[i-1];
				int R=a[i+1];
				int S_new=S-x+(L+R-x);
				int V_new=V+n*((L+R-x)*(L+R-x)-x*x)+S*S-S_new*S_new;
				if(V_new<V)
				{
					a[i]=L+R-x;
					S=S_new,V=V_new;
					flag=true;
					break;
				}
			}
			if(!flag)
				break;
		}
		int ans=V;
		while(1.0*clock()/CLOCKS_PER_SEC<=0.95)
		{
			S=S1,V=V1;
			for(int i=1;i<=n;++i)
				a[i]=b[i];
			random_shuffle(p+1,p+n+1);
			while(1)
			{
				bool flag=false;
				for(int j=1;j<=n;++j)
				{
					int i=p[j];
					if(i==1||i==n)
						continue;
					int x=a[i];
					int L=a[i-1];
					int R=a[i+1];
					int S_new=S-x+(L+R-x);
					int V_new=V+n*((L+R-x)*(L+R-x)-x*x)+S*S-S_new*S_new;
					if(V_new<V)
					{
						a[i]=L+R-x;
						S=S_new,V=V_new;
						flag=true;
						break;
					}
				}
				if(!flag)
					break;
			}
			ans=min(ans,V);
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	if(n==1)
	{
		puts("0");
		return 0;
	}
	if(n==2)
	{
		printf("%d\n",n*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]));
		return 0;
	}
	if(n==3)
	{
		int ans=n*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,n*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]));
		printf("%d\n",ans);
		return 0;
	}
	if(n<=10&&a[n]<=40)
		Subtask1::solve();
	else
		Subtask2::solve();
	return 0;
}

