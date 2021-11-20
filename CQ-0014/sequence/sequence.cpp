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
const int Mod=998244353;
#define Md(k) ((k)%Mod)
#define Ml(x,y) Md((LL)(x)*(y))
inline int Ad(int x,int y=0)
{
	return (x+=y)>=Mod?x-Mod:x;
}
inline void Add(int &x,int y)
{
	x=Ad(x,y);
}
inline void Mul(int &x,int y)
{
	x=Ml(x,y);
}
inline int Ksm(int x,int y)
{
	int s=1;
	for(;y;y>>=1)
	{
		if(y&1)Mul(s,x);
		Mul(x,x);
	}
	return s;
}
inline int Inv(int x)
{
	return Ksm(x,Mod-2);
}
const int Mx=100;
const int M=30;
int n,m,K,a[Mx+5],fac[Mx+5],inv[Mx+5];
inline int Com(int x,int y)
{
	return x<y?0:Ml(fac[x],Ml(inv[y],inv[x-y]));
}
int ans,tt[Mx+5],pre[Mx+5],C[Mx+5][Mx+5],F[M+5][M+5][M+5],G[M+5][M+5][M+5];
signed main()
{//40 642171527
	#ifndef ONLINE_JUDGE
//	freopen("_.in","r",stdin);
//	freopen("__.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
	int i,j,k,p,t,v,x;
	n=read();m=read();K=read();
	for(fac[0]=i=1;i<=Mx;i++)fac[i]=Ml(fac[i-1],i);
	for(inv[Mx]=Inv(fac[Mx]),i=Mx-1;~i;i--)inv[i]=Ml(inv[i+1],i+1);
	for(i=0;i<=Mx;i++)for(j=0;j<=Mx;j++)C[i][j]=Com(i,j);
	for(F[0][0][0]=1,i=0;i<=m;i++)
	{
		x=a[i]=read();
		for(j=0;j<=n;j++)pre[j]=Ksm(x,j);
		for(j=0;j<=K;j++)
//		for(k=0;k<=n;k++)
		{
			for(k=j;k<=n;k++)
//			for(j=0;j<=Min(k,K);j++)
			{
				for(t=0;t<=k;t++)
				{//F[i][j][k][t]
					for(p=0;p<=t;p++)
					{//F[i-1][j-?][k-p][(t-p)<<1|?]
//						v=Ksm(x,p);
//						cout<<"v:"<<x<<" "<<p<<":"<<v<<"|"<<(j?F[j-1][k-p]:0)<<" "<<F[j][k-p]<<"|"<<k
//						<<" "<<C(k,p)<<" | "<<Ml(F[j][k-p],Ml(v,C(k,p)))<<"\n";
						v=pre[p];
						Add(G[j][k][t],Ml(Ad(F[j][k-p][(t-p)<<1],!j?0:F[j-1][k-p][(t-p)<<1|1])
						,Ml(v,C[k][p])));
					}
//					cout<<"G:"<<i<<" "<<j<<" "<<k<<" "<<t<<":"<<G[j][k][t]<<"\n";
				}
			}
		}
		for(j=0;j<=K;j++)
//		for(k=0;k<=n;k++)
		{
			for(k=j;k<=n;k++)
//			for(j=0;j<=Min(k,K);j++)
			{
				for(t=0;t<=k;t++)
				{
					F[j][k][t]=G[j][k][t];
					G[j][k][t]=0;
				}
			}
		}
	}
	for(i=1;i<=Mx;i++)
	{
		tt[i]=tt[i>>1]+(i&1);
	}
	for(i=0;i<=K;i++)
	{
		for(t=0;t<=n;t++)
		{
			if(i+tt[t]<=K)Add(ans,F[i][n][t]);
		}
	}
	writenum(ans,10);
	return output;
}
/*
5 1 1
2 1
*/
/*
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
/*
30 100 30
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
/*
30 100 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
/*
30 100 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
