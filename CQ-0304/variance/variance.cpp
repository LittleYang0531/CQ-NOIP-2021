#include<bits/stdc++.h>
using namespace std;
long long a[10055];
long long n,k;
long double ak,sum,kk,maxk=0x7fffffff,maxx=0x7fffffff,did=0;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	ak=sum/n;
	for(int j=1; j<=n; j++) {
		did+=(a[j]-ak)*(a[j]-ak);
	}
	did/=n;
	maxx=min(maxx,did*n*n);
	for(int kkkk=1; kkkk<=n; kkkk++) {
		for(int i=2; i<n; i++) {
			did=0;
			a[i]=a[i-1]+a[i+1]-a[i];
			sum=0;
			for(int i=1; i<=n; i++) {
				sum+=a[i];
			}
			ak=sum/n;
			for(int j=1; j<=n; j++) {
				did+=abs(a[j]-ak)*abs(a[j]-ak);
			}
			did/=n;
			maxx=min(maxx,did*n*n);
		}
	}
	cout<<maxx<<endl;
}
