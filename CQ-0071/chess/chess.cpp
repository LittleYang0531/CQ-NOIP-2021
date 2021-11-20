#include<bits/stdc++.h>
using namespace std;
inline int readchar()
{
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	return c^48;
}
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
int n,m,Q;
int v[8000010];
int nxt[8000010];
int d[200001];
int type[8000010];
int tot;
inline void add(int x,int y,int z)
{
	v[++tot]=y;
	nxt[tot]=d[x];
	d[x]=tot;
	type[tot]=z;
	return ;
}
inline int point(int x,int y)
{
	return (x-1)*m+y;
}
inline void separate(int x)
{
	if(x%m)
	{
		cout<<x/m+1<<" "<<x%m<<endl;
	}
	else
	{
		cout<<x/m<<" "<<m<<endl;
	}
}
bool color[200001];
int lv[200001];
bool b[200001];
bool vis[200001][7];
int cnt;
int t;
inline void dfs(int now,int op)
{
	//separate(now);
	//cout<<op<<endl;
	for(int i=d[now];i;i=nxt[i])
	{
		if((!op)||type[i]==op)
		{
			if(!vis[v[i]][type[i]])
			{
				vis[v[i]][type[i]]=1;
				if(!lv[v[i]])
				{
					if(!b[v[i]])
					{
						cnt++;
						b[v[i]]=1;
					}
					//separate(v[i]);
					if(type[i]!=1)
					{
						dfs(v[i],type[i]);
					}
				}
				else if(color[t]^color[v[i]]&&lv[v[i]]<=lv[t])
				{
					if(!b[v[i]])
					{
						cnt++;
						b[v[i]]=1;
					}
					//separate(v[i]);
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(color,0,sizeof(color));
		memset(lv,0,sizeof(lv));
		memset(d,0,sizeof(d));
		n=read();
		m=read();
		Q=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				int x=readchar();
				if(x==1)
				{
					add(point(i,j),point(i,j+1),1);
					add(point(i,j+1),point(i,j),1);
				}
				else if(x==2)
				{
					add(point(i,j),point(i,j+1),3);
					add(point(i,j+1),point(i,j),4);
				}
				else if(x==3)
				{
					add(point(i,j),point(i,j+1),2);
					add(point(i,j+1),point(i,j),2);
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int x=readchar();
				if(x==1)
				{
					add(point(i,j),point(i+1,j),1);
					add(point(i+1,j),point(i,j),1);
				}
				else if(x==2)
				{
					add(point(i,j),point(i+1,j),5);
					add(point(i+1,j),point(i,j),6);
				}
				else if(x==3)
				{
					add(point(i,j),point(i+1,j),2);
					add(point(i+1,j),point(i,j),2);
				}
			}
		}
		while(Q--)
		{
			memset(b,0,sizeof(b));
			memset(vis,0,sizeof(vis));
			int c=read();
			int v=read();
			int x=read(),y=read();
			t=point(x,y);
			color[t]=c;
			lv[t]=v;
			cnt=0;
			dfs(t,0);
			printf("%d\n",cnt);
		}
	}
	return 0;
}
