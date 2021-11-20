#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,q,cnt,h[100005];
char ch[100005];
bool v[400005],v1[100005];
struct edge{int n,t,v;}e[400005];
struct work{int c,l;}a[100005];
void add(int x,int y,int z) {
	e[++cnt]=(edge){h[x],y,z};
	h[x]=cnt;
	e[++cnt]=(edge){h[y],x,z};
	h[y]=cnt;
}
int dfs(int c,int l,int x,int lx,int p) {
	if(a[x].l&&(a[x].c==c||(a[x].c!=c&&a[x].l>l)||!p))return 0;
	int sum=!v1[x];
	v1[x]=1;
	if(p==1)return !v[x];
	for(int i=h[x];i;i=e[i].n) {
		int y=e[i].t;
		if(!e[i].v||v[i])continue;
		if(p==-1) {
			v[i]=1;
			sum+=dfs(c,l,y,x,e[i].v);
		} else {
			if(p==2) {
				if(e[i].v!=2)continue;
				if(lx+m==x&&x+m==y)v[i]=1,sum+=dfs(c,l,y,x,p);
				if(lx-m==x&&x-m==y)v[i]=1,sum+=dfs(c,l,y,x,p);
				if(lx+1==x&&x+1==y)v[i]=1,sum+=dfs(c,l,y,x,p);
				if(lx-1==x&&x-1==y)v[i]=1,sum+=dfs(c,l,y,x,p);
			}else if(e[i].v==p)v[i]=1,sum+=dfs(c,l,y,x,p);
		}
	}
	return sum;
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++) {
			scanf("%s",ch);
			for(int j=1;j<m;j++)add((i-1)*m+j,(i-1)*m+j+1,ch[j-1]-'0');
		}
		for(int i=1;i<n;i++) {
			scanf("%s",ch);
			for(int j=1;j<=m;j++)add((i-1)*m+j,(i-1)*m+m+j,ch[j-1]-'0');
		}
		while(q--) {
			int c,l,x,y;
			scanf("%d%d%d%d",&c,&l,&x,&y);
			memset(v,0,sizeof(v));
			memset(v1,0,sizeof(v1));
			printf("%d\n",dfs(c,l,(x-1)*m+y,0,-1)-1);
			a[(x-1)*m+y]=(work){c,l};
		}
	}
	return 0;
}
