#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
inline double read() {
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
double n,ans,sum,Pow,pj;
double a[10001];
double csh() {
	double fz=Pow-(sum*sum/n);
	return fz*n;
}
double variance(int x) {
	if(a[x]==a[x-1]+a[x+1]-a[x])return ans;
	int jl=a[x-1]+a[x+1];
	sum-=a[x];
	Pow-=a[x]*a[x];
	a[x]=a[x-1]+a[x+1]-a[x];
	double fz=Pow+a[x]*a[x]-((sum+a[x])*(sum+a[x])/n);
	a[x]=jl-a[x];
	sum+=a[x],Pow+=a[x]*a[x];
	return fz*n;
}
double Abs(double x) {
	if(x<0)return -x;
	return x;
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	if(n<=4) {
		for(int i=1; i<=n; i++)a[i]=read(),sum+=a[i],Pow+=a[i]*a[i];
		ans=csh();
		for(int i=2; i<n; i++)ans=min(ans,variance(i));
		printf("%.0lf\n",ans);
		return 0;
	}
	for(int i=1; i<=n; i++)a[i]=read(),pj+=a[i]/n;
	int cs=n/2+1;
	while(cs--)
		for(int i=2; i<n; i++)
			if(Abs(a[i]-pj)>Abs(a[i+1]+a[i-1]-a[i]-pj+(a[i]/n)-(a[i+1]+a[i-1]-a[i])/n))
				pj-=(a[i]/n),a[i]=a[i+1]+a[i-1]-a[i],pj+=(a[i]/n);
	for(int i=1; i<=n; i++)sum+=a[i],Pow+=a[i]*a[i];
	printf("%.0lf\n",csh());
}

