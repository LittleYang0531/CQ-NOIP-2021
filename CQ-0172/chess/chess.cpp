#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
struct Edge{
	int self,next;
	int value;
}edge[1600005];
int n,m,q;
int to[200005],o;
void add_edge(int x,int y,int value)
{
	edge[++o].self=y;
	edge[o].next=to[x];
	edge[o].value=value;
	to[x]=o;
}
int get_index(const int &a,const int &b)
{
	return (a-1)*n+b;
}
pair<int,int>recover_index(const int &x)
{
	return make_pair(x/n+1,x%n);
}
int col,val;
bool vis[200005];
int st[200005],top;
int dir;
int pcol[200005],pval[200005];
void dfs(int x,int flag)
{
	if(flag==1)return ;
	if(vis[x])return ;
	vis[x]=true;
	st[++top]=x;
	pair<int,int>tpx=recover_index(x);
	for(int i=to[x];i;i=edge[i].next)
	{
		int y=edge[i].self;
		if(vis[y])continue;
		if(flag!=edge[i].value)continue;
		if(pcol[y]==0);
		else 
		{
			if(((pcol[x]^pcol[y])&&pval[y]<=pval[x])&&!vis[y])
			{
				vis[y]=true;
				st[++top]=y;
			}
			continue;
		}
		if(flag==2)
		{
			pair<int,int>tpy=recover_index(y);
			if(x==tpy.first)
			{
				if(y<tpy.second)dir=1;
				else dir=2;
			}
			else
			{
				if(x<tpy.first)dir=3;
				else dir=4;
			}
		}
		else if(flag==3)
		{
			
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	rd(T);
	while(T--)
	{
		memset(to,0,sizeof(to));
		o=0;
		rd(n),rd(m),rd(q);
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m-1;++j)
			{
				int x;
				rd(x);
				if(x!=0)
				{
					if(x!=1)flag=false;
					int a=get_index(i,j);
					int b=a+1;
					add_edge(a,b,x);
					add_edge(b,a,x);
				}
			}
		}
		for(int i=1;i<=n-1;++i)
		{
			for(int j=1;j<=m;++j)
			{
				int x;
				rd(x);
				if(x!=0)
				{
					if(x!=1)flag=false;
					int a=get_index(i,j);
					int b=a+n;
					add_edge(a,b,x);
					add_edge(b,a,x);
				}
			}
		}
		if(flag)
		{
			while(q--)
			{
				int x,y;
				rd(col),rd(val),rd(x),rd(y);
				int inx=get_index(x,y);
				pval[inx]=val;
				pcol[inx]=col;
				int ans=0;
				for(int i=to[inx];i;i=edge[i].next)
				{
					int iny=edge[i].self;
					if(pval[iny]==0||((pcol[iny]^pcol[inx])&&pval[iny]<=pval[inx]));
					else continue;
					++ans;
				}
				cout<<ans<<'\n';
			}
			
		}
//		while(m--)
//		{
//			int x,y;
//			rd(col),rd(val),rd(x),rd(y);
//			int inx=get_index(x,y);
//			pval[inx]=val;
//			pcol[inx]=col;
//			vis[inx]=true;
//			st[++top]=inx;
//			for(int i=to[inx];i;i=edge[i].self)
//			{
//				int iny=edge[i].self;
//				if(pval[iny]==0||((pcol[iny]^pcol[inx])&&pval[iny]<=pval[inx]));
//				else continue;
//				if(edge[i].value==1)
//				{
//					vis[iny]=true;
//					st[++top]=iny;
//				}
//				else if(edge[i].value==2)
//				{
//					pair<int,int>tpy=recover_index(iny);
//					if(x==tpy.first)
//					{
//						if(y<tpy.second)dir=1;
//						else dir=2;
//					}
//					else
//					{
//						if(x<tpy.first)dir=3;
//						else dir=4;
//					}
//					dfs(iny,2);
//				}
//				else if(edge[i].value==3)
//				{
//					dfs(iny,3);
//				}
//			}
//			cout<<top<<'\n';
//			while(top)vis[st[top]]=false;
//		}
	}
	return 0;
}