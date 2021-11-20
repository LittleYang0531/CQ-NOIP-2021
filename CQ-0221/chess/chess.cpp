#include <bits/stdc++.h>

using namespace std;
/*
Bao Li dfs Wan Sui !!!
Ka Shi Wan Sui !!! 
*/

const int MAXN=1e6+50;

struct Edge
{
	int x,y,Next,Kind;
}e[MAXN<<1];
int elast[MAXN],tot;
void Add(int x,int y,int Kind)
{
	tot++;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].Kind=Kind;
	e[tot].Next=elast[x];
	elast[x]=tot;
	return;
}
int n,m,q;
int Getid(int x,int y)
{
	return (x-1)*m+y;
}
int Now,Nowid;
int vis[MAXN];
bool flag[MAXN];
int Color[MAXN],Level[MAXN];
int ans;

int Getop(int x,int y)
{
	if(y==x-1)
	return 1;
	if(y==x+1)
	return 2;
	if(y==x-m)
	return 3;
	if(y==x+m)
	return 4;
}

int CanUse[MAXN];
/*
void dfs(int u,int Kind,int op)
{
//	cout<<u<<" "<<Kind<<" "<<op<<endl; 
	if(vis[Kind][op][u]==Now)
	{
		return;	
	}
	else
	{
		if(flag[u]==true)
		{
			if(Kind!=0)
			{
				if(Color[u]!=Color[Nowid]&&Level[u]<=Level[Nowid])
				{
			//		cout<<u<<" "<<Kind<<" "<<Now<<" "<<Nowid<<endl;
					if(CanUse[u]!=Now)
					{
						CanUse[u]=Now;
						ans++;
					}
					vis[Kind][op][u]=Now;
					return;
				}
				else
				{
					vis[Kind][op][u]=Now;
					return;
				}
			}
		}
		else
		{
	//		cout<<u<<" "<<Kind<<" "<<Now<<" "<<Nowid<<endl;
			
			if(CanUse[u]!=Now)
			{
				CanUse[u]=Now;
				ans++;
			} 
			
			vis[Kind][op][u]=Now; 
			if(Kind==1)
			{
				return;
			}
		}
	}
	
	for(int i=elast[u];i;i=e[i].Next)
	{
		int v=e[i].y;
		if(v==Nowid)
		continue;
		if(Kind==2&&Getop(u,v)!=op)
		continue; 
		if(e[i].Kind==Kind||Kind==0)
		{
			if(Kind==0&&e[i].Kind==2)
			dfs(v,e[i].Kind,Getop(u,v));
			else
			dfs(v,e[i].Kind,0);
		}
	}
}
*/

void dfs2(int u,int op)
{
//	cout<<"u2:"<<u<<endl; 
	if(flag[u])
	{
		if(Color[Nowid]!=Color[u]&&Level[u]<=Level[Nowid])
		{
			if(CanUse[u]!=Now)
			{
				ans++;
				CanUse[u]=Now;
			}
		}
		return;
	}
	else
	{
		if(CanUse[u]!=Now)
		{
			ans++;
			CanUse[u]=Now;
		}
	}
	for(int i=elast[u];i;i=e[i].Next)
	{
		int v=e[i].y;
		if(Getop(u,v)!=op||e[i].Kind!=2)
		continue;
		dfs2(v,op);
	}
}
void dfs3(int u)
{
	vis[u]=Now;  
	if(flag[u])
	{
		if(Color[Nowid]!=Color[u]&&Level[u]<=Level[Nowid])
		{
			if(CanUse[u]!=Now)
			{
				ans++;
				CanUse[u]=Now;
			}
		}
		return;
	}
	else
	{
		if(CanUse[u]!=Now)
		{
			ans++;
			CanUse[u]=Now;
		}
	}
	for(int i=elast[u];i;i=e[i].Next)
	{
		int v=e[i].y;
		if(e[i].Kind!=3||vis[v]==Now||v==Nowid)
		continue;
		dfs3(v);
	}
}

char op[MAXN];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		memset(e,0,sizeof(e));
		memset(elast,0,sizeof(elast));
		memset(flag,0,sizeof(flag));
		memset(Color,0,sizeof(Color));
		memset(Level,0,sizeof(Level));
	//	memset(vis,0,sizeof(vis));
	//	Now=0;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&op[1]);
			for(int j=1;j<m;j++)
			{
				if(op[j]=='0')
				{
					continue;
				}
				Add(Getid(i,j),Getid(i,j+1),(int)op[j]-48);
				Add(Getid(i,j+1),Getid(i,j),(int)op[j]-48);
			}
		}
		for(int i=1;i<n;i++)
		{
			scanf("%s",&op[1]);
			for(int j=1;j<=m;j++)
			{
				if(op[j]=='0')
				continue;
				Add(Getid(i,j),Getid(i+1,j),(int)op[j]-48);
				Add(Getid(i+1,j),Getid(i,j),(int)op[j]-48);
			}
		}
		int Col,Lv,x,y;
		while(q--)
		{
			Now++;
			scanf("%d%d%d%d",&Col,&Lv,&x,&y);
			Nowid=Getid(x,y);
			Color[Nowid]=Col;
			Level[Nowid]=Lv;
			ans=0;
			
			for(int i=elast[Nowid];i;i=e[i].Next)
			{
				int v=e[i].y;
			//	cout<<"v:"<<v<<" "<<e[i].Kind<<endl;
				if(e[i].Kind==1)
				{
					if(flag[v]==false||(Color[v]!=Color[Nowid]&&Level[v]<=Level[Nowid]))
					{
						if(CanUse[v]!=Now)
						{
							ans++;
							CanUse[v]=Now;
						}
					}
				}
				if(e[i].Kind==2)
				{
					dfs2(v,Getop(Nowid,v));
				}
				if(e[i].Kind==3)
				{
					dfs3(v);
				}
			}
			
			flag[Nowid]=true;
			printf("%d\n",ans);
		}
	}
	return 0;
}
