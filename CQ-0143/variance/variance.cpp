#include<bits/stdc++.h>
using namespace std;
double a[10005];
int n;
double ans=0;
map<double,int>visa,visb;
void dfs(int k,int pos,double ave){
	for(int i=2;i<n;i++){
		if(i==pos)continue;
		if(a[i-1]+a[i+1]-a[i]!=a[i]){
			double x=a[i];
			ave+=(a[i-1]+a[i+1]-a[i]-a[i])/n;
			a[i]=a[i-1]+a[i+1]-a[i];
			double fangcha=0;
			for(int j=1;j<=n;j++){
				fangcha+=(a[j]-ave)*(a[j]-ave);
			}	
			if(visa[fangcha*n]||visb[ave]){
				a[i]=x;
				ave-=(a[i-1]+a[i+1]-a[i]-a[i])/n;
				continue;
			}
			visa[fangcha*n]=1;
			visb[ave]=1;
			ans=min(ans,fangcha*n);
			dfs(k+1,i,ave);
			a[i]=x;
			ave-=(a[i-1]+a[i+1]-a[i]-a[i])/n;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	double sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	double av=sum/n;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-av)*(a[i]-av);
	}
	ans*=n;
	visa[ans]=1;
	visb[av]=1;
	dfs(1,0,av);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
