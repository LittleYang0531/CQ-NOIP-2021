#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define ull unsigned long long
unordered_map<ull,int>vis;
int n,a[N],b[N],stp,id[N];ull ans=-1;
inline ull hsh(){
	ull sd=5621,res=0;
	for(int i=1;i<=n;i++) res+=sd*a[i],sd*=5621;
	return res;
}inline ull getans(){
	ull res=0,sum=0;
	for(int i=1;i<=n;i++) res+=1ll*a[i]*a[i],sum+=a[i];
	return res*n-sum*sum;
}void dfs(){
	if(n>14&&(++stp)>=3000000){
		printf("%llu",ans);
		exit(0);
	}ull h=hsh();
	if(vis[h]) return;vis[h]=1;
	ans=min(ans,getans());
	for(int i=2,tmp=0;i<n;i++){
		int x=id[i];
		if(a[x]==a[x+1]&&a[x]==a[x-1]) continue;
		tmp=a[x];a[x]=a[x+1]+a[x-1]-a[x];
		dfs();a[x]=tmp;
	}
}int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(11220840);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n-2;i++) id[i]=i+1;
	random_shuffle(id+1,id+n-1);
	dfs();printf("%llu",ans);
	return 0;
}
