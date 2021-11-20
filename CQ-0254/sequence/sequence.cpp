#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[105],ans,l,r,um[100]={1,2,4,8,16,32,64,128,256,512,1024,2048,4196,8392};
bool a[10000005];
void dfs(long long x,long long y,long long z){
	if(x==n){
		if(a[y]==1){
			ans+=z;
			ans%=998244353;
		}
		return ;
	}
	if(y+(n-x)>r) return ;
	if(y+(n-x)*m<l) return ; 
	for(long long i=0;i<=m;i++){
		dfs(x+1,y+um[i],z*v[i]%998244353);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++) scanf("%lld",&v[i]);
	l=n,r=n*um[m];
	for(long long i=l;i<=r;i++){
		long long p=i,op=0;
		while(p>0){
			if(p%2==1) op++;
			p/=2;
		}
		if(op<=k) a[i]=1;
	}
	dfs(0,0,1);
	printf("%lld",ans%998244353);
	return 0;
}
