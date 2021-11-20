#include<bits/stdc++.h>
using namespace std;
int n,Pai[10003];
bool vis[10003];
long long minn=1e18,a[10003],b[10003];
void dfs(int x){
	if(x==1){
		Pai[x]=1;
		dfs(x+1);
	}else if(x==n+1){
		for(int i=1;i<=n;i++)a[i]=a[i-1]+b[Pai[i]];
		long long ans=0,ans1=0,N=n;
		for(int i=1;i<=n;i++)ans+=N*a[i]*a[i],ans1+=a[i];
		minn=min(minn,ans-ans1*ans1);
	}else{
		for(int i=2;i<=n;i++)
		 if(!vis[i])vis[i]=1,Pai[x]=i,dfs(x+1),vis[i]=0;
	}
}
int main(){
	srand(time(0));
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i]-a[i-1];
	if(n<=10){
		dfs(1);cout<<minn;return 0;
	}
    int T=50000000/n;
    while(T--){
    	random_shuffle(b+2,b+n+1);
    	for(int i=1;i<=n;i++)a[i]=a[i-1]+b[i];
		long long ans=0,ans1=0,N=n;
		for(int i=1;i<=n;i++)ans+=N*a[i]*a[i],ans1+=a[i];
		minn=min(minn,ans-ans1*ans1);
	}
	cout<<minn;
	return 0;
}
