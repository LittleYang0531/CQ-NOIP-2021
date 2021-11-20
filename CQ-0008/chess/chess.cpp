#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define N 200012
inline int re(){int x=0;char ch=getchar();while(ch<'0')ch=getchar();while('0'<=ch)x=x*10+(ch^'0'),ch=getchar();return x;}
inline int rc(){char ch=getchar();while(ch<'0')ch=getchar();return (ch^'0');}
int T,n,m,Q,cn,X[N],Y[N],V[N],C[N],Up[N],Dw[N],Le[N],Ri[N],vs[N],anss[N];vector<int>e1[N],e3[N];set<int>rw[N],cl[N];
inline void Ad1(int x,int y){e1[x].push_back(y);e1[y].push_back(x);}
inline void Ad3(int x,int y){e3[x].push_back(y);e3[y].push_back(x);}
inline int ID(int x,int y){return (x-1)*m+y;}
int f[N],tot=0,rt[2][N],c[N*63][2],s[N*63],ans,rx[N],ry[N];
void Ins(int &p,int l,int r,int x,int v)
{
	if(!p)p=++tot;s[p]+=v;if(l==r)return;int mid=(l+r)>>1;
	(x<=mid)?Ins(c[p][0],l,mid,x,v):Ins(c[p][1],mid+1,r,x,v);
}
int Me(int x,int y,int l,int r)
{
	if((!x)||(!y))return x|y;s[x]+=s[y];if(l==r)return x;int mid=(l+r)>>1;
	c[x][0]=Me(c[x][0],c[y][0],l,mid);c[x][1]=Me(c[x][1],c[y][1],mid+1,r);return x;
}
int Ask(int p,int l,int r,int L,int R)
{
	if((!p)||(R<l)||(r<L))return 0;if((L<=l)&&(r<=R))return s[p];int mid=(l+r)>>1;
	return Ask(c[p][0],l,mid,L,R)+Ask(c[p][1],mid+1,r,L,R);
}
int getf(int x){return (f[x]==x)?x:(f[x]=getf(f[x]));}
set<int>w[N];set<int>::iterator it;int sz[N];map<int,int>xm[N],ym[N];map<int,int>::iterator it1;
inline void Ix(int p1,int p2,int x)
{
	int p=xm[p2][x],o;if(!xm[p1].count(x))xm[p1][x]=p;
	else o=xm[p1][x],rx[min(p,o)]=Me(rx[p],rx[o],1,m),xm[p1][x]=min(p,o);
}
inline void Iy(int p1,int p2,int y)
{
	int p=ym[p2][y],o;if(!ym[p1].count(y))ym[p1][y]=p;
	else o=ym[p1][y],ry[min(p,o)]=Me(ry[p],ry[o],1,n),ym[p1][y]=min(p,o);
}
inline int S(int x){return w[x].size()+xm[x].size()+ym[x].size();}
inline void Mg(int x,int y)
{
	x=getf(x);y=getf(y);if(x==y)return;if(S(x)<S(y))swap(x,y);f[y]=x;sz[x]+=sz[y];
	rt[0][x]=Me(rt[0][x],rt[0][y],1,cn);rt[1][x]=Me(rt[1][x],rt[1][y],1,cn);int p;
	while(!w[y].empty()){p=*w[y].begin();w[y].erase(w[y].begin());if(w[x].find(p)==w[x].end())w[x].insert(p);else Ins(rt[C[p]][x],1,cn,V[p],-1);}
	for(it1=xm[y].begin();it1!=xm[y].end();++it1)Ix(x,y,it1->first);xm[y].clear();
	for(it1=ym[y].begin();it1!=ym[y].end();++it1)Iy(x,y,it1->first);ym[y].clear();
}
int hv[N],tim;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=re();
	while(T--)
	{
		n=re();m=re();cn=n*m;Q=re();int i,j,u,x,y,z,v,l,r;
		for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
		{
			x=(i-1)*m+j;v=rc();
			if(v==0)continue;
			if(v==1)Ad1(x,x+1);
			if(v==2)Ri[x]=Le[x+1]=1;
			if(v==3)Ad3(x,x+1);
		}
		for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
		{
			x=(i-1)*m+j;v=rc();
			if(v==0)continue;
			if(v==1)Ad1(x,x+m);
			if(v==2)Dw[x]=Up[x+m]=1;
			if(v==3)Ad3(x,x+m);
		}
		for(i=1;i<=Q;i++)
		{
			C[i]=re();V[i]=re();X[i]=re();Y[i]=re();vs[x=((X[i]-1)*m+Y[i])]=i;rw[X[i]].insert(Y[i]);cl[Y[i]].insert(X[i]);
			for(j=0,u=e3[x].size();j<u;j++)y=e3[x][j],w[y].insert(i),Ins(rt[C[i]][y],1,cn,V[i],1);
		}
		for(i=1;i<=cn;i++)
		{
			x=((i-1)/m)+1;y=i-(x-1)*m;f[i]=i;if(!vs[i]){sz[i]=1;xm[i][x]=ym[i][y]=i;Ins(rx[i],1,m,y,1);Ins(ry[i],1,n,x,1);}
			Up[i]=Up[i]?Up[i-m]:x;Le[i]=Le[i]?Le[i-1]:y;
		}
		for(i=cn;i>=1;i--)
		{
			x=((i-1)/m)+1;y=i-(x-1)*m;
			Dw[i]=Dw[i]?Dw[i+m]:x;Ri[i]=Ri[i]?Ri[i+1]:y;
		}
		for(x=1;x<=cn;x++)if(!vs[x])for(j=0,u=e3[x].size();j<u;j++)if(!vs[y=e3[x][j]])Mg(x,y);
		for(i=Q;i>=1;i--)
		{
			x=(X[i]-1)*m+Y[i];rw[X[i]].erase(Y[i]);cl[Y[i]].erase(X[i]);
			for(j=0,u=e3[x].size();j<u;j++){y=getf(e3[x][j]);if((it=w[y].find(i))!=w[y].end())w[y].erase(it),Ins(rt[C[i]][y],1,cn,V[i],-1);}
			vs[x]=0;++sz[x];xm[x][X[i]]=ym[x][Y[i]]=x;Ins(rx[x],1,m,Y[i],1);Ins(ry[x],1,n,X[i],1);
			for(j=0,u=e3[x].size();j<u;j++)if(!vs[y=e3[x][j]])Mg(x,y);z=y=getf(x);ans=Ask(rt[C[i]^1][y],1,cn,1,V[i])+sz[y];
			
			++tim;
			
			l=Le[x];r=Ri[x];it=rw[X[i]].lower_bound(Y[i]);if(it!=rw[X[i]].begin())--it,l=max(l,*it),++it;if(it!=rw[X[i]].end())r=min(r,*it);
			if(l<Y[i])hv[x-1]=tim;if(Y[i]<r)hv[x+1]=tim;
			y=ID(X[i],l);if(vs[y])++l,y=vs[y],ans+=((C[y]!=C[i])&&(V[y]<=V[i])&&(w[z].find(y)==w[z].end()));
			y=ID(X[i],r);if(vs[y])--r,y=vs[y],ans+=((C[y]!=C[i])&&(V[y]<=V[i])&&(w[z].find(y)==w[z].end()));
			ans+=r-l+1-Ask(rx[xm[z][X[i]]],1,m,l,r);
			
			
			l=Up[x];r=Dw[x];it=cl[Y[i]].lower_bound(X[i]);if(it!=cl[Y[i]].begin())--it,l=max(l,*it),++it;if(it!=cl[Y[i]].end())r=min(r,*it);
			if(l<X[i])hv[x-m]=tim;if(X[i]<r)hv[x+m]=tim;
			y=ID(l,Y[i]);if(vs[y])++l,y=vs[y],ans+=((C[y]!=C[i])&&(V[y]<=V[i])&&(w[z].find(y)==w[z].end()));
			y=ID(r,Y[i]);if(vs[y])--r,y=vs[y],ans+=((C[y]!=C[i])&&(V[y]<=V[i])&&(w[z].find(y)==w[z].end()));
			ans+=r-l+1-Ask(ry[ym[z][Y[i]]],1,n,l,r);
			
			for(j=0,u=e1[x].size();j<u;j++)
			if(hv[y=e1[x][j]]!=tim)
			{
				if(vs[y])y=vs[y],ans+=((C[y]!=C[i])&&(V[y]<=V[i])&&(w[z].find(y)==w[z].end()));
				else ans+=(getf(y)!=z);
			}
			anss[i]=ans-1;
		}
		for(i=1;i<=Q;i++)printf("%d\n",anss[i]);
		for(i=1;i<=cn;i++)w[i].clear(),sz[i]=f[i]=0,xm[i].clear(),ym[i].clear(),rt[0][i]=rt[1][i]=0,rx[i]=ry[i]=0,e1[i].clear(),e3[i].clear();
		for(i=1;i<=cn;i++)vs[i]=0,Up[i]=Dw[i]=Le[i]=Ri[i]=0;
		for(i=1;i<=n;i++)rw[i].clear();for(i=1;i<=m;i++)cl[i].clear();
		while(tot){c[tot][0]=c[tot][1]=s[tot]=0;--tot;}
	}return 0;
}
