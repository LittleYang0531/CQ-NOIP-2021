#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c;
	do
		c=getchar();
	while(c<'0'||'9'<c);
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
const int N=1e5+5;
char c[N];
int ne[4][2]={{0,1},{0,-1},{1,0},{-1,0}},n,m;
vector<int>v[N][4];
set<pair<int,int> >s,e[5];
map<pair<int,int>,int>g,p;
void dfs(int x,int y,int w,bool z,int d)
{
	if(e[w].find(pair<int,int>(x,y))!=e[w].end())
		return;
	if(g.find(pair<int,int>(x,y))!=g.end())
	{
		if(p[pair<int,int>(x,y)]!=z&&g[pair<int,int>(x,y)]<=d)
			s.insert(pair<int,int>(x,y));
		return;
	}
	s.insert(pair<int,int>(x,y));
	e[w].insert(pair<int,int>(x,y));
	int a,b,c=w,f=w+1;
	if(w==4)
		c=0,f=4;
	for(int i=c;i<f;i++)
	{
		a=x+ne[i][0];
		b=y+ne[i][1];
		if(a>=0&&b>=0&&a<n&&b<m&&
		((w<4&&v[x][i][y]==2)||(w==4&&v[x][i][y]==3)))
			dfs(a,b,w,z,d);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read(),q,o,l,x,y,a,b;
	while(t--)
	{
		p.clear(),g.clear();
		n=read(),m=read(),q=read();
		for(int i=0;i<n;i++)
			for(int k=0;k<4;k++)
			{
				v[i][k].clear();
				for(int j=0;j<m;j++)
					v[i][k].push_back(0);
			}
		for(int i=0;i<n;i++)
		{
			scanf("%s",c);
			for(int j=0;j+1<m;j++)
			{
				v[i][0][j]=c[j]-'0';
				v[i][1][j+1]=c[j]-'0';
			}
		}
		for(int i=0;i+1<n;i++)
		{
			scanf("%s",c);
			for(int j=0;j<m;j++)
			{
				v[i][2][j]=c[j]-'0';
				v[i+1][3][j]=c[j]-'0';
			}
		}
		for(int i=0;i<q;i++)
		{
			s.clear();
			for(int j=0;j<5;j++)
				e[j].clear();
			o=read(),l=read(),x=read(),y=read();
			x--,y--;
			for(int j=0;j<5;j++)
				e[j].insert(pair<int,int>(x,y));
			g[pair<int,int>(x,y)]=l;
			p[pair<int,int>(x,y)]=o;
			for(int j=0;j<4;j++)
			{
				a=x+ne[j][0],b=y+ne[j][1];
				if(a<0||b<0||a>=n||b>=m)
					continue;
				if(v[x][j][y]==1)
				{
					if((g.find(pair<int,int>(a,b))==g.end())||
					(g[pair<int,int>(a,b)]<=l&&
					o!=p[pair<int,int>(a,b)]))
						s.insert(pair<int,int>(a,b));
				}
				else if(v[x][j][y]==2)
					dfs(a,b,j,o,l);
				else if(v[x][j][y]==3)
					dfs(a,b,4,o,l);
			}
			printf("%d\n",(int)s.size());
		}
	}
}
