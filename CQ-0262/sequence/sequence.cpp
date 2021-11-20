#include<bits/stdc++.h>
#define N 2000012
using namespace std;
int n,m,k,v[N],P=998244353;
int a[N],cnt,ans;
int sum[N];

void dfs(int x){
	if(x==n+1){
		int sz=0,jl=0,zhi=1;
		for(int i=1;i<=n;i++){
			sz+=sum[a[i]];
			zhi=1ll*zhi*v[a[i]]%P;
		}
		while(sz){
			if(sz&1) jl++;
			if(jl>k) return ;
			sz>>=1;
		}
		ans=(ans+zhi)%P;
		return ;
	}
	for(int i=0;i<=m;i++){
		a[++cnt]=i;
		dfs(x+1);
		a[cnt]=0; cnt--;
	}
	return ;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	sum[0]=1;
	for(int i=1;i<=100;i++){
		sum[i]=1ll*sum[i-1]*2%P;
	}
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	dfs(1);
	printf("%d",ans);
	
	return 0;
}
