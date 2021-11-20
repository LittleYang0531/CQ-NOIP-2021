#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,cnt,ans=0x3f3f3f3f;
int f[N][N];
int vis[N][N];
int check(int now){
	int tot=0,ret=0;
	for(int i=1;i<=n;i++){
		tot+=f[now][i];
		ret=ret+f[now][i]*f[now][i];
	}
	return ret*n-tot*tot;
}
void bfs(int now){
	queue<int> q;
	q.push(now);
	while(!q.empty()){
		int u=q.front();
		ans=min(check(u),ans);
		q.pop();
		for(int i=2;i<n;i++){
			if(vis[i][f[u][i-1]+f[u][i+1]-f[u][i]]<50){
				vis[i][f[u][i-1]+f[u][i+1]-f[u][i]]++;
				cnt++;
				for(int j=1;j<=n;j++){
					f[cnt][j]=f[u][j];
				}
				f[cnt][i]=f[u][i-1]+f[u][i+1]-f[u][i];
				q.push(cnt);
			}
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[0][i]);
		vis[i][f[0][i]]=1;
	}
	bfs(0);
	printf("%d",ans);
	return 0;
}
