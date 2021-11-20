#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans,sum;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(n==1){
		printf("0\n");
		return 0;
	}
	if(n==2){
		printf("%d\n",n*a[1]*a[1]+n*a[2]*a[2]-sum*sum);
		return 0;
	}
	for(long long i=1;i<=n;i++){
		int f=0;
		for(long long j=2;j<n;j++){
			if(a[j-1]+a[j+1]>2*a[j]){
				if(sum>n*a[j]+(n-1)*(a[j-1]+a[j+1]-2*a[j])/2.0){
					sum-=a[j];
					a[j]=a[j-1]+a[j+1]-a[j];
					sum+=a[j];
					f=1;
				}
			}else if(a[j-1]+a[j+1]<2*a[j]){
				if(sum<n*a[j]-(n-1)*(a[j-1]+a[j+1]-2*a[j])/2.0){
					sum-=a[j];
					a[j]=a[j-1]+a[j+1]-a[j];
					sum+=a[j];
					f=1;
				}
			}
		}
		if(f==0)break;
	}
	ans=-sum*sum;
	for(long long i=1;i<=n;i++){
		ans+=n*a[i]*a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
