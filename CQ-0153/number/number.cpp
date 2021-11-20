#include<bits/stdc++.h>
using namespace std;
bitset<10000005>ma,maa;
int n,a[1000005],cnt;
map<int,int>ans;
bool pd(int x){
	while(x){
		if(x%10==7){
			return 1;
		}
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,max1=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a[++cnt]);
		max1=max(a[cnt],max1);
	}
	if(max1*2+100>=9999998)max1=9999998;
	else max1*=2,max1+=100;
	for(int i=7;i<=max1;i++){
		if(ma[i]==0&&pd(i)){
			for(int j=i*2;j<=max1;j+=i){
				ma[j]=1;
			}
		}
		ma[i]=(ma[i]||pd(i));
	}
	int rp=10000001;
	for(int i=max1;i>=1;i--){
		if(ma[i]==0){
			ans[i]=rp;
			rp=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(ans[a[i]]==0)printf("-1\n");
		else printf("%d\n",ans[a[i]]);
	}
	return 0;
}
