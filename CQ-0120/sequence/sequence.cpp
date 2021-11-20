#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=998244353;
int n,m,k,ans,cnt=0;
int s[N],v[N];
void find(){
	int up=n;
	for(int i=1;i<=m;i++) up*=2;
	for(int i=n;i<=up;i++){
		int t=i,num=0;
		while(t!=0){
			if(t&1) num++;
			if(num>k) break;
			t>>=1;
		}
		if(num<=k){
			s[++cnt]=i;
		}
	}
}
void dfs(int dep,int tot,int j){
	if(tot+(n-dep)*pow(2,m)<s[1]||tot>s[cnt]) return;
	if(dep==n){
		for(int i=1;i<=cnt;i++){
			if(tot==s[i]){
				ans+=j;
				ans%=inf;
				break;
			}
		}
	}
	else{
		for(int i=0;i<=m;i++){
			int up=1;
			for(int jj=1;jj<=i;jj++) up*=2;
			dfs(dep+1,tot+up,((long long) (j%inf)*(v[i]%inf))%inf);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	find();
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	dfs(0,0,1);
	printf("%d",ans);
	return 0;
}
