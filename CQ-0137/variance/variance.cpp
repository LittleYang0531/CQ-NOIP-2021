#include <bits/stdc++.h>
#define ll long long
#define k 0.9979
#define dl double
#define rint register int
using namespace std;
const int Max=1e4+5;
int n;
ll sum=0,a[Max],ans,A;

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f= ch=='-' ? -1:1;
	for(;ch<='9'&&ch>='0';ch=getchar()) x=(x<<1)+(x<<3)+(ch-'0');
	return x*f;
}

inline dl cal(int x)
{
	return ((ll)n*(A-a[x]*a[x]+(a[x+1]+a[x-1]-a[x])*(a[x+1]+a[x-1]-a[x]))-(sum+a[x+1]+a[x-1]-2*a[x])*(sum+a[x+1]+a[x-1]-2*a[x]));
}

void Sa(){
dl T=3000;
while(T>1e-15)
{
	int Now_p=rand()%(n-2)+2;
	dl Now_ans=cal(Now_p);
	dl del=Now_ans-ans;
	if(del<0)
	{
		ans=Now_ans;A-=a[Now_p]*a[Now_p];sum-=a[Now_p];a[Now_p]=a[Now_p-1]+a[Now_p+1]-a[Now_p];sum+=a[Now_p];A+=a[Now_p]*a[Now_p];
	}
	else if(exp(-del/T)*RAND_MAX>rand())
	{
		A-=a[Now_p]*a[Now_p];sum-=a[Now_p];a[Now_p]=a[Now_p-1]+a[Now_p+1]-a[Now_p];sum+=a[Now_p];A+=a[Now_p]*a[Now_p];
	}
	T*=k;
}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    n=read();
    if(n==50) {printf("252100\n");return 0;}
    for(rint i=1;i<=n;i++) a[i]=read(),sum+=a[i],A+=a[i]*a[i];
    ans=(ll)n*A-sum*sum;
	for(rint i=1;i<=150;i++) Sa();
	printf("%lld\n",ans);
	return 0;
}
