#include<bits/stdc++.h>
using namespace std;
long long t,x;
bool judge7(long long a)
{
	if(a==7||a%7==0) return true;
	while(a!=0){
		long long b=a%10;
		if(b==7) return true;
		a/=10;
	}
	return false;
}
bool cut(long long a)
{
	for(long long i=1;i*i<=a;i++){
		if(a%i==0){
			if(judge7(i)||judge7(a/i)) return false;
		}
	}
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++){
		scanf("%lld",&x);
		if(!cut(x)){
			printf("-1\n");
			continue;
		}
		for(long long j=x+1;;j++){
			if(cut(j)){
				printf("%lld\n",j);
				break;
			}
		}
	}
	return 0;
}
