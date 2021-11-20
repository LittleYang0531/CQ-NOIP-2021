#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int rd()
{
	int s=0;bool bj=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){bj|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return bj?-s:s;
}
void ptnum(int x)
{
	if(x>9)ptnum(x/10);
	putchar(x%10^48);
}
void pt(int x,char ch)
{
	if(x<0){putchar('-');x=-x;}
	ptnum(x);putchar(ch);
}
int n,m,Q;
vector<int>h[200005],l[200005],c[200005],bj[2][100005];
int ans[200005];
int vst[200005],lv[200005],col[200005];
char ch[200005];
struct node{int col,lv,x,y;}a[100005];
int C(int x,int y){return (x-1)*m+y;}
int pd(int no,int x,int y)
{
	if(!vst[C(x,y)])return 1;
	if((col[C(x,y)]^a[no].col)&&a[no].lv>=lv[C(x,y)])return 2;
	return 0;
}
int T;
void BFS(int x,int y,int aha)
{
	bj[1][x][y]=1;
	if(x-1>=1)
	{
		if(l[x-1][y]==3&&!bj[1][x-1][y])
		{
			if(pd(aha,x-1,y)==1)BFS(x-1,y,aha);
			else if(pd(aha,x-1,y)==2)bj[0][x-1][y]=1;
		}
	}
	if(x+1<=n)
	{
		if(l[x][y]==3&&!bj[1][x+1][y])
		{
			if(pd(aha,x+1,y)==1)BFS(x+1,y,aha);
			else if(pd(aha,x+1,y)==2)bj[0][x+1][y]=1;
		}
	}
	if(y-1>=1)
	{
		if(h[x][y-1]==3&&!bj[1][x][y-1])
		{
			if(pd(aha,x,y-1)==1)BFS(x,y-1,aha);
			else if(pd(aha,x,y-1)==2)bj[0][x][y-1]=1;
		}
	}
	if(y+1<=m)
	{
		if(h[x][y]==3&&!bj[1][x][y+1])
		{
			if(pd(aha,x,y+1)==1)BFS(x,y+1,aha);
			else if(pd(aha,x,y+1)==2)bj[0][x][y+1]=1;
		}
	}
}
void Clear()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)bj[0][i][j]=bj[1][i][j]=0;
	}
}
void Work1(int x,int y,int aha)
{
	for(int i=y;i>=2;--i)
	{
		if(h[x][i-1]==2&&pd(aha,x,i-1))
		{
			bj[0][x][i-1]=1;
			if(pd(aha,x,i-1)==2)break;
		}
		else break;
	}
	for(int i=y;i<m;++i)
	{
		if(h[x][i]==2&&pd(aha,x,i+1))
		{
			bj[0][x][i+1]=1;
			if(pd(aha,x,i+1)==2)break;
		}
		else break;
	}
	for(int i=x;i>=2;--i)
	{
		if(l[i-1][y]==2&&pd(aha,i-1,y))
		{
			bj[0][i-1][y]=1;
			if(pd(aha,i-1,y)==2)break;
		}
		else break;
	}
	for(int i=x;i<n;++i)
	{
		if(l[i][y]==2&&pd(aha,i+1,y))
		{
			bj[0][i+1][y]=1;
			if(pd(aha,i+1,y)==2)break;
		}
		else break;
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=m;++j)cout<<bj[0][i][j]<<" ";cout<<endl;
//	}
}
int Get_ans(int x,int y,int aha)
{
	int tot=0;
	if(x-1>=1){if(l[x-1][y]==1&&pd(aha,x-1,y))bj[0][x-1][y]=1;}
	if(x+1<=n){if(l[x][y]==1&&pd(aha,x+1,y))bj[0][x+1][y]=1;}
	if(y-1>=1){if(h[x][y-1]==1&&pd(aha,x,y-1))bj[0][x][y-1]=1;}
	if(y+1<=m){if(h[x][y]==1&&pd(aha,x,y+1))bj[0][x][y+1]=1;}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if((i^x)||(j^y))
	{
		tot+=bj[0][i][j]|bj[1][i][j];
//		if(bj[0][i][j]||bj[1][i][j])cout<<i<<" "<<j<<endl;
	}
	return tot;
}
void Solve()
{
	for(int i=1;i<=n;++i){bj[0][i].clear();bj[1][i].clear();}
	for(int i=1;i<=n;++i)
	{
		bj[0][i].push_back(0);bj[1][i].push_back(0);
		for(int j=1;j<=m;++j){bj[0][i].push_back(0);bj[1][i].push_back(0);}
	}
	for(int i=1;i<=Q;++i)
	{
		a[i].col=rd();a[i].lv=rd();a[i].x=rd();a[i].y=rd();
		Clear();
//		cout<<"QAQ\n";
		Work1(a[i].x,a[i].y,i);
		BFS(a[i].x,a[i].y,i);
		pt(Get_ans(a[i].x,a[i].y,i),'\n');
		vst[C(a[i].x,a[i].y)]=1;lv[C(a[i].x,a[i].y)]=a[i].lv;col[C(a[i].x,a[i].y)]=a[i].col;
	}
}
int QAQ(int x,int y,int aha)
{
	int qwq=0;
	if(x-1>=1){if(l[x-1][y]==1&&pd(aha,x-1,y))++qwq;}
	if(x+1<=n){if(l[x][y]==1&&pd(aha,x+1,y))++qwq;}
	if(y-1>=1){if(h[x][y-1]==1&&pd(aha,x,y-1))++qwq;}
	if(y+1<=m){if(h[x][y]==1&&pd(aha,x,y+1))++qwq;}
	return qwq;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=rd();
	while(T--)
	{
		for(int i=1;i<=n;++i)h[i].clear();
		for(int i=1;i<n;++i)l[i].clear();
		memset(vst,0,sizeof(vst));
		memset(lv,0,sizeof(lv));
		memset(col,0,sizeof(col));
		n=rd();m=rd();Q=rd();
		int flag=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",ch+1);h[i].push_back(0);
			for(int j=1;j<=m-1;++j)
			{
				flag=flag|(ch[j]=='3')|(ch[j]=='2');h[i].push_back(ch[j]-'0');
			}
		}
		for(int i=1;i<=n-1;++i)
		{
			scanf("%s",ch+1);l[i].push_back(0);
			for(int j=1;j<=m;++j){flag=flag|(ch[j]=='3')|(ch[j]=='2');l[i].push_back(ch[j]-'0');}
		}
		if(n*m<=50000)Solve();
		else 
		{
			for(int i=1;i<=Q;++i)
			{
				a[i].col=rd();a[i].lv=rd();a[i].x=rd();a[i].y=rd();
				pt(QAQ(a[i].x,a[i].y,i),'\n');
			}
		}
	}
	return 0;
}
/*
2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
*/
//Ending.
//AFO
