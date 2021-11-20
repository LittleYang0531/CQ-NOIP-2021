#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t,x;
inline bool testnum1(int a){
	while(a>0){
		if(a%10==7){
			return 1;
		}
		a/=10;
	}
	return 0;
}
inline bool testnum2(int a){
	if(a%7==0||testnum1(a)) return 1;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			if(testnum1(i))
				return 1;
		}
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(testnum2(x)){
			printf("-1\n");
			continue;
		}
		while(x++){
			if(testnum2(x)==0){
				printf("%d\n",x);
				break;
			}
		}
	}
	
	return 0;
}
//AF NOIP
