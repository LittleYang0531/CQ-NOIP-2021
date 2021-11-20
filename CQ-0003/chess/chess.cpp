#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
const int N=2e5+5,NN=5005;
using namespace std;
vector<int>v1[N],v2[N];
int n,m,q;
inline char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *(S++);
}
#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
inline int readc()
{
	char h=getchar();
	while(h<'0'||h>'3')h=getchar();
	return h-'0';
}
inline int check(int c1,int l1,int c2,int l2)
{
//	cout<<"***\n";
	if(c1==c2)return 0;
	return l1>=l2;
}
namespace subtaskwu{
	struct infor{
		int c,l,w;
		bool operator<(const infor b)const
		{
			return w<b.w;
		}
	};
	set<infor>p1[N],p2[N];
	vector<int>to1[N],to2[N],to3[N],to4[N];
	inline void work()
	{
		for(int i=1;i<=n;i++)p1[i].clear(),to1[i].resize(m+1),to3[i].resize(m+1);
		for(int i=1;i<=m;i++)p2[i].clear();
		for(int i=1;i<=n;i++)to2[i].resize(m+2),to4[i].resize(m+2);
		for(int i=1;i<=n;i++)to1[i][m]=m;
		for(int i=1;i<=n;i++)
		for(int j=m-1;j;j--)to1[i][j]=(v1[i][j]==2?to1[i][j+1]:j);
//		cout<<"!!!!\n";
		for(int i=1;i<=n;i++)to3[i][1]=1;
		for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)to3[i][j]=(v1[i][j-1]==2?to3[i][j-1]:j);
//		cout<<"!!!!\n";
		for(int i=1;i<=m;i++)to2[n][i]=n;
		for(int j=1;j<=m;j++)
		for(int i=n-1;i;i--)to2[i][j]=(v2[i][j]==2?to2[i+1][j]:i);
//		cout<<"!!!!\n";
		for(int i=1;i<=m;i++)to4[1][i]=1;
		for(int j=1;j<=m;j++)
		for(int i=2;i<=n;i++)to4[i][j]=(v2[i-1][j]==2?to4[i-1][j]:i);
//		for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)cout<<i<<' '<<j<<"::"<<to1[i][j]<<" "<<to2[i][j]<<" "<<to3[i][j]<<" "<<to4[i][j]<<"!!!\n";
		for(int i=1;i<=q;i++)
		{
			int c=read(),l=read(),x=read(),y=read(),ans=0;
			if(y<m)
			{
				if(v1[x][y]==1)
				{
					if(p1[x].size()&&p1[x].find((infor){114,514,y+1})!=p1[x].end())
					{
						set<infor>::iterator it=p1[x].find((infor){114,514,y+1});
						ans+=check(c,l,it->c,it->l);
					}
					else ans++;
				}
				else if(v1[x][y]==2)
				{
					if(p1[x].size()&&p1[x].lower_bound((infor){114,514,y+1})!=p1[x].end())
					{
						set<infor>::iterator it=p1[x].lower_bound((infor){114,514,y+1});
						if((it->w)>to1[x][y])ans+=(to1[x][y]-y);
						else ans+=check(c,l,it->c,it->l)+((it->w)-y-1);
					}
					else ans+=(to1[x][y]-y);
				}
			}
			if(y>1)
			{
				if(v1[x][y-1]==1)
				{
					if(p1[x].size()&&p1[x].find((infor){114,514,y-1})!=p1[x].end())
					{
						set<infor>::iterator it=p1[x].find((infor){114,514,y-1});
						ans+=check(c,l,it->c,it->l);
					}
					else ans++;
				}
				else if(v1[x][y-1]==2)
				{
					if(p1[x].size()&&p1[x].lower_bound((infor){114,514,y})!=p1[x].begin())
					{
						set<infor>::iterator it=p1[x].upper_bound((infor){114,514,y-1});it--;
						if((it->w)<to3[x][y])ans+=(y-to3[x][y]);
						else ans+=check(c,l,it->c,it->l)+(y-(it->w)-1);
					}
					else ans+=(y-to3[x][y]);
				}
			}
			if(x<n)
			{
				if(v2[x][y]==1)
				{
					if(p2[y].size()&&p2[y].find((infor){114,514,x+1})!=p2[y].end())
					{
						set<infor>::iterator it=p2[y].find((infor){114,514,x+1});
						ans+=check(c,l,it->c,it->l);
					}
					else ans++;
				}
				else if(v2[x][y]==2)
				{
					if(p2[y].size()&&p2[y].lower_bound((infor){114,514,x+1})!=p2[y].end())
					{
						set<infor>::iterator it=p2[y].lower_bound((infor){114,514,x+1});
						if((it->w)>to2[x][y])ans+=(to2[x][y]-x);
						else ans+=check(c,l,it->c,it->l)+((it->w)-x-1);
					}
					else ans+=(to2[x][y]-x);
				}
			}
			if(x>1)
			{
				if(v2[x-1][y]==1)
				{
					if(p2[y].size()&&p2[y].find((infor){114,514,x-1})!=p2[y].end())
					{
						set<infor>::iterator it=p2[y].find((infor){114,514,x-1});
						ans+=check(c,l,it->c,it->l);
					}
					else ans++;
				}
				else if(v2[x-1][y]==2)
				{
					if(p2[y].size()&&p2[y].lower_bound((infor){114,514,x})!=p2[y].begin())
					{
						set<infor>::iterator it=p2[y].upper_bound((infor){114,514,x-1});it--;
						if((it->w)<to4[x][y])ans+=(x-to4[x][y]);
						else ans+=check(c,l,it->c,it->l)+(x-(it->w)-1);
					}
					else ans+=(x-to4[x][y]);
				}
			}
			p1[x].insert((infor){c,l,y});
			p2[y].insert((infor){c,l,x});
			cout<<ans<<"\n";
		}
	}
}
namespace subtaskbaoli{
	int c[NN][NN],l[NN][NN];
	int ans=0;
	bool v[NN][NN][4];
	void dfs(int x,int y,int C,int L,int ty,int f)
	{
		if(v[x][y][ty]||v[x][y][0])return;
//		cout<<x<<" "<<y<<" "<<ty<<" "<<v[x][y][ty]<<" "<<v[x][y][3]<<"!!!!\n";
		if((!v[x][y][0])&&(!v[x][y][1])&&(!v[x][y][2])&&(!v[x][y][3])&&ty!=0)
		{
			if(c[x][y]!=2)
			{
//				cout<<"&&&&&&&&&&\n";
				ans+=check(C,L,c[x][y],l[x][y]);
				v[x][y][ty]=1;
				return;
			}
			else ans++;
//			cout<<"***\n";
		}
		v[x][y][ty]=1;
		if(c[x][y]!=2)return;
		if(ty==1)return;
		if(y<m&&v1[x][y]!=0&&(ty!=2||f==0)&&(ty==0||v1[x][y]==ty))dfs(x,y+1,C,L,v1[x][y],0);
		if(y>1&&v1[x][y-1]!=0&&(ty!=2||f==1)&&(ty==0||v1[x][y-1]==ty))dfs(x,y-1,C,L,v1[x][y-1],1);
		if(x<n&&v2[x][y]!=0&&(ty!=2||f==2)&&(ty==0||v2[x][y]==ty))dfs(x+1,y,C,L,v2[x][y],2);
		if(x>1&&v2[x-1][y]!=0&&(ty!=2||f==3)&&(ty==0||v2[x-1][y]==ty))dfs(x-1,y,C,L,v2[x-1][y],3);
	}
	inline void work()
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)c[i][j]=2;
		while(q--)
		{
			int C=read(),L=read(),x=read(),y=read();ans=0;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)v[i][j][0]=v[i][j][1]=v[i][j][2]=v[i][j][3]=0;
			dfs(x,y,C,L,0,0);
			cout<<ans<<"\n";
			c[x][y]=C;l[x][y]=L;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
//	t=1;
	while(t--)
	{
		n=read(),m=read(),q=read();
		bool fl=1;
		for(int i=1;i<=n;i++)v1[i].resize(m+1);
		for(int i=1;i<n;i++)v2[i].resize(m+2);
		for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)v1[i][j]=readc(),fl&=(v1[i][j]!=3);
		for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)v2[i][j]=readc(),fl&=(v2[i][j]!=3);
		if(fl)subtaskwu::work();
		else 
		subtaskbaoli::work();
	}
	return 0;
//	while(1);-
}
/*
fc E:\noiprp++\chess.out E:\noiprp++\chess3.ans
*/
