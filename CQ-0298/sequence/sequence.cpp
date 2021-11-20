#include <bits/stdc++.h>
//DFS is very great!!!
using namespace std;
const long long MOD=998244353LL;
int n,m,k;
int ans[20];
long long daan;
int v[20];
int tot;
int sum=0;
long long answ;
void check(int x[20]){
//	cout<<answ<<" "<<sum<<endl;
	int sum2=sum;
	string s="";
	int cnt=0;
	while(sum2!=0){
		if(sum2%2){
			cnt++;
		}
		sum2/=2;
	}
	if(cnt<=k){
		daan+=answ;
	}
	return;
}
void dfs(int x){
	if(x==n+1){
		check(ans);
	}
	else{
		for(int i=0;i<=m;i++){
			ans[tot]=i;
			tot++;
			if(x==1){
				answ=v[ans[0]]%MOD;
			}
			else{
				answ*=v[ans[tot-1]];
				answ%=MOD;
			}
			sum+=(1<<ans[tot-1]);
			dfs(x+1);
			sum-=(1<<ans[tot-1]);
			if(x==1){
				answ=0;
			}
			else{
				answ/=v[ans[tot-1]];
				answ%=MOD;
			}
			ans[tot-1]=0;			
			tot--;
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	dfs(1);
	cout<<daan<<endl;
	return 0;
}//0pts
