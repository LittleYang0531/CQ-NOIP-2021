#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int> 
using namespace std;
const int maxn=5000005;
const int maxm=5000005;
int n,m,q,ans;
char s[maxn];
int first[maxm],nex[maxm],e[maxm],type[maxm],dir[maxm],tot=1;
int vis[maxn],been[maxn],hasnode[maxn];
pii a[maxn];//col,lv
int id(int x,int y){
	return (x-1)*m+y;
}
int idy(int id){
	if(id%m==0) return m;
	return id%m;
}
int idx(int id){
	return id/m-idy(id)/m+1;
} 
void add(int x,int y,int opt,int direct){
	nex[++tot]=first[x];
	first[x]=tot;
	e[tot]=y;
	type[tot]=opt;
	dir[tot]=direct;//1横2竖 
}
void bfs(int col,int posx,int posy,int lv,int edgeType,int direct){
	/*
	vis[x]=0，没有走过
	vis[x]=1，走过了，还可以继续走
	vis[x]=2，走过了，但是吃了子，不能继续走 
	
	direct，1横2竖 
	
	edgeType，如题 
	*/
	memset(vis,0,(n*m+1)*sizeof(int));
	queue<int>q;
	while(!q.empty()) q.pop();
	q.push(id(posx,posy));
	vis[id(posx,posy)]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		cout<<"("<<idx(x)<<","<<idy(x)<<")\n";
		if(vis[x]==-1) continue;//不能继续走 
		for(int i=first[x];i;i=nex[i]){
			int y=e[i];
//			cout<<"(flag)("<<idx(y)<<","<<idy(y)<<")\n";
			if(type[i]==0||type[i]!=edgeType||vis[y]) continue;
			if(type[i]==2&&dir[i]!=direct) continue;//如果只能走直线，且方向不对 
//			cout<<"(flag1)("<<idx(y)<<","<<idy(y)<<")\n";
			if(hasnode[y]){//吃子 
				if(col!=a[y].first&&lv>=a[y].second){
					vis[y]=-1;//不能继续走 
					q.push(y);
					been[y]=1;
				}
			}else{
				if(type[i]==1){
					vis[y]=-1;//不能继续走，因为只能走一条普通路 
					q.push(y);
					been[y]=1;
				}else if(type[i]==2){
					if(dir[i]==direct){//走直线 
						vis[y]=1;
						q.push(y);
						been[y]=1;
					}
				}else if(type[i]==3){//随便走 
					vis[y]=1;
					q.push(y);
					been[y]=1;
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i){
			cin>>(s+1);
			for(int j=1;j<=m-1;++j){
				add(id(i,j),id(i,j+1),s[j]-'0',1);
				add(id(i,j+1),id(i,j),s[j]-'0',1);
			}
		}
		for(int i=1;i<=n-1;++i){
			cin>>(s+1);
			for(int j=1;j<=m;++j){
				add(id(i,j),id(i+1,j),s[j]-'0',2);
				add(id(i+1,j),id(i,j),s[j]-'0',2);
			}
		}
		while(q--){
			int col,lv,x,y;
			cin>>col>>lv>>x>>y;
			ans=0;
			memset(been,0,(n*m+1)*sizeof(int));
			for(int edgeType=1;edgeType<=3;++edgeType){
				if(edgeType==2){
					bfs(col,x,y,lv,edgeType,1);
					bfs(col,x,y,lv,edgeType,2);
				}else{
					bfs(col,x,y,lv,edgeType,-1);
				}
			} 
			for(int i=1;i<=n*m;++i) ans+=(been[i]==1);
			cout<<ans<<"\n";
			a[id(x,y)]=mp(col,lv);
			hasnode[id(x,y)]=1;
		}
		tot=1;
		memset(first,0,(n*m+1)*sizeof(int));
		memset(hasnode,0,(n*m+1)*sizeof(int));
	}
	return 0;
}
