#include<bits/stdc++.h>
using namespace std;
const int maxn=1006,maxadd=6;
const long long mod=998244353;
int n,m,k;
long long v[maxn],a[maxn],num[maxn];
long long ans=0;
void di_vide(int x){
//	printf("boom %d\n",x);
	if(x==n+1){
		long long sum=0;
//		for(int i=0;i<=m+maxadd;i++)num[i]=0;
		for(int i=1;i<=n;i++){
			num[a[i]]++;
		}
		for(int i=1;i<=m+maxadd;i++){
			num[i]+=num[i-1]/2;
			num[i-1]%=2;
			if(num[i-1])sum++;
			num[i-1]=0;
		}
//		for(int i=0;i<=m+maxadd;i++){
//			if(num[i])sum++;
//		}
		if(sum<=k){
			sum=1;
			for(int i=1;i<=n;i++){
//				printf("%d ",num[a[i]]);
				sum=(sum*v[a[i]])%mod;
			}
			ans=(ans+sum)%mod;
		}
		return ;
	}
	for(int i=0;i<=m;i++){
		a[x]=i;
		di_vide(x+1); 
	}
	return ;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	di_vide(1);
	printf("%lld",ans);
	return 0;
}
