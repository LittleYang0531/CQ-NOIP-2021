#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll pf(ll a){
	return a*a;
}
int n;
ll ans,sum,a[N];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		ans+=n*pf(a[i]);
		sum+=a[i];
	}ans-=pf(sum);
	bool best=true;
	for(;best;){
		best=false;
		for(int i=2;i<n;i++){
			ll p=a[i-1]+a[i+1]-a[i];
			ll op=ans+pf(p)*n-pf(sum-a[i]+p)-pf(a[i])*n+pf(sum);
			if(op<ans){
				ans=op;
				sum=sum-a[i]+p;
				a[i]=p;
				best=true;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
