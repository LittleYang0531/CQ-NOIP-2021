#include <iostream>
#include <cstdio>
using namespace std;
int n;
double a[50005],sum=0,ans;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for (int i=1; i<=n; i++) {
		ans+=(a[i]-sum)*(a[i]-sum);
	}
	ans/=4;
	ans*=n*n;
	double minn=ans;
	for (int i=2; i<n; i++) {
		sum=0,ans=0;
		a[i]=a[i-1]+a[i+1]-a[i];
		for (int j=1; j<=n; j++) sum+=a[j];
		sum/=n;
		for (int j=1; j<=n; j++) {
			ans+=(a[j]-sum)*(a[j]-sum);
		}
		ans/=4;
		ans*=n*n;
		minn=min(ans,minn);
	}
	cout<<minn;
	return 0;
}
