#include<bits/stdc++.h>
using namespace std;
int n=664579;
int t;
bool ss(int x){
	int len=sqrt(x);
	for(int i=2;i<=len;i++){
		if(x%i==0)return 0;
	}
	return 1;
}
bool pd(int x){
	int n1=x;
	while(n1!=0){
		if(n1%10==7)return 0;
		n1/=10;
	}
	for(int i=2;i<=x;i++){
		if(ss(i)){
			if(x%i==0){
//				cout<<i<<' ';
				int j=i;
				while(j!=0){
					if(j%10==7){
//						cout<<i<<' ';
						goto leap;
					}
					j/=10;
				}
				x/=i;
				if(pd(x))return 1;
				return 0;
			}
		} 
		leap:;
	}
//	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(pd(x)==0){
			printf("-1\n");
			continue;
		}
		for(int i=x+1;;i++){
			if(pd(i)==1){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
