#include<bits/stdc++.h>
#define I inline
#define R register int
#define ll long long
using namespace std;
const int bufsz=1<<21;
char buf[bufsz],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,bufsz,stdin),p1==p2)?EOF:*p1++)
//#define GC getchar()
I int read()
{
	int x=0;char c=GC;
	while(c<'0'||c>'9')c=GC;
	while(c>='0'&&c<='9')x=x*10+(c^48),c=GC;
	return x;
}
const int N=1e4+3;
int n;
set<vector<int>>S;
void dfs(const vector<int> &A)
{
	S.insert(A);
	vector<int>B(A);
	for(R i=1;i<A.size()-1;i++)
	{
		B[i]=B[i-1]+B[i+1]-B[i];
		if(S.count(B)==0)dfs(B);
		B[i]=B[i-1]+B[i+1]-B[i];
	}
}
int a[N];
void task1()
{
	vector<int>A(a+1,a+n+1),ret;
	dfs(A);
	ll mx=9e18;
//	int vmin=1e9;
	for(auto V:S)
	{
//		printf("############");
//		vmin=min(vmin,V[n-2]);
		ll s0=0,s1=0,d=0;
		for(auto u:V)
		{
//			printf("%d ",u);
			s0+=u;s1+=u*u;
		}
		s0=s0*s0;
		d=n*s1-s0;
//		printf("\nANS: %lld\n",n*s1-s0);
		if(mx>d)
		{
			mx=d;
			ret=V;
		}
	}
	printf("%lld\n",mx);
//	for(auto u:ret)printf("%d ",u);
}
ll work()
{
	ll s0=0,s1=0;
	for(R i=1;i<=n;i++)
		s0+=a[i],s1+=a[i]*a[i];
	s0=s0*s0;
//	for(R i=1;i<=n;i++)printf("%lld ",b[i]);puts("");
//	printf("Cost: %lld\n",n*s1-s0);
	return n*s1-s0;
}
void task3()
{
	
	ll mn=9e18;
	for(R u=1;u<n-u+1;u++)
	{
		bool o=1;
		while(o)
		{
			o=0;
			for(R i=u+1;i<n-u+1;i++)
			{
				int x=a[i-1]+a[i+1]-a[i];
				if(x<a[i])a[i]=x,o=1;
			}
		}
		mn=min(mn,work());
		o=1;
		while(o)
		{
			o=0;
			for(R i=n-u-1;i>u;i--)
			{
				int x=a[i-1]+a[i+1]-a[i];
				if(x>a[i])a[i]=x,o=1;
			}
		}
		mn=min(mn,work());
	}
	
	ll s0=0,s1=0;
	for(R i=1;i<=n;i++)
		s0+=a[i],s1+=a[i]*a[i];
	s0=s0*s0;
//	for(R i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
	printf("%lld\n",mn);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(R i=1;i<=n;i++)scanf("%d",a+i);
	if(n<=20)task1();
	else task3();
	return 0;
}
/*
4
1 2 4 6

10
6 19 34 35 39 63 82 82 83 99
*/
