#include<bits/stdc++.h>
#define M 105
#define N 25
using namespace std;
long long n,m,k,ans,mod=998244353;
long long v[M],a[N],s[205],a2[31];
void dfs(long long x,long long a[],long long s){
	if(x==n+1){
		long long ans1=1;
		long long sum=0;
		for(long long i=1;i<=log2(s)+1;i++){
			if(s>>(i-1)&1==1)sum++;
			if(sum>k)return ;
		}
		for(long long i=1;i<=n;i++){
			ans1=ans1*v[a[i]]%mod;
		}
		ans=(ans1+ans)%mod;
		return ;
	}
	for(long long i=0;i<=m;i++){
		a[x]=i;
		dfs(x+1,a,s+pow(2,i));
		a[x]=0;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(long long i=0;i<=m;i++){
		scanf("%d",v+i);
	}
	a2[0]=1;
	for(long long i=1;i<=30;i++)a2[i]=a2[i-1]*2%mod;
	dfs(1,a,0);
	cout<<ans;
	return 0;
}
