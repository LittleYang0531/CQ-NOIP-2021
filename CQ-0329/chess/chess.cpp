#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define inf 1e9
#define mem(a,b) memset(a,b,sizeof(a))
#define enter putchar('\n')
#define N 200005
using namespace std;
int n,m,q,ans;
int cnt,h[N],vst[N];
struct chess
{
	int color,level;
}put[N];
struct edge
{
	int to,next,type;
	char way;
}e[N*2];
int change(int x,int y)
{
	return (x-1)*n+y;
}
void add(int x,int y,int z,char w)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	e[cnt].type=z;
	e[cnt].way=w;
	h[x]=cnt;
}
void dfs(int x,int road,char go,int colo,int lev)
{
	if(vst[x]) return ;
	ans++;
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(vst[y]) continue;
		if(put[y].level!=0)
		{
			if(put[y].color!=colo&&put[y].level<=lev)
			{
				ans++;
			}
			continue;
		}
		if(e[i].type==3)
		{
			if(e[i].type==road||road==0)
				dfs(y,3,'c',colo,lev);
		}
		if(e[i].type==2)
		{
			if((e[i].type==road&&e[i].way==go)||road==0)
				dfs(y,2,e[i].way,colo,lev);
		}
		if(e[i].type==1)
		{
			if(road==0) ans++;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
		{
			char ch;
			cin>>ch;
			add(change(i,j),change(i,j+1),ch-'0','r');
			add(change(i,j+1),change(i,j),ch-'0','l');
		}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			add(change(i,j),change(i+1,j),ch-'0','d');
			add(change(i+1,j),change(i,j),ch-'0','u');
		}
	for(int i=1;i<=q;i++)
	{
		mem(vst,0);
		ans=0;
		int col,lv,x,y;
		cin>>col>>lv>>x>>y;
		dfs(change(x,y),0,'c',col,lv);
		put[change(x,y)].color=col;
		put[change(x,y)].level=lv;
		cout<<ans;
		enter;
	}
	return 0;
}

