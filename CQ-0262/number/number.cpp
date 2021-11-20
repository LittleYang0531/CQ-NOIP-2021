#include<bits/stdc++.h>
#define N 10000012
#define M 1000012
using namespace std;
int T,n;
int vis[N],ans;
int sz;

void iit(){
	for(int i=1;i<M;i++){
		if(vis[i]) continue;
		int x=i,fl=0;
		while(x){
			if(x%10==7){ fl=1; vis[i]=1; break;}
			x/=10;
		}
		if(fl){
			for(int j=2;j*i<M;j++){
				vis[j*i]=1;
			}
		}
	}
	return ;
}
void dfs(int x,int k){
	if(x==8){ vis[sz]=1; return ;}
	if(x==k){ sz=sz*10+7; dfs(x+1,k); sz/=10;}
	else{
		for(int i=0;i<=9;i++){
			sz=sz*10+i;
			dfs(x+1,k);
			sz/=10;
		}
	}
	return ;
}
void init(){
	for(int i=1;i<N;i++){
		if(vis[i]){
			for(int j=2;j*i<N;j++){
				vis[j*i]=1;
			}
		}
	}
	return ;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	if(T<=10000) iit();
	else{
		for(int i=1;i<=7;i++){
			dfs(1,i);
		}
		init();
	}
	while(T--){
		scanf("%d",&n);
		if(vis[n]){ printf("-1\n"); continue;}
		while(1){
			n++;
			if(!vis[n]){
				printf("%d\n",n);
				break;
			}
		}
	}
	
	return 0;
}
