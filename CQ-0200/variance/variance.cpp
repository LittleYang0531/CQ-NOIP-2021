#include<bits/stdc++.h>
using namespace std;
const int maxn=0x3f3f3f3f;
int n,a[10005];
int minn=maxn;
void var(){
	long long sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		sum2+=a[i]*a[i];
	}
	int varian;
	varian=n*sum2-sum1*sum1;
	minn=min(minn,varian);
}
void found(int x){
	a[x]=a[x-1]+a[x+1]-a[x];
	if(a[x-1]+a[x+1]==2*a[x])return;
	var();
	if(x-1>1)found(x-1);
	for(int i=x+1;i<n;i++)found(i);
	a[x]=a[x-1]+a[x+1]-a[x];
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	for(int i=2;i<n;i++)
		found(i);
	printf("%d",minn);
	return 0;
}
