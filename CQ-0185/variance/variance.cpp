#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
int n;
ll a[N],ans;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]&&a[i-1]+a[i+1]-a[i]>a[i]){
			a[i]=a[i-1]+a[i+1]-a[i];
		}
		if(a[i]>a[i+1]&&a[i-1]+a[i+1]-a[i]<a[i]){
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=a[i]*(a[i]-a[j]);
		}
	}
	printf("%lld",ans);
	//n*(a[i]-a[1~n]/n)^2
	//n*a[i]^2-2*a[i]*a[1~n]+a[1~n]^2/n
	//n*(a[1]^2~a[n]^2)-2*a[1~n]^2+a[1~n]^2
	//n*(a[1]^2~a[n]^2)-a[1~n]^2
	//n*a[i]^2-a[i]*sum
	//a[i]*(a[i]-a[j])
	return 0;
}
