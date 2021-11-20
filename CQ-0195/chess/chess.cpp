#include<bits/stdc++.h>
using namespace std;
int n,m,q,t,g,c,l,xx,yy,ans=0,iii=0;
struct aaa{
	int x,y;
	bool d;
}r;
struct bbb{
	int x,y;
}h;
struct ccc{
	int c,l;
}b;
map <aaa,int>p;
map <bbb,ccc>a;
map <bbb,int>d;
void dfs(int x,int y,int num){
	if (num==0) return;
	if (x==0 || y==0 || x>n || y>m) return;
	if (num==-1){
		h.x=x,h.y=y;
		d[h]=iii;
		r.x=x-1,r.y=y,r.d=true;
		dfs(x-1,y,p[r]);
		r.x=x,r.y=y-1,r.d=false;
		dfs(x,y-1,p[r]);
		r.x=x,r.y=y,r.d=true;
		dfs(x+1,y,p[r]);
		r.x=x,r.y=y,r.d=false;
		dfs(x,y+1,p[r]);
	}
	h.x=x,h.y=y;
	if (a[h].l!=0){
		if (l>=a[h].l && c!=a[h].c && d[h]!=iii) d[h]=iii,ans++;
		return;
	}
	if (d[h]!=iii) d[h]=iii,ans++;
	if (num==1) return;
	if (num==2){
		if (xx>x){
			r.x=x-1,r.y=y,r.d=true;
			if (p[r]==2)
				dfs(x-1,y,p[r]);
		}
		if (xx<x){
			r.x=x,r.y=y,r.d=true;
			if (p[r]==2)
				dfs(x+1,y,p[r]);
		}
		if (yy>y){
			r.x=x,r.y=y-1,r.d=false;
			if (p[r]==2)
				dfs(x,y-1,p[r]);
		}
		if (yy<y){
			r.x=x,r.y=y,r.d=false;
			if (p[r]==2)
				dfs(x,y+1,p[r]);
		}
	}
	if (num==3){
			r.x=x-1,r.y=y,r.d=true;
			if (p[r]==3){
				p[r]=4;
				dfs(x-1,y,p[r]);
				p[r]=3;
			}
			r.x=x,r.y=y,r.d=true;
			if (p[r]==3){
				p[r]=4;
				dfs(x+1,y,p[r]);
				p[r]=3;
			}
			r.x=x,r.y=y-1,r.d=false;
			if (p[r]==3){
				p[r]=4;
				dfs(x,y-1,p[r]);
				p[r]=3;
			}
			r.x=x,r.y=y,r.d=false;
			if (p[r]==3){
				p[r]=4;
				dfs(x,y+1,p[r]);
				p[r]=3;
			}
	}
}
int main(){
	
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		for (int i=1;i<=n;i++){
			for (int l=1;i<m;l++){
				scanf("%1d",&g);
				r.x=i,r.y=l,r.d=false;
				p[r]=g;
			}
		}
		for (int i=1;i<n;i++){
			for (int l=1;l<=m;l++){
				scanf("%1d",&g);
				r.x=i,r.y=l,r.d=true;
				p[r]=g;
			}
		}
		while (q--){
			scanf("%d%d%d%d",&c,&l,&xx,&yy);
			iii++;
			ans=0;
			dfs(xx,yy,-1);
			h.x=xx,h.y=yy;
			a[h].c=c,a[h].l=l;
			printf("%d\n",ans);
		}
	}
	
}
