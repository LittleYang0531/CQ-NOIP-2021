#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 5005
#define rc() getchar()

using namespace std;

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=rc();
	return x*b;
}

char c[maxn];
int xx[4]={-1,1,0,0},yy[4]={0,0,-1,1};
int p[maxn][maxn],a[maxn][4],col[maxn],lev[maxn],bj[maxn],flag[maxn];
int stk[maxn][2];
int n,m,q,tot;

inline int pd(int x,int y,int nc,int nl)
{
	if(col[p[x][y]]!=nc&&lev[p[x][y]]<=nl) return 1;
	return 0;
}

inline void solve1(int x,int y,int cl,int lv)
{
	for(int i=0;i<4;++i)
	{
		if(a[p[x][y]][i]!=1) continue;
		int nx=x+xx[i],ny=y+yy[i];
		if(!(1<=nx&&nx<=m&&1<=ny&&ny<=n)) continue;
		if(pd(nx,ny,cl,lv)) bj[p[nx][ny]]=1;
	}
}

inline void solve2(int x,int y,int cl,int lv)
{
	for(int i=0;i<4;++i)
	{
		int lx=x,ly=y;
		while(1<=lx&&lx<=m&&1<=ly&&ly<=n)
		{
			if(a[p[lx][ly]][i]!=2) break;
			int nx=lx+xx[i],ny=ly+yy[i];
			if(pd(nx,ny,cl,lv)) bj[p[nx][ny]]=1;
			else break;
		}
	}
}

inline void solve3(int x,int y,int cl,int lv)
{
	int t=1,w=1;stk[1][0]=x;stk[1][1]=y;
	while(t<=w)
	{
		int lx=stk[t][0],ly=stk[t++][1];
		for(int i=0;i<4;++i)
		{
			if(a[p[lx][ly]][i]!=3) continue;
			int nx=lx+xx[i],ny=ly+yy[i];
			if(!(1<=nx&&nx<=m&&1<=ny&&ny<=n)) continue;
			if(pd(nx,ny,cl,lv)) bj[p[nx][ny]]=1;
			if(!lev[p[nx][ny]]&&flag[p[nx][ny]])
				stk[++w][0]=nx,stk[w][1]=ny,flag[p[lx][ly]]=1;
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int t=read();
	while(t--)
	{
		n=read(),m=read(),q=read(),tot=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				p[i][j]=++tot;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",c+1);
			for(int j=1;j<m;++j)
				a[p[i][j]][3]=a[p[i][j+1]][2]=c[j]-'0';
		}
		for(int i=1;i<n;++i)
		{
			scanf("%s",c);
			for(int j=1;j<=m;++j)
				a[p[i][j]][1]=a[p[i+1][j]][0]=c[j]-'0';
		}
		for(int i=1;i<=q;++i)
		{
			int cl=read(),lv=read(),x=read(),y=read();
			solve1(x,y,cl,lv);//solve2(x,y,cl,lv);solve3(x,y,cl,lv);
			int ans=0;for(int i=1;i<=tot;++i) if(bj[i]) ++ans;
			printf("%d\n",ans);
			memset(bj,0,sizeof(bj));
			memset(flag,0,sizeof(flag));
		}
		memset(a,0,sizeof(a));
	}
	return 0;
}

