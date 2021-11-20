#include<bits/stdc++.h>
#define N 200005
using namespace std;
int T,n,m,q;
int id(int x,int y)
{
	return (x-1)*m+y;
}
int r[N][4],bl[N],xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int co[N],lv[N];
char s[N];
bool v[N];
int z[N],t,zz[N],tt;
bool vis[N];
void dfs(int x,int y,int op,int ii)
{
	zz[++tt]=id(x,y);
	vis[id(x,y)]=1;
	for(int i=0;i<4;i++)
	if(r[id(x,y)][i]==op&&x+xx[i]>0&&x+xx[i]<=n&&y+yy[i]>0&&y+yy[i]<=m)
	{
		int iii=id(x+xx[i],y+yy[i]);
		if(!vis[iii]&&(!bl[iii]||(co[ii]!=co[bl[iii]]&&lv[ii]>=lv[iii])))
		{
			if(!v[iii])
			{
				v[iii]=1;
				z[++t]=iii;
			}
			if(!bl[iii])
			dfs(x+xx[i],y+yy[i],op,ii);
		}
	}
}
int main()
{
freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
scanf("%d",&T);
while(T--)
{
memset(bl,0,sizeof(bl));
scanf("%d%d%d",&n,&m,&q);
for(int i=1;i<=n;i++)
{
	scanf("%s",s+1);
	for(int j=1;j<m;j++)
		r[id(i,j)][0]=s[j]-'0',r[id(i,j+1)][2]=s[j]-'0';
}
for(int i=1;i<n;i++)
{
	scanf("%s",s+1);
	for(int j=1;j<=m;j++)
	{
		if(s[j]=='2')s[j]='4';
		r[id(i,j)][1]=s[j]-'0',r[id(i+1,j)][3]=s[j]-'0';
	}
}
for(int i=1;i<=q;i++)
{
	int x,y,idd;
	scanf("%d%d%d%d",&co[i],&lv[i],&x,&y);
	idd=id(x,y);
	for(int j=0;j<4;j++)
	{
		int iii=id(x+xx[j],y+yy[j]);
		if(r[idd][j]==1&&(!bl[iii]||(co[i]!=co[bl[iii]]&&lv[i]>=lv[iii])))
		{
			v[iii]=1;
			z[++t]=iii;
		}
	}
	dfs(x,y,2,i);
	for(int i=1;i<=tt;i++)vis[zz[i]]=0;tt=0;
	dfs(x,y,3,i);
	for(int i=1;i<=tt;i++)vis[zz[i]]=0;tt=0;
	dfs(x,y,4,i);
	for(int i=1;i<=tt;i++)vis[zz[i]]=0;tt=0;
	printf("%d\n",t);
	for(int i=1;i<=t;i++)v[z[i]]=0;t=0;
	bl[idd]=i;
}

}

return 0;
}
