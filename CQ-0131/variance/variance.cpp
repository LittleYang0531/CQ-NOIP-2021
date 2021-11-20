#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sss=0;
	char chh=getchar();
	while(chh<'0'||chh>'9') chh=getchar();
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss;
}
int n;
int a[10010];
int ans=1e9;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
		a[i]=read();
	if(n==1){
		puts("0");
		return 0;
	}
	else if(n==2){
		cout<<2*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]);
		return 0;
	}
	else if(n==3){
		int ans_1=3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
		ans=min(ans,ans_1);
		a[2]=a[1]+a[3]-a[2];
		ans_1=3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]);
		cout<<min(ans,ans_1);
		return 0;
	}
	else {
		int sum=0;
		for(register int i=1;i<=n;i++){
			sum+=a[(signed)i];
		}
		int ave=sum*1.0/n;
		int sum_ave=0;
		for(register int i=1;i<=n;i++){
			sum_ave+=((a[(signed)i]-ave)*(a[(signed)i]-ave));
		}
		cout<<sum_ave*n;
	}
	cout<<ans;
	return 0;
}
/*
I love zlj forever!!! 
*/
