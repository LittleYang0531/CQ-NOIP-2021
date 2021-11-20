#include<bits/stdc++.h>
using namespace std;
#define re register int
#define LL long long

#define gc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++
char buf[1<<20],*p1,*p2;
inline int rd()
{
	int x=0,f=1;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc())if(c=='-')f=0;
	for(; '0'<=c&&c<='9'; c=gc())x=(x<<1)+(x<<3)+c-'0';
	return f?x:-x;
}
inline int sp()
{
	int x;
	char c=gc();
	for(;c!='0'&&c!='1'&&c!='2'&&c!='3';c=gc());
	x=c-'0';
	return x;
}
#define py pair<int,int>
const int N=205;
py mk[N][N];
int jud[N][N], judge, ret, r1[N][N], r2[N][N];
void DFS(int nx, int ny, int x, int y, int fr)
{
	if(jud[nx][ny]==judge)return;
	jud[nx][ny]=judge;
	if(nx!=x || ny!=y)
	{
		if(mk[nx][ny].first==-1)ret++;
		else
		{
			if(mk[nx][ny].first!=mk[x][y].first && mk[nx][ny].second<=mk[x][y].second)ret++;
			return;
		}	
	}
	
	if(fr==3)
	{
		if(r1[nx][ny]==3)DFS(nx, ny+1, x, y, 3);
		if(r1[nx][ny-1]==3)DFS(nx, ny-1, x, y, 3);
		if(r2[nx][ny]==3)DFS(nx+1, ny, x, y, 3);
		if(r2[nx-1][ny]==3)DFS(nx-1, ny, x, y, 3);
		return;
	}
	if(fr==-1)
	{
		if(r1[nx][ny])DFS(nx, ny+1, x, y, r1[nx][ny]);
		if(r1[nx][ny-1])DFS(nx, ny-1, x, y, r1[nx][ny-1]);
		if(r2[nx][ny])DFS(nx+1, ny, x, y, r2[nx][ny]);
		if(r2[nx-1][ny])DFS(nx-1, ny, x, y, r2[nx-1][ny]);
		return;
	}
	if(fr==1) return;
	if(fr==2)
	{
		if(nx==x)
		{
			
			if(r1[nx][ny]==2)DFS(nx, ny+1, x, y, 2);
			if(r1[nx][ny-1]==2)DFS(nx, ny-1, x, y, 2);
			return;
		}
		else
		{
			if(r2[nx][ny]==2)DFS(nx+1, ny, x, y, 2);
			if(r2[nx-1][ny]==2)DFS(nx-1, ny, x, y, 2);
		}
	}
}
inline void work()
{
	int n=rd(),m=rd(),q=rd();
	memset(r1, 0, sizeof r1);
	memset(r2, 0, sizeof r2);
	memset(jud, 0, sizeof jud);
	for(re i=1;i<=n;++i)
	{
		for(re j=1;j<m;++j)
		{
			int x=sp();
			r1[i][j]=x;
		}
	}
	for(re i=1;i<n;++i)
	{
		for(re j=1;j<=m;++j)
		{
			int x=sp();
			r2[i][j]=x;
		}
	}
	judge=0;
	for(re i=1;i<=n;++i)
	{
		for(re j=1;j<=m;++j)
		{
			mk[i][j].first=-1;
			mk[i][j].second=0;
			jud[i][j]=0;	
		}
	}
	while(q--)
	{
		judge++;
		ret=0;
		int co=rd(), lv=rd(), x=rd(), y=rd();
		mk[x][y]=py(co, lv);
		DFS(x, y, x, y, -1);
		printf("%d\n", ret);
	}
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=rd();
	while(T--)work();
	return 0;
}
