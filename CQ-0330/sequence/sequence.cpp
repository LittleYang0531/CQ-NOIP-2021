#include<bits/stdc++.h>
#define INF 998244353
using namespace std;
int n,m,k;
int sum;
int a[35];
int v[105];
int lowbit(int x){
	return x&(-x);
}
int low(int x){
	int ans=0;
	while(x>0){
		ans++;
		x-=lowbit(x);
	}
	return ans;
}
int rutn;
void dfs(int step,int tt){
	if(tt>sum)return ;
	if(step==n+1){
		int tot=1;
//		int tt=0;
//		for(int i=1;i<=n;i++){
//			tt+=(1<<a[i])%INF;
//		}
//		cout<<tt<<' ';
		if(tt==sum){
			for(int i=1;i<=n;i++){
				tot=tot*v[a[i]]%INF;
			}
			rutn+=tot%INF;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		a[step]=i;
		dfs(step+1,tt+(1<<i)%INF);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",v+i);
	for(int i=n;i<=n*(1<<m)%INF;i++){
		if(low(i)<=k){
			
			sum=i;cout<<sum<<'\n';
			dfs(1,0);
		}
	}
	printf("%d",rutn);
	return 0;
}
