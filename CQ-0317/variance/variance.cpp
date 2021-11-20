#include<bits/stdc++.h>
#define N 10005
using namespace std;
int a[N],n;
double fangcha(int a[]){
	int sum=0;
	double d1=0,f1=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	d1=sum*1.0/n;
	for(int i=1;i<=n;i++){
		f1+=1.0*(a[i]-d1)*(a[i]-d1);
	}
	f1*=n;
	return f1;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cout<<fangcha(a);
	return 0;
}

