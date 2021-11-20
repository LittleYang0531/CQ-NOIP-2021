#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,q;
string str;
int head[MAXN],to[MAXN],nxt[MAXN],val[MAXN],cnt=-1;
int lv[MAXN],col[MAXN];
bool vis[MAXN],vs[MAXN];
void add(int u,int v,int w) {
	nxt[++cnt]=head[u];
	to[cnt]=v;
	val[cnt]=w;
	head[u]=cnt;
	nxt[++cnt]=head[v];
	to[cnt]=u;
	val[cnt]=w;
	head[v]=cnt;
}
int num(int x,int y) {
	return (x-1)*m+y;
}
int c,l,x,y,ans;
void dfs(int p,int k) {
	if(vs[p]&&p!=num(x,y)) return;
	if(vis[p]) {
		if(c!=col[p]&&l>=lv[p]) ++ans;
		return;
	}
	if(!vs[p]) {
		vs[p]=1;
		++ans;
	}
	for(int i=head[p];~i;i=nxt[i]) {
		if(val[i]==k) {
			dfs(to[i],k);
		}
	}
}
bool f1,f2,f3;
int t;
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(head,-1,sizeof(head));
		cnt=-1;
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;++i) {
			cin>>str;
			for(int j=0;j<m-1;++j) {
				if(str[j]=='1') {
					add(num(i,j+1),num(i,j+2),1);
					f1=1;
				}
				if(str[j]=='2') {
					add(num(i,j+1),num(i,j+2),2);
					f2=1;
				}
				if(str[j]=='3') {
					add(num(i,j+1),num(i,j+2),4);
					f3=1;
				}
			}
		}
		for(int i=1;i<n;++i) {
			cin>>str;
			for(int j=0;j<m;++j) {
				if(str[j]=='1') {
					add(num(i,j+1),num(i+1,j+1),1);
					f1=1;
				}
				if(str[j]=='2') {
					add(num(i,j+1),num(i+1,j+1),3);
					f2=1;
				}
				if(str[j]=='3') {
					add(num(i,j+1),num(i+1,j+1),4);
					f3=1;
				}
			}
		}
		if(!f2&&!f3) {
			while(q--) {
				scanf("%d %d %d %d",&c,&l,&x,&y);
				ans=0;
				vis[num(x,y)]=1,col[num(x,y)]=c,lv[num(x,y)]=l;
				for(int i=head[num(x,y)];~i;i=nxt[i]) {
					if(!vis[to[i]]) ++ans;
					if(vis[to[i]]&&c!=col[to[i]]&&l>=lv[to[i]]) ++ans;
				}
				printf("%d\n",ans);
			}
		}
		else {
			while(q--) {
				scanf("%d %d %d %d",&c,&l,&x,&y);
				ans=-1;
				memset(vs,0,sizeof(vs));
				dfs(num(x,y),1),dfs(num(x,y),2),dfs(num(x,y),3),dfs(num(x,y),4);
				vis[num(x,y)]=1,col[num(x,y)]=c,lv[num(x,y)]=l;
				printf("%d\n",ans);
			}
		}
	} 
	return 0;
}
