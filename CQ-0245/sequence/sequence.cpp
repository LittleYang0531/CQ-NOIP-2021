#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0;
long long v[105];
int a[105];
long long mod=998244353;
long long ans=0;
int did(int x){
	int ss=0;
	while(x){
		if(x&1) ss++;
		x>>=1;
	}return ss;
}
void dfs(int x,int sum){//sumΪȨֵ
	if(x>n){
		int num=0;
		for(int i=1;i<=n;i++) num+=pow(2,a[i]);
		num=did(num);
		if(num>k) return;
		ans=(ans+sum)%mod;
		return;
	} 
	for(int i=0;i<=m;i++){
		a[++cnt]=i;
		dfs(x+1,sum*v[i]);
		cnt--;
	}
}
int main(){
  	freopen("sequence.in","r",stdin);
  	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}

