#include<bits/stdc++.h>
using namespace std;
int n,val[10005];
double a[10005],d[10005],minn=0x3f3f3f3f;
void dfs(int x){
	if(x>n) return ;
	double num=0,h=0;
	for(int i=1;i<=n;d[i]=a[i]+d[i-1],i++) num+=a[i];
	num=num*1.0/n;
	for(int i=1;i<=n;i++) h+=(a[i]-num)*(a[i]-num);
	h=h*n;
	minn=min(minn,h);
	for(int i=2;i<n;i++){
		double u=a[i],dg,l,z;
		a[i]=a[i+1]+a[i-1]-a[i];
		dg=a[i]-u;
		l=dg*1.0/n;
		val[i]++;
		z=2*l*(-d[i-1]-d[n]+d[i]+(n-1)*num)+l*l*(n-1)+a[i]*a[i]-2*a[i]*num-2*a[i]*l+2*num*l+l*l-u*u+2*u*num;
		if(z<0) dfs(x+1);
		a[i]=u;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	dfs(0);
	printf("%.0lf",minn);
	return 0;
}
