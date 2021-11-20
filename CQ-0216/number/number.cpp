#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
const int M=1e6+10;
int T;

bool vis[N];
int idx;
int ans[M];
int n;

bool p(int num){
	while(num){
		if(num%10==7) return true;
		num/=10;
	}
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<N;i++){
		if(p(i)){
			vis[i]=true;
			for(int j=2;j*i<N;j++){
				vis[j*i]=true;
			}
		}
	}
	for(int i=1;i<N;i++){
		if(!vis[i]){
			ans[++idx]=i;
		}
	}
	
//	for(int i=1;i<=idx;i++){
//		printf("%d\n",ans[i]);
//	}
	
	while(T--){
		scanf("%d",&n);
		if(vis[n]) puts("-1");
		else{
			int add=lower_bound(ans+1,ans+1+idx,n)-ans;
			printf("%d\n",ans[add+1]);
		}
	}

	return 0;
}

