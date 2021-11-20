#include<bits/stdc++.h>
using namespace std;
int n,m,q,vst[10005],has[10005],col[10005],lev[10005];
char A[5005][5005],B[5005][5005];
vector<int> g[10005]; 
int pos(int x,int y){
	return (x-1)*m+y;
}
void dfs(int x,int curc,int cur){
	vst[x]=1;
	for(int y:g[x]){
		if(vst[y])continue;
		if(!has[y])dfs(y,curc,cur);
		else {
			if(col[y]!=curc&&lev[y]<=cur)vst[y]=1;
		}
	}
}
void Solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
	for(int i=1;i<n;i++)scanf("%s",B[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(A[i][j]=='3'){
				g[pos(i,j)].push_back(pos(i,j+1));
				g[pos(i,j+1)].push_back(pos(i,j));
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(B[i][j]=='3'){
				g[pos(i,j)].push_back(pos(i+1,j));
				g[pos(i+1,j)].push_back(pos(i,j));
			}
		}
	}
	for(int i=1,c,lv,x,y;i<=q;i++){
		scanf("%d%d%d%d",&c,&lv,&x,&y);
		has[pos(x,y)]=1,col[pos(x,y)]=c,lev[pos(x,y)]=lv,vst[pos(x,y)]=1;
		dfs(pos(x,y),c,lv);
		int u=x,v=y;
		while(A[u][v]=='2'){
			v++;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
				break;
			}
			vst[pos(u,v)]=1;
		}
		u=x,v=y;
		while(A[u][v-1]=='2'){
			v--;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
				break;
			}
			vst[pos(u,v)]=1;
		}
		u=x,v=y;
		while(B[u][v]=='2'){
			u++;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
				break;
			}
			vst[pos(u,v)]=1;
		}
		u=x,v=y;
		while(B[u-1][v]=='2'){
			u--;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
				break;
			}
			vst[pos(u,v)]=1;
		}
		if(A[x][y]=='1'){
			u=x,v=y+1;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
			}
			else vst[pos(u,v)]=1;
		}
		if(A[x][y-1]=='1'){
			u=x,v=y-1;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
			}
			else vst[pos(u,v)]=1;
		}
		if(B[x][y]=='1'){
			u=x+1,v=y;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
			}
			else vst[pos(u,v)]=1;
		}
		if(B[x-1][y]=='1'){
			u=x-1,v=y;
			if(has[pos(u,v)]){
				if(col[pos(u,v)]!=c&&lev[pos(u,v)]<=lv)vst[pos(u,v)]=1;
			}
			else vst[pos(u,v)]=1;
		}
		int ans=0;
		for(int j=1;j<=n*m;j++)ans+=vst[j];
		cout<<ans-1<<'\n';
		for(int j=1;j<=n*m;j++)vst[j]=0;
	}
	for(int j=1;j<=n*m;j++)vst[j]=has[j]=col[j]=lev[j]=0,g[j].clear();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)A[i][j]=B[i][j]=0;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)Solve();
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,q,has[200005],col[200005],lev[200005],Q[200005][2],fa[200005],sz[200005];
int mix[200005],mxx[200005],miy[200005],mxy[200005],fax[200005],fay[200005];
int rt[200005],c[12000005][2],sum[12000005][2],tot,ans[200005];
vector<char> A[200005],B[200005];
vector<int> g[200005];
set<int> alls[200005];
map<int,int> allx[200005],ally[200005];
int pos(int x,int y){
	return (x-1)*m+y;
}
char GN(){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	return ch;
}
int gf(int x,int f[]){
	return f[x]==x?x:f[x]=gf(f[x],f);
}
void Pushup(int p){
	sum[p][0]=sum[c[p][0]][0]+sum[c[p][1]][0];
	sum[p][1]=sum[c[p][0]][1]+sum[c[p][1]][1];
}
void Upd(int &p,int l,int r,int x,int col,int dlt){
	if(!p)p=++tot;
	sum[p][col]+=dlt;
	if(l==r)return ;
	int mid=(l+r)/2;
	if(x<=mid)Upd(c[p][0],l,mid,x,col,dlt);
	else Upd(c[p][1],mid+1,r,x,col,dlt);
	Pushup(p);
}
int Merge(int p,int q,int l,int r){
	if(!p||!q)return p+q;
	if(l==r)return sum[p][0]+=sum[q][0],sum[p][1]+=sum[q][1],p;
	int mid=(l+r)/2;
	c[p][0]=Merge(c[p][0],c[q][0],l,mid);
	c[p][1]=Merge(c[p][1],c[q][1],mid+1,r);
	return Pushup(p),p;
}
int Sum(int p,int l,int r,int x,int y,int z){
	if(!p)return 0;
	if(x<=l&&r<=y)return sum[p][z];
	int mid=(l+r)/2,ret=0;
	if(x<=mid)ret+=Sum(c[p][0],l,mid,x,y,z);
	if(mid<y)ret+=Sum(c[p][1],mid+1,r,x,y,z);
	return ret;
}
void Merge3(int x,int y){
	x=gf(x,fa),y=gf(y,fa);
	if(x==y)return ;
	if(sz[y]<sz[x])swap(x,y);
	fa[x]=y,sz[y]+=sz[x],rt[y]=Merge(rt[y],rt[x],1,q);
	for(int i:alls[x]){
		if(alls[y].count(i)){
			Upd(rt[y],1,q,lev[i],col[i],-1);
		}
		else alls[y].insert(i);
	}
	for(auto i:allx[x]){
		int k=i.first;
		allx[y][k]=Merge(allx[y][k],i.second,1,m);
	}
	for(auto i:ally[x]){
		int k=i.first;
		ally[y][k]=Merge(ally[y][k],i.second,1,n);
	}
}
void Merge2(int x,int y){//y上 
	x=gf(x,fay),y=gf(y,fay);
	if(x==y)return ;
	fay[x]=y,miy[y]=min(miy[y],miy[x]),mxy[y]=max(mxy[y],mxy[x]);
}
void Merge1(int x,int y){//x上 
	x=gf(x,fax),y=gf(y,fax);
	if(x==y)return ;
	fax[x]=y,mix[y]=min(mix[y],mix[x]),mxx[y]=max(mxx[y],mxx[x]);
}
set<int> vst; 
void Check(int p,int z){
	if(!has[p]){
		if(gf(p,fa)!=gf(z,fa))vst.insert(p);
	}
	else {
		bool fl=0;
		for(int j:g[p])if(gf(j,fa)==gf(z,fa))fl=1;
		if(!fl)vst.insert(p);
	}
}
int GetX(int x){
	return (x-1)/m+1;
}
int GetY(int x){
	return (x-1)%m+1;
}
void Solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n+2;i++){
		A[i].resize(m+3);
		B[i].resize(m+3);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)A[i][j]=GN();
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)B[i][j]=GN();
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(A[i][j]=='3')
				g[pos(i,j)].push_back(pos(i,j+1)),g[pos(i,j+1)].push_back(pos(i,j));
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(B[i][j]=='3')
				g[pos(i,j)].push_back(pos(i+1,j)),g[pos(i+1,j)].push_back(pos(i,j));
		}
	}
	for(int i=1,c,lv,x,y;i<=q;i++){
		scanf("%d%d%d%d",&c,&lv,&x,&y),has[pos(x,y)]=1,col[pos(x,y)]=c,lev[pos(x,y)]=lv,Q[i][0]=x,Q[i][1]=y;
	}
	for(int i=1;i<=n*m;i++){
		mix[i]=mxx[i]=GetX(i),miy[i]=mxy[i]=GetY(i);
		fax[i]=fay[i]=fa[i]=i,sz[i]=1;
		Upd(allx[i][GetX(i)],1,m,GetY(i),0,1);
		Upd(ally[i][GetY(i)],1,n,GetX(i),0,1);
	}
	for(int i=1;i<=n*m;i++){
		for(int j:g[i])if(has[j])Upd(rt[i],1,q,lev[j],col[j],1),alls[i].insert(j);
	}
	for(int i=1;i<=n*m;i++){
		if(has[i])continue;
		for(int j:g[i]){
			if(!has[j])Merge3(i,j);
		}
		int x=GetX(i),y=GetY(i),z=i;
		if(A[x][y]=='2'&&!has[pos(x,y+1)])Merge2(z,pos(x,y+1));
		if(A[x][y-1]=='2'&&!has[pos(x,y-1)])Merge2(z,pos(x,y-1));
		if(B[x][y]=='2'&&!has[pos(x+1,y)])Merge1(z,pos(x+1,y));
		if(B[x-1][y]=='2'&&!has[pos(x-1,y)])Merge1(z,pos(x-1,y));
	}
	for(int i=q;i>=1;i--){
		int x=Q[i][0],y=Q[i][1],z=pos(x,y);
		has[z]=0;
		//1.撤销这个棋子对周围造成的影响
		for(int j:g[z]){
			int f=gf(j,fa);
			alls[f].erase(z),Upd(rt[f],1,q,lev[z],col[z],-1);
		}
		//2.把这个棋子和周围的连起来
		for(int j:g[z]){
			if(has[j])continue;
			Merge3(z,j);
		}
		ans[i]+=sz[gf(z,fa)]-1;//贡献1:互通路能到达的点数
		ans[i]+=Sum(rt[gf(z,fa)],1,q,1,lev[z],col[z]^1);//贡献2:互通路能到达的棋子
		//3.处理横向,纵向的贡献
		if(A[x][y]=='2'&&!has[pos(x,y+1)])Merge2(z,pos(x,y+1));
		if(A[x][y-1]=='2'&&!has[pos(x,y-1)])Merge2(z,pos(x,y-1));
		if(B[x][y]=='2'&&!has[pos(x+1,y)])Merge1(z,pos(x+1,y));
		if(B[x-1][y]=='2'&&!has[pos(x-1,y)])Merge1(z,pos(x-1,y));
		ans[i]+=mxx[gf(z,fax)]-mix[gf(z,fax)]+mxy[gf(z,fay)]-miy[gf(z,fay)];
		//4.处理1类边的贡献
		if(A[x][y]=='1')Check(pos(x,y+1),z);
		if(A[x][y-1]=='1')Check(pos(x,y-1),z);
		if(B[x][y]=='1')Check(pos(x+1,y),z);
		if(B[x-1][y]=='1')Check(pos(x-1,y),z);
		//5.处理横向纵向达到了最大的点上面的贡献
		int u=x,v=mxy[gf(z,fay)];
		if(A[u][v]=='2'&&has[pos(u,v+1)])Check(pos(u,v+1),z);
		u=x,v=miy[gf(z,fay)];
		if(A[u][v-1]=='2'&&has[pos(u,v-1)])Check(pos(u,v-1),z);
		u=mxx[gf(z,fax)],v=y;
		if(B[u][v]=='2'&&has[pos(u+1,v)])Check(pos(u+1,v),z);
		u=mix[gf(z,fax)],v=y;
		if(B[u-1][v]=='2'&&has[pos(u-1,v)])Check(pos(u-1,v),z);
		ans[i]+=vst.size(),vst.clear(); 
		//6.删掉横向和纵向被算重的 
		u=gf(z,fa);
		ans[i]-=Sum(allx[u][x],1,m,miy[gf(z,fay)],mxy[gf(z,fay)],0)-1;
		ans[i]-=Sum(ally[u][y],1,n,mix[gf(z,fax)],mxx[gf(z,fax)],0)-1;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}
void Clear(){
	for(int i=1;i<=200000;i++){
		has[i]=col[i]=lev[i]=Q[i][0]=Q[i][1]=fa[i]=sz[i]=0;
		mix[i]=mxx[i]=miy[i]=mxy[i]=fax[i]=fay[i]=rt[i]=ans[i]=0;
		g[i].clear(),A[i].clear(),B[i].clear(),alls[i].clear(),allx[i].clear(),ally[i].clear();
	}
	for(int i=1;i<=tot;i++)c[i][0]=c[i][1]=sum[i][0]=sum[i][1]=0;
	tot=0;
}
int main(){
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)Solve(),Clear();
	return 0;
}
*/
