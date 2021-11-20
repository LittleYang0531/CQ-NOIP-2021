#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,v[105][105],col[200005],lv[200005],t1,t2,t3,t4,ans;
bitset<200005> vis;
char s[200005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int xh(int x,int y){
	return m*(x-1)+y;
}
int dfs(int k,int fx,int tot,int pp,int qq){
	if(!vis[k]) tot++,vis[k]=1;
	if(fx==-1&&k%m!=1&&v[k][k-1]==2&&col[k-1]!=pp&&qq>=lv[k-1]) return dfs(k+fx,fx,tot,pp,qq);
	if(fx==1&&k%m!=0&&v[k][k+1]==2&&col[k+1]!=pp&&qq>=lv[k+1]) return dfs(k+fx,fx,tot,pp,qq);
	if(fx==m&&(k-1)/m!=0&&v[k][k-m]==2&&col[k-m]!=pp&&qq>=lv[k-m]) return dfs(k+fx,fx,tot,pp,qq);
	if(fx==-m&&(k-1)/m!=(n-1)&&v[k][k+m]==2&&col[k+m]!=pp&&qq>=lv[k+m]) return dfs(k+fx,fx,tot,pp,qq);
	return tot;
}
int dfs2(int k,int pp,int qq){
	int tot=0;
	queue<int> q;
	q.push(k);
	while(!q.empty()){
		int w=q.front();q.pop();
		if(!vis[w]) vis[w]=1,tot++;
		if(w%m!=1&&v[w][w-1]==3&&!vis[w-1]&&col[w-1]!=pp&&qq>=lv[w-1]) q.push(w-1);
		if(w%m!=0&&v[w][w+1]==3&&!vis[w+1]&&col[w+1]!=pp&&qq>=lv[w+1]) q.push(w+1);
		if((w-1)/m!=0&&v[w][w-m]==3&&!vis[w-m]&&col[w-m]!=pp&&qq>=lv[w-m]) q.push(w-m);
		if((w-1)/m!=(n-1)&&v[w][w+m]==3&&!vis[w+m]&&col[w+m]!=pp&&qq>=lv[w+m]) q.push(w+m);
	}
	return tot;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	for(int j=1;j<=t;j++){
		n=read(),m=read(),q=read();
		for(int i=1;i<=n*m;i++) col[i]=lv[i]=-1;
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<m;j++) v[xh(i,j)][xh(i,j+1)]=v[xh(i,j+1)][xh(i,j)]=s[j]-'0';	
		}
		for(int i=1;i<n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) v[xh(i,j)][xh(i+1,j)]=v[xh(i+1,j)][xh(i,j)]=s[j]-'0';
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
			for(long long j1=1;j1<=n;j1++) for(long long j2=1;j2<=m;j2++) vis[xh(j1,j2)]=0;
			long long p=xh(t3,t4);
			vis[p]=1;
			ans=0;
			col[p]=t1,lv[p]=t2;
			if(p%m!=1){
				if(v[p][p-1]==1&&!vis[p-1]&&col[p-1]!=col[p]&&lv[p]>=lv[p-1]) ans++,vis[p-1]=1;
				if(v[p][p-1]==2) ans+=dfs(p,-1,0,t1,t2);
				if(v[p][p-1]==3) ans+=dfs2(p,t1,t2);
			}
			if(p%m!=0){
				if(v[p][p+1]==1&&!vis[p+1]&&col[p+1]!=col[p]&&lv[p]>=lv[p+1]) ans++,vis[p+1]=1;
				if(v[p][p+1]==2) ans+=dfs(p,1,0,t1,t2);
				if(v[p][p+1]==3) ans+=dfs2(p,t1,t2);
			}
			if((p-1)/m!=0){
				if(v[p][p-m]==1&&!vis[p-m]&&col[p-m]!=col[p]&&lv[p]>=lv[p-m]) ans++,vis[p-m]=1;
				if(v[p][p-m]==2) ans+=dfs(p,-m,0,t1,t2);
				if(v[p][p-m]==3) ans+=dfs2(p,t1,t2);
			}
			if((p-1)/m!=(n-1)){
				if(v[p][p+m]==1&&!vis[p+m]&&col[p+m]!=col[p]&&lv[p]>=lv[p+m]) ans++,vis[p+m]=1;
				if(v[p][p+m]==2) ans+=dfs(p,m,0,t1,t2);
				if(v[p][p+m]==3) ans+=dfs2(p,t1,t2);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//艹没de完bug，要AFO了awa 
