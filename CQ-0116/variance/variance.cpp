#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll n,m;
ll t1,t2,t3,a[N],b[N],c[N],s,tot;
void dfs(int i,int l,int r){
	if(i==1){
		c[l]=b[i];
		t3=min(t3,t1*n-t2*t2);
		return;
	}
//	if((ls<<1ll)<=s){
	if(n<=22||l-1<=n-1-r){
		c[l]=b[i];a[l+1]=a[l]+c[l];
		t1+=a[l+1]*a[l+1],t2+=a[l+1];
		dfs(i-1,l+1,r);t1-=a[l+1]*a[l+1],t2-=a[l+1];
	}
//	if((rs<<1ll)<=s){
	if(n<=22||l-1>=n-1-r){
		c[r]=b[i];a[r]=a[r+1]-c[r];
		t1+=a[r]*a[r],t2+=a[r];
		dfs(i-1,l,r-1);t1-=a[r]*a[r],t2-=a[r];
	}
}
void work(){
	t3=1e18;t1=a[1]*a[1]+a[n]*a[n];t2=a[1]+a[n];
	dfs(n-1,1,n-1);printf("%lld\n",t3);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(i>1)b[i-1]=a[i]-a[i-1];
		s+=b[i-1];
	}sort(b+1,b+n);
	work();return 0;
}
