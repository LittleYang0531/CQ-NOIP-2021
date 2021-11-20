#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q,T,h[200005],v[200005],cnt,now,an[200005];
int reads()
{
	int re=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){re=(re<<1)+(re<<3)+(ch-'0');ch=getchar();}
	return re;
}
int readed()
{
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	return ch-'0';
}
struct ll
{
	int nx;
	int to;
	int z;
}a[2000005];
struct chess
{
	int x;
	int y;
	int c;
	int l;
}c[200005];
void ad(int x,int y,int z)
{
	a[++cnt].nx=h[x];
	a[cnt].to=y;
	a[cnt].z=z;
	h[x]=cnt;
}
int zh(int x,int y){return (x-1)*m+y;}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,x,y,z;
	T=reads();
	while(T--)
	{
		cnt=0;
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(an,0,sizeof(an));
		n=reads();m=reads();q=reads();
		for(i=1;i<=n;++i)
		for(j=1;j<m;++j)
		{
			z=readed();
			ad(zh(i,j),zh(i,j+1),z);
			ad(zh(i,j+1),zh(i,j),z);
		}
		for(i=1;i<n;++i)
		for(j=1;j<=m;++j)
		{
			z=readed();
			ad(zh(i,j),zh(i+1,j),z);
			ad(zh(i+1,j),zh(i,j),z);
		}
		for(i=1;i<=q;++i)
		{
			scanf("%d%d%d%d",&c[i].c,&c[i].l,&c[i].x,&c[i].y);
			v[zh(c[i].x,c[i].y)]=i;
		}
		for(i=q;i>=1;i--)
		{
			now=0;
			for(j=h[zh(c[i].x,c[i].y)];j;j=a[j].nx)
			{
				if(!v[a[j].to])now++;
				else if(c[v[a[j].to]].c!=c[i].c&&c[i].l>=c[v[a[j].to]].l)now++;
			}
			v[zh(c[i].x,c[i].y)]=0;
			an[i]=now;
		}
		for(i=1;i<=q;++i)printf("%d\n",an[i]);
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2
*/
