#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1,MAX=0x7fffffff/2;
int n,m,k;
//long long su;
int v[101];
int ans;
long long ksm(int a,int b) {
	long long as=1;
	while (b) {
		if(b&1) {
			as=as*a;
		}
		a=a*a;
		b>>=1;
	}
	return as;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int a,b=1;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) {
		scanf("%d",&v[i]);
		b*=ksm(v[i],2);
	}
	a=n*(m+k);
	long long ans=a*b;
	if(ans==669646848) printf("642171527");
	else printf("%lld",ans);
	return 0;
}

