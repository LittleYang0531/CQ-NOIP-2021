#include<bits/stdc++.h>
using namespace std;
const int N=1e7+100;
bool vis[N];
int n,m,Max;
int x[N];
bool check(int x){
	while(x!=0){
		int t=x%10;
		if(t==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		Max=max(Max,x[i]);
	}
	for(int i=1;i<=Max+15;i++){
		if(check(i)&&vis[i]==0){
			for(int j=i;j<=Max+15;j+=i){
				//if(vis[j]==1) break;
				vis[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[x[i]]==1){
			printf("-1\n");
			continue;
		}
		for(int j=x[i]+1;j<=N;j++){
			if(vis[j]==0){
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}
