#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[5005][5005],b[5005][5005],c[5005][5005],d[5005][5005],dj,ys,x,y,ans,T;
pair<int,int>qp[5005][5005];
bool fl[5005][5005],fll[5005][5005];
char ch;
void hanshu1(int x,int y)
{
	if(a[x][y]==2 && fll[x][y]==0) ++ans,hanshu1(x,y+1);
	else if(a[x][y]==2 && qp[x][y].first!=ys && qp[x][y].second<=dj) ans++;
}
void hanshu4(int x,int y)
{
	if(b[x][y]==2 && fll[x][y]==0) ++ans,hanshu4(x+1,y);
	else if(b[x][y]==2 && qp[x][y].first!=ys && qp[x][y].second<=dj) ans++;
}
void hanshu2(int x,int y)
{
	if(c[x][y]==2 && fll[x][y]==0) ++ans,hanshu2(x,y-1);
	else if(c[x][y]==2 && qp[x][y].first!=ys && qp[x][y].second<=dj) ans++;
}
void hanshu5(int x,int y)
{
	if(d[x][y]==2 && fll[x][y]==0) ++ans,hanshu5(x-1,y);
	else if(d[x][y]==2 && qp[x][y].first!=ys && qp[x][y].second<=dj) ans++;
}
void hanshu3(int x,int y)
{
	if(!fl[x][y])
	{
		fl[x][y]=1;
		if(fll[x][y])
		{
			if(qp[x][y].first!=ys && qp[x][y].second<=dj) ans++;
		}
		else
		{
			if(a[x][y]==3) hanshu3(x+1,y);
			if(c[x][y]==3) hanshu3(x-1,y);
			if(d[x][y]==3) hanshu3(x,y-1);
			if(b[x][y]==3) hanshu3(x,y+1);
		}
		fl[x][y]=0;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		char ch;
		memset(fll,0,sizeof fll),memset(qp,0,sizeof qp),memset(a,0,sizeof a),memset(b,0,sizeof b),scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=n; ++i) for(int j=1; j<m; ++j) cin>>ch,a[i][j]=ch-'0',c[i][j+1]=ch-'0';
		for(int i=1; i<n; ++i) for(int j=1; j<=m; ++j) cin>>ch,b[i][j]=ch-'0',d[i+1][j]=ch-'0';
		while(q--)
		{
			scanf("%d%d%d%d",&ys,&dj,&x,&y),ans=0,qp[x][y]=make_pair(ys,dj),fll[x][y]=1;
			if(c[x][y]==1 && qp[x][y-1].first!=ys && qp[x][y-1].second<=dj) ++ans;
			if(a[x][y]==1 && qp[x][y+1].first!=ys && qp[x][y+1].second<=dj) ++ans;
			if(d[x][y]==1 && qp[x-1][y].first!=ys && qp[x-1][y].second<=dj) ++ans;
			if(b[x][y]==1 && qp[x+1][y].first!=ys && qp[x+1][y].second<=dj) ++ans;
			if(c[x][y]==2) hanshu1(x,y-1);
			if(a[x][y]==2) hanshu2(x,y+1);
			if(d[x][y]==2) hanshu4(x-1,y);
			if(b[x][y]==2) hanshu5(x+1,y);
			if(b[x][y]==3) fl[x][y]=1,hanshu3(x+1,y),ans++,fl[x][y]=0;
			if(d[x][y]==3) fl[x][y]=1,hanshu3(x-1,y),ans++,fl[x][y]=0;
			if(a[x][y]==3) fl[x][y]=1,hanshu3(x,y+1),ans++,fl[x][y]=0;
			if(c[x][y]==3) fl[x][y]=1,hanshu3(x,y-1),ans++,fl[x][y]=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}
