#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int n;
double standV;//方差 
double standN;//平均数
double ans;

double getAns(double sN){
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-sN)*(a[i]-sN);
	}
	return ans;
}

void dfs(int last,double sN){//上次变换是哪个
	//ans=min(ans,sN);
	for(int i=2;i<n;i++){
		if(i==last) continue;
		int t=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		
		int dealta=a[i]-t;
		double nN=sN+(double)dealta/n;
		bool flag=true;
		double c=getAns(nN);
		if(c>ans) flag=false;
		if(flag){
			ans=c;
			dfs(i,nN);
		}
		a[i]=t;
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		standN+=(double)a[i];
	}
	standN/=n;
	for(int i=1;i<=n;i++){
		standV+=(a[i]-standN)*(a[i]-standN);
	}
	ans=standV;
//	printf("%d\n",(int)standV);
	
	dfs(-1,standN);
	
	printf("%d\n",(int)(n*ans));
	return 0;
}

