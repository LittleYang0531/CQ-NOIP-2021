#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=(1e7)+10005;
int vis[N],nxt[N],T;
void pre(int n){int i,j;
	for(i=0;i<=n;i+=7)vis[i]=1;
	for(i=0;i<=n;i++){
		if(vis[i])continue;
		int x=i,tg=0;
		while(x){
			if(x%10==7)tg=1;
			x/=10;
		}
		if(tg){
			for(j=i;j<=n;j+=i)vis[j]=1;
		}
	}int nt=0;
	for(i=n;i>=0;i--){nxt[i]=nt;if(vis[i]==0)nt=i;}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//printf("%d\n",sizeof(vis)*2);
	int x;
	pre(N-5);scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		if(vis[x]){puts("-1");}
		else printf("%d\n",nxt[x]);
	}
}
