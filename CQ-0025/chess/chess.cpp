#include<bits/stdc++.h>
#define I inline
#define R register int
#define ll long long
#define P pair<bool,int>
#define cl first
#define lv second
using namespace std;
const int bufsz=1<<21;
char buf[bufsz],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,bufsz,stdin),p1==p2)?EOF:*p1++)
//#define GC getchar()
I int read()
{
	int x=0;char c=GC;
	while(c<'0'||c>'9')c=GC;
	while(c>='0'&&c<='9')x=x*10+(c^48),c=GC;
	return x;
}
const int N=2e5+3;
vector<vector<int>>a;
vector<vector<int>>b;
vector<vector<int>>vs;
vector<vector<bool>>d;
vector<vector<pair<bool,int>>>c;
int ans,n,m;
int sk[N][2],tp;
void work(int x,int y,int p)
{
	if(!vs[x][y])sk[++tp][0]=x;sk[tp][1]=y;
	vs[x][y]|=1<<p;
}
int get(int x,int y)
{
	int ans=0;
	if(d[x][y])++ans,d[x][y]=0;
	return ans;
}
void clear()
{
	while(tp)
	{
		vs[sk[tp][0]][sk[tp][1]]=0;
		d[sk[tp][0]][sk[tp][1]]=1;
		--tp;
	}
}
void dfs(int x,int y,bool cl,int lv,int w,int ww)
{
//	printf("! %d %d\n",x,y);
	if(vs[x][y]&1<<w)return;
	work(x,y,w);
	if(c[x][y].lv)
	{
		if(c[x][y].cl!=cl&&c[x][y].lv<=lv)ans+=get(x,y);
		return;
	}
	ans+=get(x,y);
	if(w==1&&!ww)
	{
		if(x<n&&b[x][y]==w)dfs(x+1,y,cl,lv,w,1);
		if(x>1&&b[x-1][y]==w)dfs(x-1,y,cl,lv,w,1);
		if(y<m&&a[x][y]==w)dfs(x,y+1,cl,lv,w,1);
		if(y>1&&a[x][y-1]==w)dfs(x,y-1,cl,lv,w,1);
	}
	else if(w==2)
	{
		if(ww)
		{
			if(x<n&&b[x][y]==w)dfs(x+1,y,cl,lv,w,ww);
			if(x>1&&b[x-1][y]==w)dfs(x-1,y,cl,lv,w,ww);
		}
		else
		{
			if(y<m&&a[x][y]==w)dfs(x,y+1,cl,lv,w,ww);
			if(y>1&&a[x][y-1]==w)dfs(x,y-1,cl,lv,w,ww);
		}
	}
	else
	{
		if(x<n&&b[x][y]==w)dfs(x+1,y,cl,lv,w,ww);
		if(x>1&&b[x-1][y]==w)dfs(x-1,y,cl,lv,w,ww);
		if(y<m&&a[x][y]==w)dfs(x,y+1,cl,lv,w,ww);
		if(y>1&&a[x][y-1]==w)dfs(x,y-1,cl,lv,w,ww);
	}
}
void solve()
{
	int q;
	scanf("%d%d%d",&n,&m,&q);
	a=vector<vector<int>>(n+1,vector<int>(m+1));
	b=vector<vector<int>>(n+1,vector<int>(m+1));
	c=vector<vector<pair<bool,int>>>(n+1,vector<pair<bool,int>>(m+1));
	for(R i=1;i<=n;i++)
	{
		getchar();
		for(R j=1;j<m;j++)
		{
			char c=getchar();
			a[i][j]=c-'0';
		}
	}
		
	for(R i=1;i<n;i++)
	{
		
		getchar();
		for(R j=1;j<=m;j++)
		{
			char c=getchar();
			b[i][j]=c-'0';
		}
	}
	while(q--)
	{
		int cl,lv,x,y;
		scanf("%d%d%d%d",&cl,&lv,&x,&y);
		ans=0;
		if(x<n&&!b[x][y])if(c[x+1][y].lv==0||c[x+1][y].lv<lv&&c[x+1][y].cl!=cl)ans++;
		if(x>1&&!b[x-1][y])if(c[x-1][y].lv==0||c[x-1][y].lv<lv&&c[x-1][y].cl!=cl)ans++;
		if(y<m&&!a[x][y])if(c[x][y+1].lv==0||c[x][y+1].lv<lv&&c[x][y+1].cl!=cl)ans++;
		if(y>1&&!a[x][y-1])if(c[x][y-1].lv==0||c[x][y-1].lv<lv&&c[x][y-1].cl!=cl)ans++;
		c[x][y]=P(cl,lv);
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
 	int t;scanf("%d",&t);
 	while(t--)solve();
	return 0;
}

