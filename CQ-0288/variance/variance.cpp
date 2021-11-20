#include<bits/stdc++.h>
using namespace std;
long double tip,sum,ans=1e9;
long long n,a[10001],b[10001],c[10001];
void find(int k){
	if(k==tip){
		long double tmp=0,cmp=tip/n;
		for(int i=1;i<=n;i++)tmp=tmp+(a[i]-cmp)*(a[i]-cmp);
		ans=min(ans,tmp*n);return ;
	}
	int tmp,tmp_sum=0;
	if(k>=tip){
		for(int i=2;i<n;i++){
			if(b[i]<a[i]){
				tmp=a[i];a[i]=b[i];
				for(int i=1;i<=n;i++)tmp_sum+=a[i];
				for(int i=2;i<n;i++)c[i]=b[i];
				for(int i=2;i<n;i++)b[i]=a[i-1]+a[i+1]-a[i];
				find(tmp_sum);
				a[i]=tmp;for(int i=2;i<n;i++)b[i]=c[i];
			}
		}
	}
	
	if(k<=tip){
		for(int i=2;i<n;i++){
			if(b[i]>a[i]){
				tmp=a[i];a[i]=b[i];
				for(int i=1;i<=n;i++)tmp_sum+=a[i];
				for(int i=2;i<n;i++)c[i]=b[i];
				for(int i=2;i<n;i++)b[i]=a[i-1]+a[i+1]-a[i];
				find(tmp_sum);
				a[i]=tmp;for(int i=2;i<n;i++)b[i]=c[i];
			}
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	for(int i=2;i<n;i++)b[i]=a[i-1]+a[i+1]-a[i];
	tip=(long double)(a[1]+a[n])/2*n;
	find(sum);
	cout<<ans;
	return 0;
}/*
4 1 2 4 6
*/
