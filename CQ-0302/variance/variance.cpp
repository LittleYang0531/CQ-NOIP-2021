#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1,MAX=0x7fffffff/2;
int n,z;
int sum;
int a[M],c[M],d[M];
double ans;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	double mid=sum*1.0/n;
	for(int i=1;i<=n-1;i++) {
		if(a[i]<=mid&&a[i+1]>mid) {
			z=i;
			break;
		}
	}
	bool bj=0;
	while (bj==0) {
		for(int i=2; i<=z; i++) {
			int now=a[i-1]+a[i+1]-a[i];
			double nm=(sum-a[i]+now)*1.0/n;
			if(nm>mid||now>a[i]) mid=nm,a[i]=now;
			else bj=1;
		}
		for(int i=z+1; i<=n-1; i++) {
			int now=a[i-1]+a[i+1]-a[i];
			double nm=(sum-a[i]+now)*1.0/n;
			if(nm<mid||now<a[i]) mid=nm,a[i]=now;
			else bj=1;
		}
	}
	for(int i=1;i<=n;i++) {
		ans+=(double(double(a[i])-mid))*(double(double(a[i])-mid))*1.0;
	}
	ans*=n;
	printf("%2.lf",ans);
	return 0;
}

