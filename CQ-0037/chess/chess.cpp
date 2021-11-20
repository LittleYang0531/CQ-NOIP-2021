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
	char fw[buf_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
		pw=0;
	}
	inline void write_char(char x)
	{
		fw[pw++]=x;
		if(pw==buf_size)
			flush();
	}
	inline void write_int(int x)
	{
		if(!x)
		{
			write_char('0');
			return;
		}
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		static char st[26];
		int tp=0;
		while(x)
		{
			st[++tp]=x%10^'0';
			x/=10;
		}
		while(tp>0)
			write_char(st[tp--]);
	}
}
int n,m,q;
vector<vector<int> > sh,sv;
const int max_q=1e5+5;
int col[max_q],lv[max_q],X[max_q],Y[max_q];
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
namespace Subtask1 // n*m<=5000, q<=2000
{
	vector<vector<bool> > vis,mark;
	vector<vector<int> > id;
	typedef pair<int,int> P;
	const int max_size=10000+5;
	P que[max_size],st[max_size<<1];
	int head,tail,tp;
	inline void solve()
	{
		vis.clear();
		mark.clear();
		id.clear();
		vis.resize(n);
		mark.resize(n);
		id.resize(n);
		for(int i=0;i<n;++i)
		{
			vis[i].resize(m);
			mark[i].resize(m);
			id[i].resize(m);
		}
		for(int i=1;i<=q;++i)
		{
//			fprintf(stderr,"i=%d\n",i);
			id[X[i]][Y[i]]=i;
			head=1,tail=0;
			que[++tail]=st[++tp]=P(X[i],Y[i]);
			vis[X[i]][Y[i]]=true;
			while(head<=tail)
			{
				int x=que[head].first,y=que[head++].second;
				for(int d=0;d<4;++d)
				{
					int a=x+dx[d],b=y+dy[d];
					if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b])
					{
						if(d==0)
						{
							if(sv[a][b]!=3)
								continue;
						}
						else if(d==1)
						{
							if(sv[x][y]!=3)
								continue;
						}
						else if(d==2)
						{
							if(sh[a][b]!=3)
								continue;
						}
						else if(d==3)
						{
							if(sh[x][y]!=3)
								continue;
						}
						vis[a][b]=true;
						st[++tp]=P(a,b);
						if(!id[a][b])
						{
							que[++tail]=P(a,b);
							mark[a][b]=true;
						}
						else
						{
							int k=id[a][b];
							if(col[k]!=col[i]&&lv[k]<=lv[i])
								mark[a][b]=true;
						}
					}
				}
			}
			int x=X[i],y=Y[i];
			for(int d=0;d<4;++d)
			{
				int a=x+dx[d],b=y+dy[d];
				if(a>=0&&a<n&&b>=0&&b<m)
				{
					if(d==0)
					{
						if(sv[a][b]!=1)
							continue;
					}
					else if(d==1)
					{
						if(sv[x][y]!=1)
							continue;
					}
					else if(d==2)
					{
						if(sh[a][b]!=1)
							continue;
					}
					else if(d==3)
					{
						if(sh[x][y]!=1)
							continue;
					}
					st[++tp]=P(a,b);
					if(!id[a][b])
						mark[a][b]=true;
					else
					{
						int k=id[a][b];
						if(col[k]!=col[i]&&lv[k]<=lv[i])
							mark[a][b]=true;
					}
				}
			}
			for(int k=Y[i]-1;k>=0;--k)
			{
				if(sh[X[i]][k]!=2)
					break;
				st[++tp]=P(X[i],k);
				int t=id[X[i]][k];
				if(t)
				{
					if(col[t]!=col[i]&&lv[t]<=lv[i])
						mark[X[i]][k]=true;
					break;
				}
				mark[X[i]][k]=true;
			}
			for(int k=Y[i]+1;k<m;++k)
			{
				if(sh[X[i]][k-1]!=2)
					break;
				st[++tp]=P(X[i],k);
				int t=id[X[i]][k];
				if(t)
				{
					if(col[t]!=col[i]&&lv[t]<=lv[i])
						mark[X[i]][k]=true;
					break;
				}
				mark[X[i]][k]=true;
			}
			for(int k=X[i]-1;k>=0;--k)
			{
				if(sv[k][Y[i]]!=2)
					break;
				st[++tp]=P(k,Y[i]);
				int t=id[k][Y[i]];
				if(t)
				{
					if(col[t]!=col[i]&&lv[t]<=lv[i])
						mark[k][Y[i]]=true;
					break;
				}
				mark[k][Y[i]]=true;
			}
			for(int k=X[i]+1;k<n;++k)
			{
				if(sv[k-1][Y[i]]!=2)
					break;
				st[++tp]=P(k,Y[i]);
				int t=id[k][Y[i]];
				if(t)
				{
					if(col[t]!=col[i]&&lv[t]<=lv[i])
						mark[k][Y[i]]=true;
					break;
				}
				mark[k][Y[i]]=true;
			}
			assert(!mark[X[i]][Y[i]]);
			int ans=0;
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
				{
					ans+=mark[i][j];
//					fprintf(stderr,"%d%c",(int)mark[i][j],j+1<m?' ':'\n');
				}
//			fprintf(stderr,"\n");
			while(tp>0)
			{
				vis[st[tp].first][st[tp].second]=false;
				mark[st[tp].first][st[tp].second]=false;
				--tp;
			}
			IO::write_int(ans);
			IO::write_char('\n');
		}
	}
}
inline void init(vector<vector<int> > &v)
{
	v.clear();
	v.resize(n);
	for(int i=0;i<n;++i)
		v[i].resize(m);
}
namespace Subtask2
{
	inline bool check()
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<m-1;++j)
			{
				if(sh[i][j]==3)
					return false;
			}
		for(int i=0;i<n-1;++i)
			for(int j=0;j<m;++j)
			{
				if(sv[i][j]==3)
					return false;
			}
		return true;
	}
	vector<vector<int> > L,R,U,D,id;
	const int max_n=1e5+5;
	set<int> row[max_n],column[max_n];
	inline void solve()
	{
		init(L),init(R),init(U),init(D),init(id);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				int k=j;
				while(k+1<m&&sh[i][k]==2)
					++k;
				for(int t=j;t<=k;++t)
					L[i][t]=j,R[i][t]=k;
				j=k;
			}
		for(int j=0;j<m;++j)
			for(int i=0;i<n;++i)
			{
				int k=i;
				while(k+1<n&&sv[k][j]==2)
					++k;
				for(int t=i;t<=k;++t)
					U[t][j]=i,D[t][j]=k;
				i=k;
			}
		for(int i=0;i<n;++i)
			row[i].clear();
		for(int j=0;j<m;++j)
			column[j].clear();
		for(int i=1;i<=q;++i)
		{
			int x=X[i],y=Y[i],ans=0;
			for(int d=0;d<4;++d)
			{
				int a=x+dx[d],b=y+dy[d];
				if(a>=0&&a<n&&b>=0&&b<m)
				{
					if(d==0)
					{
						if(sv[a][b]!=1)
							continue;
					}
					else if(d==1)
					{
						if(sv[x][y]!=1)
							continue;
					}
					else if(d==2)
					{
						if(sh[a][b]!=1)
							continue;
					}
					else if(d==3)
					{
						if(sh[x][y]!=1)
							continue;
					}
					if(!id[a][b])
						++ans;
					else
					{
						int k=id[a][b];
						if(col[k]!=col[i]&&lv[k]<=lv[i])
							++ans;
					}
				}
			}
			set<int>::iterator it=row[x].lower_bound(y);
			if(it!=row[x].begin())
			{
				--it;
				if(L[x][y]>*it)
					ans+=y-L[x][y];
				else
				{
					ans+=y-(*it);
					int k=id[x][*it];
					assert(k);
					if(col[k]==col[i]||lv[k]>lv[i])
						--ans;
				}
			}
			else
				ans+=y-L[x][y];
			it=row[x].lower_bound(y);
			if(it!=row[x].end())
			{
				if(R[x][y]<*it)
					ans+=R[x][y]-y;
				else
				{
					ans+=(*it)-y;
					int k=id[x][*it];
					assert(k);
					if(col[k]==col[i]||lv[k]>lv[i])
						--ans;
				}
			}
			else
				ans+=R[x][y]-y;
			it=column[y].lower_bound(x);
			if(it!=column[y].begin())
			{
				--it;
				if(U[x][y]>*it)
					ans+=x-U[x][y];
				else
				{
					ans+=x-(*it);
					int k=id[*it][y];
					assert(k);
					if(col[k]==col[i]||lv[k]>lv[i])
						--ans;
				}
			}
			else
				ans+=x-U[x][y];
			it=column[y].lower_bound(x);
			if(it!=column[y].end())
			{
				if(D[x][y]<*it)
					ans+=D[x][y]-x;
				else
				{
					ans+=(*it)-x;
					int k=id[*it][y];
					assert(k);
					if(col[k]==col[i]||lv[k]>lv[i])
						--ans;
				}
			}
			else
				ans+=D[x][y]-x;
			IO::write_int(ans);
			IO::write_char('\n');
			id[x][y]=i;
			row[x].insert(y);
			column[y].insert(x);
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=IO::read_int();
	while(T--)
	{
//		assert(false);
		n=IO::read_int(),m=IO::read_int(),q=IO::read_int();
		sh.resize(n);
		for(int i=0;i<n;++i)
		{
			sh[i].resize(m-1);
			char ch=IO::read_char();
			while(ch<'0'||ch>'3')
				ch=IO::read_char();
//			fprintf(stderr,"ch=%c\n",ch);
			sh[i][0]=ch^'0';
			for(int j=1;j<m-1;++j)
				sh[i][j]=IO::read_char()^'0';
		}
		sv.resize(n-1);
		for(int i=0;i<n-1;++i)
		{
			sv[i].resize(m);
			char ch=IO::read_char();
			while(ch<'0'||ch>'3')
				ch=IO::read_char();
			sv[i][0]=ch^'0';
//			fprintf(stderr,"ch=%c\n",ch);
			for(int j=1;j<m;++j)
				sv[i][j]=IO::read_char()^'0';
		}
		for(int i=1;i<=q;++i)
		{
			col[i]=IO::read_int(),lv[i]=IO::read_int();
			X[i]=IO::read_int()-1,Y[i]=IO::read_int()-1;
//			fprintf(stderr,"col=%d lv=%d x=%d y=%d\n",col[i],lv[i],X[i],Y[i]);
		}
		if(n*m<=5000&&q<=2000)
			Subtask1::solve();
		else if(Subtask2::check())
			Subtask2::solve();
	}
	IO::flush();
	return 0;
}

