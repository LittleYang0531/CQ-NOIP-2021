#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define MOD 
#define MAXN 200005
#define INF 1e17
#define uns unsigned
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int pt[30],lp;
inline void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	pt[lp=1]=x%10;
	while(x>9)x/=10,pt[++lp]=x%10;
	while(lp)putchar(pt[lp--]^48);
	putchar(c);
}
inline ll lowbit(ll x){return x&-x;}

struct node{
	int x,y;node(){}
	node(int X,int Y){x=X,y=Y;}
};
struct sgt{
	int ls,rs,a;sgt(){}
	sgt(int A){a=A,ls=rs=0;}
}t[MAXN<<6];
int IN;
inline void upd(int x){
	t[x].a=t[t[x].ls].a+t[t[x].rs].a;
}
inline int add(int x,int l,int r,int z,int d){
	if(!x)x=++IN,t[IN]=sgt(0);
	if(l==r){t[x].a+=d;return x;}
	int mid=(l+r)>>1;
	if(z<=mid)t[x].ls=add(t[x].ls,l,mid,z,d);
	else t[x].rs=add(t[x].rs,mid+1,r,z,d);
	upd(x);return x;
}
inline int merg(int x,int y,int l,int r){
	if(!x||!y)return x^y;
	if(l==r){t[x].a+=t[y].a;return x;}
	t[x].a+=t[y].a;
	int mid=(l+r)>>1;
	t[x].ls=merg(t[x].ls,t[y].ls,l,mid);
	t[x].rs=merg(t[x].rs,t[y].rs,mid+1,r);
	return x;
}

int n,m,ps,Q;
vector<bool>vs[MAXN>>1];
vector<int>id[MAXN>>1],opr[MAXN>>1],opc[MAXN>>1];
int f[MAXN];
int rt[MAXN][2],X[MAXN],Y[MAXN];
char in[MAXN];
struct itn{
	int c,v,x,y;
	inline void readin(){
		c=read(),v=read(),x=read(),y=read();
	}
}q[MAXN];

struct bcj{
	int rt[MAXN][2],siz[MAXN],fa[MAXN],mn[MAXN],mx[MAXN];
	inline void init(int n){
		for(int i=1;i<=n;i++)
			rt[i][0]=rt[i][1]=0,siz[i]=1,fa[i]=0,mn[i]=mx[i]=i;
	}
	inline int finds(int x){
		return !fa[x]?x:(fa[x]=finds(fa[x]));
	}
	inline void unions(int u,int v,int qc,int qv){
		u=finds(u),v=finds(v);
		if(u^v){
			fa[v]=u,siz[u]+=siz[v];
			mn[u]=min(mn[u],mn[v]),mx[u]=max(mx[u],mx[v]);
			rt[u][0]=merg(rt[u][0],rt[v][0],1,Q);
			rt[u][1]=merg(rt[u][1],rt[v][1],1,Q);
			if(qc<2)rt[u][qc]=add(rt[u][qc],1,Q,qv,-1);
		}
	}
	inline void ini(int x,int si,int qc,int qv){
		x=finds(x);
		siz[x]=si,rt[x][0]=rt[x][1]=0;
		if(qc<2)rt[x][qc]=add(0,1,Q,qv,1);
	}
	inline void chg(int x,int qc,int qv){
		x=finds(x);
		siz[x]++,rt[x][qc]=add(rt[x][qc],1,Q,qv,-1);
	}
}A,B,C;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
inline int opt(int x,int y){
	if(x>y)swap(x,y);
	if(X[x]<X[y])return opc[X[x]][Y[x]];
	else return opr[X[x]][Y[x]];
}
int st[4];
bool vis[MAXN];
inline void dfs(int x,int c,int v,int dr){
	if(f[x]&&(q[f[x]].c==c||q[f[x]].v>v))
		return;
	vis[x]=1;
	if(f[x])return;
	for(int k=0;k<4;k++){
		int y=id[X[x]+dx[k]][Y[x]+dy[k]];
		if(dr>=0&&k!=dr)continue;
		if(!y)continue;
		if(dr<0&&vis[y])continue;
		int cp=3;
		if(dr>=0)cp=2;
		if(opt(x,y)==cp)dfs(y,c,v,dr);
	}
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int T=read();T--;){
		memset(f,0,sizeof(f));
		memset(rt,0,sizeof(rt));
		n=read(),m=read(),Q=read();
		vs[0].clear(),id[0].clear();
		for(int i=0;i<=m+1;i++)
			vs[0].push_back(0),id[0].push_back(0);
		opr[0]=opc[0]=id[0];
		for(int i=1;i<=n+1;i++)
			vs[i]=vs[0],opr[i]=opc[i]=id[i]=id[0];
		ps=0,IN=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				id[i][j]=++ps,X[ps]=i,Y[ps]=j;
		bool tk1=1;
		for(int i=1;i<=n;i++){
			scanf("%s",in+1);
			for(int j=1;j<m;j++){
				opr[i][j]=(in[j]^48);
				if(opr[i][j]>1)tk1=0;
			}
		}
		for(int i=1;i<n;i++){
			scanf("%s",in+1);
			for(int j=1;j<=m;j++){
				opc[i][j]=(in[j]^48);
				if(opc[i][j]>1)tk1=0;
			}
		}
		for(int i=1;i<=Q;i++){
			q[i].readin();
			int x=id[q[i].x][q[i].y];
			f[x]=i;
		}
		
		if(tk1){
			for(int i=1;i<=Q;i++)
				f[id[q[i].x][q[i].y]]=0;
			for(int i=1;i<=Q;i++){
				int x=q[i].x,y=q[i].y;
				int ans=0;
				for(int k=0;k<4;k++){
					int v=id[x+dx[k]][y+dy[k]];
					if(!v)continue;
					if(opt(id[x][y],v)==1){
						if(!f[v])ans++;
						else if(q[f[v]].c!=q[i].c&&q[f[v]].v<=q[i].v)
							ans++;
					}
				}
				print(ans);
				f[id[x][y]]=i;
			}
			continue;
		}
		
		if(n*m<=10000&&Q<=2000){
			for(int i=1;i<=Q;i++)
				f[id[q[i].x][q[i].y]]=0;
			for(int i=1;i<=Q;i++){
				for(int j=1;j<=ps;j++)vis[j]=0;
				int x=q[i].x,y=q[i].y;
				dfs(id[x][y],q[i].c,q[i].v,-1);
				for(int k=0;k<4;k++){
					dfs(id[x][y],q[i].c,q[i].v,k);
					int v=id[x+dx[k]][y+dy[k]];
					if(!v)continue;
					if(opt(id[x][y],v)==1){
						if(!f[v])vis[v]=1;
						else if(q[f[v]].c!=q[i].c&&q[f[v]].v<=q[i].v)
							vis[v]=1;
					}
				}
				int ans=0;
				for(int j=1;j<=ps;j++)
					if(j!=id[x][y]&&vis[j])ans++;
				print(ans);
				
				f[id[x][y]]=i;
			}
			continue;
		}
		
		A.init(ps),B.init(ps),C.init(ps);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int x=id[i][j];
				if(f[x]){
					A.ini(x,0,q[f[x]].c,q[f[x]].v);
					B.ini(x,0,2,0);
					C.ini(x,0,2,0);
				}else{
					A.ini(x,1,2,0);
					B.ini(x,1,2,0);
					C.ini(x,1,2,0);
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++){
				int x=id[i][j],y=id[i][j+1];
				if(opr[i][j]==2)B.unions(x,y,2,0);
				else if(opr[i][j]==3)A.unions(x,y,2,0);
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++){
				int x=id[i][j],y=id[i+1][j];
				if(opr[i][j]==2)C.unions(x,y,2,0);
				else if(opr[i][j]==3)A.unions(x,y,2,0);
			}
		for(int i=1;i<=Q;i++){
			int x=id[q[i].x][q[i].y];
			for(int k=0;k<4;k++){
				st[k]=0;
				int v=id[q[i].x+dx[k]][q[i].y+dy[k]];
				if(!v)continue;
				if(opt(x,v)==3)st[k]=A.finds(v);
			}
			for(int k=0;k<4;k++){
				if(!st[k])continue;
				bool ok=1;
				for(int j=0;j<k;j++)if(st[k]==st[j])ok=0;
				if(!ok)continue;
				A.rt[st[k]][q[i].c]=add(A.rt[st[k]][q[i].c],1,Q,q[i].v,1);
			}
		}
		
	}
	return 0;
}
