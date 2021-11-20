#include<bits/stdc++.h>
using namespace std;

const int Mod=998244353;

int n,k,m,p[35],a[35];
long long ans,v[105];
int can[5005];

void dfs(int i,int S,long long val){
	if(i>n){
		if(can[S]<=k) ans=(ans+val)%Mod;
		return ;
	} 
	for(int x=0;x<=m;x++){
		a[i]=x;
		dfs(i+1,S+p[x],val*v[x]%Mod);
	} 
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	p[0]=1;
	for(int i=1;i<=m;i++) p[i]=p[i-1]*2;
	for(int S=n;S<=n*p[m];S++){
		int x=S,cnt=0;
		while(x){
			cnt=cnt+(x%2);
			x/=2;
		}
		can[S]=cnt;
	}
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
