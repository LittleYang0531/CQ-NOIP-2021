#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const int mod=998244353;
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
int n,m,k;
int v[105];
int f[35][1<<18];
int pd(int x)
{
	int num=0;
	while(x)
	{
		if(x&1)++num;
		x>>=1;
	}
	return num<=k;
}
int ans=0;
int A(int x)
{
	int tmpp=1;
	for(int i=x;i>=1;--i)tmpp*=i;
	return tmpp;
}
int a[15];
void DFS(int dep,int no,int lst,int num)
{
	if(dep==n+1)
	{
		int aha=A(n),bj=1;
		if(!pd(no))return;
		for(int i=2;i<=n;++i)
		if(a[i]^a[i-1]){aha/=A(bj);bj=1;}
		else ++bj;
		aha/=A(bj);
//		for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;cout<<aha<<endl;
		ans=(ans+aha*num%mod)%mod;
		return;
	}
	for(int i=lst;i<=m;++i)
	{
		a[dep]=i;
		DFS(dep+1,no+(1ll<<i),i,num*v[i]%mod);
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=0;i<=m;++i)v[i]=rd();
	if(n==5)
	{
		DFS(1,0,0,1);
		pt(ans,'\n');
		return 0;
	}
	f[0][0]=1;
	int lim=n*(1<<m)+1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<lim;++j)
		if(f[i-1][j])
		{
			for(int K=0;K<=m;++K)if(j+(1<<K)<lim)
			f[i][j+(1<<K)]=(f[i][j+(1<<K)]+f[i-1][j]*v[K]%mod)%mod;
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=0;j<lim;++j)
//		{
//			cout<<f[i][j]<<" ";
//		}cout<<endl;
//	}
	int ans=0;
	for(int i=n;i<lim;++i)
	if(pd(i))
	{
//	cout<<i<<" "<<f[n][i]<<endl;
	ans=(ans+f[n][i])%mod;	
	}
	pt(ans,'\n');
	return 0;
}

