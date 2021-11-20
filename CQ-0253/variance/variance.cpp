#include<bits/stdc++.h>
using namespace std;
const int maxn=10006;
int n,a[maxn],sum=0,sum2;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	printf("%d",sum2*n-sum*sum);
	return 0;
}
