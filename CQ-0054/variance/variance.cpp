#include<bits/stdc++.h>
#define int long long
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

const int N=1e4+5;

int n,ans=1e18;
int sum,tot;
int a[N];

void sw(int x)
{
	int now=a[x];
	a[x]=a[x-1]+a[x+1]-a[x];
	tot=tot-now*now+a[x]*a[x];
	sum=sum-now+a[x];
}
double delta=0.9999;
void SA()
{
	double t=40000;
	while(t>1e-12)
	{
		int x=rand()%(n-2)+2;
		sw(x);
		int res=n*tot-sum*sum;
		int dt=res-ans;
		if(dt<0)ans=res;
		else if(exp(-dt/t)*RAND_MAX<rand())sw(x);
		t*=delta;
	}
}

signed main()
{
	srand(time(0));
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	in(n);
	For(i,1,n)
	{
		in(a[i]);
		sum+=a[i];
		tot+=a[i]*a[i];
	}
	while(1.0*clock()/CLOCKS_PER_SEC<0.9)SA();
	out(ans);
	return 0;
}
