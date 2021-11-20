#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000100;
int num[N],wei;
bool b[N]; 

inline bool check(int num){
	while(num){
		if(num%10==7)
			return true;
		num /= 10;
	}
	return false;
}

inline void init(){
	for(int k=1;k<N;k++){
		if(b[k]||(!check(k)))
			continue;
		b[k] = true;
		for(int j=2;k*j<N;j++)
			b[k*j] = true;
	}
	for(int k=1;k<N;k++)
		if(!b[k])
			num[++wei] = k;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		if(b[x]){
			puts("-1");
			continue;
		}
		int ans = *(lower_bound(num+1,num+1+wei,x)+1);
		printf("%d\n",ans);
	}
	return 0;
}
