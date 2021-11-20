#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005],n,x,s,ans=0x3f3f3f3f;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];
	}
	sort(b+2,b+n+1);
	do{
		x=s=0;
		for(int i=1;i<=n;++i){
			c[i]=c[i-1]+b[i],x+=c[i];
		}
		for(int i=1;i<=n;++i){
			s+=n*n*c[i]*c[i]-n*2*c[i]*x+x*x;
		}
		ans=min(ans,s);
	}while(next_permutation(b+2,b+n+1));
	printf("%d",ans/n);
	return 0;
}
