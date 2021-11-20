#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,x,vst[20000005],a[20000005];
bool pd(int x) {
	int tx=x;
	while(tx!=0) {
		if(tx%10==7)return 1;
		tx/=10;
	}
	return 0;
}
void check() {
	for(int i=1; i<=1e7; i++) {
		if(vst[i]==1)continue;
		if(i%7==0)vst[i]=1;
		else if(pd(i))a[++a[0]]=i;
	}
	for(int i=1; i<=a[0]; i++) {
		int j=1;
		while(a[i]*j<1e7) {
			vst[a[i]*j]=1;
			j++;
		}
	}
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	check();
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&x);
		if(vst[x]==1)printf("-1\n");
		else {
			int i=x+1;
			while(vst[i]==1)i++;
			printf("%lld\n",i);
		}
	}
	return 0;
}
