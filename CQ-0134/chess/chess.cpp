#include<bits/stdc++.h>
using namespace std;
int n,m,q,t,cnt1,h[400001],dian[200001][2],c[200001],l[200001],cnt2,ans;
bool vis[200001],ocu[200001],arrive[200001];
string s1,s2;
struct
{
	int next,to,c;
}e[400001];
void add(int u,int v,int c)
{
	e[++cnt1].to=v;
	e[cnt1].next=h[u];
	e[cnt1].c=c;
	h[u]=cnt1;
}
int dfs(int x,int y,int f,int now,int num)
{
	int k=(x-1)*n+y;
	for(int i=h[k];i;i=e[i].next)
	{
		if(!now||now==e[i].c)
		if(!vis[e[i].to]&&e[i].c!=0)
		{
			if(!ocu[e[i].to])
			{
				if(e[i].c==1)
				{
					if(!arrive[e[i].to])
					{
						ans++;
						arrive[e[i].to]=1;
					}
					continue;
				}
				if(e[i].c==2)
				{
					if(!f)
					{
						if(!arrive[e[i].to])
						{
							ans++;
							arrive[e[i].to]=1;
						}
							if(dian[e[i].to][0]-dian[k][0]!=0)
							f=1;
							else
							f=2;
							vis[e[i].to]=1;
							dfs(dian[e[i].to][0],dian[e[i].to][1],f,e[i].c,num);
							vis[e[i].to]=0;
							f=0;
					}
					else
					{
						if(f==1&&dian[e[i].to][0]-dian[k][0]!=0)
						{
							if(!arrive[e[i].to])
							{
								ans++;
								arrive[e[i].to]=1;
							}
								vis[e[i].to]=1;
								dfs(dian[e[i].to][0],dian[e[i].to][1],f,e[i].c,num);
								vis[e[i].to]=0;
						}
						else
						{
							if(f==2&&dian[e[i].to][1]-dian[k][1]!=0)
							{
								if(!arrive[e[i].to])
								{
									ans++;
									arrive[e[i].to]=1;
								}
									vis[e[i].to]=1;
									dfs(dian[e[i].to][0],dian[e[i].to][1],f,e[i].c,num);
									vis[e[i].to]=0;
							}
						}
					}
					continue;
				}
				if(e[i].c==3)
				{
					if(!arrive[e[i].to])
					{
						ans++;
						arrive[e[i].to]=1;
					}
						vis[e[i].to]=1;
						dfs(dian[e[i].to][0],dian[e[i].to][1],0,e[i].c,num);
						vis[e[i].to]=0;	
				}
			}
			else
			if(l[num]>=l[e[i].to]&&c[num]!=c[e[i].to])
			{
				if(e[i].c==1)
				{
					if(!arrive[e[i].to])
					{
						ans++;
						arrive[e[i].to]=1;
					}
				}
				if(e[i].c==2)
				{
					if(!f)
					{
						if(!arrive[e[i].to])
						{
							ans++;
							arrive[e[i].to]=1;
						}
					}
					else
					{
						if(f==1&&dian[e[i].to][0]-dian[k][0]!=0)
						{
							if(!arrive[e[i].to])
							{
								ans++;
								arrive[e[i].to]=1;
							}
						}
						else
						{
							if(f==2&&dian[e[i].to][1]-dian[k][1]!=0)
							{
								if(!arrive[e[i].to])
								{
									ans++;
									arrive[e[i].to]=1;
								}
							}
						}
					}
				}
				if(e[i].c==3)
				{
					if(!arrive[e[i].to])
					{
						ans++;
						arrive[e[i].to]=1;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cnt1=0,cnt2=0;
		memset(h,0,sizeof(h));
		memset(e,0,sizeof(e));
		memset(ocu,0,sizeof(ocu));
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dian[++cnt2][0]=i;
			dian[cnt2][1]=j;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>s1;
			for(int j=0;j<s1.length();j++)
			{
				add(n*(i-1)+j+1,n*(i-1)+j+2,s1[j]-'0');
				add(n*(i-1)+j+2,n*(i-1)+j+1,s1[j]-'0');
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			cin>>s2;
			for(int j=0;j<s2.length();j++)
			{
				add(n*(i-1)+j+1,n*i+j+1,s2[j]-'0');
				add(n*i+j+1,n*(i-1)+j+1,s2[j]-'0');
			}
		}
		for(int i=1;i<=q;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(arrive,0,sizeof(arrive));
			ans=0;
			int col,lv,xx,yy;
			scanf("%d%d%d%d",&col,&lv,&xx,&yy);
			int num=(xx-1)*n+yy;
			c[num]=col+1;
			l[num]=lv;
			ocu[num]=1;
			dfs(xx,yy,0,0,num);
			printf("%d\n",ans);
		}
	}
	return 0;
}
