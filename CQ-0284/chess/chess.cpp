#include<bits/stdc++.h>
using namespace std;
long long t,n,m,q,k,ge[10001][10001],col,lv,x,y,ans;
string kk;
vector<int>thy[10001];
struct thy{
	int col,lv;
}shu[200001];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld%lld",&n,&m,&q);
		memset(thy,0,sizeof(thy));
		for(int j=1;j<=n*m;j++){
			if(j-1>0){
				thy[j].push_back(j-1);
				thy[j-1].push_back(j);
				continue;
			}
			if(j+1<=m){
				thy[j].push_back(j+1);
				thy[j+1].push_back(j);
				continue;
			}
			if(j-m>0){
				thy[j].push_back(j-m);
				thy[j-m].push_back(j);
				continue;
			}
			if(j+m<=n){
				thy[j].push_back(j+m);
				thy[j+m].push_back(j);
				continue;
			}
		}
		for(int j=1;j<=n;j++){
			cin>>kk;
			k++;
			for(int z=0;z<kk.size();z++){
				k++;
				ge[k-1][k]=kk[z]-'0';
				ge[k][k-1]=kk[z]-'0';
			}
		}
		k=1;
		for(int j=1;j<=n-1;j++){
			cin>>kk;
			for(int z=0;z<kk.size();z++){
				k++;
				ge[k-1][k+m-1]=kk[z]-'0';
				ge[k+m-1][k-1]=kk[z]-'0';
			}
		}
		for(int j=1;j<=q;j++){
			scanf("%lld%lld%lld%lld",&col,&lv,&x,&y);
			ans=0;
			shu[thy[x][y]].col=col;
			shu[thy[x][y]].lv=lv;
			cout<<ans<<endl;
		}
	}
}
