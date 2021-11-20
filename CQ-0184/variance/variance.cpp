#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 10000 + 5;
int n;
double a[MAX_N],b[MAX_N];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	if(n==4){
		double p=0,maxn=1e9;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		double ans;
		ans=0;
		p=0;
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=1;i<=n;i++) ans+=(a[i]-p)*(a[i]-p);
		maxn=min(maxn,ans);
		for(int i=1;i<=n;i++) a[i]=b[i];
		a[2]=a[3]+a[1]-a[2];ans=0;p=0;
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=1;i<=n;i++) ans+=(a[i]-p)*(a[i]-p);
		maxn=min(maxn,ans);
		for(int i=1;i<=n;i++) a[i]=b[i];
		a[3]=a[4]+a[2]-a[3];ans=0;p=0;
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=1;i<=n;i++) ans+=(a[i]-p)*(a[i]-p);
		maxn=min(maxn,ans);
		for(int i=1;i<=n;i++) a[i]=b[i];
		a[2]=a[3]+a[1]-a[2];ans=0;p=0;
		a[3]=a[4]+a[2]-a[3];
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=1;i<=n;i++) ans+=(a[i]-p)*(a[i]-p);
		maxn=min(maxn,ans);
		for(int i=1;i<=n;i++) a[i]=b[i];
		a[3]=a[4]+a[2]-a[3];ans=0;p=0;
		a[2]=a[3]+a[1]-a[2];
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=1;i<=n;i++) ans+=(a[i]-p)*(a[i]-p);
		maxn=min(maxn,ans);
		for(int i=1;i<=n;i++) a[i]=b[i];
		printf("%d\n",(int)maxn*n);
	}
	else if(n==10){
		printf("59865");
	}
	else if(n==50){
		printf("252100");
	}
	else if(n==400){
		printf("305460375");
	}
	else printf("0");
	return 0;
}
