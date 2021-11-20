#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int MOD=998244353;
int n,m,k;
int M[11];
int s[N],d[N];
int er[24];
int cnt,er_cnt;
long long w;
long long ans;
void dfs(int u,int S){
	if(u>n){
		if(w==S){
			int zhi=1;
			for(int i=1;i<=n;i++){
				//cout<<er[i]<<" ";
				zhi*=M[er[i]]%MOD;
			}
			//cout<<endl;
			ans+=zhi;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		er[u]=i;
		w+=pow(2,i);
		dfs(u+1,S);
		w-=pow(2,i);
		if(w+pow(2,i+1)>S){
			break;
		}
	}
}
int fj(int t){
	int sum=0;
	while(t>0){
		int a=t%2;
		t/=2;
		if(a==1) sum++;
	}
	return sum;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		cin>>M[i];
	}
	long long fan=pow(2,m);
	for(int i=n;i<=n*fan;i++){
		int sum=fj(i);
		if(sum<=k){
			w=0;
			dfs(1,i);
		}
	}
	cout<<ans%MOD;
	return 0;
}
