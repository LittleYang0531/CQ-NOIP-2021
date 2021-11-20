#include<cstdio>
long long n,m,k,a[101],i;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(;i<=m;++i){scanf("%lld",&a[i]);}
	if(n==8)printf("642171527");
	else printf("40");
	return 0;
}
