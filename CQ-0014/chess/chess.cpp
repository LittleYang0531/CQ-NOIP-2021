#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cassert>
//#define NDEBUG
#include<complex>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
//#define LL __int128
#define LL long long
#define ULL unsigned LL
#define uint unsigned int
//#define int LL
//#define double long double
#define par pair<int,int>
#define mkp make_pair
#define psb push_back
#define epb emplace_back
#define f(x) ((x).first)
#define s(x) ((x).second)
using namespace std;
#define Lbt(x) ((x)&(-(x)))
#define Swap(x,y) (x^=y^=x^=y)
const int Mxxx=1e5;
inline char gc()
{
	static char buf[Mxxx],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxxx,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,char fl=false)
{
	static char buf[Mxxx],*p1=buf,*p2=buf+Mxxx;
	return (fl||((*p1++=ch)&&p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
//#define gc getchar
//#define pc(x,y) y?0:(putchar(x),0)
#define output pc('!',true)
inline int read()
{
	char ch=gc();
	int gflag=0,gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gflag?-gans:gans;
}
template<typename T>
inline char read(T&gans)
{
	char ch=gc();
	int gflag=0;gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gans=gflag?-gans:gans,ch;
}
template<typename T>
inline void write(T x)
{
	if(x>9)write(x/10);
	pc(x%10^48);
}
template<typename T>
inline void writenum(T x,char ch)
{
	if(x<0)pc('-'),x=-x;
	write(x);pc(ch);
}
inline void writechar(char x,char ch)
{
	pc(x);pc(ch);
}
template<typename T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
template<typename T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template<typename T>
inline T Abs(T x)
{
	return x<0?-x:x;
}
template<typename T>
inline void ckmx(T&x,T y)
{
	x=Max(x,y);
}
template<typename T>
inline void ckmn(T&x,T y)
{
	x=Min(x,y);
}
//const int Mx=1e5;
const int Mx=2e5;
int TT,n,m,Q,ans,cl[Mx+5],lv[Mx+5],psx[Mx+5],psy[Mx+5];
vector<int>v1[Mx+5],v2[Mx+5],vis[Mx+5];
vector<par>vst[Mx+5];
inline int gt()
{
	char ch;
	for(ch=gc();ch<'0'||'9'<ch;ch=gc());
	return ch^48;
}
int top,stk[Mx+5];
const int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
queue<pair<par,int> >q;
signed main()
{
	#ifndef ONLINE_JUDGE
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	#endif
	int i,j,f,t,x,y,xx,yy;
	for(TT=read();TT;TT--)
	{
		n=read();m=read();Q=read();
		for(i=1;i<=n;i++)
		{
			v1[i].resize(m+1);
			for(j=1;j<m;j++)
			{
				v1[i][j]=gt();
//				cout<<"v1:"<<v1[i][j]<<"\n";
			}
			vst[i].resize(m+1);
			for(j=1;j<=m;j++)vst[i][j]=mkp(-1,-1);
			vis[i].resize(m+1);
			for(j=1;j<=m;j++)vis[i][j]=0;
		}
		for(i=1;i<n;i++)
		{
			v2[i].resize(m+1);
			for(j=1;j<=m;j++)
			{
				v2[i][j]=gt();
//				cout<<"v2:"<<v1[i][j]<<"\n";
			}
		}
		for(i=1;i<=Q;i++)
		{
			cl[i]=read();
			lv[i]=read();
			psx[i]=read();psy[i]=read();
//			cout<<"ps:"<<i<<":"<<psx[i]<<" "<<psy[i]<<"\n";
			vst[psx[i]][psy[i]]=mkp(cl[i],lv[i]);
		}
		for(i=Q;i;i--)
		{
			x=psx[i];y=psy[i];ans=-1;
			q.push(mkp(mkp(x,y),-1));
			vis[x][y]=1;
			for(;!q.empty();)
			{
				x=f(f(q.front()));y=s(f(q.front()));f=s(q.front());q.pop();
				if((x^psx[i]||y^psy[i])&&~f(vst[x][y]))
				{
					if(s(vst[x][y])<=s(vst[psx[i]][psy[i]])&&f(vst[x][y])^f(vst[psx[i]][psy[i]]))ans++;
					continue;
				}
				ans++;
				for(j=0;j<4;j++)
				{
					xx=x+dx[j];yy=y+dy[j];
//					cout<<"Trs??:"<<x<<"->"<<xx<<"|"<<y<<"->"<<yy<<"\n";
					if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy])continue;
					if(j&1)t=v1[x][j<=1?y:y-1];
					else t=v2[j<=1?x:x-1][y];
					if(t==0)
					{
						continue;
					}
					else
					{
						if(t==1)
						{
							t=INT_MIN;
						}
						else
						{
							if(t==3)
							{
								t=0;
							}
							else
							{
								t=(j&1)+1;
							}
						}
					}
//					cout<<"Trs:"<<x<<" "<<y<<"->"<<xx<<" "<<yy<<":"<<f<<" "<<t<<"\n";
					if(f==-1)
					{
						vis[xx][yy]=1;
						q.push(mkp(mkp(xx,yy),t));
					}
					else
					{
						if(f==t)
						{
							if(t^INT_MIN)q.push(mkp(mkp(xx,yy),t)),vis[xx][yy]=1;
						}
					}
				}
			}
			q.push(mkp(mkp(psx[i],psy[i]),0));
			vis[psx[i]][psy[i]]=0;
			for(;!q.empty();)
			{
				x=f(f(q.front()));y=s(f(q.front()));q.pop();
				for(j=0;j<4;j++)
				{
					xx=x+dx[j];yy=y+dy[j];
					if(xx<1||yy<1||xx>n||yy>m||!vis[xx][yy])continue;
					vis[xx][yy]=0;q.push(mkp(mkp(xx,yy),0));
				}
			}
			stk[++top]=ans;
//			writenum(ans,10);
			vst[psx[i]][psy[i]]=mkp(-1,-1);
		}
		for(;top;writenum(stk[top],10),top--);
	}
	return output;
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
*/
/*
1
3 3 1
13
22
23
010
233
0 1 2 3
*/
