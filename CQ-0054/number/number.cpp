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

const int N=1e7+10;

int pw[32];
int p1[N],p2[N];
int p[N];
int b[N];

void Link()
{
//	int cnt=0;
	pw[0]=1;
	For(i,1,8)pw[i]=pw[i-1]*10;
	for(int i=7;i<N;i+=10)
	{
		if(!p1[i])p[++p[0]]=i;
		p1[i]=1;
		For(j,2,7)
		{
			int now=i;
			int x=now/pw[j-1]%10;
			now+=7*pw[j-1]-x*pw[j-1]+x-7;
			if(now>=N)continue;
			if(!p1[now])p[++p[0]]=now;
			p1[now]=1;
//			++cnt;
		}
//		++cnt;
	}
	For(x,1,p[0])
	{
//		++cnt;
		int i=p[x];
		if(p2[i])continue;
		for(int j=1;i*j<N;++j)
		{
//			++cnt;
			p2[i*j]=1;
		}
	}
	for(int i=N-2;i;--i)
	{
//		++cnt;
		if(!p2[i])b[i]=i;
		else b[i]=b[i+1];
	}
//	cerr<<cnt;
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Link();
	int T;
	in(T);
	while(T--)
	{
		int x;in(x);
		if(p2[x])puts("-1");
		else out(b[x+1]),putchar('\n');
	}
	return 0;
}
