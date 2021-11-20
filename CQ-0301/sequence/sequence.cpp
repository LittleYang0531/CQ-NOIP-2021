#include <bits/stdc++.h>
using namespace std;
int n,m,k,v[101],a[101],ans=0;
bool pd(int s){//0符合1不符 
	int num=0;
	while(s>0){if(s%2!=0)num++;s/=2;}
	if(num<=k)return 0;
	return 1;
}
void work(int s){
	memset(a,0,sizeof(a));
	while(1){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=pow(2,a[i]);
		if(sum==s){
			int now=1;
			for(int i=1;i<=n;i++)now*=v[a[i]];
			ans+=now%998244353; 
		}
		a[n]++;
		for(int i=n;i>=1;i--)if(a[i]==2){a[i]=0;a[i-1]++;}
		if(a[0]>0)break; 
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",&v[i]);
	for(int s=n;s<=n*pow(2,m);s++){
		if(pd(s))continue;//排除不合法的情况 
		work(s);
	}
	printf("%d",ans%998244353);
	return 0;
}
