#include<bits/stdc++.h>
using namespace std;
int t;
bool bj[200005];
bool pd(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=7;i<=10005;i++){
		if(pd(i)){
			for(int j=1;i*j<=200005;j++){
				bj[i*j]=1;
			}
		}
	}
	for(int i=1;i<=t;i++){
		int x;
		scanf("%d",&x);
		if(bj[x]||x%7==0){
			printf("-1\n");
		}else{
			x++;
			while(bj[x]==1){
				x++;
			}printf("%d\n",x);
		}
	}
	return 0;
}

