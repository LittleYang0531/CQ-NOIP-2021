#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar('0'+x%10);
}
int n,m,q;
int trans(int x,int y){return (x-1)*m+y;}
int row[200005],col[200005];
int ocl[200005],oco[200005];
bool occ[200005];
bool stp1[200005],stp2[200005],stp3[200005];
bool Outside(int x,int y){return !(x>=1 && y>=1 && x<=n && y<=m);}
int vec1[]={0,0,1,0,-1},
	vec2[]={0,1,0,-1,0};
int Abs(int x){return x>0?x:-x;}
int c,lv;
int getType(int x,int y,int dx,int dy)
{
	if(Abs(x-dx)+Abs(y-dy)>1)	return -1;
	if(Abs(x-dx)==1)
	{
		if(x>dx)	swap(x,dx);
		return col[trans(x,y)];
	}
	if(Abs(y-dy)==1)
	{
		if(y>dy)	swap(y,dy);
		return row[trans(x,y)];
	}
	return -1;
}
bool OK(int x,int y)
{
	if(!occ[trans(x,y)])	return true;
	if(oco[trans(x,y)]==c)	return false;
	if(ocl[trans(x,y)]>lv)	return false;
	return true;
}
void dfs1(int x,int y)
{
	stp1[trans(x,y)]=true;
	for(int i=1;i<=4;++i)
	{
		int dx=x+vec1[i],dy=y+vec2[i];
		if(!Outside(dx,dy) && getType(x,y,dx,dy)==1 && OK(dx,dy))	stp1[trans(dx,dy)]=true;
	}
}
void dfs2(int x,int y)
{
	stp2[trans(x,y)]=true;
	for(int i=y-1;i;--i)
	{
		if(getType(x,i,x,i+1)==2 && OK(x,i))	stp2[trans(x,i)]=true;
		else	break;
		if(occ[trans(x,i)])	break;
	}
	for(int i=y+1;i<=m;++i)
	{
		if(getType(x,i,x,i-1)==2 && OK(x,i))	stp2[trans(x,i)]=true;
		else	break;
		if(occ[trans(x,i)])	break;
	}
	for(int i=x-1;i;--i)
	{
		if(getType(i,y,i+1,y)==2 && OK(i,y))	stp2[trans(i,y)]=true;
		else	break;
		if(occ[trans(i,y)])	break;
	}
	for(int i=x+1;i<=n;++i)
	{
		if(getType(i,y,i-1,y)==2 && OK(i,y))	stp2[trans(i,y)]=true;
		else	break;
		if(occ[trans(i,y)])	break;
	}
}
void dfs3(int x,int y)
{
	if(stp3[trans(x,y)])	return ;
	stp3[trans(x,y)]=true;
	for(int i=1;i<=4;++i)
	{
		int dx=x+vec1[i],dy=y+vec2[i];
		if(!Outside(dx,dy) && getType(x,y,dx,dy)==3 && OK(dx,dy))
		{
			if(occ[trans(dx,dy)])	stp3[trans(dx,dy)]=true;
			else	dfs3(dx,dy);
		}
	}
}
void Solve()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n*m;++i)	occ[i]=false,ocl[i]=oco[i]=0;
	int up=0;
	for(int i=1;i<=n;++i)	for(int j=1;j<m;++j)	scanf("%1d",&row[trans(i,j)]),up=max(up,row[trans(i,j)]);
	for(int i=1;i<n;++i)	for(int j=1;j<=m;++j)	scanf("%1d",&col[trans(i,j)]),up=max(up,col[trans(i,j)]);
	if(up<=1)
	{
		while(q-->0)
		{
			int x,y;
			scanf("%d %d %d %d",&c,&lv,&x,&y);
			int ans=0;
			for(int i=1;i<=4;++i)
			{
				int dx=x+vec1[i],dy=y+vec2[i];
				if(!Outside(dx,dy) && getType(x,y,dx,dy)==1 && OK(dx,dy))	++ans;
			}
			printf("%d\n",ans);
			occ[trans(x,y)]=true;
			ocl[trans(x,y)]=lv;
			oco[trans(x,y)]=c;
		}
		return ;
	}
	while(q-->0)
	{
		int x,y;
		scanf("%d %d %d %d",&c,&lv,&x,&y);
		for(int i=1;i<=n*m;++i)	stp1[i]=stp2[i]=stp3[i]=false;
		dfs1(x,y);
		dfs2(x,y);
		dfs3(x,y);
		int ans=0;
		for(int i=1;i<=n*m;++i)	if(stp1[i] || stp2[i] || stp3[i])	++ans;
		printf("%d\n",ans-1);
		occ[trans(x,y)]=true;
		ocl[trans(x,y)]=lv;
		oco[trans(x,y)]=c;
	}
}
int main(){
	freopen("chess.in","r",stdin);
//	freopen("chess1.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}
/*
你妈的，，，我准备写点正常的注释。结果你给我出这么个jb题。
我再说一遍，数据范围带 n*m 的出题人都是傻逼，能不能死个妈。
我他妈真没想到 NOIP 也会玩这么一出。傻逼，打暴力。
哎，，，Good Riddance.
*/
