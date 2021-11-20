#include<bits/stdc++.h>
#define re register
using namespace std;
int st;
char rbuf[30000002],wbuf[10000002];
int pt=-1,pt1=-1;
inline int read(){
	re int t=0;re char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
inline void write(re int x){
	if(x>9)write(x/10);
	wbuf[++pt1]=x%10+'0';
}
int n,m,q,t,T[100002],C[100002],X[100002],Y[100002],vis[200002],fa[200002],rt[2][200002],tot,ls[40000002],rs[40000002],sz[40000002],ans[100002],siz[200002];
vector<char>A[100002],B[100002];
vector<int>L[100002],R[100002],U[100002],D[100002];
inline char nc(){
	re char v=rbuf[++pt];
	while(v<'0'||v>'3')v=rbuf[++pt];
	return v;
}
map<int,int>V[2][200002];
struct node{int x,y;bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}};
vector<node>O[200002];
set<int>P[2][200002],S1[100002],S2[100002];
set<int>::iterator it2;
inline int pos(re int x,re int y){
	if(x==0||x==n+1||y==0||y==m+1)return 0;
	return (x-1)*m+y;
}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void ins(re int &p,re int l,re int r,re int x,re int o=1){
	if(!p)p=++tot,sz[p]=ls[p]=rs[p]=0;sz[p]+=o;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x,o);
	else ins(rs[p],mid+1,r,x,o);
}
inline int ask(re int p,re int l,re int r,re int x,re int y){
	if(!sz[p]||(l>=x&&r<=y))return sz[p];
	re int mid=l+r>>1,s=0;
	if(x<=mid)s+=ask(ls[p],l,mid,x,y);
	if(y>mid)s+=ask(rs[p],mid+1,r,x,y);
	return s;
}
inline void Merge(re int x,re int y){
	x=root(x),y=root(y);if(x==y)return;
	if(P[0][x].size()+P[1][x].size()+O[x].size()<P[0][y].size()+P[1][y].size()+O[y].size())swap(x,y);
	fa[y]=x,siz[x]+=siz[y];
	for(it2=P[0][y].begin();it2!=P[0][y].end();++it2){
		int tmp=*it2;
		if(P[0][x].find(tmp)!=P[0][x].end())continue;
		P[0][x].insert(tmp),ins(rt[0][x],1,q,C[tmp]);
	}
	for(it2=P[1][y].begin();it2!=P[1][y].end();++it2){
		int tmp=*it2;
		if(P[1][x].find(tmp)!=P[1][x].end())continue;
		P[1][x].insert(tmp),ins(rt[1][x],1,q,C[tmp]);
	}
	for(re int i=0;i<O[y].size();++i){
		node tmp=O[y][i];
		O[x].push_back(tmp);
		ins(V[0][x][tmp.x],1,m,tmp.y),ins(V[1][x][tmp.y],1,n,tmp.x);
	}
}
inline void Del(re int x,re int y){
	if(P[T[y]][x].find(y)==P[T[y]][x].end())return;
	P[T[y]][x].erase(y),ins(rt[T[y]][x],1,q,C[y],-1);
}
int ed;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	fread(rbuf,1,30000000,stdin);
	t=read();
	while(t--){
		n=read(),m=read(),q=read(),tot=0;
		for(re int i=0;i<=n+1;++i)A[i].resize(m+2),B[i].resize(m+2),L[i].resize(m+2),R[i].resize(m+2),U[i].resize(m+2),D[i].resize(m+2);
		for(re int i=1;i<=n;++i)S1[i].clear();
		for(re int j=1;j<=m;++j)S2[j].clear();
		for(re int i=1;i<=n*m;++i)V[0][i].clear(),V[1][i].clear(),P[0][i].clear(),P[1][i].clear(),O[i].clear(),vis[i]=0,fa[i]=i,rt[0][i]=rt[1][i]=0,siz[i]=0;
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<m;++j)A[i][j]=nc()-'0';
			A[i][m]=0;
		}
		for(re int i=1;i<n;++i)
			for(re int j=1;j<=m;++j)B[i][j]=nc()-'0';
		for(re int j=1;j<=m;++j)B[n][j]=0;
		for(re int i=1;i<=q;++i){
			T[i]=read(),C[i]=read(),X[i]=read(),Y[i]=read();
			S1[X[i]].insert(Y[i]);
			S2[Y[i]].insert(X[i]);
			vis[pos(X[i],Y[i])]=i;
		}
		for(re int i=1;i<=n;++i){
			L[i][0]=0,R[i][m+1]=m+1;
			for(re int j=1;j<=m;++j)
				if(A[i][j-1]==2)L[i][j]=L[i][j-1];
				else L[i][j]=j;
			for(re int j=m;j;--j)
				if(A[i][j]==2)R[i][j]=R[i][j+1];
				else R[i][j]=j;
		}
		for(re int i=1;i<=m;++i){
			U[0][i]=0,D[n+1][i]=n+1;
			for(re int j=1;j<=n;++j)
				if(B[j-1][i]==2)U[j][i]=U[j-1][i];
				else U[j][i]=j;
			for(re int j=n;j;--j)
				if(B[j][i]==2)D[j][i]=D[j+1][i];
				else D[j][i]=j;
		}
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				if(!vis[pos(i,j)]){
					if(A[i][j]==3&&!vis[pos(i,j+1)])fa[root(pos(i,j))]=root(pos(i,j+1));
					if(B[i][j]==3&&!vis[pos(i+1,j)])fa[root(pos(i,j))]=root(pos(i+1,j));
				}
		for(re int i=1;i<=n*m;++i)++siz[root(i)];
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j){
				re int x=root(pos(i,j));
				ins(V[0][x][i],1,m,j);
				ins(V[1][x][j],1,n,i);
				O[x].push_back((node){i,j});
			}
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				if(vis[pos(i,j)]){
					re int y=vis[pos(i,j)];
					if(A[i][j]==3&&!vis[pos(i,j+1)])ins(rt[T[y]][root(pos(i,j+1))],1,q,C[y]),P[T[y]][root(pos(i,j+1))].insert(y);
					if(A[i][j-1]==3&&!vis[pos(i,j-1)]&&P[T[y]][root(pos(i,j-1))].find(y)==P[T[y]][root(pos(i,j-1))].end())ins(rt[T[y]][root(pos(i,j-1))],1,q,C[y]),P[T[y]][root(pos(i,j-1))].insert(y);
					if(B[i][j]==3&&!vis[pos(i+1,j)]&&P[T[y]][root(pos(i+1,j))].find(y)==P[T[y]][root(pos(i+1,j))].end())ins(rt[T[y]][root(pos(i+1,j))],1,q,C[y]),P[T[y]][root(pos(i+1,j))].insert(y);
					if(B[i-1][j]==3&&!vis[pos(i-1,j)]&&P[T[y]][root(pos(i-1,j))].find(y)==P[T[y]][root(pos(i-1,j))].end())ins(rt[T[y]][root(pos(i-1,j))],1,q,C[y]),P[T[y]][root(pos(i-1,j))].insert(y);
				}
		for(re int i=q;i>=1;--i){
			vis[pos(X[i],Y[i])]=0;
			S1[X[i]].erase(Y[i]);
			S2[Y[i]].erase(X[i]);
			if(A[X[i]][Y[i]]==3&&!vis[pos(X[i],Y[i]+1)])Merge(pos(X[i],Y[i]),pos(X[i],Y[i]+1));	
			else if(A[X[i]][Y[i]]==3&&P[T[vis[pos(X[i],Y[i]+1)]]][root(pos(X[i],Y[i]))].find((vis[pos(X[i],Y[i]+1)]))==P[T[vis[pos(X[i],Y[i]+1)]]][root(pos(X[i],Y[i]))].end())
			ins(rt[T[vis[pos(X[i],Y[i]+1)]]][root(pos(X[i],Y[i]))],1,q,C[vis[pos(X[i],Y[i]+1)]]),P[T[vis[pos(X[i],Y[i]+1)]]][root(pos(X[i],Y[i]))].insert(vis[pos(X[i],Y[i]+1)]);
			if(A[X[i]][Y[i]-1]==3&&!vis[pos(X[i],Y[i]-1)])Merge(pos(X[i],Y[i]),pos(X[i],Y[i]-1));
			else if(A[X[i]][Y[i]-1]==3&&P[T[vis[pos(X[i],Y[i]-1)]]][root(pos(X[i],Y[i]))].find((vis[pos(X[i],Y[i]-1)]))==P[T[vis[pos(X[i],Y[i]-1)]]][root(pos(X[i],Y[i]))].end())
			ins(rt[T[vis[pos(X[i],Y[i]-1)]]][root(pos(X[i],Y[i]))],1,q,C[vis[pos(X[i],Y[i]-1)]]),P[T[vis[pos(X[i],Y[i]-1)]]][root(pos(X[i],Y[i]))].insert(vis[pos(X[i],Y[i]-1)]);
			if(B[X[i]][Y[i]]==3&&!vis[pos(X[i]+1,Y[i])])Merge(pos(X[i],Y[i]),pos(X[i]+1,Y[i]));
			else if(B[X[i]][Y[i]]==3&&P[T[vis[pos(X[i]+1,Y[i])]]][root(pos(X[i],Y[i]))].find((vis[pos(X[i]+1,Y[i])]))==P[T[vis[pos(X[i]+1,Y[i])]]][root(pos(X[i],Y[i]))].end())
			ins(rt[T[vis[pos(X[i]+1,Y[i])]]][root(pos(X[i],Y[i]))],1,q,C[vis[pos(X[i]+1,Y[i])]]),P[T[vis[pos(X[i]+1,Y[i])]]][root(pos(X[i],Y[i]))].insert(vis[pos(X[i]+1,Y[i])]);
			if(B[X[i]-1][Y[i]]==3&&!vis[pos(X[i]-1,Y[i])])Merge(pos(X[i],Y[i]),pos(X[i]-1,Y[i]));
			else if(B[X[i]-1][Y[i]]==3&&P[T[vis[pos(X[i]-1,Y[i])]]][root(pos(X[i],Y[i]))].find((vis[pos(X[i]-1,Y[i])]))==P[T[vis[pos(X[i]-1,Y[i])]]][root(pos(X[i],Y[i]))].end())
			ins(rt[T[vis[pos(X[i]-1,Y[i])]]][root(pos(X[i],Y[i]))],1,q,C[vis[pos(X[i]-1,Y[i])]]),P[T[vis[pos(X[i]-1,Y[i])]]][root(pos(X[i],Y[i]))].insert(vis[pos(X[i]-1,Y[i])]);
			Del(root(pos(X[i],Y[i])),i);
			re int x=root(pos(X[i],Y[i]));
			ans[i]=siz[x]-1;
			ans[i]+=ask(rt[T[i]^1][x],1,q,1,C[i]);
			re int l=L[X[i]][Y[i]],r=R[X[i]][Y[i]];
			it2=S1[X[i]].lower_bound(Y[i]);
			if(it2!=S1[X[i]].end())r=min(r,(*it2)-1);
			if(it2!=S1[X[i]].begin())--it2,l=max(l,(*it2)+1);
			l=max(l,1),r=min(r,m);
			re int u=U[X[i]][Y[i]],d=D[X[i]][Y[i]];
			it2=S2[Y[i]].lower_bound(X[i]);
			if(it2!=S2[Y[i]].end())d=min(d,(*it2)-1);
			if(it2!=S2[Y[i]].begin())--it2,u=max(u,(*it2)+1);
			u=max(u,1),d=min(d,n);
			ans[i]+=r-l+d-u;
			ans[i]-=ask(V[0][x][X[i]],1,m,l,r)-1;
			ans[i]-=ask(V[1][x][Y[i]],1,n,u,d)-1;
			re int tt=vis[pos(X[i],l-1)]; 
			if(tt&&A[X[tt]][Y[tt]]==2&&P[T[tt]][x].find(tt)==P[T[tt]][x].end()&&C[i]>=C[tt]&&T[i]!=T[tt])++ans[i];
			tt=vis[pos(X[i],r+1)];
			if(tt&&A[X[tt]][Y[tt]-1]==2&&P[T[tt]][x].find(tt)==P[T[tt]][x].end()&&C[i]>=C[tt]&&T[i]!=T[tt])++ans[i];
			tt=vis[pos(u-1,Y[i])];
			if(tt&&B[X[tt]][Y[tt]]==2&&P[T[tt]][x].find(tt)==P[T[tt]][x].end()&&C[i]>=C[tt]&&T[i]!=T[tt])++ans[i];
			tt=vis[pos(d+1,Y[i])];
			if(tt&&B[X[tt]-1][Y[tt]]==2&&P[T[tt]][x].find(tt)==P[T[tt]][x].end()&&C[i]>=C[tt]&&T[i]!=T[tt])++ans[i];
			if(A[X[i]][Y[i]]==1&&!vis[pos(X[i],Y[i]+1)]&&root(pos(X[i],Y[i]+1))!=root(pos(X[i],Y[i])))++ans[i];
			if(A[X[i]][Y[i]]==1&&vis[pos(X[i],Y[i]+1)]&&C[i]>=C[vis[pos(X[i],Y[i]+1)]]&&T[i]!=T[vis[pos(X[i],Y[i]+1)]]&&P[T[vis[pos(X[i],Y[i]+1)]]][x].find(vis[pos(X[i],Y[i]+1)])==P[T[vis[pos(X[i],Y[i]+1)]]][x].end())++ans[i];
			if(A[X[i]][Y[i]-1]==1&&!vis[pos(X[i],Y[i]-1)]&&root(pos(X[i],Y[i]-1))!=root(pos(X[i],Y[i])))++ans[i];
			if(A[X[i]][Y[i]-1]==1&&vis[pos(X[i],Y[i]-1)]&&C[i]>=C[vis[pos(X[i],Y[i]-1)]]&&T[i]!=T[vis[pos(X[i],Y[i]-1)]]&&P[T[vis[pos(X[i],Y[i]-1)]]][x].find(vis[pos(X[i],Y[i]-1)])==P[T[vis[pos(X[i],Y[i]-1)]]][x].end())++ans[i];
			if(B[X[i]][Y[i]]==1&&!vis[pos(X[i]+1,Y[i])]&&root(pos(X[i]+1,Y[i]))!=root(pos(X[i],Y[i])))++ans[i];
			if(B[X[i]][Y[i]]==1&&vis[pos(X[i]+1,Y[i])]&&C[i]>=C[vis[pos(X[i]+1,Y[i])]]&&T[i]!=T[vis[pos(X[i]+1,Y[i])]]&&P[T[vis[pos(X[i]+1,Y[i])]]][x].find(vis[pos(X[i]+1,Y[i])])==P[T[vis[pos(X[i]+1,Y[i])]]][x].end())++ans[i];
			if(B[X[i]-1][Y[i]]==1&&!vis[pos(X[i]-1,Y[i])]&&root(pos(X[i]-1,Y[i]))!=root(pos(X[i],Y[i])))++ans[i];
			if(B[X[i]-1][Y[i]]==1&&vis[pos(X[i]-1,Y[i])]&&C[i]>=C[vis[pos(X[i]-1,Y[i])]]&&T[i]!=T[vis[pos(X[i]-1,Y[i])]]&&P[T[vis[pos(X[i]-1,Y[i])]]][x].find(vis[pos(X[i]-1,Y[i])])==P[T[vis[pos(X[i]-1,Y[i])]]][x].end())++ans[i];
		}
		for(re int i=1;i<=q;++i)write(ans[i]),wbuf[++pt1]='\n';
	}
	fwrite(wbuf,1,pt1+1,stdout);
}

