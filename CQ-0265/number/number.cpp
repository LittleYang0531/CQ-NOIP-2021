#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
long long t,x;
bool check(long long n);
bool check7(long long n);
bool biaoji[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&x);
		if(check(x)==1){
			printf("-1\n");
			continue;
		}
		long long k=x+1;
		while(check(k)==1)k++;
		printf("%lld\n",k);
	}
	return 0;
}
bool check(long long n){
	if(check7(n)==1)return 1;
	for(long long i=2;i<=sqrt(n);i++){
		if(n%i==0&&(check7(i)==1||check7(n/i)==1))return 1;
	}
	return 0;
}
bool check7(long long n){
	if(n<maxn&&biaoji[n]==1)return 1;
	while(n>0){
		if(n%10==7){
			if(n<maxn)biaoji[n]=1;
			return 1;
		}
		n/=10;
	}
	return 0;
}
