#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##END=b;i<=i##END;++i)
template<class T>
inline void in(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
template void in<int>(int&);
template<class T>
inline void out(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar(x%10^48);
}
template void out<int>(int);

using namespace std;

const int N=2e5+7;

int T,n,m,q,ans;

int mx[]={0,-1,0,1};
int my[]={-1,0,1,0};

int get(int x,int y)
{
	return (x-1)*m+y;
}

int a[2][N],b[N],c[N];

char s[N];

namespace task1
{
	const int N=5007;
	bitset<N>vis,used[2];
	bool fl=1;
	void dfs2(int x,int y,int lv,int col,int way)
	{
		if(b[get(x,y)])
		{
			if(c[get(x,y)]!=col&&lv>=b[get(x,y)]&&!vis[get(x,y)])++ans;
			vis[get(x,y)]=1;
			return;
		}
		if(!vis[get(x,y)])++ans;
		vis[get(x,y)]=1;
		for(int i=way;i<4;i+=2)
		{
			int dx=x+mx[i],dy=y+my[i];
			if(dx<1||dx>n||dy<1||dy>m)continue;
			int ep=0,ew=0;
			if(i<2)ep=get(dx,dy),ew=i;
			else ep=get(x,y),ew=i^2;
			if(used[ew][ep])continue;
			if(a[ew][ep]!=2)continue;
			used[ew][ep]=1;
			dfs2(dx,dy,lv,col,way);
		}
	}
	
	void dfs3(int x,int y,int lv,int col)
	{
		if(b[get(x,y)])
		{
			if(c[get(x,y)]!=col&&lv>=b[get(x,y)]&&!vis[get(x,y)])++ans;
			vis[get(x,y)]=1;
			return;
		}
		if(!vis[get(x,y)])++ans;
		vis[get(x,y)]=1;
		For(i,0,3)
		{
			int dx=x+mx[i],dy=y+my[i];
			if(dx<1||dx>n||dy<1||dy>m)continue;
			int ep=0,ew=0;
			if(i<2)ep=get(dx,dy),ew=i;
			else ep=get(x,y),ew=i^2;
			if(used[ew][ep])continue;
			if(a[ew][ep]!=3)continue;
			used[ew][ep]=1;
			dfs3(dx,dy,lv,col);
		}
	}
	
	void main()
	{
		For(t,1,q)
		{
			int col,lv,x,y;
			in(col),in(lv),in(x),in(y);
			ans=0;
			if(fl)
			{
				For(i,0,3)
				{
					int dx=x+mx[i],dy=y+my[i];
					if(dx<1||dx>n||dy<1||dy>m)continue;
					int ep=0,ew=0;
					if(i<2)ep=get(dx,dy),ew=i;
					else ep=get(x,y),ew=i^2;
					if(a[ew][ep]==0)continue;
					if(!b[get(dx,dy)])++ans;
					else if(c[get(dx,dy)]!=col&&lv>=b[get(dx,dy)])++ans;
				}
				b[get(x,y)]=lv,c[get(x,y)]=col;
				out(ans),putchar('\n');
				continue;
			}
			vis.reset();
			used[0].reset(),used[1].reset();
			vis[get(x,y)]=1;
			For(i,0,3)
			{
				int dx=x+mx[i],dy=y+my[i];
				if(dx<1||dx>n||dy<1||dy>m)continue;
				int ep=0,ew=0;
				if(i<2)ep=get(dx,dy),ew=i;
				else ep=get(x,y),ew=i^2;
				if(used[ew][ep])continue;
				used[ew][ep]=1;
				if(a[ew][ep]==0)continue;
				if(a[ew][ep]==1)
				{
					if(!b[get(dx,dy)])++ans;
					else if(c[get(dx,dy)]!=col&&lv>=b[get(dx,dy)]&&!vis[get(dx,dy)])++ans;
					vis[get(dx,dy)]=1;
				}
				else if(a[ew][ep]==2)
				{
					dfs2(dx,dy,lv,col,i&1);
				}
				else
				{
					dfs3(dx,dy,lv,col);
				}
			}
			b[get(x,y)]=lv,c[get(x,y)]=col;
			out(ans),putchar('\n');
		}
		memset(b,0,sizeof b);
		memset(c,-1,sizeof c);
	}
}

signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	in(T);
	while(T--)
	{
		in(n),in(m),in(q);
		For(i,1,n)
		{
			scanf("%s",s+1);
			For(j,1,m-1)
			{
				a[0][get(i,j)]=s[j]^48;
				if(s[j]>'1')task1::fl=0;
			}
		}
		For(i,1,n-1)
		{
			scanf("%s",s+1);
			For(j,1,m)
			{
				a[1][get(i,j)]=s[j]^48;
				if(s[j]>'1')task1::fl=0;
			}
		}
		task1::main();
	}
	return 0;
}
