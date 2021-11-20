#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int rech() {
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	return ch^48;
}
const int maxn = 2e5+10;
int n,m;
struct E{int x,v;};
struct Qry{int cl,lv,x,y;}Q[maxn];
vector<E>g[maxn];
void add(int x,int y,int z) {g[x].push_back((E){y,z}),g[y].push_back((E){x,z});}
int mplv[maxn],mpcl[maxn];
#define dot(x,y) ((x-1)*m+y)
int s[maxn*20],tot,ls[maxn*20],rs[maxn*20];
struct sgt1 {
	int rt;
	int New() {return ++tot,ls[tot]=rs[tot]=s[tot]=0,tot;}
	void ins(int&k,int l,int r,int p) {
		if(!k) k=New();if(l==r) return s[k]=1,void();int mid=l+r>>1;
		p>mid?ins(rs[k],mid+1,r,p):ins(ls[k],l,mid,p);
		s[k]=s[ls[k]]|s[rs[k]];
	}
	int askl(int k,int l,int r,int L) {
		if(!k||L>r) return 0;int mid=l+r>>1;
		if(L<=l) {
			if(l==r) return l;
			if(s[ls[k]]) return askl(ls[k],l,mid,L);
			if(s[rs[k]]) return askl(rs[k],mid+1,r,L);
			return 0;
		}
		int t=askl(ls[k],l,mid,L);if(t) return t;
		return askl(rs[k],mid+1,r,L);
	}
	int askr(int k,int l,int r,int R) {
		if(!k||l>R) return 0;int mid=l+r>>1;
		if(r<=R) {
			if(l==r) return l;
			if(s[rs[k]]) return askr(rs[k],mid+1,r,R);
			if(s[ls[k]]) return askr(ls[k],l,mid,R);
			return 0;
		}
		int t=askr(rs[k],mid+1,r,R);if(t) return t;
		return askr(ls[k],l,mid,R);
	}
}li[maxn][2],ha[maxn][2];
//struct seg2 {
//	int rt;
//	void ins()
//}R[maxn];
int q,rv[maxn],dv[maxn],uw[maxn],dw[maxn],rg[maxn],lg[maxn],pr[maxn];
int v[maxn],c[maxn],dfx,lft,Lft,rgt,Rgt;
int bfs(Qry X) {
	queue<int>ve;
	int res=0;
	while(!ve.empty()) ve.pop();
	ve.push(dot(X.x,X.y));v[dot(X.x,X.y)]=dfx;
	while(!ve.empty()) {
		int x=ve.front();ve.pop();
		for(E y:g[x]) if(y.v==3) {
			if(v[y.x]==dfx) continue;
			v[y.x]=dfx;
			if(mplv[y.x]) {
				if(lft<=y.x&&y.x<=rgt) continue;
				if(Lft<=y.x&&y.x<=Rgt&&(y.x-Lft)%m==0) continue;
				if(c[y.x]==dfx) continue;
				res+=(mpcl[y.x]!=X.cl&&mplv[y.x]<=X.lv);
			}
			else {
				ve.push(y.x);
				if(lft<=y.x&&y.x<=rgt) continue;
				if(Lft<=y.x&&y.x<=Rgt&&(y.x-Lft)%m==0) continue;
				if(c[y.x]==dfx) continue;
				++res;
			}
		}
	}return res;
}
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int csa=read();
	while(csa--) {
		n=read(),m=read(),q=read();
		
		//清空 
		for(int i=1;i<=n*m;i++) g[i].clear(),mplv[i]=mpcl[i]=0;
		for(int i=1;i<=n;i++) ha[i][0].rt=ha[i][1].rt=0;
		for(int i=1;i<=m;i++) li[i][0].rt=li[i][1].rt=0;
		tot=0;
		
		//读入 
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++) add(dot(i,j),dot(i,j+1),rv[dot(i,j)]=rech());
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++) add(dot(i,j),dot(i+1,j),dv[dot(i,j)]=rech());
		for(int i=1;i<=n;i++) rv[dot(i,m)]=0;
		for(int j=1;j<=m;j++) dv[dot(n,j)]=0;
		
		//预处理直行铁轨上下左右延伸的最长距离 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				uw[dot(i,j)]=(dv[dot(i-1,j)]==2?uw[dot(i-1,j)]+1:0);
				lg[dot(i,j)]=(rv[dot(i,j-1)]==2?lg[dot(i,j-1)]+1:0);
			}
		for(int i=n;i;i--)
			for(int j=m;j;j--) {
				dw[dot(i,j)]=(dv[dot(i,j)]==2?dw[dot(i+1,j)]+1:0);
				rg[dot(i,j)]=(rv[dot(i,j)]==2?rg[dot(i,j+1)]+1:0);
			}
		
		for(int i=1,t,res;i<=q;i++) {
			pr[i]=0;++dfx;
			Q[i]=(Qry){read(),read(),read(),read()};
//			L[i]=(E){Q[i].lv,i};
			mplv[dot(Q[i].x,Q[i].y)]=Q[i].lv;
			mpcl[dot(Q[i].x,Q[i].y)]=Q[i].cl;
			//先在这里处理普通铁轨的贡献 
			for(E y:g[dot(Q[i].x,Q[i].y)])
				if(y.v==1) {
					if(!mplv[y.x]) ++pr[i];
					else if(mpcl[y.x]!=Q[i].cl&&mplv[y.x]<=Q[i].lv) ++pr[i];
					c[y.x]=dfx;
				}
			//处理直行铁轨的贡献 
			res=dw[dot(Q[i].x,Q[i].y)];
			t=li[Q[i].y][Q[i].cl].askl(li[Q[i].y][Q[i].cl].rt,1,n,Q[i].x);
			if(t&&mplv[dot(t,Q[i].y)]) res=min(res,t-Q[i].x-1);
			t=li[Q[i].y][Q[i].cl^1].askl(li[Q[i].y][Q[i].cl^1].rt,1,n,Q[i].x);
			if(t&&mplv[dot(t,Q[i].y)]) res=min(res,t-Q[i].x-(mplv[dot(t,Q[i].y)]>Q[i].lv));
			pr[i]+=res;
			Rgt=dot(Q[i].x,Q[i].y)+res*m;
			
			res=uw[dot(Q[i].x,Q[i].y)];
			t=li[Q[i].y][Q[i].cl].askr(li[Q[i].y][Q[i].cl].rt,1,n,Q[i].x);
			if(t&&mplv[dot(t,Q[i].y)]) res=min(res,Q[i].x-t-1);
			t=li[Q[i].y][Q[i].cl^1].askr(li[Q[i].y][Q[i].cl^1].rt,1,n,Q[i].x);
			if(t&&mplv[dot(t,Q[i].y)]) res=min(res,Q[i].x-t-(mplv[dot(t,Q[i].y)]>Q[i].lv));
			pr[i]+=res;
			Lft=dot(Q[i].x,Q[i].y)-res*m;
			
			res=rg[dot(Q[i].x,Q[i].y)];
			t=ha[Q[i].x][Q[i].cl].askl(ha[Q[i].x][Q[i].cl].rt,1,m,Q[i].y);
			if(t&&mplv[dot(Q[i].x,t)]) res=min(res,t-Q[i].y-1);
			t=ha[Q[i].x][Q[i].cl^1].askl(ha[Q[i].x][Q[i].cl^1].rt,1,m,Q[i].y);
			if(t&&mplv[dot(Q[i].x,t)]) res=min(res,t-Q[i].y-(mplv[dot(Q[i].x,t)]>Q[i].lv));
			pr[i]+=res;
			rgt=dot(Q[i].x,Q[i].y)+res;
			
			res=lg[dot(Q[i].x,Q[i].y)];
			t=ha[Q[i].x][Q[i].cl].askr(ha[Q[i].x][Q[i].cl].rt,1,m,Q[i].y);
			if(t&&mplv[dot(Q[i].x,t)]) res=min(res,Q[i].y-t-1);
			t=ha[Q[i].x][Q[i].cl^1].askr(ha[Q[i].x][Q[i].cl^1].rt,1,m,Q[i].y);
			if(t&&mplv[dot(Q[i].x,t)]) res=min(res,Q[i].y-t-(mplv[dot(Q[i].x,t)]>Q[i].lv));
			pr[i]+=res;
			lft=dot(Q[i].x,Q[i].y)-res;
			//为直行铁轨更新信息 
			ha[Q[i].x][Q[i].cl].ins(ha[Q[i].x][Q[i].cl].rt,1,m,Q[i].y);
			li[Q[i].y][Q[i].cl].ins(li[Q[i].y][Q[i].cl].rt,1,n,Q[i].x);
			pr[i]+=bfs(Q[i]);
			cout<<pr[i]<<'\n';
		}
//		sort(L+1,L+1+q,[](E x,E y) {return x.x<y.x;});
//		for(int i=1,cnt=0;i<=q;i++) {
//			int j=i;
//			while(j<q&&L[j+1].x==L[i].x) ++j;
//			for(int k=i,MX=cnt+(j-i+1);k<=j;k++) mplv[dot(Q[L[k].v].x,Q[L[k].v].y)]=++cnt,mx[cnt]=MX;
//			i=j;
//		}
//		tot=0;
//		for(int i=1;i<=n*m;f[i]=i,i++)
//			for(E y:g[i]) if(y.v==3) {
//				if(mplv[y.x]) R[i].ins(R[i].rt,1,q,mplv[y.x]);
//			}
//		for(int i=1;i<=n*m;i++)
//			for(E y:g[i]) if(y.v==3) {
//				if(!mplv[y.x]) mrg(i,y.x);
//			}
//		for(int i=q;i;i--) {
//			
//		}
	}
	return 0;
}
