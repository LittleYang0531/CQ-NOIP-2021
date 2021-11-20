#include <bits/stdc++.h>
using namespace std;
int n,a[10001],cnt=0;double mx=100,fc=0;
struct alal{int al[10001];}c[10001];//存储
bool st_pd(int x){//1相同0不同 
	for(int i=1;i<=n;i++)if(a[i]!=c[x].al[i])return 0;
	return 1;
}
bool pd(){//1有0无 
	for(int i=1;i<=cnt;i++)if(st_pd(i))return 1;
	return 0;
} 
double work(){
	cnt++;
	for(int i=1;i<=n;i++)c[cnt].al[i]=a[i];
	double sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	double jun=sum/n,fc=0;
	for(int i=1;i<=n;i++)fc+=pow(jun-a[i],2);
	return fc;
}
void dfs(){
	for(int i=2;i<=n-1;i++){//掐头去尾
		int jilu=a[i];a[i]=a[i-1]+a[i+1]-a[i];
		if(pd()){a[i]=jilu;continue;}//已计算 
		double now=work();mx=min(mx,now);
		dfs();a[i]=jilu;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);//输入 
	dfs();cout<<mx*n;
	return 0;
}
