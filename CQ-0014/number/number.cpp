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
const int Mx=1e7;
//const int Mx=2e7;
int tot,pw[10],tt[Mx+5],vst[Mx+5],num[Mx+5];
int TT,nxt[Mx+5];
signed main()
{
	#ifndef ONLINE_JUDGE
//	system("fc _.out number4.ans");
//	freopen("_.in","r",stdin);
//	freopen("number4.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	int i,j,k,v;
	for(pw[0]=i=1;i<=7;i++)pw[i]=pw[i-1]*10;
	for(vst[7]=1,i=1;i<=Mx;i++)
	{
		tt[i]=tt[i/10]+1;
		if(vst[i]&&tt[i]<=6)
		{
//			if(i<=100)cout<<i<<":"<<tt[i]<<" "<<i+pw[tt[i]]<<"\n";
//			if(i<=1000)cout<<i<<"\n";
			for(k=0;k<7;k++)if(tt[i]+k<=7&&i+pw[k]*pw[tt[i]]<=Mx)for(v=pw[k]*pw[tt[i]],j=1;j<10;j++)
			if(i+v*j<=Mx)vst[i+v*j]=1;
			if(i*10<=Mx)for(j=0;j<10;j++)if(i*10+j<=Mx)vst[i*10+j]=1;
		}
		if(vst[i])num[++tot]=i;
//		int f=0;
//		for(j=i;j;j/=10)if((f|=(j%10==7))&&!vst[i])return cout<<i<<" "<<vst[i]<<"\n",666;
//		if(!f&&vst[i])return cout<<i<<" "<<vst[i]<<"\n",666;
	}
//	cout<<"Chk:"<<vst[1000007]<<"\n";
//	int p;
//	for(i=1;i<=Mx;i++)
//	{
//		vst[i]=vst[i]==1?i:vst[i];
////		if(vst[i])
////		if(i<=150)cout<<i<<":"<<vst[i]<<"\n";
//		if(vst[i])
//		for(j=1;j<=tot;j++)
//		{
//			if((k=(p=num[j])*i)>Mx)break;
//			vst[k]=p;
//			if(vst[i]==p)break;
//		}
//		int f=0;
//		for(j=1;j<=tot;j++)
//		{
//			p=num[j];
//			if(p>i)break;
//			if((f|=!(i%p))&&!vst[i])return cout<<i<<" "<<vst[i],666;
//		}
//		if(!f&&vst[i])return cout<<i<<" "<<vst[i],666;
//	}
//	int ttt=0;
	for(i=1;i<=Mx;i++)
	{
		if(vst[i]==1)
		{
			for(j=i<<1;j<=Mx;j+=i)vst[j]=2
//			,ttt++;
			;
		}
//		if(i>1000000)
//		if(i>Mx-100)
//		{
//			int f=0;
//			for(j=1;j<=tot;j++)
//			{
//				p=num[j];
//				if(p>i)break;
//				if((f|=!(i%p))&&!vst[i])return cout<<i<<" "<<vst[i],666;
//			}
//			if(!f&&vst[i])return cout<<i<<" "<<vst[i],666;
//			if(!(i%10000))cout<<i<<" ";
//		}
//		if(!(i%10000))cout<<ttt<<" ";
		//1000007
//		int f=0;
//		for(j=1;j<=tot;j++)
//		{
//			p=num[j];
//			if(p>i)break;
//			if((f|=!(i%p))&&!vst[i])return cout<<i<<" "<<vst[i],666;
//		}
//		if(!f&&vst[i])return cout<<i<<" "<<vst[i],666;
//		if(!(i%1000))cout<<i<<" ";
	}
//	cout<<vst[(int)1e7+1]<<"\n";
	int lst;
	for(lst=Mx+1,i=Mx;i;i--)
	{
		nxt[i]=lst;
		lst=vst[i]?lst:i;
	}
	int x;
	for(TT=read();TT;TT--)
	{
		x=read();
		if(vst[x])writenum(-1,10);
		else writenum(nxt[x],10);
	}
	return output;
}
/*
4
6
33
69
300
*/
/*
5
90
99
106
114
169
*/
