#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	double sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum/=n;
	double ans1=0;
	for(int i=1;i<=n;i++){
		ans1+=pow(a[i]-sum,2);
	}
	ans1/=n;
	double ans2=0,ans3=0,ans4=0;
	int k=a[2];
	a[2]=a[1]+a[3]-a[2];
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum/=n;
	for(int i=1;i<=n;i++){
		ans2+=pow(a[i]-sum,2);
	}
	ans2/=n;
	a[2]=k;
	int k1=a[3];
	a[3]=a[2]+a[4]-a[3];
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum/=n;
	for(int i=1;i<=n;i++){
		ans3+=pow(a[i]-sum,2);
	}
	ans3/=n;
	a[2]=k,a[3]=k1;
	a[2]=a[1]+a[3]-a[2];
	a[3]=a[2]+a[4]-a[3];
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum/=n;
	for(int i=1;i<=n;i++){
		ans4+=pow(a[i]-sum,2);
	}
	ans4/=n;
	ans1*=n*n;
	ans2*=n*n;
	ans3*=n*n;
	ans4*=n*n;
	cout<<min(ans1,min(ans2,min(ans3,ans4)));
	return 0;
}
