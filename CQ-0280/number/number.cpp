#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
#define RP 0x7fffffffffffffff
using namespace std;
int T;
int x;
int maxx;
int a[200005];
int book[10000005];
int max(int x,int y) {
	return x>y?x:y;
}
int seven(int x) {
	while(x) {
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int shai() {
	maxx+=1000;
	for(int i=7;i<=maxx;++i) {
		if(book[i])continue;
		if(seven(i)) {
			for(int j=i;j<=maxx;j+=i) {
				book[j]=1;
			}
		}
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int I_Love_LXY=1;I_Love_LXY<=T;++I_Love_LXY) {
		scanf("%d",&a[I_Love_LXY]);
		maxx=max(maxx,a[I_Love_LXY]);
	}
	shai();
	for(int I_Love_LXY=1;I_Love_LXY<=T;++I_Love_LXY) {
		if(book[a[I_Love_LXY]]) puts("-1");
		else {
			for(int i=a[I_Love_LXY]+1;i<=maxx;++i) {
				if(!book[i]) {
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
//sto CRN、GYH、did、xinyue、jzp1025、HCQ、MZH orz
//I want to fuck CCF, but I love LXY, so I can't fuck CCF.
