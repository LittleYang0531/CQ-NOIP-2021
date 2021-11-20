#include <bits/stdc++.h>
using namespace std;
int XX[]={1,-1,0,0},YY[]={0,0,1,-1};
int _,n,m,q;
unordered_map<int,int>A[100005],B[100005];
map<int,pair<int,int>>Map[100005];
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1,*p2;
inline int read()
{
	char ch;int x(0);while((ch=gc)<48);
	do x=x*10+ch-48;while((ch=gc)>=48);
	return x;
}
inline int Read()
{
	char ch;int x(0);while((ch=gc)<48);
	x=ch-48;return x;
}
inline int BFS(int c,int v,int x,int y)
{
	int RET(0);
//	if(x-1>0&&B[x-1][y]!=0&&(!Map[x-1].count(y)||Map[x-1]))
	return 4;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	_=read();
	for(register int __=1;__<=_;++__)
	{
		n=read(),m=read(),q=read();
		for(register int i=1;i<=n;++i)
		{
			for(register int j=1;j<m;++j) A[i][j]=Read();
			Map[i].clear();
		}	
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=m;++j) B[i][j]=Read();
		for(register int i=1,c,v,x,y;i<=q;++i)
		{
			c=read(),v=read(),x=read(),y=read();
			printf("%d\n",BFS(c,v,x,y)),Map[x][y]=make_pair(c,v);
		}
	}
	return 0;
}
