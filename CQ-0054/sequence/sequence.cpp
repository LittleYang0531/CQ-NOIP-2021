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

const int mod=998244353;

int n,m,k,ans;
int a[37];
int v[107];
int cnt[107];

void dfs1(int p)
{
	if(p==n+1)
	{
		memset(cnt,0,sizeof cnt);
		For(i,1,n)
		{
			++cnt[a[i]];
		}
		int res=0;
		For(i,0,m+4)
		{
			cnt[i+1]+=cnt[i]>>1;
			cnt[i]&=1;
			res+=cnt[i];
			if(res>k)return;
		}
		res=1;
		For(i,1,n)
		{
			res=1ll*res*v[a[i]]%mod;
		}
		ans=(1ll*ans+res)%mod;
		return;
	}
	For(i,0,m)
	{
		a[p]=i;
		dfs1(p+1);
	}
}

//void dfs1(int p,int tot)
//{
//	if(p==m+1)
//	{
//		
//	a[p]=0,dfs1(p+1,tot);
//	if(tot<m)a[p]=1,dfs1(p+1,tot+1);
//}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	in(n),in(m),in(k);
	For(i,0,m)in(v[i]);
	dfs1(1);
	out(ans);
	return 0;
}
