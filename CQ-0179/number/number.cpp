#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int p[N],cnt;
map<int,int> vis;
bool pd(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
void pre(){
	for(int i=1;i<=N;i++){
		if(vis[i]==0){
			if(pd(i)){
				vis[i]=1;
				for(int j=1;j<=N;j++){
					if(i*j>N) break;
					vis[i*j]=1;
				}
			}
		}
		if(vis[i]==0) p[++cnt]=i,vis[i]=cnt;
		else vis[i]=0;
	}
}
int T,x;
int main(){// 70 pts
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		if(vis[x]==0) printf("-1\n");
		else printf("%d\n",p[vis[x]+1]);
	}
	return 0;
}
/*
29121

2 3 4 5 6 7 8 9 10
7 17 27 37 47 57 67 70 77
*/
