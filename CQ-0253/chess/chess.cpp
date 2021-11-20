#include<bits/stdc++.h>
#define id(i,j) ((i-1)*m+j)
using namespace std;
const int maxn=1e6+7;
int T,n,m,Q,sx,sy,lv[maxn],col[maxn],ans;
int cnt,hed[maxn],nxt[maxn*2],to[maxn*2],val[maxn*2],f[maxn];
char s[maxn];
bool vis[maxn],yd[maxn],can[maxn];
struct node{
	int x,fx,co;
};
void add(int u,int v,int w,int fxa){
	nxt[++cnt]=hed[u];
	hed[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
	f[cnt]=fxa;
	return ;
}
queue<node>q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(hed,0,sizeof(hed));
		memset(nxt,0,sizeof(nxt));
		memset(yd,0,sizeof(nxt));
		scanf("%d%d%d",&n,&m,&Q);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<m;j++){
				add(id(i,j),id(i,j+1),s[j]-'0',0);
				add(id(i,j+1),id(i,j),s[j]-'0',0);
			}
		}
		for(int i=1;i<n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++){
				add(id(i+1,j),id(i,j),s[j]-'0',1);
				add(id(i,j),id(i+1,j),s[j]-'0',1);
			}
		}
//		printf("boom\n");
		int S,u,v,nf,nc,coll,l;
		while(Q--){
			memset(can,0,sizeof(can));
			scanf("%d%d%d%d",&coll,&l,&sx,&sy);
			S=id(sx,sy);
			col[S]=coll,lv[S]=l;
			vis[S]=yd[S]=1;
//			while(!q.empty())q.pop();
			for(int i=hed[S];i;i=nxt[i]){
				if(val[i]==0)continue;
				if(yd[to[i]]&&(col[to[i]]==col[S]||lv[to[i]]>lv[S]))continue;
				can[to[i]]=1;
				if(val[i]==1)continue;
				if(!yd[to[i]])q.push((node){to[i],f[i],val[i]});
				memset(vis,0,sizeof(vis));
				vis[to[i]]=1,vis[S]=1;
//				if(to[i]==9&&S==6)printf("papapppa %d\n",val[i]);
				while(!q.empty()){
					u=q.front().x,nf=q.front().fx,nc=q.front().co;
					q.pop();
					for(int j=hed[u];j;j=nxt[j]){
						if(val[j]!=nc)continue;
						if((nc==2&&f[j]!=nf)||vis[to[j]])continue;
						if(yd[to[j]]&&(col[to[j]]==col[S]||lv[to[j]]>lv[S]))continue;
						can[to[j]]=1;
						vis[to[j]]=1;
						if(!yd[to[j]])q.push((node){to[j],f[j],val[j]});
					}
				}
			}
			ans=0;
			for(int i=1;i<=id(n,m);i++){
//				cout<<can[i]<<' ';
//				if(i%m==0)cout<<'\n';
				if(can[i])ans++;
			}
			printf("%d",ans);
			putchar('\n');
		}
	}
	return 0;
}
