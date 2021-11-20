#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10000001;
int T,tot,a[10000005],b[10000005];
bool v[10000005];
bool check(int x) {
	while(x) {
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=maxn;i++) {
		if(v[i])continue;
		if(i%7==0||check(i)) {
			for(int j=i;j<=maxn;j+=i)v[j]=1;
		}
	}
	for(int i=1;i<=maxn;i++) 
		if(!v[i])a[++tot]=i,b[i]=tot;
	while(T--) {
		int x;
		scanf("%d",&x);
		if(!b[x])puts("-1");
		else printf("%d\n",a[b[x]+1]);
	}
	return 0;
}
