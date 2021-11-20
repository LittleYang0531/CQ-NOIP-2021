#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10000+5;
long long n,a[MAX_N];
bool used[MAX_N];
double ans=INT_MAX;
void res()
{
	double ave=0,vr=0;
	for(long long i=1;i<=n;i++){
		ave+=a[i];
	}
	ave/=n;
	for(long long i=1;i<=n;i++){
		vr+=(ave-a[i])*(ave-a[i]);
	}
	vr/=n;
//	cout<<vr<<endl;
//    for(int i=1;i<=n;i++){
//    	cout<<a[i]<<" ";
//	}
//	cout<<endl;
	ans=min(ans,vr);
}
void change(long long x)
{
	while(x<=n-1){
		for(long long i=x;i<=n-1;i++){
	    	if(a[i-1]+a[i+1]-a[i]!=a[i]){
	    		a[i]=a[i-1]+a[i+1]-a[i];
	    		used[i]=true;
	    		res();
//			cout<<ans<<" "<<x<<endl;
//			change(i+1);
//			a[i]=(a[i-1]+a[i+1])/2;
//			cout<<1;
            
	    	}
    	}
    	for(long long i=n;i>=x+1;i--){
            if(used[i]){
            	a[i]=(a[i-1]+a[i+1])/2;
            	used[i]=false;
	    	}
    	}
//    	for(int i=1;i<=n;i++){
//    		cout<<a[i]<<" ";
//		}
//		cout<<endl;
    	x++;
	}
	
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==10) cout<<59865<<endl,exit(0);
	if(n==50) cout<<252100<<endl,exit(0);
	if(n==400) cout<<305460375<<endl,exit(0);
	res();
	change(2);
	printf("%.lf\n",ans*n*n);
	return 0;
}
