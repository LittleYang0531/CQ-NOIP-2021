#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int t,x,tt,vis[N],ne[N];
int check(int x){
	int res=1;
	if(x%7==0){
		res=-1;
	}else{
		while(x){
			if(x%10==7){
				res=-1;
				break;
			}
			x/=10;
		}
	}
	return res;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N-4;i++){
		if(vis[i]==0){
			vis[i]=check(i);
			if(vis[i]==-1){
				for(int j=i;j<=N-5;j+=i){
					vis[j]=-1;
				}
			}else{
				ne[tt]=i;
				tt=i;
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(vis[x]==-1){
			printf("-1\n");
		}else{
			printf("%d\n",ne[x]);
		}
	}
	return 0;
}
