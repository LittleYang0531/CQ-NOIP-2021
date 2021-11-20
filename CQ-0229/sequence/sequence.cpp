#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=998244353;
ll arr[105];
ll pm(ll n,ll m){
	n=n%mod;
	ll ans=1;
	while(m){
		if(m%2)ans=ans*n%mod;
		n=n*n%mod;
		m/=2;
	}
	return ans%mod;
}
int n,m,k;
ll ans=1,sum=0;
int er[205];
int times[105];
ll inv[105];
ll Inv(ll c){
	return pm(c,mod-2);
}
void dfs(int x,int use){
	if(x==n){
		if(use<=k){
		sum=(sum+ans)%mod;
	}
		return;
	}
	for(int i=0;i<=m;i++){
		times[i]++;
		ans=ans*arr[i]%mod;
		if(er[i]==0){
			er[i]=1;
			dfs(x+1,use+1);
			er[i]=0;
		}
		if(er[i]==1){
			er[i]=0;
			int k=1;
			while(1){
				if(er[i+k]==0)break;
				er[i+k]=0;
				k++;
			}
			er[i+k]++;
			dfs(x+1,use-k+1);
			er[i+k]=0;
			er[i]=1;
			for(int j=1;j<k;j++)er[i+j]=1;
		}
		times[i]--;
		ans=ans*inv[i]%mod;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",&arr[i]);
	for(int i=0;i<=m;i++)inv[i]=Inv(arr[i]);
	dfs(0,0);
	printf("%lld",sum);
	return 0;
}
