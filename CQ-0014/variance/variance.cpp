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
const int Mx=1e5;
//map<vector<int>,bool>mp;
set<vector<int> >mp;
int n;
LL ans;
int ttt;
inline void DFS(vector<int>x,LL y,int z)
{
//	if(!((++ttt)%100000))cout<<ans<<" ";
	ckmn(ans,y);
	if(mp.find(x)!=mp.end())return;
//	mp[x]=1;
	mp.insert(x);
	for(int i=2;i<n;i++)
	{
		int v=x[i-1],w=x[i-2]+x[i]-v,dlt=w-v;
		if(dlt)x[i-1]=w,DFS(x,y+2ll*n*v*dlt+(LL)dlt*dlt*(n-1)-2ll*z*dlt,z+dlt),x[i-1]=v;
	}
}
int w[Mx+5];
vector<int>vec;
signed main()
{
	#ifndef ONLINE_JUDGE
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	#endif
	int i,s=0,ss=0;
	n=read();for(i=1;i<=n;i++)w[i]=read(),s+=w[i],ss+=w[i]*w[i],vec.epb(w[i]);
	ans=LLONG_MAX;DFS(vec,(LL)n*ss-(LL)s*s,s);
	writenum(ans,10);
	return output;
}
/*

*/
