#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
double n,p,ans,a[10001],sum;
int Ans=1e9;
void dfs(int st,int ma) {
	p=sum/n;
	ans=0;
	for(int i=1; i<=n; i++)
		ans+=(a[i]-p)*(a[i]-p);
	Ans=min(Ans,int(ans/n*n*n));
	if(st>ma) return ;
	for(int i=2; i<n; i++) {
		double k=a[i-1]+a[i+1]-a[i];
		if(k<=a[i+1]&&k>=a[i-1]) {
			int tmp=a[i];
			sum=sum-a[i]+k;
			a[i]=k;
			dfs(st+1,ma);
			sum=sum+tmp-k;
			a[i]=tmp;
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lf",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lf",a+i);
		sum+=a[i];
	}
	dfs(1,n*2);
	printf("%d",Ans);
	return 0;
}
