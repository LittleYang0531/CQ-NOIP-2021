#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long
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
int n,a[10005];
int minn=1e18;
void Work(int x){a[x]=a[x+1]+a[x-1]-a[x];}
int Get()
{
	int tmp=0,tot=0;
	for(int i=1;i<=n;++i)tmp+=a[i];
	for(int i=1;i<=n;++i)tot+=(n*a[i]-tmp)*(n*a[i]-tmp);
//	for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
	return tot;
}
void dfs(int dep,int aha)
{
	if(dep==aha-1)
	{
		minn=min(minn,Get());
		return;
	}
	Work(dep);
	dfs(dep-1,aha);
	Work(dep);
	dfs(dep-1,aha);
}
void DFS(int dep,int aha)
{
	if(dep==aha+1)
	{
		dfs(n-1,aha);
		return;
	}
	Work(dep);
	DFS(dep+1,aha);
	Work(dep);
	DFS(dep+1,aha);
}
void MAXMIN()
{
	for(int i=1;i<=5;++i)
	{
		for(int j=2;j<n;++j)
		if(a[j+1]+a[j-1]-a[j]<a[j])Work(j);
	}
	minn=min(minn,Get());
	for(int i=1;i<=5;++i)
	{
		for(int j=2;j<n;++j)
		if(a[j+1]+a[j-1]-a[j]>a[j])Work(j);
	}
	minn=min(minn,Get());
}
void TryOne()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=2;j<n;++j)
		if(abs(a[j+1]+a[j-1]-a[j]-a[i])<=abs(a[j]-a[i]))Work(j);
		minn=min(minn,Get());
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=n-1;j>=2;--j)
		if(abs(a[j+1]+a[j-1]-a[j]-a[i])<=abs(a[j]-a[i]))Work(j);
		minn=min(minn,Get());
	}
}
void QAQ(double x)
{
	for(int j=2;j<n;++j)
	if(abs(a[j+1]+a[j-1]-a[j]-x)<=abs(a[j]-x))Work(j);
	for(int j=n-1;j>=2;--j)
	if(abs(a[j+1]+a[j-1]-a[j]-x)<=abs(a[j]-x))Work(j);
}
void Try_Average()
{
	for(double i=1;i<=100;i+=0.1)
	{
		for(int k=1;k<=5;++k)QAQ(i);
//		for(int j=2;j<n;++j)
//		if(abs(a[j+1]+a[j-1]-a[j]-i)<=abs(a[j]-i))Work(j);
		minn=min(minn,Get());
	}
}
void Try_Average1n()
{
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	for(int k=1;k<=n;++k)
	{
		double aha=(a[i]+a[j]+a[k])/3.0;
		for(int qwq=1;qwq<=5;++qwq)QAQ(aha);
		minn=min(minn,Get());
	}
}
void Try_Ano()
{
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	{
		double aha=(a[i]+a[j])/2.0;
//		for(int qwq=1;qwq<=5;++qwq)
		QAQ(aha);
		minn=min(minn,Get());
	}
}
void Try_1()
{
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	for(int k=1;k<=n;++k)
	{
		double aha=(a[i]+a[j]+a[k])/3.0;
		QAQ(aha);
		minn=min(minn,Get());
	}
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	minn=Get();
//	if(n<=20)for(int i=2;i<n;++i)DFS(2,i);
//	TryOne();
//	Try_Average();
//	MAXMIN();
	if(n>=200){Try_Ano();pt(minn/n,'\n');return 0;}
	else if(n>=100){Try_1();pt(minn/n,'\n');return 0;}
	Try_Average1n();
	pt(minn/n,'\n');
	return 0;
}

