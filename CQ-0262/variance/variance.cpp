#include<bits/stdc++.h>
#define N 10012
#define ll long long
using namespace std;
int n,a[N],c[N];
int vis[N],jl[N],cnt=1;
int zhi[N];
ll ans=1e18;

void dfs(int x){
	if(x==n){
		ll sz=0,as=0;
		zhi[1]=a[1];
		for(int i=2;i<=cnt;i++){
			zhi[i]=zhi[i-1]+jl[i];
		}
		for(int i=1;i<=cnt;i++){
			//cout<<zhi[i]<<" ";
			sz+=zhi[i]; as+=zhi[i]*zhi[i];
		}
		//cout<<sz<<" "<<as<<"\n";
		ans=min(ans,as*n-sz*sz);
		return ;
	}
	for(int i=1;i<n;i++){
		if(!vis[i]){
			vis[i]=1; jl[++cnt]=c[i];
			dfs(x+1);
			vis[i]=0; jl[cnt]=0; cnt--;
		}
	}
	return ;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		//cout<<c[i]<<" ";
	}
	dfs(1);
	printf("%lld",ans);
	
	return 0;
}
//ans=n*(ai^2)-S^2
/*4 
1 2 4 6*/
