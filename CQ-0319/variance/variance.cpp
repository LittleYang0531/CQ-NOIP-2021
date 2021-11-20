#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
double le=999999999;
int nums[10005];
inline int cz(int n){
	return nums[n-1]+nums[n+1]-nums[n];
}
inline void js(){
	double pj=0,kj=0;
	for(int i=1;i<=n;i++) pj+=nums[i];
	pj/=n;
	for(int i=1;i<=n;i++){
		kj+=(nums[i]-pj)*(nums[i]-pj);
	}
	kj/=n;
	if(kj<le) le=kj;
}
inline void ty(){
	int z=0;
	while(1){
		bool k=0;
		for(int i=2;i<=n-1;i++){
			if(i==z) continue;
			int a=cz(i);
			if(a!=nums[i]){
				nums[i]=a,z=i;
				js();
				break;
			}
		}
		if(!k) break;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&nums[i]);
	ty();
	le*=n*n;
	cout<<int(le)<<endl;
//	for(int i=1;i<=n;i++) cout<<nums[i]<<" ";
	
	return 0;
}
//AF NOIP
