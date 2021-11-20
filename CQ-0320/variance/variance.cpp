#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[50005],b[50005];
double minx;
bool pd() {
	for(int i=2; i<n; i++)
		if(a[i]!=a[i-1]+b[i+1]-b[i]&&a[i]!=b[i])return 0;
	return 1;
}
double check() {
	double mid=0,sum=0;
	for(int i=1; i<=n; i++)mid+=a[i];
	mid/=n;
	for(int i=1; i<=n; i++)sum+=pow((a[i]-mid),2);
	sum/=n;
//	cout<<sum<<endl;
	return sum;
}
void dfs(int x) {
	if(x==n+1) {
//		if(pd())cout<<"Y"<<endl;
//		else cout<<"N"<<endl;
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);
//		printf("\n");
		double k=check();
		if(k<minx)minx=k;
		return;
	}
	int k=a[x];
	if(x>1&&x<n) {
		a[x]=a[x-1]+a[x+1]-a[x];
		dfs(x+1);
	}
	a[x]=k;
	dfs(x+1);
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	minx=1e8;
	dfs(1);
	printf("%.0lf\n",minx*n*n);
	return 0;
}
